#include <fcntl.h>      /* for open()                       */
#include <sys/stat.h>   /* for file access permission bits  */
#include <stdio.h>      /* for FILENAME_MAX                 */
#include <unistd.h>     /* for pathconf()                   */
#include <string.h>     /* for strcat()                     */
#include <stdlib.h>     /* for malloc()                     */
#include <errno.h>      /* for errno                        */

int getChar(int filedes);
int getBytePosition(int row, int filedes);
void putChar(int filedes, char c, off_t byte);

int main(int argc, char *argv[])
{
    off_t curr_byte;
    ssize_t num_bytes;
    char buf[200];
    int row=3;
    char *path_name="/Users/awise/Stevens/Lecture2/books.txt";
    int fd=open(path_name, O_CREAT|O_RDWR);
    
    /* 0 bytes from current offset to find current offset */
        curr_byte=lseek(fd, 0, SEEK_SET);
        printf("Cursor is at the %lldth byte.\n", curr_byte);
    
    /* 0 bytes from EOF to find the number of bytes in file */
        num_bytes=lseek(fd, 0, SEEK_END);
        printf("The file has %zd bytes.\n", num_bytes);
    
    /* 0 bytes from current offset to find current offset */
        curr_byte=lseek(fd, 0, SEEK_SET);
        printf("Cursor is at the %lldth byte.\n", curr_byte);
    
    /* Read file contents, knowing total bytes in the file */
        ssize_t read_bytes=read(fd, buf, num_bytes);
        printf("Reading %zd bytes.\n", read_bytes);
        printf("Reading --->%s<---.\n", buf);
    
    /* Output the contents of buffer onto terminal */
        ssize_t written_bytes=write(1, buf, read_bytes);
        printf("Writing %zd bytes.\n", written_bytes);
        printf("Writing --->%s<---.\n", buf);
    
    /* Get the byte # at beginning of specified row */

        off_t b=(off_t)getBytePosition(row, fd);
        printf("Byte number at row %d is %lld.\n", row, b);
        putChar(fd, '\n', b);
        putChar(fd, 'X', b+1);
    
    return 0;
}

/* Returns the byte # at the beginning of specified row # */
int getBytePosition(int row, int filedes)
{
    printf("In getBytePosition()...\n");
    char buf[200];
    int i;
    
    /* Find the total number of bytes in file */
    ssize_t num_bytes=lseek(filedes, 0, SEEK_END);
    printf("num_bytes=%zd\n", num_bytes);
    
    /* IMPORTANT! Bring cursor back to BOF */
    lseek(filedes, 0, SEEK_SET);
    ssize_t read_bytes=read(filedes, buf, num_bytes);
    printf("read_bytes=%zd\n", read_bytes);
    int num_rows=1;
    
    /* Loop goes through the number of bytes in the file */
    for (i=0; i<num_bytes; i++)
    {
        printf("buf[%d]=%c\n", i, buf[i]);
        /* On EOL character, we increment the row # */
        if (buf[i]=='\n')
        {
            printf("***EOL\n");
            num_rows++;
            /* If row # equals row specified, ret. byte # */
            if (num_rows==row)
                return i;
        }
    }
    return -1;
}

/* Writes a character into a file at specified byte */
void putChar(int filedes, char c, off_t byte)
{
    lseek(filedes, byte, SEEK_SET);
    /* The write starts at the current offset */
    write(filedes, &c, 1);
}
