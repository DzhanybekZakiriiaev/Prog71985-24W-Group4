#include "tasklist.h"
#include "menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ceren askin, andy guest, dzhanybek zakiriiaev  - prog71985 - taskManager

int main(void) {
    //initialize the task list
    PTASKLIST tasklist = ReadTaskListFromDiskFile(TASKLISTFILE);

    displayWelcomeMenu();
    taskManager(&tasklist);

    Dispose(&tasklist);
    return 0;
}

