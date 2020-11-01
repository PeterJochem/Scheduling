/** @brief Add Doxygen style comments 
 */
#include <string>
#include <vector>
#include "../include/recipeStep.hpp"


class recipe {
	
	public:
		recipe(std::string recipeDef);
		recipeStep* getStep(int);
		recipeStep* nextStep();

	private:
		std::vector<recipeStep> allSteps;
		int currentStep;
		int totalSteps;

};
