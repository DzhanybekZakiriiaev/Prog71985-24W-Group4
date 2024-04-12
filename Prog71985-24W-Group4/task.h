// task interface
// dzhanybek zakiriiaev - andy guest - prog71985 - winter24 - taskManager
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
}TASK;

TASK CreateTask(int priorityLevel, STATE state, char content[MAXCONTENT], char name[MAXNAME]);

TASK CopyTask(TASK src);

bool CompareTask(TASK lhs, TASK rhs);

void PrintTask(TASK t);

void DisposeTask(TASK t);