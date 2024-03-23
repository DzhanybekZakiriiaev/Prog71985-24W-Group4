// Menu - implementation
#define _CRT_SECURE_NO_WARNINGS
#include "menu.h"
#include "task.h"
#include <stdio.h>

void displayWelcomeMenu() {
    printf(" ****************************\n");
    printf("**         Welcome to       **\n");
    printf("**   Task Manager Program   **\n");
    printf(" ****************************\n");
}

void displayMenu(TASK selection) {
    char userInput;

    do {
        printf("\nTo choose a function, enter its letter label:\n");
        printf("1) TASK - (Add, Delete, Update)\n");
        printf("2) DISPLAY TASK - (Single, Range, All)\n");
        printf("3) SEARCH TASK\n");
        printf("4) QUIT\n");
        printf("Enter your choice: ");
        scanf(" %c", &userInput);
        printf("\n****************************");

        switch (userInput) {
        case '1':
            printf("\nTASK - (Add, Delete, Update) Selected\n");
            printf("a) Task add\n");
            printf("b) Task delete\n");
            printf("c) Task update\n");
            printf("\nPlease enter your choice: ");

            char taskInput;
            scanf(" %c", &taskInput);

            switch (taskInput) {
            case 'a':
                printf("Add\n");
                break;
            case 'b':
                printf("Delete\n");
                break;
            case 'c':
                printf("Update\n");
                break;
            default:
                break;
            }
            break;
        case '2':
            printf("\nDISPLAY TASK - (Single, Range, All) Selected\n");
            printf("a) Display single task\n");
            printf("b) Display range task\n");
            printf("c) Display all task\n");

            char displayInput;
            scanf(" %c", &displayInput);

            switch (displayInput) {
            case 'a':
                printf("Display single task\n");
                break;
            case 'b':
                printf("Display range task\n");
                break;
            case 'c':
                printf("Display all task\n");
                break;
            default:
                break;
            }
            break;
        case '3':
            printf("\nSEARCH TASK - Selected.\n");
            break;
        case '4':
            printf("Exiting the program.\n");
            break;
        default:
            break;
        }

    } while (userInput != '4');
}
