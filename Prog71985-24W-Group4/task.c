#define _CRT_SECURE_NO_WARNINGS
#include "task.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h> //for strcpy and memcpy

TASK CreateTask(char name[MAXNAME], int priorityLevel, char content[MAXCONTENT]) {// , STATE state, time_t time) {
	TASK t;
	t.isEmpty = false;
	strcpy(t.name, name);
	t.priorityLevel = priorityLevel;
	strcpy(t.content, content);
	//t.state = state;
	//t.time = time;
	return t;
}

void PrintTask(TASK t) {
	printf("Task: %s\n", t.name);
	printf("Priority Level: %d\n", t.priorityLevel);
	if (strcmp(t.content, "")) { //check whether content is empty or not
		printf("Details: %s\n", t.content);
	}
	//we can print more task properties as we create them (state, time, etc)
}

TASK CopyTask(TASK src) {
	return CreateTask(src.name, src.priorityLevel, src.content);
}

bool CompareTask(TASK lhs, TASK rhs) {
	return (strcmp(lhs.name, rhs.name) && strcmp(lhs.content, rhs.content));
}

void DisposeTask(TASK t) {
	// nothing to be done yet? 
}


//-------KEEPING THESE FUNCTIONS HERE FOR NOW UNTIL WE MOVE THEM-------//
//void addTaskToList(TASK taskList[], char name[MAXNAME], int priorityLevel, char content[MAXCONTENT]) {// , STATE state, time_t time) {
//	TASK newTask = createTask(name, priorityLevel, content);// , state, time);
//	for (int index = 0; index < MAX_TASKS; index++) {
//		if (taskList[index].isEmpty) {
//			taskList[index] = newTask;
//			printf("index:%d\ntask: %s\n", index, taskList[index].name);//for debugging
//			return;
//		}
//	}
//}
//
//void deleteTaskFromList(TASK taskList[], char taskToDelete[MAXNAME]) {
//	for (int index = 0; index < MAX_TASKS; index++) {
//		if (strcmp(taskList[index].name, taskToDelete)) { //finds the correct task to delete by comparing names
//			taskList[index].isEmpty = 1;
//			strcpy(taskList[index].name, "");//set all values to empty
//			taskList[index].priorityLevel = 0;
//			strcpy(taskList[index].content, "");
//		}
//	}
//}
//
//void updateTaskFromList(TASK taskList[], char taskToUpdate[MAXNAME], char newName[MAXNAME], int newPriorityLevel, char newContent[MAXCONTENT]) {
//	for (int index = 0; index < MAX_TASKS; index++) {
//		if (strcmp(taskList[index].name, taskToUpdate) == 0) { //finds the correct task to update by comparing names
//			strcpy(taskList[index].name, newName);//sets to new values as specified by user
//			taskList[index].priorityLevel = newPriorityLevel;
//			strcpy(taskList[index].content, newContent);
//		}
//	}
//}
