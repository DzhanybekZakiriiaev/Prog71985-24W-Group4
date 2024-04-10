#include "getValidInput.h"

//andy guest - prog71985 - taskManager

//gets string from user and allocates memory for it with malloc
char* getValidStringInput(char* prompt, int maxLength) {
    printf("%s", prompt);
    char* stringArray = (char*)malloc(maxLength * sizeof(char));
    if (stringArray == NULL) {
        printf("Error allocating memory\n");
        exit(1);
    }
    fgets(stringArray, maxLength, stdin); 
    size_t length = strlen(stringArray); //length of string stored in stringArray not inc \0 (null terminator)
    if (stringArray[length - 1] == '\n') {//check if the last char in the string is a \n
        stringArray[length - 1] = '\0';//if it is \n, replace with \0 (to remove \n)
    }
    else {
        while (getchar() != '\n');
    }
    return stringArray;
}

//given a min and max value (inclusive) will ask for user input and verify it is within the range
int getValidInt(char* prompt, int minValue, int maxValue) {
    int input;
    printf("%s", prompt);
    while (scanf("%d", &input) != 1 || input < minValue || input > maxValue) {
        while (getchar() != '\n');
        printf("\033[31mInvalid input. Please enter an number between %d and %d\n\033[0m", minValue, maxValue);
        printf("%s", prompt);
    }
    return input;
}

//returns a state based on the users input
enum state getValidState() {
    int stateChoice = getValidInt("Enter the number corresponding to the tasks status:\n1.Not Started\n2.In Progress\n3.Complete/Closed\n", 1, 3);//1 & 3 are directly corresponding to the prompt
    switch (stateChoice) {
    case 1:
        return NOT_STARTED;
    case 2:
        return IN_PROGRESS;
    case 3:
        return CLOSED;
    default:
        printf("Could not set state. Please try again.");
        exit(1);
    }
    
}
 
char* getValidTaskName(PTASKLIST tasklist, char* prompt, int maxLength) { //task name cannot contain spaces
    bool invalidName;
    char* taskname;
    do {
        invalidName = 0; 
        taskname = getValidStringInput(prompt, maxLength);
        for (int stringIndex = 0; stringIndex < strlen(taskname); stringIndex++) {
            if (taskname[stringIndex] == ' ') {
                printf("The name of the task cannot contain spaces. Please try again.\n");
                invalidName = 1;
                continue; //loop again, to ask for new name
            }
        }
    } while (invalidName);
    return taskname;
}