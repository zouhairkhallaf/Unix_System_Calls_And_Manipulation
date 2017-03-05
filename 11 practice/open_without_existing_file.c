#include <fcntl.h> /* for open()    */
#include <stdio.h> /* for printf()  */

int main(int argc, char *argv[])
{
    char *filename= "/Users/zouhairkhallaf/Desktop/zouzou.txt";
    int fd=open(filename, O_RDWR|O_CREAT); //The Only line that changes 
    printf("File descriptor fd=%d\n", fd);
}















