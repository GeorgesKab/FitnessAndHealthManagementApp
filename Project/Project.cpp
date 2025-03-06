#include "Workout.h"
#include "MealPlan.h"
#include "MilestoneTracker.h"

#include <string>
#include <iostream>
using namespace std;

int main()
{
    // Variables for user input
    string name; // Name of a meal
    int calories, protein, fats, carbs; // Nutritional details of a meal

    WorkoutPlan fitness; // Object for managing workout plans
    MealPlan mealPlan; // Object for managing meal plans
    MilestoneTracker milestoneTracker; // Object for tracking progress

    int choice; // User's menu choice

    // Main application loop
    do {
        // Display the main menu
        cout << endl << "Main Menu:" << endl;
        cout << "1. Do Workout" << endl;
        cout << "2. Manage Meals" << endl;
        cout << "3. View Milestone Progress" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        // Handle user's choice
        switch (choice)
        {
        case 1:
            // Perform a daily workout using the milestone tracker
            fitness.DailyWorkoutPlan(milestoneTracker);
            break;

        case 2:
            // Submenu for meal plan management
            do {
                cout << endl << "Meal Plan Menu:" << endl;
                cout << "1. Add Meal" << endl;
                cout << "2. Remove Meal" << endl;
                cout << "3. Display Meals" << endl;
                cout << "4. Calculate Total Nutrition" << endl;
                cout << "5. Exit" << endl;
                cout << "Enter your choice: " << endl;
                cin >> choice;

                switch (choice)
                {
                case 1:
                    // Add a new meal with nutritional details
                    cout << "Enter meal name: ";
                    cin.ignore(); // Clear input buffer
                    getline(cin, name); // Read full meal name
                    cout << "Enter calories: ";
                    cin >> calories;
                    cout << "Enter protein (g): ";
                    cin >> protein;
                    cout << "Enter fats (g): ";
                    cin >> fats;
                    cout << "Enter carbs (g): ";
                    cin >> carbs;
                    mealPlan.addMeal(name, calories, protein, fats, carbs, milestoneTracker);
                    break;

                case 2:
                    // Remove a meal by name
                    cout << "Enter the name of the meal to remove: ";
                    cin.ignore(); // Clear input buffer
                    getline(cin, name); // Read full meal name
                    mealPlan.removeMeal(name);
                    break;

                case 3:
                    // Display all meals in the meal plan
                    mealPlan.displayMeals();
                    break;

                case 4:
                    // Calculate and display total nutritional values
                    mealPlan.calculateTotalNutrition();
                    break;

                case 5:
                    // Exit the meal plan submenu
                    cout << "Exiting Meal Plan Manager." << endl;
                    break;

                default:
                    // Handle invalid menu options
                    cout << "Invalid choice. Please try again." << endl;
                    break;
                }
            } while (choice != 5); // Loop until the user chooses to exit the meal plan submenu
            break;

        case 3:
            // View progress on milestones
            milestoneTracker.viewProgress();
            break;

        case 4:
            // Exit the program
            cout << "Exiting the program. Goodbye!" << endl;
            break;

        default:
            // Handle invalid menu options
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4); // Loop until the user chooses to exit the main program

    return 0; // Exit the program successfully
}
