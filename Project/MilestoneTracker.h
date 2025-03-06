#ifndef MilestoneTracker_h
#define MilestoneTracker_h

#include <iostream>
#include <map>
#include <string>
using namespace std;

class MilestoneTracker {
private:
    map<string, bool> milestones; // Stores milestones and their completion status
    int workoutsCompleted;                  // Counter for completed workouts
    int mealsAdded;                         // Counter for meals added

public:
    MilestoneTracker(); // Constructor

    void updateWorkoutMilestone(); // Updates milestones based on workouts
    void updateMealMilestone();    // Updates milestones based on meals
    void viewProgress();           // Displays milestone progress
    void celebrateMilestone(const string& milestone); // Congratulate user
};

#endif
