#include "includes.h"

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
