#include "apue.h"
#include <time.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>  //For open()
#include <limits.h> //PATH_MAX
#include <sys/types.h>
#include <sys/stat.h>


const char * FormatTime(time_t rawtime);
void show_properties(const char * file_name);

int main(void) {
    
    int fd;
    char fname[PATH_MAX];
    static char template[] = "/tmp/myfileXXXXXX";
    
    
    strcpy(fname, template); // copy static string into the char array.
    fd = mkstemp(fname);     // File descriptor
   
    printf("\n> Create a unique pathfname AND print that unique pathfname:\t%s\n",fname);
    
    printf("> Create TEMP file with Read and Write permissions:");
    if (fd !=  2 && fd !=  1 && fd !=  0 )
        printf("\t\tDONE succesfully \n");
    else
        printf("\t\tERROR UNsuccesful \n");
    
    printf("> Check if TEMP file created succesfully:");
    if (fd !=  2 && fd !=  1 && fd !=  0 )
        printf("\t\t\tYES, mkstemp() functions succeeded fd = %d\n", fd);
    else
        printf("\t\t\tNO, mkstemp() function failed\n");
    
    printf("> Check if TEMP file Exist: ");
    if( access( fname, F_OK ) != -1 )
        printf("\t\t\t\t\tYES, File exist\n");
    else
        printf("\tNO, File DOES NOT exist\n");
    
    printf("> Print current time to make sure the string is formated: ");
    const char * current_time = FormatTime(time(NULL));
    printf("\t%s the size of the string is %lu\n" , current_time, strlen(current_time));

    //printf("> Print properties of the TEMP file BEFOR:\n"); //By uncomenting this line we can see the infos of the file right after creation and before adding the line
    //show_properties(fname);                                 // For some reasons this needs to be uncomented for the write to act on the temp file.
   
    
    printf("> Open the file using open(fname, O_RDWR|O_APPEND) function:");
    int opened_file = open(fname, O_RDWR|O_APPEND);
  
    if (opened_file >= 0)
        printf("\tDONE succesfully fd = %d\n", opened_file);
    else
        printf("\tERROR UNsuccesful\n");
    
    // WRITING
     printf("> Run the write() function:");
    int result = write(fd, current_time, strlen(current_time));
    if ( result == -1)
        printf("\t\t\t\t\tERROR CODE resutls =%zd but original = %d\n", result, opened_file);
    else
        printf("\t\t\t\t\tWrite() Succedded\n");

    printf("> Print properties of the TEMP file AFTER:\n");
    show_properties(fname);
    
    //Read the file back to make sure the date is there
    printf("> Read the file to make sure the date is there: ");
    char buff[128];
    read(opened_file, buff, 12);
    printf("\t\t%s\n\n", buff);
    
    exit(0);
}



const char * FormatTime(time_t rawtime) {
    struct tm *info;
    char buffer[80];
    time(&rawtime);                             /* sets to current time */
    info=localtime(&rawtime);
    strftime(buffer, 80, "%b %d %H:%M", info);
    //printf("Formatted date & time : | %s |\n", buffer);
    char * current_time = buffer;
    return current_time;
}

void show_properties(const char * fname){
    int i;
    struct stat buf;
    char *ptr;
    if (lstat(fname, &buf)<0)
        printf("lstat() error\n\n");
    if (S_ISREG(buf.st_mode))
        ptr="Regular";
    else if (S_ISDIR(buf.st_mode))
        ptr="Directory";
    else if (S_ISCHR(buf.st_mode))
        ptr="Charachter special";
    else if (S_ISBLK(buf.st_mode))
        ptr="Blk special";
    else if (S_ISFIFO(buf.st_mode))
        ptr="FIFO";
    else if (S_ISLNK(buf.st_mode))
        ptr="Symbolic link";
    else if (S_ISSOCK(buf.st_mode))
        ptr="Socket";
    else
        ptr="unknown mode";
    printf("\n");
    printf("\t\t|-------------------------------------------------------|\n");
    printf("\t\t| File fname \t\t\t    |%s\n", fname);
    printf("\t\t|-------------------------------------------------------|\n");
    printf("\t\t| File type \t\t\t    | %s\n", ptr);
    printf("\t\t| File Size \t\t\t    | %lld bytes\n",buf.st_size);
    printf("\t\t| File inode\t\t\t    | %llu\n",buf.st_ino);
    printf("\t\t| Number of Links\t\t    | %d\n",buf.st_nlink);
    printf("\t\t| File Permissions \t\t    |");
    printf( (S_ISDIR(buf.st_mode))  ? "d" : "-");
    printf( (buf.st_mode & S_IRUSR) ? "r" : "-");
    printf( (buf.st_mode & S_IWUSR) ? "w" : "-");
    printf( (buf.st_mode & S_IXUSR) ? "x" : "-");
    printf( (buf.st_mode & S_IRGRP) ? "r" : "-");
    printf( (buf.st_mode & S_IWGRP) ? "w" : "-");
    printf( (buf.st_mode & S_IXGRP) ? "x" : "-");
    printf( (buf.st_mode & S_IROTH) ? "r" : "-");
    printf( (buf.st_mode & S_IWOTH) ? "w" : "-");
    printf( (buf.st_mode & S_IXOTH) ? "x" : "-");
    printf ("\n");
    printf("\t\t|-------------------------------------------------------|\n\n");

}