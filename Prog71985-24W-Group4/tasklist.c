// linked list of tasks(tasklist) implementation
// dzhanybek zakiriiaev - ceren askin - prog71985 - winter24 - taskManager
#define _CRT_SECURE_NO_WARNINGS
#include "task.h"
#include "tasklist.h"
#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 300

PTASKLIST taskList = NULL;

void Add(PTASKLIST* list, TASK t) {
	PTASKLIST newNode = (PTASKLIST)malloc(sizeof(TASKLIST));
	if (newNode == NULL) {
		fprintf(stderr, "error allocating memory\n");
		exit(EXIT_FAILURE);
	}
	else {
		newNode->task = CopyTask(t);
		newNode->next = *list;

		*list = newNode;
	}
}

void Display(PTASKLIST list) {
	PTASKLIST current = list;
	if (current == NULL) {
		return;
	}
	do {
		PrintTask(current->task);
		current = current->next;
	} while (current != NULL);
}

void Remove(PTASKLIST* list, TASK t) {
	PTASKLIST current = *list;
	if (current != NULL && CompareTask(current->task, t)) {
		*list = current->next;
		free(current);
		return;
	}
	PTASKLIST prev = NULL;
	while (current != NULL && !CompareTask(current->task, t)) {
		prev = current;
		current = current->next;
	}
	if (current == NULL) {
		return;
	}
	else {
		prev->next = current->next;
		free(current);
	}
}

TASK* SearchTaskByName(PTASKLIST list, char* name) {
	PTASKLIST current = list;
	while (current != NULL) {
		if (strcmp(current->task.name, name)) {
			return &(current->task);
		}
		current = current->next;
	}
	return (TASK*)NULL;
}

void SaveTaskListToDiskFile(PTASKLIST list, char* filename) {
	FILE* fp = fopen(filename, "w");
	if (fp == NULL) {
		fprintf(stderr, "Error opening the file.\n");
		return;
	}

	PTASKLIST current = list;
	while (current != NULL) {
		if (current->task.state == NOT_STARTED) {
			fprintf(fp, "%s %d not_started\n", current->task.name, current->task.priorityLevel);
		}
		else if (current->task.state == IN_PROGRESS) {
			fprintf(fp, "%s %d in_progress\n", current->task.name, current->task.priorityLevel);
		}
		else if (current->task.state == CLOSED) {
			fprintf(fp, "%s %d closed\n", current->task.name, current->task.priorityLevel);
		}
		fprintf(fp, "%s\n", current->task.content);
		current = current->next;
	}

	fclose(fp);
	printf("Data is saved!\n");
}

PTASKLIST ReadTaskListFromDiskFile(char* filename) {
	PTASKLIST list = NULL;
	FILE* fp = fopen(filename, "r");
	if (fp == NULL) {
		SaveTaskListToDiskFile(list, filename);
		return (PTASKLIST)NULL;
	}
	TASK t = {0};
	char line[MAXLINE] = {0};
	char state[MAXNAME] = {0};
	while (fgets(line, sizeof(line), fp) != NULL) {
		if (sscanf(line, "%s %d %s", t.name, &t.priorityLevel, state) == 3) {
			if (strcmp(state, "not_started") == 0) {
				t.state = NOT_STARTED;
			}
			else if (strcmp(state, "in_progress") == 0) {
				t.state = IN_PROGRESS;
			}
			else if (strcmp(state, "closed") == 0) {
				t.state = CLOSED;
			}
			if (fgets(line, sizeof(line), fp) != NULL) {
				line[strcspn(line, "\n")] = 0;
				strcpy(t.content, line);
			}
			else {
				fprintf(stderr, "Error reading content.\n");
				exit(EXIT_FAILURE);
			}
			Add(&list, t);
		}
		else {
			fprintf(stderr, "Error parsing data from the file.\n");
			exit(EXIT_FAILURE);
		}
	}

	fclose(fp);
	return list;
}

void DisplayFinishedTasks() {
	extern PTASKLIST taskList;
	printf("Finished Tasks:\n\n");
	PTASKLIST current = taskList;
	while (current != NULL) {
		if (current->task.state == CLOSED) {
			PrintTask(current->task);
			printf("\n");
		}
		current = current->next;
	}
}

void DisplayTasksInProgress() {
	extern PTASKLIST taskList;
	printf("In Progress Tasks:\n\n");
	PTASKLIST current = taskList;
	while (current != NULL) {
		if (current->task.state == IN_PROGRESS) {
			PrintTask(current->task);
			printf("\n");
		}
		current = current->next;
	}
}

void DisplayTasksByPriority() {
	extern PTASKLIST taskList;
	printf("Displaying all tasks by priority:\n\n");
	SortTasksByPriority(taskList);

	PTASKLIST current = taskList;
	while (current != NULL) {
		PrintTask(current->task);
		printf("\n");
		current = current->next;
	}
}

void SortTasksByPriority(PTASKLIST list) {
	if (list == NULL) {
		fprintf(stderr, "Error: List is empty.\n");
		return;
	}
	int swap;
	do {
		swap = 0;
		PTASKLIST current = list;
		while (current->next != NULL) {
			if (current->task.priorityLevel < current->next->task.priorityLevel) {
				int tempPriority = current->task.priorityLevel;
				current->task.priorityLevel = current->next->task.priorityLevel;
				current->next->task.priorityLevel = tempPriority;
				swap = 1;
			}
			current = current->next;
		}
	} while (swap);
}

void Dispose(PTASKLIST* list) {
	PTASKLIST current = *list;
	while (current != NULL) {
		PTASKLIST tmp = current;
		DisposeTask(current->task);
		current = current->next;
		free(tmp);
	}
}