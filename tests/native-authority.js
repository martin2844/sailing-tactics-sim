import assert from 'node:assert/strict';
import { createReadStream } from 'node:fs';
import { createHash } from 'node:crypto';

async function readAuthorityFields(path) {
  const wanted = new Set(['source_sha256','fixture_sha256','x87_control_word','comparison_complete',
    'all_fixture_cases_match','loaded_original_text_unchanged','original_file_unchanged',
    'process_exit_code','groups','original_routine_addresses']);
  const stream = createReadStream(path,{encoding:'utf8',highWaterMark:1024*1024});
  const fields=[];let selected,partial='';
  const finish=()=>{if(selected)fields.push(selected.join('').replace(/,\s*$/,''));selected=undefined;};
  const consume=text=>{
    const boundary=/^  "([^\"]+)":|^}$/gm;let start=0,match;
    while((match=boundary.exec(text))){
      if(selected)selected.push(text.slice(start,match.index));
      finish();
      if(match[1]&&wanted.has(match[1]))selected=[];
      start=match.index;
    }
    if(selected)selected.push(text.slice(start));
  };
  try {
    for await(const chunk of stream){
      const text=partial+chunk,last=text.lastIndexOf('\n');
      if(last===-1){partial=text;continue;}
      consume(text.slice(0,last+1));partial=text.slice(last+1);
    }
    if(partial)consume(partial);finish();
  } finally {stream.destroy();}
  return JSON.parse('{'+fields.join(',\n')+'}');
}

/** A native result is evidence only for the exact captured fixture bytes. */
export async function assertNativeAuthority(fixtureName, reportName, fixture) {
  const fixtureHash = async () => {
    const hash = createHash('sha256');
    for await (const chunk of createReadStream(new URL(`./fixtures/${fixtureName}`, import.meta.url))) hash.update(chunk);
    return hash.digest('hex');
  };
  const [rawHash, report] = await Promise.all([
    fixtureHash(),
    readAuthorityFields(new URL(`../analysis/${reportName}`, import.meta.url)),
  ]);
  assert.equal(report.source_sha256, fixture.provenance.sha256);
  assert.equal(report.fixture_sha256[fixtureName], rawHash);
  const controlWord = fixture.provenance.x87_control_word ?? '0x037f';
  assert.ok(['0x027f', '0x037f'].includes(controlWord));
  assert.equal(report.x87_control_word, controlWord);
  assert.equal(report.comparison_complete, true);
  assert.equal(report.all_fixture_cases_match, true);
  assert.equal(report.loaded_original_text_unchanged, true);
  assert.equal(report.original_file_unchanged, true);
  assert.equal(report.process_exit_code, 0);
  for (const [name, routine] of Object.entries(fixture.routines)) {
    assert.equal(report.groups[name].cases, routine.cases.length, `${name}: native call count`);
    assert.equal(report.groups[name].exact_matches, routine.cases.length, `${name}: native exact matches`);
    assert.equal(report.groups[name].different_cases, 0, `${name}: no native tolerance`);
    assert.ok(report.original_routine_addresses.includes(routine.address.toString(16).padStart(8, '0')));
  }
}
