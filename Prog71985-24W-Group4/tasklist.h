#pragma once
#include "task.h"

typedef struct tasklist {
	TASK task;
	struct tasklist* next;
} TASKLIST, *PTASKLIST;

void Add(PTASKLIST* list, TASK t);

void Display(PTASKLIST list);

void Remove(PTASKLIST* list, TASK t);

void Dispose(PTASKLIST* list);