#include "../include/recipeStep.hpp"

/** Constructor  
 */
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
