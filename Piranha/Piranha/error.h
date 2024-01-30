#include "includes.h"

bool errorShown;

void error(int line, char error[MAX_STRING]);
void bypassError(int line, char error[MAX_STRING], char reason[MAX_STRING]);
void hideErrors();
void showErrors();