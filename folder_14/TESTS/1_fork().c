#include <unistd.h> /* for fork() */
#include <stdio.h> /* for printf() */
#include <sys/types.h> /* for getpid() */
int global=6;
char buf[]="Hi, class!\n";

int main(void)
{
    int var;
    pid_t ret;
    var=88;
    
    if (write(STDOUT_FILENO, buf, sizeof(buf)-1)!= sizeof(buf)-1){
        printf("Error on write().\n");
    }
    
    printf("Before call to fork().\n");
    
    ret=fork();
    
    if (ret==0) /* child */
    {
        global++;
        var++;
        printf("Return value from fork() is ret=%d\n", ret);
        printf("pid=%d, global=%d, var=%d\n", getpid(), global, var);
    }
    else /* parent */
    {
        sleep(2);
        printf("Return value from fork() is ret=%d\n", ret);
        printf("pid=%d, global=%d, var=%d\n", getpid(), global, var);
    }
    
    return 0;
}