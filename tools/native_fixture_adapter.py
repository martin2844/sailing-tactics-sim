"""Adapt captured, fixed original routines to the bounded native state protocol.

Arguments retain the original declared order within separate integer/double
vectors. The native runner chooses the reviewed ABI for each fixed numeric ID;
the fixture cannot select an arbitrary address or supply executable bytes.
"""
from native_mutable_state import prepare_case


# Fixed IDs shared with native_reference_2002.c command 14.
ROUTINE_IDS = {
    0x42a530: 0, 0x42a2d0: 1, 0x429f40: 2, 0x42c400: 4,
    0x428c60: 5, 0x4249a0: 6, 0x427fd0: 10, 0x4280c0: 18,
    0x4286e0: 19, 0x428a30: 20, 0x44dfe0: 35, 0x44dbc0: 36, 0x414010: 37,
    0x42adb0: 11, 0x412f60: 12, 0x413100: 13, 0x41b170: 14,
    0x41b510: 15, 0x42e0a0: 16, 0x41e9c0: 17,
    0x41fd90: 21, 0x41f5b0: 22, 0x44e470: 23, 0x41f0b0: 24,
    0x4201a0: 25, 0x41eb80: 26, 0x420dd0: 27, 0x413f00: 28,
    0x4313a0: 29, 0x426ad0: 30, 0x420b20: 31,
    0x4139d0: 32, 0x413a20: 33, 0x413370: 34,
    0x42c210: 38, 0x42c2e0: 39, 0x42bfc0: 40, 0x4060a0: 41,
    0x42ad00: 42, 0x415ac0: 43, 0x415c40: 44, 0x42cf70: 45, 0x42d0c0: 46,
    0x4304d0: 47, 0x42cca0: 48, 0x42cd00: 49, 0x42cf50: 50,
}

# These are original signatures, independent of JavaScript implementations.
ARGUMENT_TYPES = {
    0x42a530: ['I32'] * 3, 0x42a2d0: ['I32'], 0x429f40: ['I32'],
    0x42c400: ['F64', 'F64', 'I32', 'I32'], 0x428c60: ['I32'], 0x4249a0: ['I32'],
    0x427fd0: ['I32'], 0x4280c0: ['I32'] * 4, 0x4286e0: ['I32'] * 3, 0x428a30: ['I32'],
    0x412f60: ['F64', 'F64'], 0x413100: ['F64', 'F64'],
    0x41e9c0: ['I32'], 0x4201a0: ['I32'], 0x426ad0: ['I32'],
    0x420b20: ['I32'] * 4, 0x4139d0: ['I32'],
    0x413a20: ['F64'] * 4 + ['I32'] * 5,
    0x413370: ['F64', 'I32', 'I32'],
    0x414010: ['F64', 'I32', 'I32', 'I32', 'I32', 'F64'],
    0x42c210: ['F64', 'F64', 'I32'], 0x42c2e0: ['F64', 'I32', 'F64', 'F64', 'I32'],
    0x42bfc0: ['I32', 'F64', 'F64', 'I32', 'I32'], 0x4060a0: ['I32', 'I32'],
    0x42ad00: ['I32', 'I32'], 0x42cf70: ['I32'], 0x42d0c0: ['I32'],
    0x42cca0: ['I32'], 0x42cd00: ['I32'] * 3,
}


def _i32(value):
    if not isinstance(value, int) or isinstance(value, bool) or not -0x80000000 <= value <= 0x7fffffff:
        raise ValueError('Original signed argument is outside I32')
    return value


