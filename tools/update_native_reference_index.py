"""Index independent native datasets without counting their subset reports twice."""
import json
from pathlib import Path

ROOT=Path(__file__).resolve().parents[1]
REPORTS=(
    'native-reference-comparison','native-state-reference-comparison',
    'screens-p53-native-reference-comparison','connected-frames-p53-native-reference-comparison',
    'scene-vegetation-native-reference-comparison','scene-vegetation-pc53-native-reference-comparison',
    'native-frame-chains-p53-reference-comparison')


def main():
    rows=[];addresses=set();isolated=0;frames=0;initializations=0
    for name in REPORTS:
        path=ROOT/'analysis'/(name+'.json');report=json.loads(path.read_text())
        for flag in ('comparison_complete','all_fixture_cases_match','loaded_original_text_unchanged','original_file_unchanged'):
            if report.get(flag) is not True:raise ValueError(f'{path.name}: incomplete {flag}')
        functions=set(report['original_routine_addresses']);functions.discard('00403c62')
        addresses.update(functions)
        count=report.get('function_cases')
        if count is None:
            frames+=report['retained_native_frames'];initializations+=report['native_initializations']
            count=report['retained_native_frames']+report['native_initializations']
        else:isolated+=count
        rows.append({'report':str(path.relative_to(ROOT)),
                     'control_word':report.get('x87_control_word','0x037f'),
                     'cases':count,'routines':len(functions)})
    index={'reports':rows,'independent_original_calls':isolated+frames+initializations,
           'isolated_original_calls':isolated,'retained_native_frames':frames,
           'original_initialized_lifetimes':initializations,
           'unique_original_routine_addresses':len(addresses),'addresses':sorted(addresses),
           'reviewed_original_fragments':[{'start':'00403c62','end':'00403cb9',
               'scope':'Viewport calibration; exact original instructions, owned hardware stop before CreateBitmap. Not a separate recovered function.'}],
           'scope':'Independent isolated datasets plus three actual original-initialized retained100-frame chains under live startupCW027f. Repeated subset reports are excluded. The three initialization cases are lifetimes of a reviewed connected prefix; function/address counts exclude its calibration fragment. Full Windows lifecycle and raster identity remain separately scoped.'}
    (ROOT/'analysis/native-reference-index.json').write_text(json.dumps(index,indent=2)+'\n')
    print(index['independent_original_calls'],index['unique_original_routine_addresses'])


if __name__=='__main__':main()
