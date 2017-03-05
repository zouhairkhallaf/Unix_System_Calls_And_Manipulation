#include <fcntl.h> /* for open() */
#include <sys/stat.h> /* for file access permission bits */
#include <stdio.h> /* for FILENAME_MAX */
#include <unistd.h> /* for pathconf() */
#include <string.h> /* for strcat() */
#include <stdlib.h> /* for malloc() */
#include <errno.h> /* for errno */
int main(int argc, char *argv[])
{
   // char *newpath="link.c";
    char *newpath="/Users/zouhairkhallaf/Desktop/Lecture_5_TESTS/created_from_readlink_exe_.txt";
    int n=symlink("/Users/zouhairkhallaf/Desktop/Just_for_testing/test.txt", newpath);
    printf("Function symlink() returned with %d\n", n);
    char buf[100];
    //int m=readlink("/Users/awise/Stevens/Lecture5/link.c",buf, 100);
    int m=readlink(newpath, buf, 4096);
    printf("The contents of symlink %s is %s.\n", newpath, buf);
    printf("%s\n", strerror(errno));
    return 0;
}
