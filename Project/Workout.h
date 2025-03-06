#ifndef WorkoutPlan_h
#define WorkoutPlan_h

#include "MilestoneTracker.h"

#include <string>
#include <stack>
using namespace std;

class WorkoutPlan
{
private:
	int day;
	stack<string> Workout;
	stack<string> other;
	stack<string> skipped;
	stack<string> completed;

public:
	void DailyWorkoutPlan(MilestoneTracker& milestoneTrackerWorkout);
};

#endif