import matplotlib.pyplot as plt 
import re
import sys

schedule = open("../allSchedules/schedule.csv", "r")

allSteps = []
allRecipe_ids = []
finalEndTime = -1.0
for line in schedule:

    #recipe_id, step_type, startTime, duration = line.split(",")
    recipe_id, step_type, startTime, duration, __ = re.split(',|\n', line)

    allSteps.append([recipe_id, step_type, startTime, duration])
    
    if recipe_id not in allRecipe_ids:
        allRecipe_ids.append(recipe_id)
    if (float(startTime) + float(duration) > finalEndTime):
        finalEndTime = float(startTime) + float(duration)
    

# sort based on the recipe_id
allSteps.sort(key = lambda x: x[0])

fig, gnt = plt.subplots()

gnt.set_ylim(0, 65)
gnt.set_xlim(0, finalEndTime)
gnt.set_xlabel('time(s)')
gnt.set_ylabel('Recipe_id')

yTicks = [15, 25, 35, 45, 55]
gnt.set_yticks(yTicks)
gnt.set_yticklabels(allRecipe_ids)
gnt.grid(True)


for i in range(len(allRecipe_ids)):
    for item in allSteps:
    
        recipe_id, step_type, startTime, duration = item
        if (recipe_id == allRecipe_ids[i]):
            # add gant chart item 
            gnt.broken_barh([(float(startTime), float(duration))], (yTicks[i], 5), facecolors =('tab:orange'))  


plt.savefig("schedule.png") 
