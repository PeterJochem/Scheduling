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
		double getStartTime();
		bool isDone(double);
		bool getHasStarted(void);
		void startStep(double);
		bool markAsDone(double);
		char type();
		friend std::ostream & operator << (std::ostream &out, const recipeStep &step);
	private:
		std::string recipe_id;	
		int stepNum;
		bool isCookStep;
		double timeToComplete;
		bool hasStarted;
		bool hasFinished;
		double startTime; // Time that the process started
		double endTime; // Time that the process is scheduled to end
};
