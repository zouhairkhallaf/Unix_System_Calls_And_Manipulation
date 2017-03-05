/*
FILE PERMITIONS : st_mode mask :
USER-READ  : S_IRUSR  | USER-WRITE : S_IWUSR  |  USER-EXECUTE : S_IXUSR
GROUP-READ : S_IRGRP  | GROUP-WRITE: S_IWGRP  |  GROUP-EXECUTE: S_IXGRP
OTHER-READ : S_IROTH  | OTHER-WRITE: S_IWOTH  |  OTHER-EXECUTE: S_IXOTH

A nice way to easily code the permitions:

#define RWRWRW (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)
//now we can just write something like : if (creat("foo", RWRWRW)<0)
*/


#include <sys/stat.h>
#include <stdio.h>

int main(void)
{
    printf("-----------------------------------------\n");
    printf("|\tS_IRUSR\t\t|\t%o\t|\n", S_IRUSR);
    printf("|\tS_IWUSR\t\t|\t%o\t|\n", S_IWUSR);
    printf("|\tS_IXUSR\t\t|\t%o\t|\n", S_IXUSR);
    printf("|\tS_IRGRP\t\t|\t%o\t|\n", S_IRGRP);
    printf("|\tS_IWGRP\t\t|\t%o\t|\n", S_IWGRP);
    printf("|\tS_IXGRP\t\t|\t%o\t|\n", S_IXGRP);
    printf("|\tS_IROTH\t\t|\t%o\t|\n", S_IROTH);
    printf("|\tS_IWOTH\t\t|\t%o\t|\n", S_IWOTH);
    printf("|\tS_IXOTH\t\t|\t%o\t|\n", S_IXOTH);
    printf("-----------------------------------------\n");
    return 0;
}


//COMPILE N RUN TESTED