#include "shellCommands.h"

bool inInput = false;
bool shownStartMessage = false;
bool hasRecievedCommand = false;

void piranha_startMessage() {
    printf("%s V%s (c) %s %d\n",PROGRAM_NAME,CURRENT_VERSION,MAINTAINER,YEAR);
    printf("Licensed under the [%s] license.\n",LICENSE);
    printf("Type 'help' or 'start' to get started.\n");
}

void piranha_cd() {
    
    char directoryChange[MAX_STRING] = "";
    char s[MAX_STRING];
    
    printf("> ");
    
    gets(directoryChange);
    chdir(directoryChange);
    
    printf("%s\n",getcwd(s, 100));
    
    hasRecievedCommand = true;
}

void piranha_start() {
    
    printf("Welcome to %s V%s\n\n",PROGRAM_NAME,CURRENT_VERSION);
    printf("If you are new to %s, you should read the documentation at '%s'.\n",PROGRAM_NAME,DOCUMENTATION);
    printf("To get started, type the 'run' command.\n");
    printf("To view a list of commands, type the 'help' command.\n");
    
    hasRecievedCommand = true;
}

void piranha_exit() {
    
    inInput = false;
    shownStartMessage = false;
    hasRecievedCommand = true;
    
}

void piranha_delete() {
    
    char fileName[MAX_STRING] = "";
    printf("> ");
    gets(fileName);
    
    if (remove(fileName) == 0) {
        printf("File '%s' deleted successfully.\n",fileName);
    } else {
        printf("Unable to delete '%s'.",fileName);
    }
    
    hasRecievedCommand = true;
}

void piranha_new() {
    
    char fileName[MAX_STRING] = "";
    printf("> ");
    gets(fileName);
    
    FILE *fp;
    fp = fopen (fileName, "w");
    fclose(fp);
    
    printf("Created file '%s'.\n",fileName);
    hasRecievedCommand = true;
}

void piranha_read() {
    
    char fileName[MAX_STRING] = "";
    printf("> ");
    gets(fileName);
    
    FILE *fp;
    char ch;
    fp = fopen (fileName, "r");
    
    if (fp == NULL) {
        printf("File '%s' cannot be opened.\n",fileName);
    } else {
        while (ch != EOF) {
            ch = fgetc(fp);
            printf("%c", ch);
        }
        printf("\n");
        fclose(fp);
    }
    hasRecievedCommand = true;
}

void piranha_help() {
    printf("cd - Changes the current directory.\n");
    printf("read - Reads a specified file.\n");
    printf("new - Creates a new file.\n");
    printf("delete - Deletes a file.\n");
    printf("start - Shows the start menu.\n");
    printf("exit - Exits the shell.\n");
    printf("help - Shows this help menu.\n");
}

void piranha_shell() {
    inInput = true;
    while (inInput) {
        char consoleInput[MAX_STRING] = "";
        hasRecievedCommand = false;

        if (!shownStartMessage) {
            piranha_startMessage();
            shownStartMessage = true;
        }
        printf("Novel : ");

        gets(consoleInput);

        if (strcmp(consoleInput,"help")==0) {
            piranha_help();
        } else if (strcmp(consoleInput,"exit")==0) {
            piranha_exit();
        } else if (strcmp(consoleInput,"cd")==0) {
            piranha_cd();
        } else if (strcmp(consoleInput,"new")==0) {
            piranha_new();
        } else if (strcmp(consoleInput,"delete")==0) {
            piranha_delete();
        } else if (strcmp(consoleInput,"start")==0) {
            piranha_start();
        } else if (strcmp(consoleInput,"read")==0) {
            piranha_read();
        } else {
            hasRecievedCommand = false;
        }

        if (!hasRecievedCommand) {
            printf("Command '%s' not found.\nPlease use 'help' or 'start' to get started.\n",consoleInput);
        }

        hasRecievedCommand = true;
    }
}
