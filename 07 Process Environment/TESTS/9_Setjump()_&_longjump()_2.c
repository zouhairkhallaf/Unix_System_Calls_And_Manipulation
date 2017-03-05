#include <stdio.h>
#include <setjmp.h>
#include <limits.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
char *EnterName(void);
char *Success(char *(*ptrEnterName)(void));
void Failure(char *);
char *RemoveEOL(char *string);
char *myname;
int main(int argc, char** argv)
{
    jmp_buf array;
    char *(*ptrEnterName)(void);
    ptrEnterName=&EnterName;
    if (setjmp(array)==0)
    {
        printf("In if branch.\n");
        myname=Success(ptrEnterName);
        printf("In if branch, %s\n", myname);
        longjmp(array, 1);
    }
    else
    {
        printf("In else branch!\n");
        Failure(myname);
    }
    return 0;
}
char *EnterName(void)
{
    printf("Enter name: ");
    char *line=malloc(20*sizeof(char));
    char *name=fgets(line, 20, stdin);
    name=RemoveEOL(name);
    printf("%s\n", name);
    return name;
}
char *Success(char *(*ptrEnterName)(void))
{
    char *result=(*ptrEnterName)();
    printf("%s\n", result);
    if (strncmp(result, "Adriana Wise", 20)==0)
    {
        printf("%s is the best\n", result);
    }
    return result;
}
void Failure(char *x)
{
    printf("Passed in --->%s<---\n", x);
    int len1=strlen(x);
    int len2=strlen("Adriana Wise");
    printf("%d vs. %d\n", len1, len2);
    if (strncmp(x, "Adriana Wise", strlen("Adriana Wise"))!=0)
        printf("Ooops. You're %s, not Adriana Wise!\n", x);
}
char *RemoveEOL(char *string)
{
    int len=strlen(string);
    if (string[len-1]=='\n')
        string[len-1]='\0';
    return string;
}