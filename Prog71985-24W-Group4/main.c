#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "task.h"

int main(void) {

	
	TASK taskList[MAX_TASKS]; //initialize the list of tasks

	//testing my functions
	addTaskToList(taskList, "do math homework", 1, "multiplication homework");
	addTaskToList(taskList, "take out trash", 5, "garbage day is wednesday");
	deleteTaskFromList(taskList, "do math homework");
	printf("index:%d\ntask: %s\n", 1, taskList[1].name);
	updateTaskFromList(taskList, "do math homework", "do science homework", 4, "due soon!");
	printf("index:%d\ntask: %s\n", 0, taskList[0].name);
	//end of testing 







	return 0;
}
