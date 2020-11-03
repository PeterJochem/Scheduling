/** @brief Implements the order abstraction */
#include <string>
#include <vector>
#include <iostream>
#include <fstream> 
#include <bits/stdc++.h>
#include "../include/order.hpp" 

/** @brief Constructor for recipe order
 *  @param recipeIds is a list of names of txt files describing recipes */
order::order(std::vector<std::string> recipeIds) {
	using namespace std;

	if (recipeIds.size() > 5) {
		cout << "Recipe list is too long. Trimming it to the first 5 recipes" << endl;
	}	

	allRecipes = vector<recipe>();
	numRecipes = 0;
	for (auto itr = recipeIds.begin(); itr < recipeIds.end(); itr++) { 
			
		allRecipes.push_back(recipe(*itr));
		numRecipes++;
		if (numRecipes >= 5) {
			return;
		}
	}			

	// Construct priority_queue of pointers to the above vector
	// this->nextAction = priority_queue<recipe*>();
	for (auto itr = allRecipes.begin(); itr < allRecipes.end(); itr++) {
		this->nextAction.push(&(*itr));
	}
}

/** @brief Create the schedule and write it to a csv for plotting 
 *  Schedule is written as csv to schedules/scheduleName */
void order::createSchedule(std::string& scheduleName) { 
	using namespace std; 

	double currentTime = 0.0;
	double time_increment = 0.5;
	bool isDispenserBusy;

	while (!isOrderDone()) {
		
		checkForFinishedSteps(currentTime);			
		isDispenserBusy = isDispenserInUse(currentTime);		

		if (!isDispenserBusy) {
			// Schedule recipe at top of the queue whose is a) free and b) needs dispenser for next instruction
			scheduleDispenser(currentTime);	
		}

		scheduleCooking(currentTime);			
		currentTime = currentTime + time_increment;
	}

	writeScheduleToCSV(scheduleName);
}

/** @brief Write the order's scheduled list of steps to a csv file for plotting */
void order::writeScheduleToCSV(std::string& scheduleName) { 
	using namespace std;

	string relativePath = "../schedules/"; 
	ofstream ofs(relativePath + scheduleName);
	
	for (auto itr = scheduleForCSV.begin(); itr < scheduleForCSV.end(); itr++) {
		
		auto[recipe_id, recipe_type, startTime, duration] = *itr;
		ofs << recipe_id << "," << recipe_type << "," << startTime << "," << duration << "\n";
	}			
}

/** @brief Choose which recipe has priority on the dispenser and start that step */
void order::scheduleDispenser(double currentTime) { 	
	using namespace std;
		
	recipe* maxPriority = nullptr;
	double maxPriorityScore = INT_MIN + 1;
	for (int index = 0; index < allRecipes.size(); index++) {
       		
		recipe* nextRecipe = &(allRecipes[index]);	
		recipeStep* nextStep = nextRecipe->nextUndoneStep();

                if (nextStep && !nextStep->getHasStarted() && !nextStep->isDone(currentTime)) {
			
			if (nextRecipe->orderingScore() > maxPriorityScore) {
				maxPriority = &(allRecipes[index]);
				maxPriorityScore = nextRecipe->orderingScore();
			}		
		}
	}
	
	if (maxPriority) { 
		// start process
		recipeStep* nextStep = maxPriority->nextUndoneStep();	
		this->schedule.push_back(make_tuple(maxPriority->getRecipeID(), nextStep->type(), currentTime));
		this->scheduleForCSV.push_back(make_tuple(maxPriority->getRecipeID(), nextStep->type(), currentTime, nextStep->getTimeToComplete()));	
		nextStep->startStep(currentTime);
	}
}

/** @brief Schedule each idle process to start its next cooking operation */
void order::scheduleCooking(double currentTime) {
	using namespace std;

	for (vector<recipe>::iterator itr = allRecipes.begin(); itr < allRecipes.end(); itr++) {

       		recipeStep* nextStep = itr->nextUndoneStep();
                if (nextStep && !nextStep->getHasStarted() && nextStep->isCooking()) {
                	// start process
			this->schedule.push_back(make_tuple(itr->getRecipeID(), nextStep->type(), currentTime));
            		this->scheduleForCSV.push_back(make_tuple(itr->getRecipeID(), nextStep->type(), currentTime, nextStep->getTimeToComplete()));
			nextStep->startStep(currentTime);
           	}
       }
}


/** @brief Check if any of the running recipe steps is completed */
void order::checkForFinishedSteps(double currentTime) {
	using namespace std;

	for (vector<recipe>::iterator itr = allRecipes.begin(); itr < allRecipes.end(); itr++) {
       		
		recipeStep* nextStep = itr->nextUndoneStep();
        	if (nextStep && nextStep->isDone(currentTime)) {
                	nextStep->markAsDone(currentTime);
                	itr->nextStep(); // move recipe object to the next step, but don't begin it yet
        	}	
	}
}

bool order::isDispenserInUse(double currentTime) { 
	using namespace std; 
	
	bool inUse = false;	
	for (vector<recipe>::iterator itr = allRecipes.begin(); itr < allRecipes.end(); itr++) {
        	
		recipeStep* nextStep = itr->nextUndoneStep();
                if (nextStep && nextStep->getHasStarted() && !nextStep->isDone(currentTime) && nextStep->isIngredient()) {
                	inUse = true;
		}
	}

	return inUse;
}

/** @brief Check if the order is completed 
 *  @return True if all recipes of order are done. Else false */
bool order::isOrderDone() { 
	using namespace std; 

	for (vector<recipe>::iterator itr = allRecipes.begin(); itr < allRecipes.end(); itr++) {
		if (!(itr->isDone())) {
			return false;
		}		
	}

	return true;
}


/** @brief Compute and return refrence to the recipe at the given index
 *  @param index The index into the list of recipes 
 *  @return Refrence to recipe at index. nullptr if index is invalid */
recipe* order::getRecipe(int index) { 
	
	if (index < 0 || index >= numRecipes) {
		return nullptr;
	}
		
	auto itr_outer = allRecipes.begin();
	for (int i = 0; i < index; i++) {
		itr_outer++;
	}

	return &(*itr_outer);	
}

std::ostream & operator << (std::ostream &out, const std::vector<recipe> &allRecipes) {
        
	for (auto itr_outer = allRecipes.begin(); itr_outer < allRecipes.end(); itr_outer++) {
		for (int j = 0; j < itr_outer->allSteps.size(); j++) {
                	out << itr_outer->allSteps[j];
        	}
	}

        return out;
}
