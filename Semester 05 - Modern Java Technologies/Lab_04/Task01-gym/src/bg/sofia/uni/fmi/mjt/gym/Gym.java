package bg.sofia.uni.fmi.mjt.gym;

import bg.sofia.uni.fmi.mjt.gym.member.Address;
import bg.sofia.uni.fmi.mjt.gym.member.GymMember;
import bg.sofia.uni.fmi.mjt.gym.member.MemberNameComparator;
import bg.sofia.uni.fmi.mjt.gym.workout.Workout;

import java.time.DayOfWeek;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Set;
import java.util.SortedSet;
import java.util.TreeSet;

public class Gym implements GymAPI {
    private int capacity;
    private Address address;
    private Set<GymMember> members;

    private class DistanceToGymComparator implements Comparator<GymMember> {

        @Override
        public int compare(GymMember o1, GymMember o2) {
            double distance1 = o1.getAddress().getDistanceTo(address);
            double distance2 = o2.getAddress().getDistanceTo(address);
            return Double.compare(distance1, distance2);
        }
    }

    public Gym(int capacity, Address address) {
        this.capacity = capacity;
        this.address = address;
        members = new HashSet<GymMember>();
    }

    @Override
    public SortedSet<GymMember> getMembers() {
        SortedSet<GymMember> membersCopy = new TreeSet<GymMember>(Set.copyOf(members));
        return Collections.unmodifiableSortedSet(membersCopy);
    }

    @Override
    public SortedSet<GymMember> getMembersSortedByName() {
        SortedSet<GymMember> membersCopy = new TreeSet<GymMember>(new MemberNameComparator());
        membersCopy.addAll(members);
        return Collections.unmodifiableSortedSet(membersCopy);
    }

    @Override
    public SortedSet<GymMember> getMembersSortedByProximityToGym() {
        SortedSet<GymMember> membersCopy = new TreeSet<GymMember>(new DistanceToGymComparator());
        membersCopy.addAll(members);
        return Collections.unmodifiableSortedSet(membersCopy);
    }

    @Override
    public void addMember(GymMember member) throws GymCapacityExceededException {
        if (member == null) {
            throw new IllegalArgumentException("Member cannot be null.");
        }
        if (members.size() >= capacity) {
            throw new GymCapacityExceededException("Gym is full.");
        }

        members.add(member);
    }

    @Override
    public void addMembers(Collection<GymMember> members) throws GymCapacityExceededException {
        if (members == null || members.isEmpty()) {
            throw new IllegalArgumentException("Member cannot be null or empty.");
        }
        if (this.members.size() + members.size() > capacity) {
            throw new GymCapacityExceededException("Gym is full.");
        }

        this.members.addAll(members);
    }

    @Override
    public boolean isMember(GymMember member) {
        if (member == null) {
            throw new IllegalArgumentException("Member cannot be null.");
        }
        return members.contains(member);
    }

    @Override
    public boolean isExerciseTrainedOnDay(String exerciseName, DayOfWeek day) {
        if (exerciseName == null || exerciseName.isEmpty()) {
            throw new IllegalArgumentException("Exercise name cannot be null or empty.");
        }
        if (day == null) {
            throw new IllegalArgumentException("Day cannot be null.");
        }

        for (var member : members) {
            Workout workout = member.getTrainingProgram().get(day);
            if (workout == null) {
                continue;
            }
            for (var exercise : workout.exercises()) {
                if (exercise.name().equals(exerciseName)) {
                    return true;
                }
            }
        }
        
        return false;
    }

    @Override
    public Map<DayOfWeek, List<String>> getDailyListOfMembersForExercise(String exerciseName) {
        if (exerciseName == null || exerciseName.isEmpty()) {
            throw new IllegalArgumentException("Exercise name cannot be null or empty.");
        }
        
        Map<DayOfWeek, List<String>> dailyMemberList = new HashMap<DayOfWeek, List<String>>();

        for (var day : DayOfWeek.values()) {
            for (var member : members) {
                Workout workout = member.getTrainingProgram().get(day);
                if (workout == null) {
                    continue;
                }
                for (var exercise : workout.exercises()) {
                    if (exercise.name().equals(exerciseName)) {
                        if (!dailyMemberList.containsKey(day)) {
                            dailyMemberList.put(day, new ArrayList<String>());
                        }
                        dailyMemberList.get(day).add(member.getName());
                    }
                }
            }
        }

        return Collections.unmodifiableMap(dailyMemberList);
    }
}
