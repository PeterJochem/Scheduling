/** @brief   
 */
#include <string>
#include <vector>
#include <iostream>
#include "../include/order.hpp" 

/** Constructor */
order::order(std::vector<std::string> recipeIds) {
	using namespace std;

	allRecipes = vector<recipe>();
	// Traverse the vector of recipeIds and create the recipe for each 
	for (auto itr = recipeIds.begin(); itr < recipeIds.end(); itr++) { 
			
		allRecipes.push_back(recipe(*itr));
		cout << *itr << endl;
	}		
	
	numRecipes = allRecipes.size();
}
