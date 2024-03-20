#pragma once
#include <time.h>
#include "state.h"
#include <time.h> 
#include <stdbool.h>
#define MAXNAME 40
#define MAXCONTENT 300
#define MAX_TASKS 25 //maximum number of tasks in the tasklist

typedef struct task {
	bool isEmpty; //to keep track of which element in the array it is
	char name[MAXNAME];
	int priorityLevel;
	char content[MAXCONTENT];
	STATE state;
	time_t deadLine;
}TASK;

TASK createTask(char name[MAXNAME], int priorityLevel, char content[MAXCONTENT], time_t date);//, STATE state, time_t time);

void addTaskToList(TASK taskList[], char name[MAXNAME], int priorityLevel, char content[MAXCONTENT]);// , STATE state, time_t time);

void deleteTaskFromList(TASK taskList[], char taskToDelete[MAXNAME]);

void updateTaskFromList(TASK taskList[], char taskToUpdate[MAXNAME], char newName[MAXNAME], int newPriorityLevel, char newContent[MAXCONTENT]);

