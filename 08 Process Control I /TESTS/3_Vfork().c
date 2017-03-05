#include <unistd.h> /* for read(), write() */
#include <fcntl.h> /* for open() */
#include <string.h> /* for strlen() */
#include <stdio.h> /* for printf() */
#include <stdlib.h> /* for calloc() */
#define BUFFSIZE 4096
#define FILESIZE 1474560
void Input(int);
int main(int argc, char *argv[])
{
    int fd=open("file2.txt",O_CREAT|O_RDWR|O_APPEND, S_IRUSR|S_IWUSR);
    int ret=vfork();
    if (ret==0)
    {
        Input(fd);
        exit(0);
    }else
        Input(fd);
    return 0;
}
void Input(int filedes)
{
    char **name=calloc(3, 20*sizeof(char));
    char **it;
    name[0]="Adriana Wise\n";
    name[1]="Richard Stevens\n";
    name[2]="Evi Nemeth\n";
    for (it=&name[0]; *it!=NULL; it++)
    {
        ssize_t num_bytes=write(filedes, *it, strlen(*it));
        sleep(2);
    }
}