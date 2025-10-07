package bg.sofia.uni.fmi.mjt.football;

import java.time.LocalDate;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Iterator;
import java.util.List;

public record Player(String name, String fullName,
                     LocalDate birthDate, int age,
                     double heightCm, double weightKg,
                     List<Position> positions,
                     String nationality,
                     int overallRating, int potential,
                     long valueEuro, long wageEuro,
                     Foot preferredFoot) {
    public static Player of(String line) {
        Iterator<String> comp = Arrays.stream(line.split(";")).iterator();
        String name = comp.next();
        String fullName = comp.next();
        var date = comp.next().split("/");
        LocalDate birthDate = LocalDate.of(
            Integer.parseInt(date[2]),
            Integer.parseInt(date[0]),
            Integer.parseInt(date[1])
            );
        int age = Integer.parseInt(comp.next());
        double weight = Double.parseDouble(comp.next());
        double height = Double.parseDouble(comp.next());
        List<Position> positions = new ArrayList<>();
        for (var pos : comp.next().split(",")) {
            positions.add(Position.valueOf(pos));
        }
        String nationality = comp.next();
        int overallRating = Integer.parseInt(comp.next());
        int potential = Integer.parseInt(comp.next());
        long valueEuro = Long.parseLong(comp.next());
        long wageEuro = Long.parseLong(comp.next());
        Foot prefferedFoot = Foot.valueOf(comp.next().trim().toUpperCase());
        return new Player(name, fullName, birthDate, age, weight, height, positions,
            nationality, overallRating, potential, valueEuro, wageEuro, prefferedFoot);
    }
}
