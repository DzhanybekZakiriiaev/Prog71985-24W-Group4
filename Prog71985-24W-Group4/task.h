#pragma once
#include <time.h>
#include "state.h"
#include <stdbool.h>
#define MAXNAME 40
#define MAXCONTENT 300

typedef struct task {
	char name[MAXNAME];
	int priorityLevel;
	char content[MAXCONTENT];
	STATE state;
	//time_t time;
}TASK;

TASK CreateTask(char name[MAXNAME], int priorityLevel, char content[MAXCONTENT], STATE state);//, STATE state, time_t time);

TASK CopyTask(TASK src);

bool CompareTask(TASK lhs, TASK rhs);

void PrintTask(TASK t);

void DisposeTask(TASK t);
