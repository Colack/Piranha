@ECHO OFF
  : Compile 

  powershell write-host -fore green Compiling...
  
  cd ./Piranha
  gcc Piranha.c commands.c error.c -o Piranha
  
  powershell write-host -fore green Compiled
  
  echo Press any key to Exit...
  time 9999 > NUL
  
  EXIT /B 0
