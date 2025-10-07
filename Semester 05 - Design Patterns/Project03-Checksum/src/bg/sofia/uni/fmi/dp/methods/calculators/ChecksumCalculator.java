package bg.sofia.uni.fmi.dp.methods.calculators;

import java.io.InputStream;

public interface ChecksumCalculator {
    public String calculate(InputStream inputStream);
}