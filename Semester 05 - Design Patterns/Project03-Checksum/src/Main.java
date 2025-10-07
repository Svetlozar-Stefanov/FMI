import bg.sofia.uni.fmi.dp.Application;
import bg.sofia.uni.fmi.dp.methods.calculators.MD5Calculator;
import bg.sofia.uni.fmi.dp.tree.AbstractFileComponent;
import bg.sofia.uni.fmi.dp.tree.builders.AbstractFileTreeBuilder;
import bg.sofia.uni.fmi.dp.tree.builders.FileTreeBuilder;
import bg.sofia.uni.fmi.dp.tree.visitors.HashStreamWriter;

import bg.sofia.uni.fmi.dp.tree.visitors.mementos.Memento;
import bg.sofia.uni.fmi.dp.tree.visitors.observers.ProgressReporter;

import java.io.IOException;
import java.io.StringWriter;
import java.io.Writer;
import java.nio.file.Path;

public class Main {
    public static void main(String[] args) throws IOException, InterruptedException {
        Application app = new Application();
        app.start();
    }
}