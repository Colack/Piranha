#include "shell.h"

int versionMajor = 1;
int versionMinor = 0;
int versionPatch = 0;

bool inInput = false;
bool shownStartMessage = false;
bool hasRecievedCommand = false;

// Error Handling for Novel
void errorHandling(int line, int code, char reason[MAX_STRING]) {
    if (line == 0) {
        printf("Error Code : #%d\n%s",code,reason);
    } else {
        printf("Error Code : #%d\nLine : %d\n%s",code,line,reason);
    }
}

// Run a file
void run(char filePath[MAX_STRING]) {

}

// Get input from the console
void getInput() {
    inInput = true;
    while (inInput) {
        char consoleInput[MAX_STRING] = "";

        if (!shownStartMessage) {
            printf("Novel V%d.%d.%d (c) Colack 2022\n",versionMajor,versionMinor,versionPatch);
            printf("Licensed under the [MIT] license.\n");
            printf("Type 'help' to get started.\n");
            printf("Novel : ");
            shownStartMessage = true;
        } else {
            printf("Novel : ");
        }

        gets(consoleInput);

        if (strcmp(consoleInput,"help")==0) {

            printf("Welcome to Novel V%d.%d.%d\n\n",versionMajor,versionMinor,versionPatch);
            printf("If you have never used Novel, you should read the documentation");
            printf("before you do any coding. (https://github.com/Colack/Novel/wiki)\n\n");
            printf("To get started, type the 'run' command to run a program.\n\n");
            printf("The rest of the commands are for shell manipulation.\n");
            printf("cd - Change the current directory Novel is in.\n");
            printf("craft - Create a new file.\n");
            printf("break - Delete a file.\n");
            printf("explore - View the contents of a specified file.\n");
            printf("exit - Terminate the prorgam.\n");
            hasRecievedCommand = true;

        } else if (strcmp(consoleInput,"exit")==0) {

            inInput = false;
            shownStartMessage = false;
            hasRecievedCommand = true;

        } else if (strcmp(consoleInput,"cd")==0) {

            char directoryChange[MAX_STRING] = "";
            char s[MAX_STRING];
            printf(">");
            gets(directoryChange);
            chdir(directoryChange);
            printf("%s\n",getcwd(s, 100));
            hasRecievedCommand = true;

        } else if (strcmp(consoleInput,"craft")==0) {

            char fileName[MAX_STRING] = "";
            printf(">");
            gets(fileName);
            FILE *fp;
            fp = fopen (fileName, "w");
            fclose(fp);
            printf("Created file '%s'.\n",fileName);
            hasRecievedCommand = true;

        } else if (strcmp(consoleInput,"break")==0) {

            char fileName[MAX_STRING] = "";
            printf(">");
            gets(fileName);
            if (remove(fileName) == 0) {
                printf("File '%s' deleted successfully.\n",fileName);
            } else {
                printf("Unable to delete '%s'.\n",fileName);
            }
            hasRecievedCommand = true;

        } else if (strcmp(consoleInput,"explore")==0) {

            char fileName[MAX_STRING] = "";
            printf(">");
            gets(fileName);
            FILE *fr;
            char ch;
            fr = fopen(fileName, "r");
            if (NULL == fr) {
                printf("File '%s' cannot be opened.\n",fileName);
            } else {
                while (ch != EOF) {
                    ch = fgetc(fr);
                    printf("%c", ch);
                }
                printf("\n");
                fclose(fr);
            }
            hasRecievedCommand = true;
        }

        if (!hasRecievedCommand) {
            printf("The command '%s' is not found.\nPlease use 'help' to get a list of commands.\n",consoleInput);
        }

        hasRecievedCommand = false;
    }
}
