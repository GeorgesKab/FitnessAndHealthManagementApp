# FitnessAndHealthManagementApp
This is a project I worked on in my data structures course.
1.	Domain Selection: Fitness and Health Management App
The domain I have chosen is a personalized fitness and health management app that helps users manage their daily diet, track their fitness objectives, and monitor their general health development. This application uses a variety of data structures to store and arrange food planning, workouts, and progress monitoring, providing users with a customized experience.

2.	Activity Selection in the Domain
 Activity 1: Daily Workout Routine Management
•	Description: Provides individuals with structured routines depending on their fitness objectives by creating a personalized daily training plan.
•	Data Structure Used: Stack
The stack will allow the user to reorder, skip, or complete exercises efficiently.
•	Actions:
1)	Skip Exercises: Send the exercise to the end of the workout.
2)	Mark as Complete: Log exercises as done to track daily progress.
3)	End Workout: End workout early and show which exercises were completed.

 Activity 2: Meal Plan and Nutrition Tracking
•	Description: Enables users to track and plan their meals each day, modifying based on dietary preferences and nutrition goals.
•	Data Structure Used: Singly linked list
Singly linked lists offer a structured method for quickly adding, removing, or changing meals in response to user input.
•	Actions:
1)	Add/Remove Meals: Modify the day’s food items.
2)	Display Meals: Show all the meals that have been added.
3)	Calculate Nutritional Values: Summarize total calories and nutrients for the day.

 Activity 3: Goal Setting and Progress Tracker
•	Description: Users organize short-term milestones toward longer-term health goals by setting and monitoring targets like weight loss, strength training, or endurance enhancements.
•	Data Structure Used: Map
A map will be used to store and retrieve user-defined objectives and milestones, enabling the app to monitor different goal categories and their corresponding accomplishments.
•	Actions:
1)	Set Milestones: Define specific health objectives.
2)	View Progress: Access next milestones.
3)	Celebrate Milestone Completion: Recognize achievements with rewards.

3.	Relationships Between Activities
•	In the Goal Setting and Progress Tracker, the Daily Workout Routine Management activity directly supports user goals. As users reach particular goals, such "Complete 30 workouts in a month," each workout they finish pushes them closer to bigger fitness goals every day.

•	Goal Setting and Progress Tracker are also related to Meal Plan and Nutrition Tracking, as the program modifies meal suggestions according to the user's accomplishments. For example, if a user wants to lose weight, the app recommends meal plans with less calories that fit that aim.

•	Daily Workout Routine Management and Meal Plan and Nutrition Tracking also work in parallel by balancing calorie intake and expenditure. Calories burned during workouts are factored into daily meal planning, allowing the app to adjust calorie recommendations based on workout intensity. This ensures that users have enough energy for their routines without exceeding their daily caloric goals.

•	The Goal Setting and Progress Tracker summarizes both workout and meal tracking results. As users complete milestones related to workouts and nutritional goals, they unlock achievements and see their overall progress, encouraging them to stay committed to their routines.

4.	Data Structures and Algorithm Selection
This software application employs three main data structures for tailored functionality:
Stack: Organizes the daily workout routines, supporting flexibility in exercise order and easy tracking of completed activities.
Singly linked list: Manages meal plans, allowing users to update their daily meals and calculate nutritional totals seamlessly.
Map: Tracks goals and milestones, associating each milestone with specific health objectives.

Algorithm Applied: A nutrition calculation algorithm iterates through the meal list to sum total daily calories and nutrients, helping users maintain a balanced diet that aligns with their fitness goals.
