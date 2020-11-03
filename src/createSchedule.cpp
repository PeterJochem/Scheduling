#include <iostream>
#include <fstream>
#include "../include/order.hpp"

int main() {
	using namespace std;

	cout << "Starting Schedule Creation" << endl;

	
	vector<string> recipe_ids = {"chocolate_ice_cream.txt"};
        order newOrder = order(recipe_ids);
	
	string fileName = "myFile.txt";
	newOrder.createSchedule(fileName);

	cout << "Schedule Creation Done" << endl;
	return 0;
}	
