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
# .SUFFIXES : .cpp.o 

.cpp.o:
	g++ $(C++FLAG) $(INCLUDES)  -c $< -o $@

.c.o:
	gcc $(CFLAGS) $(INCLUDES)  -c $< -o $@

#Including
INCLUDES=  -I. 

#ZEROTH PROGRAM
ALL_OBJ0=HW_creatNwrite.o
PROGRAM_0=HW_creatNwrite
ALL_OBJ1=HW_Copy_A_File.o
PROGRAM_1=HW_Copy_A_File

$(PROGRAM_0): $(ALL_OBJ0)
	g++ $(C++FLAG) -o $(EXEC_DIR)/$@ $(ALL_OBJ0) $(INCLUDES) $(LIBS_ALL)
$(PROGRAM_1): $(ALL_OBJ1)
	gcc $(CFLAGS) -o $(EXEC_DIR)/$@ $(ALL_OBJ1) $(INCLUDES) $(LIBS_ALL)

#Compiling all
all: 	
		make $(PROGRAM_0) $(PROGRAM_1)

#Clean obj files

clean:
	(rm -f *.o;)
