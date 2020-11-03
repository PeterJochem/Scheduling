# @brief This reads in a csv file of operations and creates a gant chart to visualize them 
import re
import sys
import matplotlib.pyplot as plt 
import matplotlib.patches as mpatches

schedule = open("../schedules/schedule.csv", "r")

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

plt.title('Cooking Schedule')
gnt.set_ylim(0, 65)
gnt.set_xlim(0, finalEndTime)
gnt.set_xlabel('time(s)')
gnt.set_ylabel('Recipe_id')

yTicks = [10, 20, 30, 40, 50]
gnt.set_yticks(yTicks)
gnt.set_yticklabels([1, 2, 3, 4, 5])
gnt.grid(True)

cookingColor = ('tab:orange')
dispensingColor = ('tab:blue')
orange_patch = mpatches.Patch(color='orange', label='Cooking')
blue_patch = mpatches.Patch(color='blue', label='Dispensing')
plt.legend(handles=[orange_patch, blue_patch])

for i in range(len(allRecipe_ids)):
    for item in allSteps:
    
        recipe_id, step_type, startTime, duration = item
        if (recipe_id == allRecipe_ids[i]):
            # add gant chart item 
            if (step_type == 'c'):
                gnt.broken_barh([(float(startTime), float(duration))], (yTicks[i], 5), facecolors=cookingColor)  
            else:
                gnt.broken_barh([(float(startTime), float(duration))], (yTicks[i], 5), facecolors=dispensingColor)


plt.savefig("schedule.png") 