def initialization_cases(fixture):
    """Yield fixed protocol metadata for complete-state initialization/crew cases.

    Only ``patches`` contains bytes. All expected metadata consists of normal
    JSON values; the large materialized before/after bytearrays stay local.
    Residual EAX is compared only when the fixture declares it as observable.
    """
    for name, group in fixture['routines'].items():
        address = group['address']
        if address not in ROUTINE_IDS:
            raise ValueError(f'Original routine 0x{address:x} is outside the fixed native dispatch')
        kinds = group.get('argumentTypes', [])
        if kinds != ARGUMENT_TYPES.get(address, []):
            raise ValueError(f'Original routine 0x{address:x} has an unexpected ABI')
        return_type = group.get('returnType', 'void')
        if return_type not in ('void', 'I32', 'residualEAX', 'Float80', 'F64'):
            raise ValueError(f'Unsupported captured return type {return_type!r}')
        for index, case in enumerate(group['cases']):
            arguments = case.get('arguments', [])
            if len(arguments) != len(kinds):
                raise ValueError(f'{name} case {index} has a wrong argument count')
            integers = [_i32(value) for value, kind in zip(arguments, kinds) if kind == 'I32']
            doubles = [float(value) for value, kind in zip(arguments, kinds) if kind == 'F64']
            # Small existing vectors remain valid; the encoder pads to 8/4.
            integers += [0] * max(0, 4 - len(integers))
            doubles += [0.] * max(0, 2 - len(doubles))
            seed = case['seedAtCall'] if 'seedAtCall' in case else case['seed']
            if not isinstance(seed, int) or isinstance(seed, bool) or not 0 <= seed <= 0xffffffff:
                raise ValueError('Original CRT RNG seed is outside uint32')
            patches, state = prepare_case(fixture, case)
            captured = case['expected']
            expected = {key: state[key] for key in ('mutableBlockHash', 'imageChanges')}
            expected.update(rngState=captured['rngState'], sounds=captured.get('sounds', []))
            if return_type == 'I32':
                expected['returnValue'] = _i32(captured['returnValue'])
            elif return_type == 'residualEAX':
                expected['residualEAX'] = captured['residualEAX']
            elif return_type == 'Float80':
                if isinstance(captured['returnValue'], dict):
                    result = captured['returnValue']
                    expected.update(returnValue=result['value'], returnBits=result['bits'],
                                    returnExtendedBits=result['extendedBits'])
                else:
                    for key in ('returnValue', 'returnBits', 'returnExtendedBits'):
                        expected[key] = captured[key]
            elif return_type == 'F64':
                result = captured['returnValue']
                expected.update(returnValue=result['value'], returnBits=result['bits'],
                                returnExtendedBits=result['extendedBits'])
            yield {'group': name, 'routine': ROUTINE_IDS[address], 'index': index,
                   'integers': integers, 'doubles': doubles, 'seed': seed,
                   'patches': patches, 'expected': expected}


