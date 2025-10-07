package bg.sofia.uni.fmi.dp.methods;

import java.nio.file.Path;

public interface AbstractFileChecksumCalculator {
    public String calculate(Path file);
}
