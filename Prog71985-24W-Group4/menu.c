// menu - implementation
// ceren askin - prog71985 - taskManager

#define _CRT_SECURE_NO_WARNINGS
#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 10

void displayWelcomeMenu() {
    printf(" ****************************\n");
    printf("**         Welcome to       **\n");
    printf("**   Task Manager Program   **\n");
    printf(" ****************************\n");
}

int getMenuChoice() {
    int choice = 0;
    char input[MAXSIZE];

    do {
        printf("\nTo choose a function, enter its number:\n");
        printf("1) TASK - (Add, Delete, Update)\n");
        printf("2) DISPLAY TASK - (Single, Range, All)\n");
        printf("3) SEARCH TASK\n");
        printf("4) QUIT\n");
        printf("\nPlease enter your choice: ");

        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        if (strlen(input) > 1 || sscanf(input, "%d", &choice) != 1 || choice < 1 || choice > 4) {
            printf("\nInvalid choice. Please enter a valid option (1-4).\n");
            printf("****************************");
        }
    } while (choice < 1 || choice > 4);

    return choice;
}

char getTaskChoice() {
    printf("****************************");
    printf("\nTASK - (Add, Delete, Update) Selected\n");
    printf("a) Task add\n");
    printf("b) Task delete\n");
    printf("c) Task update\n");
    printf("d) Back to main menu\n");
    printf("\nPlease enter your choice: ");

    char taskInput[MAXSIZE];
    fgets(taskInput, sizeof(taskInput), stdin);

    if (taskInput[0] == 'd' && (taskInput[1] == '\n' || taskInput[1] == '\0')) {
        printf("\nReturning to main menu...\n");
        printf("****************************");
        return 'd';
    }
    if ((taskInput[0] >= 'a' && taskInput[0] <= 'd') && (taskInput[1] == '\n' || taskInput[1] == '\0')) {
        return taskInput[0];
    }

    printf("\nInvalid selection. Please choose a, b, c, or d.\n");
    return '\0';
}

char getDisplayChoice() {
    printf("****************************");
    printf("\nDISPLAY TASK - (Single, Range, All) Selected\n");
    printf("a) Display single task\n");
    printf("b) Display range task\n");
    printf("c) Display all task\n");
    printf("d) Back to main menu\n");
    printf("\nPlease enter your choice: ");

    char displayInput[MAXSIZE];
    fgets(displayInput, sizeof(displayInput), stdin);

    if (displayInput[0] == 'd' && (displayInput[1] == '\n' || displayInput[1] == '\0')) {
        printf("\nReturning to main menu...\n");
        printf("****************************");
        return 'd';
    }
    if ((displayInput[0] >= 'a' && displayInput[0] <= 'd') && (displayInput[1] == '\n' || displayInput[1] == '\0')) {
        return displayInput[0];
    }
    printf("\nInvalid selection. Please choose a, b, c, or d.\n");
    return '\0';
}

void taskManager() {
    char taskInput;
    int invalidInputCount;
   
    while (1) {
        int inputMain = getMenuChoice();
        invalidInputCount = 0;

        switch (inputMain) {
        case 1: {
            do {
                taskInput = getTaskChoice();
                if (taskInput == 'd') {
                    break;
                }
                if (taskInput >= 'a' && taskInput <= 'd') {
                    printf("****************************");
                    printf("\nValid selection: %c\n", taskInput);

                    switch (taskInput) {
                    case 'a':
                        printf("\nAdding a new task...\n");
                        break;
                    case 'b':
                        printf("\nDeleting a task...\n");
                        break;
                    case 'c':
                        printf("\nUpdating a task...\n");
                        break;
                    default:
                        printf("\nInvalid selection. Please choose a, b, c, or d.\n");
                        break;
                    }
                    invalidInputCount = 0;
                    break;
                }
                else {
                    invalidInputCount++;
                    if (invalidInputCount >= 3) {
                        printf("\n* Too many invalid inputs. Returning to main menu. *\n");
                        printf("****************************");
                        break;
                    }
                }
            } while (1);
            break;
        }
        case 2: {
            char displayChoice;
            invalidInputCount = 0;
            do {
                displayChoice = getDisplayChoice();
                if (displayChoice == 'd') {
                    break;
                }
                if (displayChoice >= 'a' && displayChoice <= 'd') {
                    printf("****************************");
                    printf("\nValid selection: %c\n", displayChoice);

                    switch (displayChoice) {
                    case 'a':
                        printf("Displaying single task...\n");
                        break;
                    case 'b':
                        printf("Displaying range task...\n");
                        break;
                    case 'c':
                        printf("Displaying all tasks...\n");
                        break;
                    }
                    invalidInputCount = 0;
                    break;
                }
                else {
                    invalidInputCount++;
                    if (invalidInputCount >= 3) {
                        printf("\n* Too many invalid inputs. Returning to main menu. *\n");
                        printf("****************************");
                        break;
                    }
                }
            } while (1);
            break;
        }
        case 3:
            printf("\nSEARCH TASK - Selected\n");
            break;
        case 4:
            printf("\nExisting the program. Good bye!\n");
            return;

        default:
            printf("****************************");
            printf("Invalid choice. Please enter a valid option (1-4).\n");
            break;
        }
    }
}
