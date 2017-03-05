#include <unistd.h>
#include <sys/stat.h> /* for the file permission bits */
#include <stdio.h> /* for printf() */
#define XXX (S_IXUSR | S_IXGRP | S_IXOTH)

int main(int argc, char* argv[])
{
    struct stat statbuf;
    
    if (stat(argv[1], &statbuf)<0)
        printf("stat() error for \"foo\"\n");
    
    /* turn on user execute, group execute, and others execute */

    if (chmod(argv[1], (statbuf.st_mode | XXX))<0)
        printf("chmod() error for \"foo\"\n");
    
    return 0;
}