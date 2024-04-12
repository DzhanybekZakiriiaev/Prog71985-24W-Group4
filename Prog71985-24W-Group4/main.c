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

