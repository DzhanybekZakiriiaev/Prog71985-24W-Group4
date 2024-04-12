// task implementation
// andy guest - dzhanybek zakiriiaev  - prog71985 - winter24 - taskManager
#define _CRT_SECURE_NO_WARNINGS
#include "task.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h> //for strcpy and memcpy

TASK CreateTask(int priorityLevel,  STATE state, char content[MAXCONTENT],char name[MAXNAME]) {
	TASK t;
	strcpy(t.name, name);
	t.priorityLevel = priorityLevel;
	strcpy(t.content, content);
	t.state = state;
	return t;
}

void PrintTask(TASK t) {
	printf("Task: %s\n", t.name);
	printf("Priority Level: %d\n", t.priorityLevel);
	printf("State: ");
	if (t.state == NOT_STARTED) {
		printf("not started\n");
	}
	else if (t.state == IN_PROGRESS) {
		printf("in progress\n");
	}
	else{
		printf("closed\n");
	}
	if (strcmp(t.content, "")!=0) { //check whether content is empty or not
		printf("Details: %s\n", t.content);
	}
	//we can print more task properties as we create them (state, time, etc)
}

TASK CopyTask(TASK src) {
	return CreateTask(src.priorityLevel, src.state,  src.content,src.name);
}

bool CompareTask(TASK lhs, TASK rhs) {
	return (strcmp(lhs.name, rhs.name) == 0 && strcmp(lhs.content, rhs.content)== 0); //added ==0 for correct string comparison 
}

void DisposeTask(TASK t) {
	// nothing
}
