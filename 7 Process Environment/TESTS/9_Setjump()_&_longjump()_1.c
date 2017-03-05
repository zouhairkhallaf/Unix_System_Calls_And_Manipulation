#include <stdio.h>
#include <setjmp.h>
int main(int argc, char** argv)
{
    do
    {
        jmp_buf array;
        if (setjmp(array)==0)
        {
            printf("In if branch.\n");
            longjmp(array, 1);
            printf("I do not appear\n");
        }
        else
        {
            printf("In else branch!\n");
        }
    } while(0);
    return 0;
}