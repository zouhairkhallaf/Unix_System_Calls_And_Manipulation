#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pwd.h>
#include <dirent.h>
#include <grp.h>
#include <time.h>

int main(int argc, char* argv[])
{
    DIR *mydir;
    struct dirent *myfile;
    struct stat mystat;

    char buf[512];
    mydir = opendir(argv[1]);
    while((myfile = readdir(mydir)) != NULL)
    {
        sprintf(buf, "%s/%s", argv[1], myfile->d_name);
        stat(buf, &mystat);
        
        //File permissions: PARTIALLY DONE WE NEED @ +r symbols
        printf( (S_ISDIR(mystat.st_mode))  ? "d" : "-");
        printf( (mystat.st_mode & S_IRUSR) ? "r" : "-");
        printf( (mystat.st_mode & S_IWUSR) ? "w" : "-");
        printf( (mystat.st_mode & S_IXUSR) ? "x" : "-");
        printf( (mystat.st_mode & S_IRGRP) ? "r" : "-");
        printf( (mystat.st_mode & S_IWGRP) ? "w" : "-");
        printf( (mystat.st_mode & S_IXGRP) ? "x" : "-");
        printf( (mystat.st_mode & S_IROTH) ? "r" : "-");
        printf( (mystat.st_mode & S_IWOTH) ? "w" : "-");
        printf( (mystat.st_mode & S_IXOTH) ? "x" : "-");
        printf (" ");
        
        //Number of links: DONE
        printf("%4d",mystat.st_nlink);
        printf (" ");

        //Owner name: DONE
        struct passwd *pass_struct_ptr;
        pass_struct_ptr = getpwuid(mystat.st_uid);
        printf("%s", pass_struct_ptr->pw_name);
        printf (" ");

        //Owner group: DONE
        struct group *grp_struct_ptr;
        grp_struct_ptr = getgrgid(mystat.st_gid);
        printf("%s", grp_struct_ptr->gr_name);
        printf (" ");

        //File size:
        printf("%7lld",mystat.st_size);
        printf (" ");

        //Time of last modification:
        char some_buff[20];
        //time_t now = time(&mystat.st_ctime);
        strftime(some_buff, 20, " %b  %d %H:%M  ", localtime(&(mystat.st_ctime)));
        printf ("%s", some_buff);

        //File/directory name:
        printf("%s", myfile->d_name);
        printf (" ");

        // End of a line:
        printf("\n"); 
        
    }
    closedir(mydir);
}
