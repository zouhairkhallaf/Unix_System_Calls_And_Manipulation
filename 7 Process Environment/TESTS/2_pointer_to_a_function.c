#include <stdio.h>
#include <string.h>
#include <stdbool.h>

char *Input(void);

void Success(char *(*function)(void));

int main(void)
{
    char *(*function)(void)=&Input;
    char *result=(*function)();
    printf("%s\n", result);
    Success(function);
    return 0;
}

char *Input(void)
{
    char *x="Adriana Wise";
    return x;
}

void Success(char *(*function)(void))
{
    char *y=(*function)();
    if (strcmp(y, "Adriana Wise")==0)
        printf("Hello, %s\n", y);
    printf("Good bye, %s\n", y);
}