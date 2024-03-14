#pragma once
#include <time.h>
#include "state.h"
#define MAXNAME 40
#define MAXCONTENT 300
typedef struct task {
	char name[MAXNAME];
	int priorityLevel;
	char content[MAXCONTENT];
	STATE state;
	time_t time;
}TASK;

