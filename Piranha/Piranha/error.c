#include "error.h"

bool errorShown = true;

void error(int line, char error[MAX_STRING]) {
    if (errorShown) {
        printf("%s Error : \n",PROGRAM_NAME);
        printf("Line %d : %s\n",line,error);
    }
}

void bypassError(int line, char error[MAX_STRING], char reason[MAX_STRING]) {
    printf("Skipped Error : Line : %s\n",error);
    if (errorShown) {
        printf("%s Error : \n", PROGRAM_NAME);
        printf("Line %d : %s\n",line,error);
    }
}

void hideErrors() {
    errorShown = false;
}

void showErrors() {
    errorShown = true;
}