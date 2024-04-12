// menu - implementation
// ceren askin - andy guest - dzhanybek zakiriiaev - prog71985 - taskManager - group4
// principal editors - ceren askin - andy guest
#define _CRT_SECURE_NO_WARNINGS
#include "tasklist.h"
#include "task.h"
#include "state.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "getValidInput.h"

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
            printf("\033[31mInvalid choice. Please enter a valid option (1-4).\n\033[0m");
            printf("****************************");
        }
    } while (choice < 1 || choice > 4);

    return choice;
}

char getTaskChoice() {
    printf("****************************");
    printf("\n\033[1;31mTASK - (Add, Delete, Update) Selected\n\033[0m");
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

    printf("\033[31mInvalid selection. Please choose a, b, c, or d.\n\033[0m");
    return '\0';
}

char getDisplayChoice() {
    printf("****************************");
    printf("\n\033[1;31mDISPLAY TASK - (Single, Range, All) Selected\n\033[0m");
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
    printf("\033[31mInvalid selection. Please choose a, b, c, or d.\n\033[0m");
    return '\0';
}

void taskManager() {
    PTASKLIST tasklist = NULL;
    tasklist = ReadTaskListFromDiskFile(TASKLISTFILE);
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

                    switch (taskInput) {
                    case 'a':
                        printf("\nAdding a new task...\n");
                        char* taskname;
                        do{
                            taskname = getValidText("Enter the task name: ", MAXNAME);
                            if (SearchTaskByName(tasklist, taskname) != NULL) {
                                printf("A task by that name already exists. Please try again and use a different name.\n");
                            }//keep looping until valid, unique name is entered
                        } while (SearchTaskByName(tasklist, taskname) != NULL);

                        TASK task = CreateTask(
                            getValidInt("\nEnter the priority level of the task (1-5): ", MIN_PRIORITYLEVEL, MAX_PRIORITYLEVEL), 
                            getValidState(), 
                            getValidText("\nEnter the tasks details: ", MAXCONTENT),
                            taskname);
                        Add(&tasklist, task);
                        printf("%s added to the tasklist. content: %s\n", task.name, task.content);
                        SaveTaskListToDiskFile(tasklist, TASKLISTFILE);
                        break;
                    case 'b':
                        printf("\nDeleting a task...\n");

                        TASK* taskToDelete = SearchTaskByName(tasklist, getValidText("Enter the name of the task you want to delete: ", MAXSTRINGLENGTH));

                        if (taskToDelete == NULL) {
                            printf("Could not find a task by that name. Please try again.\n");
                        }
                        else {
                            Remove(&tasklist, *taskToDelete);
                            SaveTaskListToDiskFile(tasklist, TASKLISTFILE); //save after completing delete
                        }
                        break;
                    case 'c':
                        printf("\nUpdating a task...\n");
                        TASK* taskToUpdate = SearchTaskByName(tasklist, getValidText("Enter the name of the task to update: ", MAXSTRINGLENGTH));
                        if (taskToUpdate == NULL) {
                            printf("Could not find a task by that name. Please try again.\n");
                        }
                        else {
                            int updateChoice = getValidInt("\n1.Name\n2.Priority\n3.Content\n4.State\nEnter the number corresponding to the feild you'd like to update: ", 1, 4);
                            switch (updateChoice) {
                            case 1:
                                //update the name feild
                                strcpy(taskToUpdate->name, getValidText("Enter the new name for the task: ", MAXNAME));
                                break;
                            case 2:
                                //update the priority level
                                taskToUpdate->priorityLevel = getValidInt("Enter the priority level of the task (1-5): ", MIN_PRIORITYLEVEL, MAX_PRIORITYLEVEL);
                                break;
                            case 3:
                                //update the content
                                strcpy(taskToUpdate->content, getValidText("Enter the new content for the task: ", MAXCONTENT));
                                break;
                            case 4:
                                //update the status 
                                taskToUpdate->state = getValidState();
                                break;
                            }
                            SaveTaskListToDiskFile(tasklist, TASKLISTFILE); //save before exiting
                        }
                        break;
                    default:
                        printf("\033[31mInvalid selection. Please choose a, b, c, or d.\n\033[0m");
                        break;
                    }
                    invalidInputCount = 0;
                    break;
                }
                else {
                    invalidInputCount++;
                    if (invalidInputCount >= 3) {
                        printf("\033[31m* Too many invalid inputs. Returning to main menu. *\n\033[0m");
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
                    printf("****************************\n");

                    switch (displayChoice) {
                   case 'a':
                        printf("Displaying single task...\n\n");
                        PTASKLIST tempList = tasklist;
                        if (tempList == NULL) {
                            printf("No tasks to display");
                            break;
                        }
                        int userChoice; 
                        PrintTask(tempList->task);
                        do {
                            userChoice = getValidInt("To go to next task press '1'. To exit press '2': ", 1, 2);
                            if(userChoice == 2){
                                break;
                            }
                            else if (tempList->next != NULL && userChoice == 1) {
                                tempList = tempList->next;
                                PrintTask(tempList->task);
                            }
                            else {
                                printf("\nNo more tasks in the list.\n");
                                break;
                            }
                        } while (userChoice != 2);
                    
                        break;
                    case 'b': {
                        printf("Please select the list you want to view\n");
                        printf("a) Display finished tasks\n");
                        printf("b) Display tasks in progress\n");
                        printf("c) Display not started tasks\n");
                        printf("d) Display tasks with priority\n");
                        printf("e) Back to main menu\n");
                        printf("\nPlease enter your choice: ");

                        char listChoice[MAXSIZE];
                        fgets(listChoice, sizeof(listChoice), stdin);
                        listChoice[strcspn(listChoice, "\n")] = '\0';

                        printf("****************************\n");
                        switch (listChoice[0]) {
                        case 'a':
                            DisplayFinishedTasks(tasklist);
                            break;
                        case 'b':
                            DisplayTasksInProgress(tasklist);
                            break;
                        case 'c':
                            DisplayTasksNotStarted(tasklist);
                            break;
                        case 'd':
                            DisplayTasksByPriority(tasklist);
                            break;
                        case 'e':
                            break;
                        default:
                            printf("\033[31mInvalid choice. Please enter a valid option (a-d).\n\033[0m");
                            break;
                        }
                        printf("****************************");
                        break;
                    }
                    case 'c':
                        DisplayTasksByPriority(tasklist);
                        printf("****************************");
                        break;
                    }
                    invalidInputCount = 0;
                    break;
                }
                else {
                    invalidInputCount++;
                    if (invalidInputCount >= 3) {
                        printf("\033[31m* Too many invalid inputs. Returning to main menu. *\n\033[0m");
                        printf("****************************");
                        break;
                    }
                }
            } while (1);
            break;
        }
        case 3:
            printf("\n\033[1;31mSEARCH TASK - Selected\n\033[0m");

            TASK* taskToSearch = SearchTaskByName(tasklist, getValidText("Enter the name of the task you want to search for: ", MAXSTRINGLENGTH));
            if (taskToSearch == NULL) {
                printf("Could not find a task by that name. Please try again.\n");
            }
            else {
                PrintTask(*taskToSearch);
            }
            break;
        case 4:
            printf("\nExiting the program. Good bye!\n");
            Dispose(&tasklist);
            return;

        default:
            printf("****************************");
            printf("\033[31mInvalid choice. Please enter a valid option (1-4).\n\033[0m");
            break;
        }
    }
}
