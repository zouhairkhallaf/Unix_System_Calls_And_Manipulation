# UNIX System Programming
An introduction to the key components of the UNIX application programming interface, including files, processes, terminal control, signals, interprocess communication, the ncurses library, and multi-threading. Includes basic of the internal structure of the UNIX operating system, and selected user-level utilities and commands for efficient programming and working in UNIX

##Objectives
    1. How to write programs on and for a UNIX platform.
    2. How to work efficiently within the UNIX environment. 
    3. How UNIX is designed and structured.
    4. To examine the most important parts of the UNIX operating system's application programming interface (API).
    5. To examine the command level view of UNIX. 
    6. To expose the internal structure of the UNIX operating system.

----------------
##PROGRAMS
1. Creates a file and writes your name in it, taking your name as input from the command line. It should use the system functions creat() and write(). For the synopsis of these functions, consult section 2 of the man pages on your system. Then, adapt the ./mycp program from earlier, to copy your newly created file into another file, without the redirect operators. To to that, you need to pass the source and the target files as command line arguments to your program.<br>
> **Please check the following programs**
<br>
    * _HW_creatNwrite.cpp_
    * _HW_Copy_A_File.c_
    * _Makefile_
2. This system program  replaces or inserts a row in a <file> name books.txt here. You can specify your own row number as the row that needs to be replaced. You can supply your own record (for instance, your favorite book and its author). The books.txt file contains book records, each with two fields: a book title field (with no blank spaces in it) and an author field (again, with no blank spaces in it). You should be able to replace the record at the row number specified, with your own.
>>Ex Input:       Aaron_David     Book_number_06
>
>>Becomes :       fname_Lname     Book_number_00
>
    * _CHECK THE FOLLOWING PROGRAMS_
    * **HW_creatNwrite.cpp**

3. This system program 
    1. Illustrates the use of the chown() system call on a file.
    2. Displays all the information from the stat structure about a file in a “formatted” table, with the constant names on the left, and their binary values on the right. In particular, the st_mode member of the stat structure, which encodes the file type and the permissions mode, should be broken down into the values of its components, given that each bit has a meaning. List the meanings of each bit of st_mode and its values for your file. Convert into binary using the % operator on the octal value of st_mode, then test against the values obtained by selecting each bit using bitwise operations. 
    3. There are 16 bits for st_mode (no two leading 0 bits as in the mask examples):
        1. 1 for set-user-ID
        2. 1 for set-group-ID
        3. 1 for the sticky bit
        4. 4 for the file type
        5. 9 for access permissions
    
    * _CHECK THE FOLLOWING PROGRAMS_
    *  **HW_creatNwrite.cpp**

4. Copy, adapt, and compile the program that traverses a file hierarchy from Chapter 4, Files and Directories. Taking as input a starting pathname, the program descends the file hierarchy from that point, and returns how many files of each of the seven types there are, and what percentage of the total that represents. (You will need to (re)visit Chapter 2, UNIX Standardizations and Implementations, and create a *.c and a *.h file for path_alloc().)
    * _CHECK THE FOLLOWING PROGRAMS_
    * **HW_creatNwrite.cpp**

5. Write a cron job that appends the current date and time into a temporary file. The output should be in a formatted table.
    * _CHECK THE FOLLOWING PROGRAMS_
    * **HW_creatNwrite.cpp**
6. PROGRAM5.c
    1. Write a program that finds all users on a system. You should test for a large
number of UID numbers, since no function returns that information wholesale.
    2. Modify the program that returns supplementary GIDs for a user to also list
these groups’ names
    * _CHECK THE FOLLOWING PROGRAMS_
    * **HW_creatNwrite.cpp**
7. Write an example program showing the use of setjmp() and longjmp() across two function calls. You should have two functions, one of which calls the other function. Add and set a string array variable for each function, changing its value. Write a function that prints the string array from within each function. Show what happens to the array upon return from the longjmp().
    * _CHECK THE FOLLOWING PROGRAMS_
    * **HW_creatNwrite.cpp**
8. Add functionality to this program to print the error messages associated with the
numeric termination status values from <signal.h>. Also add functionality to
print the values of the members of struct rusage, which will get filled in by
calling wait3(). Check these entries with man 2.
    * _CHECK THE FOLLOWING PROGRAMS_
    * **HW_creatNwrite.cpp**
9. Write a simple program showing the system call sigsuspend(). Your program should initialize three sets of signals (oldset, newset, waitset) to the empty set, using sigemptyset(). It should then add a few signals to this set, using sigaddset(). It should contain a signal handler, which you can design to be shared across the few signals you have added to your set. You should then specify a set of blocked signals, using sigprocmask(). The signals you want triggered and handled, you should set, and establish handler(s) for, using either signal() or sigaction(). Then, you want the signals in the blocked mask to suspend until the signals from the wait mask are triggered and return from their handler, using sigsuspend(). After the signals in the wait mask have been delivered and handled, unblock the suspended signals using sigprocmask() again. Insert printouts of every point in your program where you can show the signal sets, where the signals are raised, and where the suspended signals get unblocked.
    * _CHECK THE FOLLOWING PROGRAMS_
    * **HW_creatNwrite.cpp**
10. ls -al   
    * _CHECK THE FOLLOWING PROGRAMS_
    * **HW_creatNwrite.cpp**
11. WRITE YOU OWN SHELL :  My-Shell
    * _CHECK THE FOLLOWING PROGRAMS_
    * **HW_creatNwrite.cpp**
