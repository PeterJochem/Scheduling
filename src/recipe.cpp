/** @brief 
 */

#include <string>
#include <vector>
#include "../include/recipe.hpp"
//#include "../include/recipeStep.hpp"

/** Constructor  */
recipe::recipe(std::string recipeDef) {
	using namespace std;

	allSteps = vector<recipeStep>();	
	allSteps.reserve(100);

	// Read the recipeDef in from the file 
	string nextLine;
	// while(getLine()) {
	// }  	  				

	currentStep = 0;
	// totalSteps = 	
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