# A separate fixed command-15 namespace. CDC is supplied by the native host,
# never by a fixture address. These are original signatures without that CDC.
GDI_ROUTINE_IDS = {
    0x416420: 0, 0x417be0: 1, 0x41a450: 2, 0x41af70: 3,
    0x419d50: 4, 0x415590: 5, 0x4166e0: 6, 0x423670: 7,
    0x423640: 8, 0x424890: 9,
    0x423aa0: 10, 0x423830: 11,
    0x415de0: 12, 0x416070: 13, 0x416300: 14, 0x417d30: 15,
    0x417fb0: 16, 0x418890: 17, 0x418a10: 18, 0x417eb0: 19,
    0x418580: 20, 0x419ca0: 21, 0x419b40: 22, 0x4194b0: 23,
    0x419640: 24, 0x4198f0: 25, 0x417570: 26,
    0x412810: 27, 0x419db0: 28, 0x4156f0: 29, 0x414d00: 30,
    0x416ad0: 31, 0x41a5d0: 32, 0x418b80: 33,
    0x418120: 34, 0x416d10: 35, 0x431890: 36, 0x431440: 37, 0x421d90: 38,
    0x411000: 39, 0x422970: 40, 0x4232e0: 41, 0x422cf0: 42, 0x44f630: 43,
    0x4226c0: 44, 0x44f320: 45, 0x430f30: 46, 0x430eb0: 47, 0x430570: 48,
    0x407e40: 49, 0x4094c0: 50, 0x409050: 51, 0x408c70: 52,
    0x42cd40: 53, 0x42c550: 54, 0x42c7b0: 55,
    0x40a360: 56, 0x40b130: 57, 0x409760: 58, 0x40b990: 59,
    0x40db30: 60, 0x40c3b0: 61, 0x40e9a0: 62,
    0x4060f0: 63, 0x42fe00: 64, 0x42f930: 65, 0x42fe40: 66, 0x431b30: 67,
    0x42d120: 68, 0x42d8a0: 69, 0x42e190: 70, 0x42e550: 71,
    0x42e750: 72, 0x42e870: 73, 0x42e970: 74, 0x42eb40: 75,
    0x42ede0: 76, 0x42f0d0: 77,
    0x410090: 78, 0x4063e0: 79, 0x406c90: 80, 0x4064d0: 81,
    0x41d890: 82, 0x41c940: 83, 0x40f4a0: 84,
    0x416990: 85, 0x44d6d0: 86, 0x44d830: 87,
    0x432000: 88, 0x432920: 89, 0x4330f0: 90, 0x4337a0: 91,
    0x433ea0: 92, 0x434470: 93, 0x434c10: 94, 0x4354d0: 95,
    0x435b50: 96, 0x436300: 97, 0x436960: 98, 0x4372d0: 99,
    0x437950: 100, 0x438330: 101, 0x438c30: 102, 0x439600: 103,
    0x439f20: 104, 0x43a5d0: 105, 0x43a9b0: 106, 0x43b910: 107,
    0x43c100: 108, 0x43ccd0: 109, 0x43e070: 110, 0x43f460: 111,
    0x440d20: 112, 0x442740: 113, 0x443bf0: 114, 0x445830: 115,
    0x445ee0: 116, 0x446570: 117, 0x446a90: 118, 0x4479e0: 119,
    0x449ef0: 120, 0x44b220: 121, 0x44b9e0: 122, 0x44c120: 123,
    0x44c950: 124, 0x44d140: 125, 0x41beb0: 126,
    0x41bb40: 127, 0x404880: 128, 0x404020: 129,
}
GDI_ARGUMENT_TYPES = {
    0x416420: ['I32'], 0x417be0: [], 0x41a450: ['I32'], 0x41af70: ['I32'],
    0x419d50: ['I32'] * 3, 0x415590: ['I32'] * 10, 0x4166e0: ['I32'], 0x423670: ['I32'] * 5,
    0x423640: ['I32'] * 3, 0x424890: ['I32'] * 5,
    0x423aa0: ['I32'] * 4, 0x423830: ['I32'] * 4,
    0x415de0: ['F64', 'I32', 'I32'], 0x416070: ['F64', 'I32', 'I32'],
    0x416300: ['F64', 'I32', 'I32', 'I32'], 0x417d30: ['F64', 'I32', 'I32'],
    0x417fb0: ['F64', 'I32', 'I32'], 0x418890: ['F64', 'I32', 'I32'],
    0x418a10: ['F64', 'I32', 'I32'], 0x417eb0: ['F64'] + ['I32'] * 4,
    0x418580: ['F64', 'F64'], 0x419ca0: ['I32', 'F64', 'I32', 'I32'],
    0x419b40: ['I32', 'F64'] + ['I32'] * 3, 0x4194b0: ['F64', 'I32', 'I32'],
    0x419640: ['F64', 'I32'], 0x4198f0: ['F64'] + ['I32'] * 4, 0x417570: ['I32'] * 6,
    0x412810: ['F64', 'I32', 'I32'], 0x419db0: ['I32', 'F64'] + ['I32'] * 3,
    0x4156f0: ['I32'] * 4 + ['F64'], 0x414d00: ['F64', 'I32', 'F64'] + ['I32'] * 3,
    0x416ad0: ['F64'] + ['I32'] * 3, 0x41a5d0: ['F64'] + ['I32'] * 3,
    0x418b80: ['I32', 'I32', 'F64'] + ['I32'] * 3,
    0x418120: ['F64', 'I32', 'I32'],
    0x416d10: ['I32', 'F64', 'I32', 'I32', 'I32', 'F64', 'I32', 'I32', 'I32'],
    0x431890: ['I32', 'I32', 'F64'] + ['I32'] * 7,
    0x431440: ['I32'] * 6, 0x421d90: ['I32', 'I32', 'F64'] + ['I32'] * 8,
    0x411000: ['I32'] * 6, 0x422970: [], 0x4232e0: [], 0x422cf0: [], 0x44f630: [],
    0x4226c0: ['I32', 'I32', 'F64'] + ['I32'] * 4, 0x44f320: ['I32', 'I32', 'F64'] + ['I32'] * 4,
    0x430f30: ['I32'] * 4, 0x430eb0: ['I32'] * 4, 0x430570: ['I32'] * 3,
    0x407e40: ['I32'] * 6, 0x4094c0: ['I32'] * 3, 0x409050: ['I32'] * 3, 0x408c70: ['I32'] * 3,
    0x42cd40: ['I32'] * 4, 0x42c550: ['I32'] * 4, 0x42c7b0: ['I32'] * 6,
    0x40a360: ['I32'] * 6, 0x40b130: ['I32'] * 6, 0x409760: ['I32'] * 6,
    0x40b990: ['I32'] * 6, 0x40db30: ['I32'] * 6, 0x40c3b0: ['I32'] * 5, 0x40e9a0: ['I32'] * 5,
    0x4060f0: ['I32'], 0x42fe00: ['I32'] * 4, 0x42f930: ['I32'] * 5,
    0x42fe40: ['I32'] * 5, 0x431b30: ['I32'] * 6,
    0x42d120: ['I32'] * 9, 0x42d8a0: ['I32'] * 12, 0x42e190: ['I32'] * 3,
    0x42e550: ['I32'] * 2, 0x42e750: ['I32'] * 2, 0x42e870: ['I32'] * 2,
    0x42e970: ['I32'] * 3, 0x42eb40: ['I32'] * 3, 0x42ede0: ['I32'] * 3,
    0x42f0d0: ['I32'] * 5,
    0x410090: [], 0x4063e0: ['I32'] * 6, 0x406c90: ['I32'] * 3,
    0x4064d0: ['I32'] * 3, 0x41d890: [], 0x41c940: [], 0x40f4a0: [],
    0x416990: ['I32'], 0x44d6d0: ['I32'], 0x44d830: ['I32'] * 2,
    0x41bb40: [], 0x404880: ['I32'] * 5, 0x404020: [],
}
# The 39 fixed pages follow the separately captured original dispatcher order.
for _tutorial_address in (0x432000, 0x432920, 0x4330f0, 0x4337a0, 0x433ea0, 0x434470,
        0x434c10, 0x4354d0, 0x435b50, 0x436300, 0x436960, 0x4372d0, 0x437950,
        0x438330, 0x438c30, 0x439600, 0x439f20, 0x43a5d0, 0x43a9b0, 0x43b910,
        0x43c100, 0x43ccd0, 0x43e070, 0x43f460, 0x440d20, 0x442740, 0x443bf0,
        0x445830, 0x445ee0, 0x446570, 0x446a90, 0x4479e0, 0x449ef0, 0x44b220,
        0x44b9e0, 0x44c120, 0x44c950, 0x44d140, 0x41beb0):
    GDI_ARGUMENT_TYPES[_tutorial_address] = []


