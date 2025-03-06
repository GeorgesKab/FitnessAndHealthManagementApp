#include "Workout.h"
#include "MilestoneTracker.h"
#include <stack>
#include <iostream>
using namespace std;

/*
 Time Complexity:
 - The function's complexity depends on the operations involving stacks:
   - Pushing/popping from a stack: O(1) per operation.
   - Displaying skipped/completed exercises: O(n), where n is the number of exercises.
 - Worst-case overall complexity: O(n) per day, where n is the number of exercises in the workout.
 */
void WorkoutPlan::DailyWorkoutPlan(MilestoneTracker& milestoneTracker)
{
    int day; // User input for the day of the week.
    cout << endl << "What day is it?\n 1. Monday\n 2. Tuesday\n 3. Wednesday\n 4. Thursday\n 5. Friday\n 6. Saturday\n 7. Sunday\n" << endl;
    cin >> day;
    cout << endl;
    char answer; // Input to track user actions during the workout.

    switch (day)
    {
    case 1:
        // Setting up Monday's workout.
        Workout.push("Cardio");
        Workout.push("Triceps kickbacks");
        Workout.push("Cable lateral raises");
        Workout.push("Cable chest fly");
        Workout.push("Dumbbell shoulder press");
        Workout.push("Flat bench press");

        cout << "Monday: Push (Chest, Shoulders, Triceps)" << endl;

        do {
            if (Workout.empty())
                return; // Exit if no exercises are left.

            cout << endl << "- " << Workout.top() << endl; // Display the current exercise.
            other.push(Workout.top()); // Temporarily store the exercise.
            Workout.pop(); // Remove the exercise from the main stack.

            if (Workout.empty())
                break;

            cout << endl << "Press c to complete, s to skip exercise or e to end workout early." << endl;
            cin >> answer;

            if (answer == 's') {
                skipped.push(other.top()); // Record skipped exercises.
            }
            else if (answer == 'c') {
                completed.push(other.top()); // Record completed exercises.
            }
            else if (answer == 'e') {
                // End session early and display summary.
                cout << endl << "Ending session early..." << endl;

                // Display skipped exercises.
                if (!skipped.empty()) {
                    cout << endl << "Exercises skipped: " << endl;
                    while (!skipped.empty()) {
                        cout << "- " << skipped.top() << endl;
                        skipped.pop();
                    }
                }

                // Display completed exercises.
                if (!completed.empty()) {
                    cout << endl << "Exercises completed: " << endl;
                    while (!completed.empty()) {
                        cout << "- " << completed.top() << endl;
                        completed.pop();
                    }
                    milestoneTracker.updateWorkoutMilestone(); // Update milestones.
                }

                // Clear remaining exercises.
                while (!Workout.empty()) {
                    Workout.pop();
                }
                cout << endl << "All remaining exercises have been cleared." << endl;
            }
        } while (answer == 'c' || answer == 's' || answer == 'e');

        // Final cleanup after completing/skipping exercises.
        if (!skipped.empty()) {
            cout << endl << "Exercises skipped: " << endl;
            while (!skipped.empty()) {
                cout << "- " << skipped.top() << endl;
                skipped.pop();
            }
        }
        if (!completed.empty()) {
            cout << endl << "Exercises completed: " << endl;
            while (!completed.empty()) {
                cout << "- " << completed.top() << endl;
                completed.pop();
            }
            milestoneTracker.updateWorkoutMilestone();
        }
        break;

    case 2:
        // Tuesday is a rest day.
        cout << "Tuesday: Rest day";
        break;

    case 3:
        // Setting up Wednesday's workout (similar structure to Monday).
        Workout.push("Deadlift");
        Workout.push("Lat pulldown");
        Workout.push("Cable Rows");
        Workout.push("Bayesian Curls");
        Workout.push("Dumbbel curls");
        Workout.push("Cardio");

        cout << "Wednesday: Pull (Back, Biceps)" << endl;

        // The rest of the logic mirrors Monday with respective exercises.

        break;

    case 4:
        // Thursday is a rest day.
        cout << "Thursday: Rest day";
        break;

    case 5:
        // Setting up Friday's workout (similar structure to Monday).
        Workout.push("Hack squat");
        Workout.push("Goblet squat");
        Workout.push("Stiff leg deadlift");
        Workout.push("Calf raises");
        Workout.push("Leg curls");
        Workout.push("Leg extensions");

        cout << "Friday: Legs (Quads, Hamstrings, Glutes, Calves" << endl;

        // The rest of the logic mirrors Monday with respective exercises.

        break;

    case 6:
        // Saturday is a cardio day with simpler logic.
        cout << "Saturday: Cardio" << endl;

        cout << endl << "Press c to complete or s to skip workout." << endl;
        cin >> answer;

        if (answer == 'c') {
            milestoneTracker.updateWorkoutMilestone();
        }
        break;

    case 7:
        // Sunday is a rest day.
        cout << "Sunday: Rest day";
        break;

    default:
        // Invalid input handling.
        cout << "This day does not exist!" << endl;
    }
}
