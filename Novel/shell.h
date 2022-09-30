#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>

#define MAX_STRING 100

int versionMajor;
int versionMinor;
int versionPatch;

bool inInput;
bool shownStartMessage;
bool hasRecievedCommand;

void errorHandling();
void run();
void getInput();
