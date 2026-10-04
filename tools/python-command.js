import {existsSync} from 'node:fs';
import {fileURLToPath} from 'node:url';

const local=fileURLToPath(new URL('./python-runtime/bin/python3',import.meta.url));
// The local interpreter is ignored by Git; fresh clones may use a system or
// virtual-environment Python containing the documented generator dependencies.
export const pythonCommand=process.env.TACT_PYTHON||(existsSync(local)?local:'python3');
