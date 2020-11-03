/** @brief 
 */
#include <vector>
#include <string>
#include <queue>
#include <tuple>
#include "../include/recipe.hpp"

// Custom comparator for the priority_queue of recipe pointers
// See http://neutrofoton.github.io/blog/2016/12/29/c-plus-plus-priority-queue-with-comparator/
struct recipeCompare {
    bool operator()(recipe* lhs, recipe* rhs) {
        return (lhs->orderingScore()) > (rhs->orderingScore());
    }
};

class order { 
						
	public:
		order(std::vector<std::string> recipeIds);
		int getNumRecipes();
		void setNumRecipes(int); 
		recipe* getRecipe(int);
		void createSchedule(std::string&);		
	private:
		std::priority_queue<recipe*, std::vector<recipe*>, recipeCompare> nextAction;
		//std::priority_queue<recipe*> nextAction; // Sort the actions we can take 
		std::vector<recipe> allRecipes; // Static list of the recipes
		std::vector<std::tuple<std::string, char, double, double>> schedule;
		int numRecipes;
		bool isOrderDone();
		bool isDispenserInUse(double);
                void updateDispenserPriorities();
		void checkForFinishedSteps(double);
		void scheduleDispenser(double);
		void scheduleCooking(double);
		void writeToCSV(std::string&);
};
