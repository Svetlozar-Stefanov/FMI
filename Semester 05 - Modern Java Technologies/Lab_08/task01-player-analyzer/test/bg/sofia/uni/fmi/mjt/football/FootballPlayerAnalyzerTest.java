package bg.sofia.uni.fmi.mjt.football;

import org.junit.jupiter.api.AfterAll;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.Test;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.Reader;
import java.io.Writer;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.NoSuchElementException;
import java.util.Optional;
import java.util.Set;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class FootballPlayerAnalyzerTest {
    private final static Path testFilesPath = Path.of("test/bg/sofia/uni/fmi/mjt/football/testFiles");
    private final static Path testPlayersFile = Path.of("test/bg/sofia/uni/fmi/mjt/football/testFiles/players.csv");

    private static void deleteFiles() throws IOException {
        for (var file : Files.list(testFilesPath).toList()) {
            Files.deleteIfExists(file);
        }
        Files.deleteIfExists(java.nio.file.Path.of("test/bg/sofia/uni/fmi/mjt/football/testfiles"));
    }

    @BeforeAll
    static void setUpTestFile() throws IOException {
        Files.createDirectory(testFilesPath);
        Writer writer = new FileWriter(testPlayersFile.toString());
        writer.write("name;full_name;birth_date;age;height_cm;weight_kgs;positions;nationality;overall_rating;potential;value_euro;wage_euro;preferred_foot\n");
        writer.write("L. Messi;Lionel Andrés Messi Cuccittini;6/24/1987;31;170.18;72.1;CF,RW,ST;Argentina;94;94;110500000;565000;Left\n");
        writer.write("C. Eriksen;Christian  Dannemann Eriksen;2/14/1992;27;154.94;76.2;CAM,RM,CM;Denmark;88;89;69500000;205000;Right\n");
        writer.write("P. Pogba;Paul Pogba;3/15/1993;25;190.5;83.9;CM,CAM;France;88;91;73000000;255000;Right\n");
        writer.write("G. Higuaín;Gonzalo Gerardo Higuaín;12/10/1987;31;185.42;88.9;ST;Argentina;87;87;48500000;205000;Right\n");
        writer.close();
    }

    @AfterAll
    static void clenUp() throws IOException {
       deleteFiles();
    }

    @Test
    void testSuccessfulConstructionAndGetter() throws IOException {
        List<Player> expected = Stream.of(
            Player.of("L. Messi;Lionel Andrés Messi Cuccittini;6/24/1987;31;170.18;72.1;CF,RW,ST;Argentina;94;94;110500000;565000;Left"),
            Player.of("C. Eriksen;Christian  Dannemann Eriksen;2/14/1992;27;154.94;76.2;CAM,RM,CM;Denmark;88;89;69500000;205000;Right"),
            Player.of("P. Pogba;Paul Pogba;3/15/1993;25;190.5;83.9;CM,CAM;France;88;91;73000000;255000;Right"),
            Player.of("G. Higuaín;Gonzalo Gerardo Higuaín;12/10/1987;31;185.42;88.9;ST;Argentina;87;87;48500000;205000;Right")
        ).toList();

        try (Reader reader = new FileReader(testPlayersFile.toString())) {
            var analyzer = new FootballPlayerAnalyzer(reader);

            Assertions.assertEquals(expected, analyzer.getAllPlayers(),
                "Construction from file does not parse correctly.");
        }
    }

    @Test
    void testSuccessfulGetAllNationalities() throws IOException {
        Set<String> expected = Stream.of("France", "Denmark", "Argentina").collect(Collectors.toSet());

        try (Reader reader = new FileReader(testPlayersFile.toString())) {
            var analyzer = new FootballPlayerAnalyzer(reader);

            Assertions.assertEquals(expected, analyzer.getAllNationalities(),
                "Nationalities not filtered properly.");
        }
    }

    @Test
    void testNullToGetHighestPaidPlayerByNationality() throws IOException {
        try (Reader reader = new FileReader(testPlayersFile.toString())) {
            var analyzer = new FootballPlayerAnalyzer(reader);

            Assertions.assertThrows(IllegalArgumentException.class, () -> analyzer.getHighestPaidPlayerByNationality(null),
                "Allows for null to be passed.");
        }
    }

    @Test
    void testNonexistentNationalityToGetHighestPaidPlayerByNationality() throws IOException {
        try (Reader reader = new FileReader(testPlayersFile.toString())) {
            var analyzer = new FootballPlayerAnalyzer(reader);

            Assertions.assertThrows(NoSuchElementException.class, () -> analyzer.getHighestPaidPlayerByNationality("Columbia"),
                "Does not throw when no such player exists.");
        }
    }

    @Test
    void testSuccessfulToGetHighestPaidPlayerByNationality() throws IOException {
        try (Reader reader = new FileReader(testPlayersFile.toString())) {
            var analyzer = new FootballPlayerAnalyzer(reader);

            Player expected = Player.of("L. Messi;Lionel Andrés Messi Cuccittini;6/24/1987;31;170.18;72.1;CF,RW,ST;Argentina;94;94;110500000;565000;Left\n");

            Assertions.assertEquals(expected, analyzer.getHighestPaidPlayerByNationality("Argentina"),
                "Does not properly filter out highest paid player from nationality.");
        }
    }

    @Test
    void testSuccessfulGroupByPosition() throws IOException {
        Player p1 = Player.of("L. Messi;Lionel Andrés Messi Cuccittini;6/24/1987;31;170.18;72.1;CF,RW,ST;Argentina;94;94;110500000;565000;Left");
        Player p2 = Player.of("C. Eriksen;Christian  Dannemann Eriksen;2/14/1992;27;154.94;76.2;CAM,RM,CM;Denmark;88;89;69500000;205000;Right");
        Player p3 = Player.of("P. Pogba;Paul Pogba;3/15/1993;25;190.5;83.9;CM,CAM;France;88;91;73000000;255000;Right");
        Player p4 = Player.of("G. Higuaín;Gonzalo Gerardo Higuaín;12/10/1987;31;185.42;88.9;ST;Argentina;87;87;48500000;205000;Right");
        Map<Position, Set<Player>> expected = new HashMap<>();
        expected.put(Position.CF, Stream.of(p1).collect(Collectors.toSet()));
        expected.put(Position.RW, Stream.of(p1).collect(Collectors.toSet()));
        expected.put(Position.ST, Stream.of(p1, p4).collect(Collectors.toSet()));
        expected.put(Position.CAM, Stream.of(p2, p3).collect(Collectors.toSet()));
        expected.put(Position.RM, Stream.of(p2).collect(Collectors.toSet()));
        expected.put(Position.CM, Stream.of(p2,p3).collect(Collectors.toSet()));

        try (Reader reader = new FileReader(testPlayersFile.toString())) {
            var analyzer = new FootballPlayerAnalyzer(reader);

            Assertions.assertEquals(expected, analyzer.groupByPosition(),
                "Does not properly group players.");
        }
    }

    @Test
    void testNullPositionGetTopProspectPlayerForPositionInBudget() throws IOException {
        try (Reader reader = new FileReader(testPlayersFile.toString())) {
            var analyzer = new FootballPlayerAnalyzer(reader);

            Assertions.assertThrows(IllegalArgumentException.class, () -> analyzer.getTopProspectPlayerForPositionInBudget(null, 100),
                "Allows for null to be passed.");
        }
    }

    @Test
    void testNegativeBudgetGetTopProspectPlayerForPositionInBudget() throws IOException {
        try (Reader reader = new FileReader(testPlayersFile.toString())) {
            var analyzer = new FootballPlayerAnalyzer(reader);

            Assertions.assertThrows(IllegalArgumentException.class, () -> analyzer.getTopProspectPlayerForPositionInBudget(Position.CB, -1),
                "Allows for negative budget to be passed.");
        }
    }

    @Test
    void testSuccessfulGetTopProspectPlayerForPositionInBudget() throws IOException {
        try (Reader reader = new FileReader(testPlayersFile.toString())) {
            var analyzer = new FootballPlayerAnalyzer(reader);

            Optional<Player> expected = Optional.of(
                Player.of("L. Messi;Lionel Andrés Messi Cuccittini;6/24/1987;31;170.18;72.1;CF,RW,ST;Argentina;94;94;110500000;565000;Left"));

            Assertions.assertEquals(expected, analyzer.getTopProspectPlayerForPositionInBudget(Position.ST, 695000000),
                "Does not properly filter out highest paid player from nationality.");
        }
    }

    @Test
    void testNullGetSimilarPlayers() throws IOException {
        try (Reader reader = new FileReader(testPlayersFile.toString())) {
            var analyzer = new FootballPlayerAnalyzer(reader);

            Assertions.assertThrows(IllegalArgumentException.class, () -> analyzer.getSimilarPlayers(null),
                "Allows for a null player to be passed.");
        }
    }

    @Test
    void testSuccessfulGetSimilarPlayers() throws IOException {
        try (Reader reader = new FileReader(testPlayersFile.toString())) {
            var analyzer = new FootballPlayerAnalyzer(reader);

            Player p = Player.of("C. Eriksen;Christian  Dannemann Eriksen;2/14/1992;27;154.94;76.2;CAM,RM,CM;Denmark;88;89;69500000;205000;Right\n");

            Set<Player> expected = Stream.of(
                Player.of("C. Eriksen;Christian  Dannemann Eriksen;2/14/1992;27;154.94;76.2;CAM,RM,CM;Denmark;88;89;69500000;205000;Right\n"),
                Player.of("P. Pogba;Paul Pogba;3/15/1993;25;190.5;83.9;CM,CAM;France;88;91;73000000;255000;Right\n")
            ).collect(Collectors.toSet());

            Assertions.assertEquals(expected, analyzer.getSimilarPlayers(p),
                "Does not find all similar players correctly");
        }
    }

    @Test
    void testNullKeywordGetPlayersByFullNameKeyword() throws IOException {
        try (Reader reader = new FileReader(testPlayersFile.toString())) {
            var analyzer = new FootballPlayerAnalyzer(reader);

            Assertions.assertThrows(IllegalArgumentException.class, () -> analyzer.getPlayersByFullNameKeyword(null),
                "Allows for a null keyword to be passed.");
        }
    }

    @Test
    void testSuccessfulGetPlayersByFullNameKeyword() throws IOException {
        try (Reader reader = new FileReader(testPlayersFile.toString())) {
            var analyzer = new FootballPlayerAnalyzer(reader);

            Set<Player> expected = Stream.of(
                Player.of("C. Eriksen;Christian  Dannemann Eriksen;2/14/1992;27;154.94;76.2;CAM,RM,CM;Denmark;88;89;69500000;205000;Right\n")
            ).collect(Collectors.toSet());

            Assertions.assertEquals(expected, analyzer.getPlayersByFullNameKeyword("Chris"),
                "Does not find names with keyword properly.");
        }
    }
}
