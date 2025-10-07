package bg.sofia.uni.fmi.dp.commands;

import bg.sofia.uni.fmi.dp.DirectoryManager;

import java.io.Writer;

public class ReportCommand implements Command {
    private final DirectoryManager executor;
    private final Writer writer;

    public ReportCommand(DirectoryManager executor, Writer writer) {
        this.executor = executor;
        this.writer = writer;
    }

    @Override
    public void execute() {
        executor.report(writer);
    }
}
