/*
FILE PERMITIONS : st_mode mask :
USER-READ  : S_IRUSR  | USER-WRITE : S_IWUSR  |  USER-EXECUTE : S_IXUSR
GROUP-READ : S_IRGRP  | GROUP-WRITE: S_IWGRP  |  GROUP-EXECUTE: S_IXGRP
OTHER-READ : S_IROTH  | OTHER-WRITE: S_IWOTH  |  OTHER-EXECUTE: S_IXOTH

 The "access()" function ACCESSES, it s a GETTER
 The "umask()"  function SETTER,   it SETTS the t_mode
 
*/

#include <fcntl.h>      /* for creat() */
#include <sys/stat.h>   /* for the file permission bits */
#include <stdio.h>      /* for printf() */
#include <unistd.h>

#define RWXRWXRWX (S_IRUSR|S_IWUSR|S_IXUSR|S_IRGRP|S_IWGRP|S_IXGRP|S_IROTH|S_IWOTH|S_IXOTH)

int main(void)
{
    umask(0);
    
    if (creat("umask_created.txt", RWXRWXRWX)<0)
        printf("creat() error for \"foo\"\n");
    access()
    umask(S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH);
    
    if (creat("bar", RWRWRW)<0)
        printf("creat() error for \"bar\"\n");
    return 0;
}



