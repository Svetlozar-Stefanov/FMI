package bg.sofia.uni.fmi.mjt.football;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.Reader;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.NoSuchElementException;
import java.util.Optional;
import java.util.Set;
import java.util.stream.Collectors;

public class FootballPlayerAnalyzer {
    private Collection<Player> players;

    /**
     * Loads the dataset from the given {@code reader}. The reader argument will not be null and a correct dataset of
     * the specified type can be read from it.
     *
     * @param reader Reader from which the dataset can be read.
     */
    public FootballPlayerAnalyzer(Reader reader) {
        players = new ArrayList<>();
        BufferedReader bufferedReader = new BufferedReader(reader);
        try {
            bufferedReader.readLine();
        } catch (IOException e) {
            throw new RuntimeException(e);
        }
        String line;
        while (true) {
            try {
                if (((line = bufferedReader.readLine()) == null)) break;
            } catch (IOException e) {
                throw new RuntimeException(e);
            }
            players.add(Player.of(line));
        }
    }

    /**
     * Returns all players from the dataset in undefined order as an unmodifiable List. If the dataset is empty, returns
     * an empty List.
     *
     * @return the list of all players.
     */
    public List<Player> getAllPlayers() {
        return players.stream().toList();
    }

    /**
     * Returns an unmodifiable set of all nationalities in the dataset. If the dataset is empty, returns an empty Set.
     *
     * @return the set of all nationalities
     */
    public Set<String> getAllNationalities() {
        return players.stream().map(Player::nationality).collect(Collectors.toUnmodifiableSet());
    }

    /**
     * Returns the highest paid player from the provided nationality. If there are two or more players with equal
     * maximum wage, returns any of them.
     *
     * @param nationality the nationality of the player to return
     * @return the highest paid player
     * @throws IllegalArgumentException in case the provided nationality is null
     * @throws NoSuchElementException   in case there is no player with the provided nationality
     */
    public Player getHighestPaidPlayerByNationality(String nationality) {
        if (nationality == null || nationality.isBlank()) {
            throw new IllegalArgumentException("Nationality cannot be null or blank.");
        }

        var highestPaid = players.stream()
            .filter(p -> p.nationality().equals(nationality))
            .max(Comparator.comparingLong(Player::wageEuro));

        if (highestPaid.isPresent()) {
            return highestPaid.get();
        }
        throw new NoSuchElementException("There are no players from this nation.");
    }

    /**
     * Returns a breakdown of players by position. Note that some players can play in more than one position so they
     * should be present in more than one value Set. If no player plays in a given Position then that position should
     * not be present as a key in the map.
     *
     * @return a Map with key: a Position and value: the set of players in the dataset that can play in that Position,
     * in undefined order.
     */
    public Map<Position, Set<Player>> groupByPosition() {
        Map<Position, Set<Player>> playersAtPosition = new HashMap<>();
        for (var position : Position.values()) {
            Set<Player> atPosition = players.stream()
                .filter(p -> p.positions().contains(position)).collect(Collectors.toSet());
            if (!atPosition.isEmpty()) {
                playersAtPosition.put(position, atPosition);
            }
        }
        return playersAtPosition;
    }

    /**
     * Returns an Optional containing the top prospect player in the dataset that can play in the provided position and
     * that can be bought with the provided budget considering the player's value_euro. If no player can be bought with
     * the provided budget then return an empty Optional.
     * <p>
     * The player's prospect is calculated by the following formula: Prospect = (r + p) ÷ a where r is the player's
     * overall rating, p is the player's potential and a is the player's age
     *
     * @param position the position in which the player should be able to play
     * @param budget   the available budget for buying a player
     * @return an Optional containing the top prospect player
     * @throws IllegalArgumentException in case the provided position is null or the provided budget is negative
     */
    public Optional<Player> getTopProspectPlayerForPositionInBudget(Position position, long budget) {
        if (position == null) {
            throw new IllegalArgumentException("Provided position cannot be null.");
        }
        if (budget < 0) {
            throw new IllegalArgumentException("Provided budget cannot be negative.");
        }

        return players.stream()
            .filter(p -> p.positions().contains(position) && p.valueEuro() <= budget)
            .max(Comparator.comparingDouble(p -> ((double) (p.overallRating() * p.potential()) / p.age())));
    }

    /**
     * Returns an unmodifiable set of players that are similar to the provided player. Two players are considered
     * similar if: 1. there is at least one position in which both of them can play 2. both players prefer the same foot
     * 3. their overall_rating measures differ by at most 3 (inclusive)
     * If the dataset contains the provided player, the player will be present in the returned result.
     *
     * @param player the player for whom similar players are retrieved. It may or may not be part of the dataset.
     * @return an unmodifiable set of similar players
     * @throws IllegalArgumentException if the provided player is null
     */
    public Set<Player> getSimilarPlayers(Player player) {
        if (player == null) {
            throw new IllegalArgumentException("Provided player cannot be null.");
        }

        final int ratingDiff = 3;

        return players.stream()
            .filter(p -> !Collections.disjoint(p.positions(), player.positions()))
            .filter(p -> p.preferredFoot().equals(player.preferredFoot()))
            .filter(p -> Math.abs(p.overallRating() - player.overallRating()) <= ratingDiff)
            .collect(Collectors.toUnmodifiableSet());
    }

    /**
     * Returns an unmodifiable set of players whose full name contains the provided keyword (case-sensitive search)
     *
     * @param keyword the keyword that should be contained in player's full name
     * @return an unmodifiable set of players
     * @throws IllegalArgumentException if the provided keyword is null
     */
    public Set<Player> getPlayersByFullNameKeyword(String keyword) {
        if (keyword == null || keyword.isBlank()) {
            throw new IllegalArgumentException("Keyword cannot be null.");
        }

        return players.stream().filter(p -> p.fullName().contains(keyword)).collect(Collectors.toUnmodifiableSet());
    }
}