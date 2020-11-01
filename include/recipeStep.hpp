/** @brief Describe me   
 */
#include <string>

class recipeStep {

	public:
		//recipeStep();	
		recipeStep(std::string, int, bool, double);
		bool isIngredient();
		bool isCooking();
		std::string getRecipeId();
		double getTimeToComplete();
		friend std::ostream & operator << (std::ostream &out, const recipeStep &step);
	private:
		std::string recipe_id;	
		int stepNum;
		bool isCookStep;
		double timeToComplete;
		
};
