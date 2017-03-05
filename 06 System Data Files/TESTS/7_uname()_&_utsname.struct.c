/*
 The following code lists information about my system, printing out values of the members of the utsname structure
 */
#include <sys/utsname.h>    /* for uname() */
#include <stdio.h>          /* for printf() */
#include <stdlib.h>         /* for malloc() */

int main(void)
{
    struct utsname ptr;
    int n = uname(&ptr);
    
    printf("OS:     %50s\n", ptr.sysname);
    printf("node:   %50s\n", ptr.nodename);
    printf("release:%50s\n", ptr.release);
    printf("version:%50s\n", ptr.version);
    printf("machine:%50s\n", ptr.machine);
    
    return 0;
}