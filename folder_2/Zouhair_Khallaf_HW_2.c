#include <fcntl.h>      /* for open()                       */
#include <sys/stat.h>   /* for file access permission bits  */
#include <stdio.h>      /* for FILENAME_MAX                 */
#include <unistd.h>     /* for pathconf()                   */
#include <string.h>     /* for strcat()                     */
#include <stdlib.h>     /* for malloc()                     */
#include <errno.h>      /* for errno                        */

int getChar(int filedes);
off_t getBytePosition(int row, int filedes);
void putChar(int filedes, char c[], off_t byte,  size_t size );

int main(int argc, char *argv[])
{
    //TARGET
    
    off_t curr_byte;
    ssize_t num_bytes;
    char buf[2000];
    int row;
    char *path_name="books.txt";
    
    printf("\n\t.The new book is named : ZOUHAIR_KHALLAF BOOK_NUMBER007\n");
    printf("\t.My Books are 20 lines of records\n");
    printf("\n\t.PLEASE ENTER THE ROW NUMBER (between 1 and 20) TO SUBSTITUTE: ");
    scanf ("%d",&row);
    int fd=open(path_name, O_CREAT|O_RDWR);
    
    printf("\n");
    
    /* 0 bytes from current offset to find current offset */
    printf("/*0 bytes from current offset to find current offset */\n");
    curr_byte=lseek(fd, 0, SEEK_SET);
    printf("Cursor is at the %lldth byte.\n\n", curr_byte);
    
    /* 0 bytes from EOF to find the number of bytes in file*/
     printf("/*0 bytes from EOF to find the number of bytes in file */\n");
     num_bytes=lseek(fd, 0, SEEK_END);
     printf("The file has %zd bytes.\n\n", num_bytes);
    
    /* 0 bytes from current offset to find current offset */
    printf("/*0 bytes from current offset to find current offset */\n");
    curr_byte=lseek(fd, 0, SEEK_SET);
    printf("Cursor is at the %lldth byte.\n\n", curr_byte);
    
    /* Read file contents, knowing total bytes in the file */
    printf("/*Read file contents, knowing total bytes in the file */\n");
    ssize_t read_bytes=read(fd, buf, num_bytes);
    printf("Reading %zd bytes.\n\n", read_bytes);
    printf("Reading --->\n%s<---.\n\n\n", buf);
    
    /* Output the contents of buffer onto terminal */
    printf("/*Output the contents of buffer onto terminal */\n");
    ssize_t written_bytes=write(1, buf, read_bytes);
    printf("\n\nWriting %zd bytes.\n\n", written_bytes);
    printf("Writing --->\n%s<---.\n\n", buf);

    
    /* Get the byte # at beginning of specified row */
    printf("/*Get the byte # at beginning of specified row */\n");
    off_t b = getBytePosition(row, fd);
    if (b == -1){
        printf("\n ERROR : UNSUCCESFUL getBytePotition\n");
    }else{
        printf("\nSuccesful getBytePotition\n");
        printf("The starting Byte index of row %d is %lld.\n", row, b+1);
        //putChar(fd, '\n', b);
        
        
        char new_record[]="ZOUHIAR_KHALLAF BOOK_NUMBER007\n";
        printf("\nsizeof(new_record): %zu\n",sizeof(new_record));
        size_t size = sizeof(new_record);
        putChar(fd, new_record, b+1, size);
    }
    close(fd);
    return 0;
}

/* Returns the byte # at the beginning of specified row # */
off_t getBytePosition(int row, int filedes)
{
    printf("In getBytePosition()...\n");
    char buf[2000];
    //int i;

    /* Find the total number of bytes in file */
    ssize_t num_bytes=lseek(filedes, 0, SEEK_END);
    printf("num_bytes=%zd\n", num_bytes);
    
    /* IMPORTANT! Bring cursor back to BOF */
    lseek(filedes, 0, SEEK_SET);
    ssize_t read_bytes=read(filedes, buf, num_bytes);
    printf("read_bytes=%zd\n", read_bytes);
    int num_rows=1;
    
    /* Loop goes through the number of bytes in the file */
    for (int i=0; i<num_bytes; i++)
    {
        printf("row: %d \t ", num_rows);
        printf("buf[%d]=%c\n", i, buf[i]);
        /* On EOL character, we increment the row # */
        if (buf[i]=='\n')
        {
            printf("***EOL\n");
            num_rows++;
            
            /* If row # equals row specified, ret. byte # */
            if (num_rows == row){
                printf("ATTENTION THE ROW SPECIFIED IS DETECTED");
                return i;
            }
        }
    }
    return -1;
}

/* Writes a character into a file at specified byte */
void putChar(int filedes, char c[], off_t byte, size_t size)
{
    lseek(filedes, byte, SEEK_SET);
    /* The write starts at the current offset */
    printf("The new record to write is: %s \n", c );
    printf("Write will start writing from %lld adding %zd characters, and will finish at the %lld's Byte\n", byte , size , byte+size );
    write(filedes, c, strlen(c));
    
}













