/** @brief  Implements recipe abstraction */
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <bits/stdc++.h>
#include "../include/recipe.hpp"

/** @brief Constructor for recipe
 *  @param recipeDef is the text file defining the recipe */
recipe::recipe(std::string recipeDef) {
	using namespace std;

	allSteps = vector<recipeStep>();	
	string prefix = "../allRecipes/";
	string nextLine;	

	allSteps.reserve(100);
	ifstream ifs = ifstream(prefix + recipeDef);
	
	totalSteps = 0;
	while(getline(ifs, nextLine)) {
		addRecipeStep(nextLine);	
		totalSteps++;
	}  	  				
	
	currentStep = 0;	
	//std::cout << allSteps; Helpful for testing
}

/** @brief Scores the recipe for access to limited kitchen resources
 *  @return The recipe's score */
double recipe::orderingScore() { 
	
	recipeStep* nextStep = nextUndoneStep();
	if (nextStep == nullptr) {
		// Recipe is done. Don't work on it
		return INT_MIN;
	}
	else if (nextStep && nextStep->isCooking()) {
		// The recipe's next step is cooking  
		return INT_MIN;
	}

	
	return (1.0/nextStep->getTimeToComplete());  
}

/** @brief 
 *  @return List of each starting time of the recipe
 */
std::vector<double> recipe::recoverStartTimes() { 
	using namespace std;

	vector<double> startTimes;
	startTimes.reserve(totalSteps);			
	
	for (vector<recipeStep>::iterator itr = allSteps.begin(); itr < allSteps.end(); itr++) {
		startTimes.push_back(itr->getStartTime());			
	}	

	return startTimes;	
}

/** @brief Describe me  */
bool recipe::isDone() {
	
	if (nextUndoneStep() == nullptr) {
		return true;
	}

	return false;
}

/** @brief Create a new step in this recipe
 *  @param newLine is the string to parse step from */
void recipe::addRecipeStep(std::string newLine) {
	using namespace std;	
	
	// (recipe_id,step_num,c/i,timeToComplete) - step template
	newLine.erase(0, 1); // Remove the parenthesis from line
	newLine.erase(newLine.size() - 1);
		
	string delimiter = ",";
	size_t pos = 0;
	string token;
	
	pos = newLine.find(delimiter);
    	string recipe_id = newLine.substr(0, pos);
	newLine.erase(0, pos + delimiter.length());
	
	pos = newLine.find(delimiter);
        int stepNum = stoi(newLine.substr(0, pos));
        newLine.erase(0, pos + delimiter.length());
	
	pos = newLine.find(delimiter);
        token = newLine.substr(0, pos);
	bool isCookStep = false;
	if (token == "c") {
		isCookStep = true;
	}

        newLine.erase(0, pos + delimiter.length());
	pos = newLine.find(delimiter);
        double timeToComplete = stof(newLine.substr(0, pos));
        newLine.erase(0, pos + delimiter.length());
	
	allSteps.emplace_back(recipe_id, stepNum, isCookStep, timeToComplete);
}

/** @brief Return refrence to the step at the given index 
 *  @param index - Index into the recipe's list of steps
 *  @return The pointer to the recipeStep at the given index
 *  null if the index is invalid */
recipeStep* recipe::getStep(int index) { 
	
	if (index < 0 || index >= totalSteps) {
		return nullptr;
	}
					
	return &(allSteps[index]);
}

/** @brief Get a refrence to the next unstarted step in recipe
 *  @return The pointer to the next unstarted recipeStep. 
 *  null if the index is invalid */
recipeStep* recipe::nextUndoneStep() { 	
	
	if (currentStep < 0 || currentStep >= totalSteps) {
                return nullptr;
        }

	return &(allSteps[currentStep]);
}

/** @brief Marks current step as completed and returns 
 *  a refrence to the next step
 *  @return Refrence to the next step. Returns nullptr if done */
recipeStep* recipe::nextStep() {
	
	if (currentStep < 0 || currentStep >= totalSteps) {
		return nullptr;
	}
	
	recipeStep* nextStep = &(allSteps[currentStep]);
	currentStep++;
	return nextStep;
}

std::ostream & operator << (std::ostream &out, const recipe &recipe) { 
	for (int i = 0; i < recipe.allSteps.size(); i++) {
		out << recipe.allSteps[i];
	}
	return out;	
}
