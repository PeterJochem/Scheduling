/** @brief Add Doxygen style comments 
 */
#include <string>
#include <vector>
#include "../include/recipeStep.hpp"

class recipe {
	
	public:
		recipe(std::string recipeDef);
		recipeStep* getStep(int);
		recipeStep* nextStep(); // Finishes current step. Advances pointer
		recipeStep* nextUndoneStep(); // Only returns pointer to the next step  
		double orderingScore();
		bool isDone();
		std::string getRecipeID();
		std::vector<double> recoverStartTimes();
		friend std::ostream & operator << (std::ostream &out, const recipe &recipe);
		friend std::ostream & operator << (std::ostream &out, const std::vector<recipe> &allRecipes);
	private:
		void addRecipeStep(std::string);
		std::vector<recipeStep> allSteps;
		int currentStep;
		int totalSteps;
		
		std::string recipe_id;		
		bool workInProgress; // Is useful work being done on this recipe at this time
		double timeWhenReady; // Denotes when step in process will be completed 
};
