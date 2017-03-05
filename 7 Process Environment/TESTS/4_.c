#include <stdio.h>
#include <stdlib.h>
void my_exit1(void);
void my_exit2(void);

int main(void)
{
    void (*ptr1)(void)=&my_exit1;
    void (*ptr2)(void)=&my_exit2;
    int status1=atexit(ptr1);
    int status2=atexit(ptr2);
    if (status2!=0)
        printf("Uh-oh. Can't register my_exit2().\n");
    if (status1!=0)
        printf("Grrr. Can't register my_exit1(), either.\n");
    printf("End of main().\n");
    return(0);
}

void my_exit1(void)
{
    printf("My 1st exit handler.\n");
}

void my_exit2(void)
{
    printf("My 2nd exit handler.\n");
}