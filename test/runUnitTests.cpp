#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include <string>
#include "../include/order.hpp"

// Read in a recipe and make sure fields of the object are correct
TEST(Scheduler, read_In_One_Recipe) {	
	using namespace std;
			
	vector<string> recipe_ids = {"chocolate_ice_cream"};
	order newOrder = order(recipe_ids);
	
	// Check that data matches that in the .txt files
	ASSERT_TRUE((newOrder.getRecipe(0))->getStep(0)->getTimeToComplete() == 3.5);
	ASSERT_TRUE((newOrder.getRecipe(0))->getStep(1)->isCooking() == true);
	ASSERT_TRUE((newOrder.getRecipe(0))->getStep(1)->isIngredient() == false); 	
	ASSERT_TRUE((newOrder.getRecipe(0))->getStep(5)->getTimeToComplete() == 100);
}

// Read in multiple recipes and make sure fields of the object are correct
TEST(Scheduler, read_In_Multiple_Recipes) {
        using namespace std;

        vector<string> recipe_ids = {"chocolate_ice_cream", "mushroom_risotto"};
        order newOrder = order(recipe_ids);
	
        // Check that data matches that in the .txt files
        ASSERT_TRUE((newOrder.getRecipe(0))->getStep(0)->getTimeToComplete() == 3.5);
        ASSERT_TRUE((newOrder.getRecipe(0))->getStep(1)->isCooking() == true);
        ASSERT_TRUE((newOrder.getRecipe(0))->getStep(1)->isIngredient() == false);
        ASSERT_TRUE((newOrder.getRecipe(0))->getStep(5)->getTimeToComplete() == 100);
	
	// Test the mushroom risotto recipe
	ASSERT_TRUE((newOrder.getRecipe(1))->getStep(0)->getTimeToComplete() == 3.5);
        ASSERT_TRUE((newOrder.getRecipe(1))->getStep(1)->isCooking() == false);
        ASSERT_TRUE((newOrder.getRecipe(1))->getStep(1)->isIngredient() == true);
        ASSERT_TRUE((newOrder.getRecipe(1))->getStep(5)->getTimeToComplete() == 25);
}

// Test that the schedule for a single recipe works  
TEST(Scheduler, test_single_recipe_scheduling) {
        using namespace std;

	vector<string> recipe_ids = {"chocolate_ice_cream"};
        order newOrder = order(recipe_ids);

	string fileName = "unitTestSchedule1";
	newOrder.createSchedule(fileName);	
	
	vector<double> schedule = newOrder.getRecipe(0)->recoverStartTimes();	

	vector<double> known_start_times = {0.0, 3.5, 43.5, 45.0, 68.0, 69.0};
	
	for (int i = 0; i < schedule.size(); i++) { 
		ASSERT_TRUE(schedule[i] == known_start_times[i]);
	}	
}

// Test that the scheduling for multiple recipes does not create seg faults etc. 
TEST(Scheduler, test_multiple_recipes_scheduling) {
        using namespace std;

        vector<string> recipe_ids = {"chocolate_ice_cream", "asparagus_soup", "carrot_soup", "mushroom_risotto", "sabayon"};
        order newOrder = order(recipe_ids);

	string fileName = "unitTestSchedule2";
        newOrder.createSchedule(fileName);
}




int main(int argc, char **argv){

        testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
}

