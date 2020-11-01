/** @brief   
 */
#include <string>
#include <vector>
#include <iostream>
#include "../include/order.hpp" 

/** Constructor */
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

	//std::cout << allRecipes;
}

/** Describe me */
recipe* order::getRecipe(int index) { 
	
	if (index < 0 || index >= numRecipes) {
		return nullptr;
	}
			
	return &(allRecipes[index]);	

}

std::ostream & operator << (std::ostream &out, const std::vector<recipe> &allRecipes) {
        
	for (int i = 0; i < allRecipes.size(); i++) {
		for (int j = 0; j < allRecipes[i].allSteps.size(); j++) {
                	out << allRecipes[i].allSteps[i];
        	}
	}
        return out;
}
