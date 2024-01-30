#include "commands.h"

bool inInput = false;
bool shownStartMessage = false;
bool hasRecievedCommand = false;

void piranha_startMessage() {
    printf("%s V%s (c) %s %d\n",PROGRAM_NAME,CURRENT_VERSION,MAINTAINER,YEAR);
    printf("Type 'help' or 'start' to get started.\n");
}

void piranha_cd() {
    
    char directoryChange[MAX_STRING] = "";
    char s[MAX_STRING];
    
    printf("> ");
    
    scanf("%s",directoryChange);
    chdir(directoryChange);
    
    printf("%s\n",getcwd(s, 100));
    
    hasRecievedCommand = true;
}

void piranha_list() {
    printf("\n");
    DIR *d;
    struct dirent *dir;
    d = opendir(".");
    if (d) {
        while ((dir = readdir(d)) != NULL) {
            printf("%s\n", dir->d_name);
        }
        closedir(d);
    }
    printf("\n");
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
    scanf("%s",fileName);
    
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
    scanf("%s",fileName);
    
    FILE *fp;
    fp = fopen (fileName, "w");
    fclose(fp);
    
    printf("Created file '%s'.\n",fileName);
    hasRecievedCommand = true;
}

void piranha_read() {
    
    char fileName[MAX_STRING] = "";
    printf("> ");
    scanf("%s",fileName);
    
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
    printf("\ncd - Changes the current directory.\n");
    printf("read - Reads a specified file.\n");
    printf("new - Creates a new file.\n");
    printf("delete - Deletes a file.\n");
    printf("start - Shows the start menu.\n");
    printf("exit - Exits the shell.\n");
    printf("help - Shows this help menu\n\n");
    hasRecievedCommand = true;
}