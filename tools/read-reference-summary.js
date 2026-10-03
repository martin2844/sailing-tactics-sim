import { createReadStream } from 'node:fs';
import { createHash } from 'node:crypto';
import { StringDecoder } from 'node:string_decoder';

/** Read bounded metadata from pretty JSON without allocating raw capture bodies. */
export async function readReferenceSummary(path) {
  const wanted=new Set(['source_sha256','fixture_sha256','x87_control_word','comparison_complete',
    'all_fixture_cases_match','loaded_original_text_unchanged','original_file_unchanged',
    'process_exit_code','groups','original_routine_addresses','function_cases','exact_function_cases','scope']);
  const fields=[],hash=createHash('sha256'),decoder=new StringDecoder('utf8');
  let selected,partial='';
  const finish=()=>{if(selected)fields.push(selected.join('').replace(/,\s*$/,''));selected=undefined;};
  const consume=text=>{
    const boundary=/^  "([^\"]+)":|^}$/gm;let start=0,match;
    while((match=boundary.exec(text))){
      if(selected)selected.push(text.slice(start,match.index));finish();
      if(match[1]&&wanted.has(match[1]))selected=[];start=match.index;
    }
    if(selected)selected.push(text.slice(start));
  };
  const stream=createReadStream(path,{highWaterMark:1024*1024});
  try{
    for await(const chunk of stream){
      hash.update(chunk);const text=partial+decoder.write(chunk),last=text.lastIndexOf('\n');
      if(last===-1){partial=text;continue;}consume(text.slice(0,last+1));partial=text.slice(last+1);
    }
    partial+=decoder.end();if(partial)consume(partial);finish();
  }finally{stream.destroy();}
  return {report:JSON.parse('{'+fields.join(',\n')+'}'),sha256:hash.digest('hex')};
}
