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

TASK* SearchTaskByName(PTASKLIST, char*);

PTASKLIST ReadTaskListFromDiskFile(char* filename);

void SaveTaskListToDiskFile(PTASKLIST list, char* filename);