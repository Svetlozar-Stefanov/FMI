package bg.sofia.uni.fmi.dp.commands;

import bg.sofia.uni.fmi.dp.DirectoryManager;

public class LoadDirectoryCommand implements Command {
    private final DirectoryManager executor;
    private final String dirPath;
    private final boolean traverseSymlinks;

    public LoadDirectoryCommand(DirectoryManager executor, String dirPath, boolean traverseSymlinks) {
        this.executor = executor;
        this.dirPath = dirPath;
        this.traverseSymlinks = traverseSymlinks;
    }

    @Override
    public void execute() {
        executor.loadDirectory(dirPath, traverseSymlinks);
    }
}
