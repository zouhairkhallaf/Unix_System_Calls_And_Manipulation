########################################
##
## Makefile
## LINUX compilation 
##
##############################################

#FLAGS
#CFLAGS = -g -std=c++0x -Wall

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
ALL_OBJ0=Zouhair_Khallaf_HW_Lecture8_Question1.o
PROGRAM_0=Zouhair_Khallaf_HW_Lecture8_Question1
ALL_OBJ1=Zouhair_Khallaf_HW_Lecture8_Question2.o
PROGRAM_1=Zouhair_Khallaf_HW_Lecture8_Question2

$(PROGRAM_0): $(ALL_OBJ0)
	gcc $(CFLAGS) -o $(EXEC_DIR)/$@ $(ALL_OBJ0) $(INCLUDES) $(LIBS_ALL)
$(PROGRAM_1): $(ALL_OBJ1)
	gcc $(CFLAGS) -o $(EXEC_DIR)/$@ $(ALL_OBJ1) $(INCLUDES) $(LIBS_ALL)

#Compiling all
all: 	
		make $(PROGRAM_0) $(PROGRAM_1)

#Clean obj files

clean:
	(rm -f *.o;)
