// group project - taskManager
// ceren askin - andy guest - dzhanybek zakiriiaev - prog71985 - taskManager - group4
// 
//The program your group will write will be one of :
//1. a calendar / appointment manager
//2. a to - do / task manager
//3. a recipe(as in cooking) manager
//4. (some other) activity manager * *you must get prior approval from
//professor * before * choosing this option * *
//Your program must have the following mandatory features :
//1. add a new appt / task / recipe / other
//2. delete an existing appt / task / recipe / other
//3. update an existing appt / task / recipe / other
//4. display single appt / task / recipe / other
//5. display range appt / task / recipe / other
//6. display all appt / task / recipe / other
//7. search for appt / task / recipe / other
//8. friendly / easy to use UI(or menu system)
//9. save accumulated data to disk
//10. load accumulated data from disk
#include "tasklist.h"
#include "menu.h"
#include "task.h"
#include "state.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    displayWelcomeMenu();
    taskManager();
    return 0;
}

