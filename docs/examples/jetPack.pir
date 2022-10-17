exchange "classic"
exchange "jetpack"

int versionMajor = 1;
int versionMinor = 0;
int versionPatch = 0;
str currentCommand = "";

fun main() {
    spew "Chomp Shell V" + versionMajor + "." + versionMinor + "." + versionPatch;
    spew "(c) Team Piranha 2022";
    currentCommand = ask ">";
    
}
