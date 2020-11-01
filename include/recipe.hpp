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
		friend std::ostream & operator << (std::ostream &out, const recipe &recipe);
		friend std::ostream & operator << (std::ostream &out, const std::vector<recipe> &allRecipes);
	private:
		void addRecipeStep(std::string);
		std::vector<recipeStep> allSteps;
		int currentStep;
		int totalSteps;
};
