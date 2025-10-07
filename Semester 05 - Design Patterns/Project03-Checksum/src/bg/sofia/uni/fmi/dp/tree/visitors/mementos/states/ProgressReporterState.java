package bg.sofia.uni.fmi.dp.tree.visitors.mementos.states;

public record ProgressReporterState(
        String processedFile,
        String processedFileSize,

        long totalBytes,
        long  totalReadBytes
) implements State {
}
