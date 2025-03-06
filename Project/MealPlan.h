#ifndef MealPlan_h
#define MealPlan_h

#include "MilestoneTracker.h"

#include <iostream>
#include <string>
using namespace std;

struct Meal {
    string name;
    int calories;
    int protein;
    int fats;
    int carbs;
    Meal* next;

    Meal(string n, int cal, int pro, int fat, int carb)
        : name(n), calories(cal), protein(pro), fats(fat), carbs(carb), next(nullptr) {}
};

class MealPlan {
private:
    Meal* head;

public:
    MealPlan();  // Constructor
    ~MealPlan(); // Destructor

    void addMeal(const string& name, int calories, int protein, int fats, int carbs, MilestoneTracker& milestoneTrackerMealPlan);
    void removeMeal(const string& name);
    void displayMeals() const;
    void calculateTotalNutrition() const;
};

#endif
