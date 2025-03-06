#include "MilestoneTracker.h"

#include <map>
#include <iostream>
#include <string>
using namespace std;

// Declare a pair to hold milestone information
pair<string, bool> milestone;

// Constructor. Time Complexity: O(1).
// Initializes the tracker with zero workouts and meals and sets default milestone statuses to false.
MilestoneTracker::MilestoneTracker() : workoutsCompleted(0), mealsAdded(0) {
    milestones["First Workout Completed"] = false;
    milestones["Seven Workouts Completed"] = false;
    milestones["Meals Added for a Day"] = false;
}

// Update milestones based on completed workouts. Time Complexity: O(1)
void MilestoneTracker::updateWorkoutMilestone() {
    workoutsCompleted++; // Increments the workout count
    if (workoutsCompleted == 1 && !milestones["First Workout Completed"]) { // Check if milestone 1 is achieved
        milestones["First Workout Completed"] = true; // If achieved, mark the milestone as true and call the celebrateMilestone function.
        celebrateMilestone("First Workout Completed");
    }
    if (workoutsCompleted == 7 && !milestones["Seven Workouts Completed"]) { // Check if milestone 7 is achieved
        milestones["Seven Workouts Completed"] = true; // If achieved, mark the milestone as true and call the celebrateMilestone function.
        celebrateMilestone("Seven Workouts Completed");
    }
}

// Update milestones based on meals added. Time Complexity: O(1)
void MilestoneTracker::updateMealMilestone() {
    mealsAdded++; // Increment the meal count.
    if (mealsAdded >= 3 && !milestones["Meals Added for a Day"]) { //Check if the milestone for adding meals for a day is achieved.
        milestones["Meals Added for a Day"] = true; // If achieved, mark the milestone as true and call the celebrateMilestone function.
        celebrateMilestone("Meals Added for a Day");
    }
}

// Display progress of all milestones. Time Complexity: O(n), where n is the number of milestones
void MilestoneTracker::viewProgress() {
    cout << endl << "Milestone Progress:" << endl;
    for (pair<string, bool> milestone : milestones) { // Go through the milestones map and prints the status of each milestone.
        cout << "- " << milestone.first << ": "
            << (milestone.second ? "Achieved" : "Not Achieved") << endl;
    }
}

// Congratulate user for achieving a milestone. Time Complexity: O(1)
void MilestoneTracker::celebrateMilestone(const string& milestone) {
    cout << endl << "Congratulations! You've achieved: " << milestone << endl; // Display a congratulatory message for the specified milestone.
}
