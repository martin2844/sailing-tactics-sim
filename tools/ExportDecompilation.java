// Export all recovered functions without editing the input program.
// @category Tact.Preservation
import ghidra.app.script.GhidraScript;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.program.model.listing.*;
import ghidra.program.model.address.*;
import ghidra.program.model.mem.MemoryBlock;
import ghidra.program.model.symbol.*;
import java.nio.file.*;
import java.nio.charset.StandardCharsets;
import java.io.*;
import java.util.*;

public class ExportDecompilation extends GhidraScript {
    private static String q(String value) {
        if (value == null) return "null";
        return "\"" + value.replace("\\", "\\\\").replace("\"", "\\\"")
            .replace("\n", "\\n").replace("\r", "\\r").replace("\t", "\\t") + "\"";
    }
    @Override public void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length != 1) throw new IllegalArgumentException("Output directory required");
        Path out = Paths.get(args[0]);
        Files.createDirectories(out.resolve("functions"));
        DecompInterface decompiler = new DecompInterface();
        decompiler.toggleCCode(true);
        decompiler.toggleSyntaxTree(true);
        if (!decompiler.openProgram(currentProgram)) throw new IOException(decompiler.getLastMessage());
        int total = 0, complete = 0, failed = 0, external = 0;
        try (BufferedWriter combined = Files.newBufferedWriter(out.resolve("recovered.c"), StandardCharsets.UTF_8);
             BufferedWriter index = Files.newBufferedWriter(out.resolve("functions.jsonl"), StandardCharsets.UTF_8);
             BufferedWriter globals = Files.newBufferedWriter(out.resolve("defined-data.jsonl"), StandardCharsets.UTF_8)) {
            combined.write("/* Mechanically decompiled from Tact02Demo.exe. Inferred types/names; not original source. */\n\n");
            FunctionIterator iterator = currentProgram.getFunctionManager().getFunctions(true);
            while (iterator.hasNext() && !monitor.isCancelled()) {
                Function f = iterator.next();
                if (f.isExternal()) { external++; continue; }
                total++;
                String address = f.getEntryPoint().toString();
                monitor.setMessage("Decompiling " + address + " " + f.getName());
                DecompileResults result = decompiler.decompileFunction(f, 60, monitor);
                boolean success = result.decompileCompleted() && result.getDecompiledFunction() != null;
                String error = success ? "" : result.getErrorMessage();
                String c = success ? result.getDecompiledFunction().getC() : "/* " + address + " decompilation failed: " + error + " */\n";
                if (success) complete++; else failed++;
                Files.writeString(out.resolve("functions").resolve(address + ".c"), c, StandardCharsets.UTF_8);
                combined.write("/* Address: " + address + "; symbol: " + f.getName() + " */\n" + c + "\n\n");
                StringJoiner calls = new StringJoiner(",", "[", "]");
                for (Function called : f.getCalledFunctions(monitor))
                    calls.add("{\"address\":" + q(called.getEntryPoint().toString()) + ",\"name\":" + q(called.getName()) + "}");
                index.write("{\"address\":" + q(address) + ",\"name\":" + q(f.getName())
                    + ",\"signature\":" + q(f.getSignature().toString()) + ",\"body_bytes\":" + f.getBody().getNumAddresses()
                    + ",\"decompiled\":" + success + ",\"error\":" + q(error) + ",\"calls\":" + calls + "}\n");
                if (total % 100 == 0) { combined.flush(); index.flush(); println("EXPORT_PROGRESS functions=" + total + " complete=" + complete + " failed=" + failed); }
            }
            DataIterator data = currentProgram.getListing().getDefinedData(true);
            while (data.hasNext()) {
                Data d = data.next();
                globals.write("{\"address\":" + q(d.getAddress().toString()) + ",\"type\":" + q(d.getDataType().getName())
                    + ",\"size\":" + d.getLength() + ",\"label\":" + q(d.getLabel())
                    + ",\"value\":" + q(String.valueOf(d.getValue())) + "}\n");
            }
        } finally { decompiler.dispose(); }
        String summary = "{\"program\":" + q(currentProgram.getName()) + ",\"image_base\":" + q(currentProgram.getImageBase().toString())
            + ",\"language\":" + q(currentProgram.getLanguageID().toString()) + ",\"functions\":" + total
            + ",\"decompiled\":" + complete + ",\"failed\":" + failed + ",\"external_functions\":" + external
            + ",\"cancelled\":" + monitor.isCancelled() + "}\n";
        Files.writeString(out.resolve("summary.json"), summary, StandardCharsets.UTF_8);
        println("EXPORT_COMPLETE " + summary);
    }
}
