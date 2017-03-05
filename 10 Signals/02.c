#include <sys/types.h> /* for fork() */
#include <unistd.h> /* for fork() */
#include <stdio.h> /* for putc() */
#include <string.h> /*for strlen() */
static void STDOutput(char *string);
int main(void)
{
    pid_t pid;
    pid=fork();
    if (pid==0) /* child process */
    {
        STDOutput("Output from the child.\n");
    }
    else
    {
        STDOutput("Output from the parent.\n");
    }
    return 0;
}
static void STDOutput(char *string)
{
    char *ptr;
    int c;
    int n=strlen(string);
    setbuf(stdout, NULL);
    for (ptr=&string[0]; ptr!=&string[n]; ptr++)
    {
        c=*ptr;
        putc(c, stdout);
        sleep(2);
    }
}