#include <gtest/gtest.h>
#include <iostream>
#include <vector>
#include <string>
#include "../include/order.hpp"

// Read in a recipe and make sure fields of the object are correct
TEST(Scheduler, read_In_One_Recipe) {	
	using namespace std;
			
	vector<string> recipe_ids = {"chocolate_ice_cream.txt"};
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

        vector<string> recipe_ids = {"chocolate_ice_cream.txt", "mushroom_risotto.txt"};
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

// Read in multiple recipes and make sure fields of the object are correct
TEST(Scheduler, aaaaaaaaaaaa) {
        using namespace std;

        vector<string> recipe_ids = {"chocolate_ice_cream.txt", "mushroom_risotto.txt"};
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



int main(int argc, char **argv){

        testing::InitGoogleTest(&argc, argv);
        return RUN_ALL_TESTS();
}

