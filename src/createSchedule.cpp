/** @brief This reads in a command line list of recipes, checks if they are legal, and then creates the schedule */
#include <iostream>
#include <fstream>
#include <algorithm>
#include "../include/order.hpp"
using namespace std;

tuple<vector<string>, bool> parseInputs(int numUserRecipes, char* userRecipes[]) { 
	
	vector<string> legal_recipes = {"asparagus_soup", "carrot_soup", "chili_con_carne", "chocolate_ice_cream", "mushroom_risotto", 
					"sabayon", "strawberry_ice_cream"};
	vector<string> legalUserRecipes;

	if (userRecipes[0] == string("help")) {
		cout << "The available recipes are below \n";	
		for (auto itr = legal_recipes.begin(); itr < legal_recipes.end(); itr++) {
			cout << *itr << "\n";
		}

		cout << endl;
		return {vector<string>(), false};
	}	

	bool allRecipesLegal = true; 	
	for (int i = 0; i < numUserRecipes; i++) {
		
		if (find(legal_recipes.begin(), legal_recipes.end(), userRecipes[i]) == legal_recipes.end()) { 
			cout << "You entered a recipe (" << userRecipes[i] << ") not in our menu. ";
		        cout << "To view all available recipes. Run ./createSchedule help" << endl;	
			allRecipesLegal = false;
		}
		else {
			legalUserRecipes.push_back(userRecipes[i]);
		}
	}	

	return {legalUserRecipes, allRecipesLegal};	
}


int main(int argc, char* argv[]) {

	if (argc > 6) {
		cout << "You entered too many recipes for the system. Please enter 1-5 recipes" << endl;
		return -1;
	}
	if (argc == 1) {
		cout << "You entered too few recipes for the system. Please enter 1-5 recipes" << endl;
                return -1;
	}

	auto[recipe_ids, allRecipesLegal] = parseInputs(argc - 1, argv + 1);
	if (!allRecipesLegal) {
		return -1;
	}	

	cout << "Starting Schedule Creation" << endl;
	order newOrder = order(recipe_ids);
	
	string fileName = "schedule.csv";
	newOrder.createSchedule(fileName);

	cout << "Schedule Creation Done" << endl;
	return 0;
}	
