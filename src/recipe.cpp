/** @brief 
 */
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "../include/recipe.hpp"

/** Constructor  */
recipe::recipe(std::string recipeDef) {
	using namespace std;

	allSteps = vector<recipeStep>();	
	string prefix = "../allRecipes/";
	string nextLine;	

	allSteps.reserve(100);
	ifstream ifs = ifstream(prefix + recipeDef);
	
	while(getline(ifs, nextLine)) {
		addRecipeStep(nextLine);	
		totalSteps++;
	}  	  				
	
	currentStep = 0;
			
	//std::cout << allSteps;
}

/** Describe me */
void recipe::addRecipeStep(std::string newLine) {
	using namespace std;	
	
	// (chocolate_ice_cream,1,i,3.5)
	newLine.erase(0,1); // Remove the parenthesis from line
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

/** Describe me */
recipeStep* recipe::getStep(int index) { 
	
	if (index < 0 || index >= totalSteps) {
		// Throw an error
		return nullptr;
	}
					
	return &(allSteps[index]);
}

/** Describe me */
recipeStep* recipe::nextStep() {
	
	if (currentStep < 0 || currentStep >= totalSteps) {
		// Throw an error
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
