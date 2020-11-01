/** @brief 
 */
#include <vector>
#include <string>
#include "../include/recipe.hpp"

class order { 
						
	public:
		order(std::vector<std::string> recipeIds);
		int getNumRecipes();
		void setNumRecipes(int); 

	private:
		std::vector<recipe> allRecipes;
		int numRecipes; 	
};
