#include <stdio.h>
int main(void)
{
    extern char **environ;
    char **iterator;
    for (iterator=&environ[0]; *iterator!=NULL; iterator++)
    {
        printf("%s\n", *iterator);
    }
    return 0;
}
