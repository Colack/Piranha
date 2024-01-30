#include "shell.h"

void piranha_shell() {
    inInput = true;
    while (inInput) {
        char consoleInput[MAX_STRING] = "";
        hasRecievedCommand = false;

        if (!shownStartMessage) {
            piranha_startMessage();
            shownStartMessage = true;
        }
        printf("Piranha : ");

        scanf("%s",consoleInput);

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
        } else if (strcmp(consoleInput,"list")==0) {
            piranha_list();
        } else {
            hasRecievedCommand = false;
        }

        if (!hasRecievedCommand) {
            printf("Command '%s' not found.\nPlease use 'help' or 'start' to get started.\n",consoleInput);
        }

        hasRecievedCommand = true;
    }
}