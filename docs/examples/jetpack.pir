exchange "classic"
exchange "jetpack"

int versionMajor = 1;
int versionMinor = 0;
int versionPatch = 0;
str currentCommand = "";
bool inShell = true;
bool shownStartMessage = true;

fun main() {
    if (!shownStartMessage) {
        spew "Chomp Shell V" + versionMajor + "." + versionMinor + "." + versionPatch;
        spew "(c) Team Piranha 2022";
        shownStartMessage = true;
    }
    while (inShell) {
        currentCommand = ask ">";
        if (currentCommand = "help") {
            spew "Chomp Shell V" + versionMajor + "." + versionMinor + "." + versionPatch;
            spew "(c) Team Piranha 2022";
            currentCommand = refuel; ~~ Resets a variable back to its original value.
        } else if (currentCommand = "exit") {
            spew "Aborting...";
            currentCommand = refuel; ~~ Resets a variable back to its original value.
            inShell = false;
        } else if (currentCommand = "all") {
            spew "Testing all commands.";
            boost 20 22;
            boost 24 26;
            currentCommand = refuel; ~~ Resets a variable back to its original value.
        } else if (currentCommand = "reset") {
            spew "Reseting all values...";
            versionMajor = refuel; ~~ Resets a variable back to its original value.
            versionMinor = refuel; ~~ Resets a variable back to its original value.
            versionPatch = refuel; ~~ Resets a variable back to its original value.
            currentCommand = refuel; ~~ Resets a variable back to its original value.
            inShell = refuel; ~~ Resets a variable back to its original value.
            shownStartMessage = refuel; ~~ Resets a variable back to its original value.
            fly main();
        }
    } 
}
