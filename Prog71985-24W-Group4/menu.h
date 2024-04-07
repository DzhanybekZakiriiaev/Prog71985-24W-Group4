#pragma once
// menu - interface
// ceren askin - prog71985 - taskManager
#include "getValidInput.h"
#include "tasklist.h"

void displayWelcomeMenu();
int getMenuChoice();
char getTaskChoice();
char getDisplayChoice();
void taskManager(PTASKLIST tasklist);
