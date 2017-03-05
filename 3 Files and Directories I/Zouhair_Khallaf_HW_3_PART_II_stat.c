#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>

char* Convet_octal_toBinary(int octal);

int main(int argc, char *argv[])
{
    int i;
    struct stat buf;
    char *ptr;
    for (i=1; i<argc; i++)
    {
        if (lstat(argv[i], &buf)<0)
        {
            printf("lstat() error\n");
            continue;
        }
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
    }
    
    
        printf("\n");
        printf("|---------------------------------------------------------------------------------------|\n");
        printf("| File name \t\t\t    | %s\t|\n", argv[1]);
        printf("|---------------------------------------------------------------------------------------|\n");
        printf("| File type \t\t\t    | %s\n", ptr);
        printf("| File Size \t\t\t    | %lld bytes\n",buf.st_size);
        printf("| File inode\t\t\t    | %llu\n",buf.st_ino);
        printf("| Number of Links\t\t    | %d\n",buf.st_nlink);
        printf("| File Permissions \t\t    |");
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
        printf("|---------------------------------------------------------------------------------------|\n");
        printf("| Set-user-ID on execution  S_ISUID | %o\t\t| In binary: %s\t|\n", S_ISUID, Convet_octal_toBinary(S_ISUID));
        printf("| Set-group-ID on execution S_ISGID | %o\t\t| In binary: %s\t|\n", S_ISGID, Convet_octal_toBinary(S_ISGID));
        printf("|-----------------------------------|-------------------|-------------------------------|\n");
        printf("| Saved-text (sticky bit)   S_ISVTX | %o\t\t| In binary: %s\t|\n", S_ISVTX, Convet_octal_toBinary(S_ISVTX));
        printf("|-----------------------------------|-------------------|-------------------------------|\n");
        printf("| USER  read,write,execute  S_IRWXU | %o\t\t| In binary: %s\t\t|\n", S_IRWXU, Convet_octal_toBinary(S_IRWXU));
        printf("| USER  read  permission    S_IRUSR | %o\t\t| In binary: %s\t\t|\n", S_IRUSR, Convet_octal_toBinary(S_IRUSR));
        printf("| USER  write permission    S_IWUSR | %o\t\t| In binary: %s\t\t|\n", S_IWUSR, Convet_octal_toBinary(S_IWUSR));
        printf("| USER  exe   permission    S_IXUSR | %o\t\t| In binary: %s\t\t|\n", S_IXUSR, Convet_octal_toBinary(S_IXUSR));
        printf("|-----------------------------------|-------------------|-------------------------------|\n");
        printf("| Group  read,write,execute S_IRWXG | %o\t\t| In binary: %s\t\t|\n", S_IRWXG, Convet_octal_toBinary(S_IRWXG));
        printf("| Group read  permission    S_IRGRP | %o\t\t| In binary: %s\t\t|\n", S_IRGRP, Convet_octal_toBinary(S_IRGRP));
        printf("| Group write permission    S_IWGRP | %o\t\t| In binary: %s\t\t|\n", S_IWGRP, Convet_octal_toBinary(S_IWGRP));
        printf("| Group exe   permission    S_IXGRP | %o\t\t| In binary: %s\t\t|\n", S_IXGRP, Convet_octal_toBinary(S_IXGRP));
        printf("|-----------------------------------|-------------------|-------------------------------|\n");
        printf("| Other read,write,execute  S_IRWXO | %o\t\t\t| In binary: %s\t\t|\n", S_IRWXO, Convet_octal_toBinary(S_IRWXO));
        printf("| Other read  permission    S_IROTH | %o\t\t\t| In binary: %s\t\t|\n", S_IROTH, Convet_octal_toBinary(S_IROTH));
        printf("| Other write permission    S_IWOTH | %o\t\t\t| In binary: %s\t\t|\n", S_IWOTH, Convet_octal_toBinary(S_IWOTH));
        printf("| Other exe   permission    S_IXOTH | %o\t\t\t| In binary: %s\t\t|\n", S_IXOTH, Convet_octal_toBinary(S_IXOTH));
        printf("|---------------------------------------------------------------------------------------|\n");
        printf("\n");
    return 0;
}

    
char* Convet_octal_toBinary(int octal){
    char binary[1000];
    char octalNumber[100];
    memset(&binary[0], 0, sizeof(binary));
    memset(&octalNumber[0], 0, sizeof(octalNumber));
    long int i=0, j=0;
    sprintf(octalNumber, "%o", octal);
    while(octalNumber[i]){
        switch(octalNumber[i]){
            case '0':
                binary[j]   = '0';
                binary[++j] = '0';
                binary[++j] = '0';
                break;
            case '1':
                binary[j]   = '0';
                binary[++j] = '0';
                binary[++j] = '1';
                break;
            case '2':
                binary[j]   = '0';
                binary[++j] = '1';
                binary[++j] = '0';
                break;
            case '3':
                binary[j]   = '0';
                binary[++j] = '1';
                binary[++j] = '1';
                break;
            case '4':
                binary[j]   = '1';
                binary[++j] = '0';
                binary[++j] = '0';
                break;
            case '5':
                binary[j]   = '1';
                binary[++j] = '0';
                binary[++j] = '1';
                break;
            case '6':
                binary[j]   = '1';
                binary[++j] = '1';
                binary[++j] = '0';
                break;
            case '7':
                binary[j]   = '1';
                binary[++j] = '1';
                binary[++j] = '1';
                break;
            default:
                printf("\nInvalid octal digit %c ",octalNumber[i]);
        }
        i++;
        j++;
    }
    return binary;
}









