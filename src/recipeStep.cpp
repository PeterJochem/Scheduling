/** Implements an abstraction of a step in a recipe */
#include <iostream>
#include "../include/recipeStep.hpp"

/** @brief Constructor for recipeStep */
recipeStep::recipeStep(std::string recipe_id, int stepNum, bool isCookStep, double timeToComplete) {
		
	this->recipe_id = recipe_id;
	this->stepNum = stepNum;
	this->isCookStep = isCookStep;
	this->timeToComplete = timeToComplete;

	this->hasStarted = false;
        this->hasFinished = false;
	this->startTime = -1.0;
	this->endTime = -1.0;
}

/** @brief Check if the recipeStep is done at the currentTime */
bool recipeStep::isDone(double currentTime) { 
	
	if (!hasStarted) {
		return false;
	}
	if (currentTime >= endTime) {
		return true;
	}

	return false;
}

bool recipeStep::getHasStarted() {
	return hasStarted;
}

/** @brief Update object to inicate it has started the step */
void recipeStep::startStep(double startTime) { 
	
	this->hasStarted = true;
	this->startTime = startTime;
	this->endTime = startTime + timeToComplete;	
}

/** @brief Mark recipe object as done */
bool recipeStep::markAsDone(double endTime) { 
	
	this->hasFinished = true;
	this->endTime = endTime;
}

bool recipeStep::isIngredient() {
	return !isCookStep;	
}

bool recipeStep::isCooking() {
	return isCookStep;
}

std::string recipeStep::getRecipeId() {
	return recipe_id;
}

double recipeStep::getTimeToComplete() {
	return timeToComplete;
}

double recipeStep::getStartTime() { 
	return startTime;
}

char recipeStep::type() {
        if (isIngredient()) {
                return 'i';
        }
        return 'c';
}

/** Overloads << operator to easily easily display data structure */
std::ostream & operator << (std::ostream &out, const recipeStep &step) { 
	out << "recipe_id = " << step.recipe_id << "\t\tstepNum = " << step.stepNum << "\t\tc/i = ";
	if (step.isCookStep) {
		out << "c\t\t";
	}
	else {
		out << "i\t\t";
	}
	
	out << "startTime = " << step.startTime << "\t\t";     
	out << "endTime = " << step.endTime << "\t\t";

	out << "\t\t timeToComplete = " << step.timeToComplete << std::endl;
	return out;
}
