# UNIX System Programming
An introduction to the key components of the UNIX application programming interface, including files, processes, terminal control, signals, interprocess communication, the ncurses library, and multi-threading. Includes basic of the internal structure of the UNIX operating system, and selected user-level utilities and commands for efficient programming and working in UNIX

##Objectives
1. How to write programs on and for a UNIX platform.
2. How to work efficiently within the UNIX environment. 
3. How UNIX is designed and structured.
4. To examine the most important parts of the UNIX operating system's application programming interface (API).
5. To examine the command level view of UNIX. 
6. To expose the internal structure of the UNIX operating system.

#####All lectures are from Hunter College CSci 493.66 Unix Tools Class I finished with A+ :)

##Programs

### 1. Introduction (Check Lecture 1)

Write a small system program that creates a file and writes your name in it,
taking your name as input from the command line. It should use the system
functions creat() and write(). For the synopsis of these functions, consult
section 2 of the man pages on your system. Then, adapt the ./mycp program
from earlier, to copy your newly created file into another file, without the
redirect operators. To to that, you need to pass the source and the target files as
command line arguments to your program.

**Please check the folder_1 it contains the folowing programs:**

**1. HW\_creatNwrite.cpp**

**2. HW\_Copy\_A\_File.c**

**3. Makefile**

>To run:

>$ make all

>$ ./HW_creatNwrite fileName.txt yourMessage

>$ ./HW_Copy_A_File copyThis.txt InThis.txt

### 2. File I/O (Check Lecture 2 and 3)

Write a C program that replaces or inserts a row in the books.txt file. You can specify your own row number as the row that needs to be replaced. You can supply your own record (for instance, your favorite book and its author). The books.txt file contains book records, each with two fields: a book title field (with no blank spaces in it) and an author field (again, with no blank spaces in it). You should be able to replace the record at the row number specified, with your own.

######Please Check the row number you want to change in books.txt before and after the change.

**Please check the folder_2 it contains the folowing programs:**

**1. Zouhair_Khallaf_HW_2.cpp**

**2. books.txt**

>To run:

>$ make all

>$ ./Zouhair_Khallaf_HW_2

### 3. Files and Directories I (Check Lecture 4)

Write a small program that illustrates the use of the chown() system call on a file. Write another program that displays all the information from the stat structure about a file in a “formatted” table, with the constant names on the left, and their binary values on the right. In particular, the st_mode member of the stat structure, which encodes the file type and the permissions mode, should be broken down into the values of its components, given that each bit has a meaning. List the meanings of each bit of st_mode and its values for your file. Convert into binary using the % operator on the octal value of st_mode, then test against the values obtained by selecting each bit using bitwise operations.

There are 16 bits for st\_mode (no two leading 0 bits as in the mask examples)

- 1 for set-user-ID

- 1 for set-group-ID

- 1 for the sticky bit

- 4 for the file type

- 9 for access permissions

**Please check the folder_3 it contains the folowing programs:**

**1. Zouhair_Khallaf_HW_3_PART_I_chown.c**

**2. Lecture 3.pdf**

**3. Lecture 4.pdf**

**4. README.txt** _Contains all instructions MUST READ_ 

**5. TESTED file contains tested components:**

- access_TESTED.c

- chmod_TESTED.c

- List_of_octal_permisions_TESTED.c

- lstat_TESTED.c

- shows_all_file_attributes_TESTED.c

### 4. Files and Directories II (Check Lecture 5)
 
Copy, adapt, and compile the program that traverses a file hierarchy from Chapter 4, Files and Directories. Taking as input a starting pathname, the program descends the file hierarchy from that point, and returns how many files of each of the seven types there are, and what percentage of the total that represents. (You will need to (re)visit Chapter 2, UNIX Standardizations and Implementations, and create a *.c and a *.h file for path_alloc().)

**Please check the folder_4 it contains the folowing programs:**

**1.Zouhair_Khallaf_HW_3.c**

**2. apue.h**

**3. dynamic_alloc.h**

**4. errors.h**

**5. Lecture 5.pdf**

**6. TESTED file contains tested components:**

- chdir.c

- link.c

- myspecialdev.c

- myunlink.c

- readlink.c

- timing.c

- unlink.c


### 5. Standard I/O Library (Check Lecture 6 and 7)

Write a cron job that appends the current date and time into a temporary file. The output should be in a formatted table.

**Please check the folder_5 it contains the folowing programs:**

**1. HW-creatNwrite.cpp**


### 6. System Data Files (Check Lecture 8)

First Write a program that finds all users on a system. You should test for a large number of UID numbers, since no function returns that information wholesale. Second Modify the program that returns supplementary GIDs for a user to also list these groups’ names

**Please check the folder_6 it contains the folowing programs:**

**1. HW-creatNwrite.cpp**


### 7. Process Environment (Check Lecture 9)

Write an example program showing the use of setjmp() and longjmp() across two function calls. You should have two functions, one of which calls the other function. Add and set a string array variable for each function, changing its value. Write a function that prints the string array from within each function. Show what happens to the array upon return from the longjmp().

**Please check the folder_7 it contains the folowing programs:**

**1. HW-creatNwrite.cpp**

### 8. Process Control I (Check Lecture 10 and 11)

Add functionality to this program to print the error messages associated with the numeric termination status values from <signal.h>. Also add functionality to print the values of the members of struct rusage, which will get filled in by calling wait3(). Check these entries with man 2.

**Please check the folder_8 it contains the folowing programs:**

**1. HW-creatNwrite.cpp**

### 9. Process Relationships (Check Lecture 12 and 13)

### 10. Signals (Check Lecture 14)

Write a simple program showing the system call sigsuspend(). Your program should initialize three sets of signals (oldset, newset, waitset) to the empty set, using sigemptyset(). It should then add a few signals to this set, using sigaddset(). It should contain a signal handler, which you can design to be shared across the few signals you have added to your set. You should then specify a set of blocked signals, using sigprocmask(). The signals you want triggered and handled, you should set, and establish handler(s) for, using either signal() or sigaction(). Then, you want the signals in the blocked mask to suspend until the signals from the wait mask are triggered and return from their handler, using sigsuspend(). After the signals in the wait mask have been delivered and handled, unblock the suspended signals using sigprocmask() again. Insert printouts of every point in your program where you can show the signal sets, where the signals are raised, and where the suspended signals get unblocked.

**Please check the folder_9 it contains the folowing programs:**

**1. HW-creatNwrite.cpp**


### Threads (Check Lecture 15)

### Threads Synchronization (Check Lecture 16)

### Threads Attributes (Check Lecture 17 and 18)

### Interprocess Communication (Check Lecture 19)

### Semaphores (Check Lecture 20)

Write a program using multiple semaphores in a semaphore set, and using semaphore values greater than 1. Have your program access a file for reading/writing as your shared resource.

### Network IPC: Sockets (Check Lecture 21)

### Program and Make your own ls-al command.

### program and make your own terminla like Shell.


