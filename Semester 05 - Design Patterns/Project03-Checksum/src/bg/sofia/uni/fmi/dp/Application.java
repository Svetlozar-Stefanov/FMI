package bg.sofia.uni.fmi.dp;

import bg.sofia.uni.fmi.dp.commands.*;
import bg.sofia.uni.fmi.dp.methods.calculators.ChecksumCalculator;
import bg.sofia.uni.fmi.dp.methods.calculators.MD5Calculator;

import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.Writer;
import java.util.Arrays;
import java.util.Scanner;

public class Application {
    public void start() {
        Scanner scanner = new Scanner(System.in);
        DirectoryManager executor = new DirectoryManager();
        boolean exit = false;

        while (!exit) {
            System.out.println("Please enter command: ");
            String input = scanner.nextLine();
            var args = Arrays.stream(input.split("\s+")).iterator();

            while(args.hasNext()) {
                String command = args.next();

                try {
                    switch (command) {
                        case "load" -> {
                            String dirPath = args.next();
                            boolean traverseSymlinks = false;
                            if (args.hasNext()) {
                                traverseSymlinks = Boolean.parseBoolean(args.next());
                            }

                            new LoadDirectoryCommand(executor, dirPath, traverseSymlinks).execute();
                            System.out.println("Successfully loaded directory.");
                        }
                        case "report" -> {
                            String outDir = args.next();
                            if (outDir.equals("console")) {
                                Writer writer = new PrintWriter(System.out);
                                new ReportCommand(executor, writer).execute();
                                writer.flush();
                            } else {
                                try (Writer writer = new FileWriter(outDir)) {
                                    new ReportCommand(executor, writer).execute();
                                    System.out.println("Successfully reported to file.");
                                } catch (IOException e) {
                                    throw new RuntimeException("Could not write to console", e);
                                }
                            }
                        }
                        case "hash" -> {
                            String outDir = args.next();
                            String hashType = args.next();

                            ChecksumCalculator calculator;
                            switch (hashType) {
                                case "MD5" -> calculator = new MD5Calculator();
                                default -> throw new IllegalArgumentException("No such hash exists.");
                            }
                            Writer writer = null;
                            if (outDir.equals("console")) {
                                writer = new PrintWriter(System.out);
                                new HashCommand(executor, writer, calculator).execute();
                                writer.flush();
                            } else {
                                writer = new FileWriter(outDir);
                                new HashCommand(executor, writer, calculator).execute();
                                System.out.println("Hash was written to file successfully.");
                                writer.close();
                            }
                        }
                        case "exit" -> {
                            exit = true;
                        }
                        default -> {
                            System.out.println("Invalid command.");
                        }
                    }
                    if (exit) {
                        break;
                    }
                } catch (Exception e) {
                    System.out.println(e.getMessage());
                }
            }
        }
    }
}
