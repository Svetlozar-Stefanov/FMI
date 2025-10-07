package bg.sofia.uni.fmi.mjt.gym.member;

import bg.sofia.uni.fmi.mjt.gym.workout.Exercise;
import bg.sofia.uni.fmi.mjt.gym.workout.Workout;

import java.time.DayOfWeek;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Objects;

public class Member implements GymMember, Comparable<GymMember> {
    private Address address;
    private String name;
    private int age;
    private String personalIdNumber;
    private Gender gender;
    Map<DayOfWeek, Workout> trainingProgram;

    public Member(Address address, String name, int age, String personalIdNumber, Gender gender) {
        this.address = address;
        this.name = name;
        this.age = age;
        this.personalIdNumber = personalIdNumber;
        this.gender = gender;
        trainingProgram = new HashMap<DayOfWeek, Workout>();
        for (var day : DayOfWeek.values()) {
            trainingProgram.put(day, null);
        }
    }

    @Override
    public String getName() {
        return name;
    }

    @Override
    public int getAge() {
        return age;
    }

    @Override
    public String getPersonalIdNumber() {
        return personalIdNumber;
    }

    @Override
    public Gender getGender() {
        return gender;
    }

    @Override
    public Address getAddress() {
        return address;
    }

    @Override
    public Map<DayOfWeek, Workout> getTrainingProgram() {
        return Collections.unmodifiableMap(trainingProgram);
    }

    @Override
    public void setWorkout(DayOfWeek day, Workout workout) {
        if (day == null) {
            throw new IllegalArgumentException("Day cannot be null.");
        }
        if (workout == null) {
            throw new IllegalArgumentException("Workout cannot be null.");
        }

        trainingProgram.put(day, workout);
    }

    @Override
    public Collection<DayOfWeek> getDaysFinishingWith(String exerciseName) {
        if (exerciseName == null || exerciseName.isEmpty()) {
            throw new IllegalArgumentException("Exercise name cannot be null or empty.");
        }

        Collection<DayOfWeek> days = new ArrayList<DayOfWeek>();
        for (var trainingDay : trainingProgram.entrySet()) {
            DayOfWeek day = trainingDay.getKey();
            Workout workout = trainingDay.getValue();

            if (workout == null) {
                continue;
            }

            if (workout.exercises().getLast().name().equals(exerciseName)) {
                days.add(day);
            }
        }
        return days;
    }

    @Override
    public void addExercise(DayOfWeek day, Exercise exercise) {
        if (day == null) {
            throw new IllegalArgumentException("Day of week cannot be null.");
        }
        if (exercise == null) {
            throw new IllegalArgumentException("Exercise cannot be null.");
        }

        Workout workout = trainingProgram.get(day);
        if (workout == null) {
            throw new DayOffException("This is a rest day.");
        }

        workout.exercises().add(exercise);
    }

    @Override
    public void addExercises(DayOfWeek day, List<Exercise> exercises) {
        if (day == null) {
            throw new IllegalArgumentException("Day of week cannot be null.");
        }
        if (exercises == null || exercises.isEmpty()) {
            throw new IllegalArgumentException("Exercise cannot be null or empty.");
        }

        Workout workout = trainingProgram.get(day);
        if (workout == null) {
            throw new DayOffException("This is a rest day.");
        }

        for (var exercise : exercises) {
            workout.exercises().add(exercise);
        }
    }

    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Member member = (Member) o;
        return Objects.equals(personalIdNumber, member.personalIdNumber);
    }

    @Override
    public int hashCode() {
        return Objects.hash(personalIdNumber);
    }

    @Override
    public int compareTo(GymMember o) {
        return this.name.compareTo(o.getName());
    }
}

