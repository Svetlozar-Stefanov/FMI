package bg.sofia.uni.fmi.mjt.football;

import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.Test;

import java.time.LocalDate;
import java.util.stream.Stream;

public class PlayerTest {
    @Test
    void testPlayerCreation() {
        Player actualPlayer = Player.of("T;Test Test;6/2/1999;30;172.72;69.9;ST,RM;Test;89;89;64500000;300000;Right");
        Player expectedPlayer = new Player("T", "Test Test",
            LocalDate.of(1999, 6, 2),
            30, 172.72, 69.9, Stream.of(Position.ST, Position.RM).toList(),
            "Test", 89, 89, 64500000, 300000, Foot.RIGHT);
        Assertions.assertEquals(expectedPlayer, actualPlayer, "Static builder method does not parse line correctly.");
    }
}
