# Problem Description
Part 1 of the File System Scanner will take the lecture example of the File System Scanner, extend it to use getopt to process command line arguments, and stub out options to allow the user to specify sort and filter options from the commandline.

<br />
1. Modify the File System Scanner to use getopt() functionality
<br /><br />
Maintain existing functionality, however instead of directly reading an optional directory directly from argv[], add a "-d" option with an argument to getopt().  


**NOTE:** The following examples assume the code is running on the BoiseStateBudgie VM and that the user's home directory is /home/student.  If you are running on a different Linux Development Environment, such as onyx.boisestate.edu, please substitute the path to your home directory for testing.

Below is the expected -d usage:  

## Listing contents of student home directory using -d 
```
./myls -d /home/student
< too much output >
```
  
<br />
2. Add a "-s" option to enable/disable alphabetical sorting
<br /><br />

## List the contents of student home directory, sorted alphabetically
```
./myls -s -d /home/student
< too much output, but entries should be sorted alphabetically in ascending order >
```

## List the contents of the current directory, unsorted
```
./myls 
main.o
.vscode
.
..
main.c
Makefile
myls
```

## List the contents of the current directory, sorted alphabetically in ascending order
```
./myls -s
.
..
.vscode
Makefile
main.c
main.o
myls
```

<br />
3. Release allocated memory. The scandir allocates memory internally that must be freed by the caller to prevent memory leaks. Also make certain to close any files that were opened. Be certain to test all possible commandline enabled/disabled options.
<br /><br />

## Expected Valgrind Output 
```
valgrind --tool=memcheck --leak-check=yes --show-reachable=yes ./myls -s -d /usr/bin 

==154461== Memcheck, a memory error detector
==154461== Copyright (C) 2002-2017, and GNU GPL'd, by Julian Seward et al.
==154461== Using Valgrind-3.15.0 and LibVEX; rerun with -h for copyright info
==154461== Command: ./myls -s -d /usr/bin 

<<<<<<<< PROGRAM OUTPUT REMOVED >>>>>>>>

==154461== 
==154461== HEAP SUMMARY:
==154461==     in use at exit: 0 bytes in 0 blocks
==154461==   total heap usage: 1,575 allocs, 1,575 frees, 138,448 bytes allocated
==154461== 
==154461== All heap blocks were freed -- no leaks are possible
==154461== 
==154461== For lists of detected and suppressed errors, rerun with: -s
==154461== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)
```
