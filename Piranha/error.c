#include "error.h";

void error(int line, char error[MAX_STRING]) {
    printf("%s Error : \n",PROGRAM_NAME);
    printf("Line %d : %s\n",line,error);
}

void bypassError(int line, char error[MAX_STRING], char reason[MAX_STRING], bool show) {
    printf("Skipped Error : Line : %s\n",error);
    if (show) {
        printf("%s Error : \n",PROGRAM_NAME);
        printf("Line %d : %s\n",line,error);
    }
}
