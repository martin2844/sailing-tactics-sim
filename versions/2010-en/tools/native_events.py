"""Decode the shared observational GDI binary contract; preserve request order."""
import struct

def decode_gdi_events(data):
    events, cursor = [], 0
    while cursor < len(data):
        if cursor + 8 > len(data):
            raise ValueError('Truncated native drawing event')
        op, size = struct.unpack_from('<II', data, cursor)
        cursor += 8
        if size > len(data) - cursor:
            raise ValueError('Truncated native drawing payload')
        value = data[cursor:cursor + size]
        cursor += size
        if op in (1, 2, 9, 10, 11):
            if size != 4:
                raise ValueError('Wrong scalar drawing event size')
            names = {1: ('selectStockObject', 'index', '<i'), 2: ('selectObject', 'handle', '<I'),
                9: ('setTextColor', 'color', '<I'), 10: ('setBkColor', 'color', '<I'), 11: ('setBkMode', 'mode', '<i')}
            name, field, fmt = names[op]
            events.append({'op': name, field: struct.unpack(fmt, value)[0]})
        elif op in (3, 4):
            if size != 8:
                raise ValueError('Wrong point drawing event size')
            x, y = struct.unpack('<2i', value)
            events.append({'op': 'moveTo' if op == 3 else 'lineTo', 'x': x, 'y': y})
        elif op == 5:
            if size < 4 or size != 4 + 8 * struct.unpack_from('<I', value)[0]:
                raise ValueError('Wrong polygon drawing event size')
            events.append({'op': 'polygon', 'points': [dict(zip(('x', 'y'), point)) for point in struct.iter_unpack('<2i', value[4:])]})
        elif op in (6, 7):
            if size != 16:
                raise ValueError('Wrong shape drawing event size')
            events.append({'op': 'ellipse' if op == 6 else 'rectangle', **dict(zip(('left', 'top', 'right', 'bottom'), struct.unpack('<4i', value)))})
        elif op == 8:
            if size != 12:
                raise ValueError('Wrong pixel drawing event size')
            x, y, color = struct.unpack('<iiI', value)
            events.append({'op': 'setPixel', 'x': x, 'y': y, 'color': color})
        elif op == 12:
            if size < 12 or struct.unpack_from('<I', value, 8)[0] != size - 12:
                raise ValueError('Wrong text drawing event size')
            x, y = struct.unpack('<2i', value[:8])
            events.append({'op': 'textOut', 'x': x, 'y': y, 'text': value[12:].decode('cp1252')})
        elif op in (13, 14):
            if size != 32:
                raise ValueError('Wrong arc drawing event size')
            events.append({'op': 'arc' if op == 13 else 'pie', **dict(zip(('left', 'top', 'right', 'bottom', 'startX', 'startY', 'endX', 'endY'), struct.unpack('<8i', value)))})
        elif op == 15:
            if size != 16:
                raise ValueError('Wrong clip rectangle event size')
            events.append({'op': 'pushClipRect', **dict(zip(('left', 'top', 'right', 'bottom'), struct.unpack('<4i', value)))})
        elif op == 16:
            if size:
                raise ValueError('Wrong clip restore event size')
            events.append({'op': 'popClipRect'})
        elif op == 17:
            if size != 24:
                raise ValueError('Wrong rounded rectangle event size')
            events.append({'op': 'roundRect', **dict(zip(('left', 'top', 'right', 'bottom', 'ellipseWidth', 'ellipseHeight'), struct.unpack('<6i', value)))})
        elif op == 18:
            if size != 4:
                raise ValueError('Wrong message beep event size')
            events.append({'op': 'messageBeep', 'type': struct.unpack('<I', value)[0]})
        elif op == 19:
            if size != 12:
                raise ValueError('Wrong synthetic pixel-read event size')
            x,y,color=struct.unpack('<iiI',value)
            events.append({'op': 'getPixel', 'x': x, 'y': y, 'color': color})
        else:
            raise ValueError('Unknown original drawing event')
    return events
