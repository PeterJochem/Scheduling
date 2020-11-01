#include <string>

class recipeStep {

	public:
		//recipeStep();	
		recipeStep(std::string, int, bool, double);
		bool isIngredient();
		bool isCooking();
		std::string getRecipeId();
		double getTimeToComplete();
	private:
		std::string recipe_id;	
		int stepNum;
		bool isCookStep;
		double timeToComplete;
		
};
