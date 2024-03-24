#include "task.h"
#include "tasklist.h"
#include <stdio.h>
#include <stdlib.h>

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

void Dispose(PTASKLIST* list) {
	// needs to be finished later
}