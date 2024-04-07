#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "state.h"
#define MAXSTRINGLENGTH 300

//andy guest - prog71985 - taskManager

char* getValidStringInput(char* prompt, int maxLength);
int getValidInt(char* prompt, int minValue, int maxValue);
enum state getValidState();


