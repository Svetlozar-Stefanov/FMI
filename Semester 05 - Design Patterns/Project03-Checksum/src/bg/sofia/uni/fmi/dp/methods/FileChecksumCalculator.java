package bg.sofia.uni.fmi.dp.methods;

import bg.sofia.uni.fmi.dp.methods.calculators.ChecksumCalculator;

import java.io.*;
import java.nio.file.Files;
import java.nio.file.Path;

public class FileChecksumCalculator implements AbstractFileChecksumCalculator {
    private final ChecksumCalculator calculator;

    public FileChecksumCalculator(ChecksumCalculator calculator) {
        this.calculator = calculator;
    }

    protected InputStream openFile(Path file) {
        if (file == null) {
            throw new IllegalArgumentException("File cannot be null.");
        }
        if (!Files.isRegularFile(file)) {
            throw new IllegalArgumentException("Provided path does not lead to a valid file.");
        }

        try {
            return new FileInputStream(file.toString());
        } catch (IOException e) {
            throw new RuntimeException("Could not open file properly.", e);
        }
    }

    @Override
    public String calculate(Path file) {
        String checksum;
        try (InputStream inputStream = openFile(file)) {
            checksum = calculator.calculate(inputStream);
        } catch (IOException e) {
            throw new RuntimeException("Could not open file properly.", e);
        }

        return checksum;
    }
}
