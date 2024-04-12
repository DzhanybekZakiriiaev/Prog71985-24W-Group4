// ceren askin - andy guest - dzhanybek zakiriiaev - prog71985 - taskManager - group4
// input validation interface 
// principal editor - andy guest
#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "state.h"
#include "tasklist.h"
#define MAXSTRINGLENGTH 300

char* getValidStringInput(char* prompt, int maxLength);
int getValidInt(char* prompt, int minValue, int maxValue);
enum state getValidState();
char* getValidText(char* prompt, int maxLength);//task name cannot contain spaces or be same as another task
