#include <stdio.h>
#include <setjmp.h>


// I will enumerate the lines so I can tell what line I am in

// Declaring out buffer
static jmp_buf buf;

// FUNCTION DECLARATION
void Second_Function (void);
void First_function(void);

int main() {
    printf("\n\t.Main():\"STARTING ...\"\t\t\t\t\tLINE 0\n");                                                           //Line 0
    printf("\n\t.Main():\"Executing setjmp(buf)\"\t\t\t\tLINE 1 and 2\n");                                              //Line 1
    int setjump_return = setjmp(buf);                                                                                   //Line 2
    printf("\n\t.Main():\"Checking if(!setjmp(buf))\"\t\t\tLINE 3\n");                                                  //Line 3
    printf("\t.Main():\"setjump(buff) returning %d now\"\t\t\tLINE 4 \n",setjump_return);                                //Line 4
    
    if (!setjump_return){                                                                                               //Line 5
        printf("\n\t.Main():\"IF statement is TRUE\t\t\t\tLINE 5 and 6\n");                                             //Line 6
        First_function();         // when executed, setjmp returns 0                                                    //Line 7
    }else{                        // when longjmp jumps back, setjmp returns 1                                          //Line 8
        printf("\n\t.Main():\"ELSE statement is TRUE\"\t\t\tLINE 9 and 10\n");                                          //Line 9
    }                                                                                                                   //Line 10
    printf("\t.Main():\"TERMINATING\"\t\t\t\t\tLINES 11 and 12\n\n");                                                   //Line 11
    return 0;                                                                                                           //Line 12
}

// FUNCTION DEFINITION
void First_function(void) {                                                                                             //Line 13
    printf("\t .FIRST  function called calling Second_Function()\tLINE 13, 14, and 15\n");                              //Line 14
    Second_Function();                                                                                                  //Line 15
    printf("\t .FIRST  function terminated.\t\t\tLINE 20\n");                                                           //Line 16
}
void Second_Function (void) {                                                                                           //Line 17
    printf("\t .SECOND function called executing longjmp(buf,1)\tLINE 17, 18, and 19\n");                               //Line 18
    longjmp(buf,1); // Jumps back to where setjmp was called - making setjmp now return 1                               //Line 19
    printf("\t .SECOND Function terminated.\t\t\tLINE 20\n");                                                           //Line 20
}