#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void) {
    taskList = ReadTaskListFromDiskFile("tasklist.txt");
    //initialize the task list
    //Display(tasklist);
    //TASK newTask = CreateTask(4, "ALALLALALALAL", IN_PROGRESS, "NEWTASK");
    //Add(&tasklist, newTask);
    //printf("\n");
    //Display(tasklist);
    //SaveTaskListToDiskFile(tasklist, TASKLISTFILE);
    //PTASKLIST tasklist2 = ReadTaskListFromDiskFile(TASKLISTFILE);
    //printf("\n-----------------------\n");
    //Display(tasklist2);
    displayWelcomeMenu();
    taskManager();

    Dispose(&taskList);
    return 0;
}