def gdi_cases(fixture):
    """Yield bounded drawing requests and full original mutable-state evidence."""
    for name, group in fixture['routines'].items():
        address = group['address']
        if address in ROUTINE_IDS and 'CDC' not in group.get('argumentTypes', []):
            for case in initialization_cases({**fixture, 'routines': {name: group}}):
                yield {'command': 14, **case}
            continue
        if address not in GDI_ROUTINE_IDS:
            raise ValueError(f'Original drawing routine 0x{address:x} is outside fixed native dispatch')
        count = len(GDI_ARGUMENT_TYPES[address])
        kinds = group.get('argumentTypes', [])[1:]
        if group.get('argumentTypes', [])[:1] != ['CDC'] or kinds != GDI_ARGUMENT_TYPES[address] or group.get('returnType') != 'void':
            raise ValueError(f'Original drawing routine 0x{address:x} has an unexpected ABI')
        for index, case in enumerate(group['cases']):
            if len(case['arguments']) != count:
                raise ValueError(f'{name} case {index} has a wrong drawing argument count')
            integers = [_i32(value) for value, kind in zip(case['arguments'], kinds) if kind == 'I32']
            doubles = [float(value) for value, kind in zip(case['arguments'], kinds) if kind == 'F64']
            integers += [0] * (12 - len(integers))
            doubles += [0.] * max(0, 2 - len(doubles))
            seed = case['seedAtCall'] if 'seedAtCall' in case else case['seed']
            if not isinstance(seed, int) or isinstance(seed, bool) or not 0 <= seed <= 0xffffffff:
                raise ValueError('Original CRT RNG seed is outside uint32')
            patches, state = prepare_case(fixture, case)
            captured = case['expected']
            expected = {key: state[key] for key in ('mutableBlockHash', 'imageChanges')}
            expected.update(rngState=captured['rngState'], sounds=captured.get('sounds', []),
                            drawingCommands=captured['drawingCommands'])
            if 'hudText' in captured: expected['hudText'] = captured['hudText']
            control_word = fixture.get('provenance', {}).get('x87_control_word', '0x037f')
            if control_word not in ('0x027f', '0x037f'):
                raise ValueError('Unsupported original drawing arithmetic context')
            cursor = case.get('cursor', {'x': 0, 'y': 0})
            if set(cursor) != {'x', 'y'} or any(not isinstance(value, int) or isinstance(value, bool) or not -16384 <= value <= 16384 for value in cursor.values()):
                raise ValueError('Owned cursor input exceeds the fixed screen bounds')
            menu_height = case.get('menuHeight', 20)
            tick_start, tick_step = case.get('tickStart', 0), case.get('tickStep', 1)
            if not isinstance(menu_height, int) or isinstance(menu_height, bool) or not 0 <= menu_height <= 128:
                raise ValueError('Owned menu height exceeds the fixed screen bounds')
            if not isinstance(tick_start, int) or isinstance(tick_start, bool) or not 0 <= tick_start <= 0xffffffff or tick_step != 1:
                raise ValueError('Owned timer must be a uint32 counter with unit increments')
            if 'elapsedPaintTicks' in captured: expected['elapsedPaintTicks'] = captured['elapsedPaintTicks']
            yield {'command': 15, 'group': name, 'routine': GDI_ROUTINE_IDS[address], 'index': index,
                   'integers': integers, 'doubles': doubles, 'seed': seed, 'patches': patches,
                   'controlWord': int(control_word, 16), 'cursor': cursor, 'menuHeight': menu_height,
                   'tickStart': tick_start, 'tickStep': tick_step,
                   'pixelReadValues': case.get('pixelReadValues', []), 'expected': expected}
