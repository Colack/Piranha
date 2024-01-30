fun main() {
	int versionMajor = 1;
	int versionMinor = 0;
	int versionPatch = 0;
	bool inShell = true;
	str currentCommand = "";

	spew "Chomp V";
	spew versionMajor;
	spew ".";
	spew versionMinor;
	spew ".";
	spew versionPatch;
	spew ".";
	spew "(c) Colack 2022";
		
	while inShell
	currentCommand = ask ">";

	if currentCommand = "help"
	spew "Chomp V";
	spew versionMajor;
	spew ".";
	spew versionMinor;
	spew ".";
	spew versionPatch;
	spew ".";
	spew "(c) Colack 2022";
	return;

	else currentCommand = "exit"
	spew "Exiting...";
	inShell = false;
	return;

	currentCommand = "";
}
