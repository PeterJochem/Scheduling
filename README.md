# How To Compile The Code
```mkdir build``` <br />
```cd build``` <br />
```cmake ..``` <br />
```make```

# How To Run the Scheduler 
Follow the steps above to compile and then from the build directory, run ```./createSchedule arg1, ..., arg5```, where arg1 to arg5 are the names of the recipes in the order. For example, you might run ```./createSchedule asparagus_soup.txt carrot_soup.txt chili_con_carne.txt chocolate_ice_cream.txt mushroom_risotto.txt```. This will create a schedule and write it to a csv file. To then create the gant chart, run ```cd ../src``` and then ```python3 plotSchedule.py```. The schedule is written to src/schedule.png. To view it, run vlc ```schedule.png```. To view all available recipes, run ```./createSchedule help```. This will show you a list of available recipes.

# Toy Dataset
I created a set of text files that describe recipes. The text files are at allRecipes/<recipe_name>.txt

# Results 
Below is an example of the gant charts created by the scheduler. <br />  
![Example Gant Chart](media/schedule.png)



# Unit Testing
I used gtest to create unit tests. test/runUnitTests has a set of tests for creating schedules. To run the tests, ```cd build``` <br />
```cmake ..``` <br />
```make``` <br />
```./runUnitTests```

# Dependencies
matplotlib, (```pip install matplotlib```) <br />
C++ 14 <br />
Python3 <br />
CMake <br />
