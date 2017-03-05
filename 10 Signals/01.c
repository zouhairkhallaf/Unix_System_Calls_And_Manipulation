#include <unistd.h> /* for read(), write() */
#include <fcntl.h>  /* for open()  */
#include <string.h> /* for strlen()*/
#include <stdio.h>  /* for printf()*/
#include <stdlib.h> /* for calloc()*/
#define BUFFSIZE 4096
#define FILESIZE 1474560
void Input(int, char *);
int main(int argc, char *argv[])
{
    int fd=open("/Users/zouhairkhallaf/Desktop/testFile.txt", O_CREAT|O_RDWR|O_APPEND, S_IRUSR|S_IWUSR);
    int pid=fork();
    char *process;
    if (pid==0) /* child process */
    {
        process="Child process:\n";
        Input(fd, process);
        while (getppid()!=1) /* while parent's parent is not init */
            sleep(2);
    }
    else /* parent process */
    {
        process="Parent process:\n";
        Input(fd, process);
    }
    return 0;
}
void Input(int filedes, char *which)
{
    write(filedes, which, strlen(which));
    char **name=calloc(3, 20*sizeof(char));
    char **it;
    name[0]="Adriana Wise\n";
    name[1]="Richard Stevens\n";
    name[2]="Evi Nemeth\n";
    for (it=&name[0]; *it!=NULL; it++)
    {
        ssize_t num_bytes=write(filedes, *it, strlen(*it));
    }
}