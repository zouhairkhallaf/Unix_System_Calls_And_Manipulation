#include <stdio.h>      /* for printf()       */
#include <string.h>     /* for strcmp()       */
#include <stdbool.h>    /* for true and false */
#include <stdlib.h>     /* for atexit()       */

char *Input(void) ;
void Wrapper(void);
bool Success(char *(*function)(void));

int main(void)
{
    char *(*function)(void)=&Input;
    void (*ptr)(void)=&Wrapper;
    bool status;
    int exit_status;
    char *result=(*function)();
    
    printf("%s\n", result);
    
    exit_status=atexit(ptr);
    
    printf("Exit status: %d\n", exit_status);
    
    status=Success(function);
    
    return 0;
}

char *Input(void)
{
    char *x="Adriana Wise";
    return x;
}

void Wrapper(void)
{
    char *y;
    y=Input();
}

bool Success(char *(*function)(void))
{
    char *y=(*function)();
    if (strcmp(y, "Adriana Wise")==0)
    {
        printf("Hello, %s\n", y);
        return true;
    }
    else
    {
        printf("Good bye, %s\n", y);
        return false;
    }
}