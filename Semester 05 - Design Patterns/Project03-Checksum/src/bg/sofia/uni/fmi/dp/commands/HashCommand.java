package bg.sofia.uni.fmi.dp.commands;

import bg.sofia.uni.fmi.dp.DirectoryManager;
import bg.sofia.uni.fmi.dp.methods.calculators.ChecksumCalculator;

import java.io.Writer;
import java.util.Scanner;

public class HashCommand implements Command {
    private final DirectoryManager executor;
    private final Writer writer;
    private final ChecksumCalculator calculator;

    public HashCommand(DirectoryManager executor, Writer writer, ChecksumCalculator calculator) {
        this.executor = executor;
        this.writer = writer;
        this.calculator = calculator;
    }

    @Override
    public void execute() {
        Thread thread = new Thread( () -> {
            executor.hash(writer, calculator);
        });
        thread.start();

        Scanner scanner = new Scanner(System.in);
        boolean abort = false;
        boolean paused = false;

        while (!abort && thread.isAlive()) {
            String command = scanner.next();

            switch (command) {
                case "p" -> {
                    if (!paused) {
                        executor.pause();
                        paused = true;
                    }
                }
                case "r" -> {
                    if (paused) {
                        executor.resumeRequest();
                        try {
                            thread.join();
                        } catch (InterruptedException e) {
                            throw new RuntimeException("Paused thread was interrupted.", e);
                        }
                        thread = new Thread(
                                executor::resumeTraversal
                        );
                        thread.start();
                        paused = false;
                    }
                }
                case "q" -> {
                    executor.pause();
                    try {
                        thread.join();
                    } catch (InterruptedException e) {
                        throw new RuntimeException("Resumed thread was interrupted.", e);
                    }
                    abort = true;
                }
                case "c" -> {
                    if (thread.isAlive()) {
                        System.out.println("Process not ready.");
                        continue;
                    }
                    abort = true;
                }
                default -> System.out.println("Invalid command.");
            }
        }
    }
}
