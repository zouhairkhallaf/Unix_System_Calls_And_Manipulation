########################################
##
## Makefile
## LINUX compilation 
##
##############################################

#FLAGS
C++FLAG = -g -std=c++0x -Wall

#Math Library
MATH_LIBS = -lm
EXEC_DIR=.

#Rule for .cpp files
# .SUFFIXES : .c.o 

.c.o:
	gcc $(CFLAGS) $(INCLUDES)  -c $< -o $@

#Including
INCLUDES=  -I. 

#ZEROTH PROGRAM
ALL_OBJ0=Zouhair_Khallaf_HW_2.o
PROGRAM_0=Zouhair_Khallaf_HW_2

$(PROGRAM_0): $(ALL_OBJ0)
	gcc $(CFLAGS) -o $(EXEC_DIR)/$@ $(ALL_OBJ0) $(INCLUDES) $(LIBS_ALL)

#Compiling all
all: 	
		make $(PROGRAM_0)

#Clean obj files

clean:
	(rm -f *.o;)
