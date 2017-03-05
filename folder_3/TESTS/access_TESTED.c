#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
int main(int argc, char *argv[])
{
    if (argc!=2)
        printf("Usage: ./a.out <pathname>\n");
    if (access(argv[1], R_OK | X_OK)<0)
        printf("Access error for %s\n", argv[1]);
    else
        printf("Read access OK.\n");
    if (open(argv[1], O_RDONLY)<0)
        printf("Open error for %s\n\n", argv[1]);
    else
        printf("Open for reading OK.\n");
    return 0;
}