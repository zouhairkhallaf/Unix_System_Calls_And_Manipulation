
//The following code returns the name of my machine:


#include <unistd.h> /* for gethostname() */
#include <stdio.h> /* for printf() */
#include <limits.h> /* for _POSIX_HOST_NAME_MAX */

int main(void)
{
    int n;
    char *sys_name;
    n=gethostname(sys_name, _POSIX_HOST_NAME_MAX);
    
    printf("Hostname: %s\n", sys_name);
    
    return 0;
}