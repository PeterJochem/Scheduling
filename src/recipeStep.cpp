#include <iostream>
#include "../include/recipeStep.hpp"

/** Constructor */
recipeStep::recipeStep(std::string recipe_id, int stepNum, bool isCookStep, double timeToComplete) {
		
	this->recipe_id = recipe_id;
	this->stepNum = stepNum;
	this->isCookStep = isCookStep;
	this->timeToComplete = timeToComplete;
		
}

/** Describe me */
bool recipeStep::isIngredient() {
	return !isCookStep;	
}

/** Describe me */
bool recipeStep::isCooking() {
	return isCookStep;
}

/** Describe me */
std::string recipeStep::getRecipeId() {
	return recipe_id;
}

/** Describe me */
double recipeStep::getTimeToComplete() {
	return timeToComplete;
}

/** Describe me */
std::ostream & operator << (std::ostream &out, const recipeStep &step) { 
	out << "recipe_id = " << step.recipe_id << "\t\tstepNum = " << step.stepNum << "\t\tc/i = ";
	if (step.isCookStep) {
		out << "c";
	}
	else {
		out << "i";
	}
	
	out << "\t\t timeToComplete = " << step.timeToComplete << std::endl;
	return out;
}
