#include "MealPlan.h"
#include "MilestoneTracker.h"

#include <iostream>
#include <string>
using namespace std;

// Constructor: Initializes the MealPlan object with an empty linked list.
MealPlan::MealPlan() : head(nullptr) {}

// Destructor: Frees all dynamically allocated memory in the linked list. Time Complexity: O(n), where n is the number of nodes in the list.
MealPlan::~MealPlan() {
    Meal* current = head; 
    while (current) {     // Traverse the list until all nodes are deleted.
        Meal* temp = current;   
        current = current->next; 
        delete temp;             
    }
}

// Adds a meal to the front of the linked list. Time Complexity: O(1).
void MealPlan::addMeal(const string& name, int calories, int protein, int fats, int carbs, MilestoneTracker& milestoneTrackerMealPlan) {
    // Dynamically create a new Meal node with the provided data.
    Meal* newMeal = new Meal(name, calories, protein, fats, carbs);
    newMeal->next = head; // Link the new node to the current head.
    head = newMeal;       // Update head to point to the new node.
    cout << "Meal added: " << name << endl;

    // Update meal-related milestones (tracked externally).
    milestoneTrackerMealPlan.updateMealMilestone();
}

// Removes a meal from the linked list by name. Time Complexity: O(n), where n is the number of nodes in the list (worst case: traverse the entire list).
void MealPlan::removeMeal(const string& name) {
    Meal* current = head; // Start at the head of the list.
    Meal* prev = nullptr; // Keep track of the previous node.

    while (current) { // Traverse the list.
        if (current->name == name) { // Check if the current node matches the name.
            if (prev) {              // If not at the head, bypass the current node.
                prev->next = current->next;
            }
            else {                 // If at the head, update the head pointer.
                head = current->next;
            }
            delete current;
            cout << "Meal removed: " << name << endl;
            return;
        }
        prev = current;              // Move the previous pointer forward.
        current = current->next;     // Move to the next node.
    }

    // If no node matches the name, print a message.
    cout << "Meal not found: " << name << endl;
}

// Displays all meals in the linked list. Time Complexity: O(n), where n is the number of nodes in the list (one traversal).
void MealPlan::displayMeals() const {
    Meal* current = head; // Start at the head of the list.

    if (!current) { // If the list is empty, print a message.
        cout << "No meals in the plan." << endl;
        return;
    }

    // Traverse the list and print each meal's details.
    while (current) {
        cout << "Meal: " << current->name
            << ", Calories: " << current->calories
            << ", Protein: " << current->protein << "g, "
            << "Fats: " << current->fats << "g, "
            << "Carbs: " << current->carbs << "g" << endl;
        current = current->next; // Move to the next node.
    }
}

// Calculates and prints the total nutritional values of all meals.
void MealPlan::calculateTotalNutrition() const {
    int totalCalories = 0, totalProtein = 0, totalFats = 0, totalCarbs = 0;

    Meal* current = head; // Start at the head of the list. Time Complexity: O(n), where n is the number of nodes in the list (one traversal).
    while (current) {     // Traverse the list.
        totalCalories += current->calories; // Add calories of the current meal.
        totalProtein += current->protein;   // Add protein.
        totalFats += current->fats;         // Add fats.
        totalCarbs += current->carbs;       // Add carbs.
        current = current->next;            // Move to the next node.
    }

    // Print the aggregated nutritional values.
    cout << "Total Nutrition for the Day:" << endl;
    cout << "Calories: " << totalCalories
        << ", Protein: " << totalProtein << "g, "
        << "Fats: " << totalFats << "g, "
        << "Carbs: " << totalCarbs << "g" << endl;
}
