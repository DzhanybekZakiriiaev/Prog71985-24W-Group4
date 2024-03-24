#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task.h"
#include "taskManager.h"
#include "menu.h"

int main(void) {

	TASK selection();
	displayWelcomeMenu();
	displayMenu();


	//testing my functions --andy (will delete later)
	TASK taskList[MAX_TASKS]; //initialize the list of tasks
	PrintTask(createTask("make dinner", 3, "make salmon and rice"));
	addTaskToList(taskList, "do math homework", 1, "multiplication homework");
	addTaskToList(taskList, "take out trash", 5, "garbage day is wednesday");
	deleteTaskFromList(taskList, "do math homework");
	printf("index:%d\ntask: %s\n", 1, taskList[1].name);
	updateTaskFromList(taskList, "do math homework", "do science homework", 4, "due soon!");
	printf("index:%d\ntask: %s\n", 0, taskList[0].name);
	//end of testing 

	return 0;
}
