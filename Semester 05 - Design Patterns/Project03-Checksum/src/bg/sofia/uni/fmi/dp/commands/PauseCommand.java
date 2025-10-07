package bg.sofia.uni.fmi.dp.commands;

import bg.sofia.uni.fmi.dp.DirectoryManager;

public class PauseCommand implements Command {
    private final DirectoryManager executor;

    public PauseCommand(DirectoryManager executor) {
        this.executor = executor;
    }

    @Override
    public void execute() {
        executor.pause();
    }
}
