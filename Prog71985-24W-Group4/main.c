#include "tasklist.h"
#include "menu.h"
#include "task.h"
#include "state.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ceren askin, andy guest, dzhanybek zakiriiaev  - prog71985 - taskManager

int main(void) {
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
    return 0;
}

