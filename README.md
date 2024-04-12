# PROG71985 Group4 Tasklist Project
## Dzhanybek Zakiriiaev:
- conducted code reviews and managed github repository
- added "DisplayNotStartedTasks", "Display", "Add", "Remove", "SearchTaskByName", "SaveTaskListToDiskFile", "ReadTaskListFromDiskFile", "Dispose" functions for tasklist struct
- created a project outline and struct relations (task.h, tasklist.h, state.h)
- added CopyTask and CompareTask functions
## Andy Guest:
- created the getValidInput functions to ensure correct string, int, taskname, and state input from user
- create task and print task functions in the task.c file
- search, add, update, display single task, and delete task implementation in the menu
## Ceren Askin:
- Code reviews were conducted
- A simple interface design was created for the user (menu.c and menu.h were created).
- User input validation checks were implemented, providing necessary warning messages to the user to make errors more understandable.
- A wrong input counter was added to the program to make it more efficient.
- Functions like DisplayFinishedTasks, DisplayTasksInProgress, DisplayTasksByPriority were created. Additionally, a function called SortTasksByPriority was created to support these functions, enabling listing tasks by priority.
