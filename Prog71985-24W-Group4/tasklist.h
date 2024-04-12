// linked list of tasks(tasklist) interface
// ceren askin - andy guest - dzhanybek zakiriiaev - prog71985 - taskManager - group4
// principal editors - dzhanybek zakiriiaev - ceren askin
#pragma once
#include "task.h"
#define MIN_PRIORITYLEVEL 1
#define MAX_PRIORITYLEVEL 5
#define TASKLISTFILE "tasklist.txt"

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

void DisplayFinishedTasks(PTASKLIST taskList);

void DisplayTasksInProgress(PTASKLIST taskList);

void DisplayTasksNotStarted(PTASKLIST tasklist);

void DisplayTasksByPriority(PTASKLIST taskList);

void SortTasksByPriority(PTASKLIST list);