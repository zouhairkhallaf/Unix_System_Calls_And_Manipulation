#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>

int main(int argc, char *argv[]){

    DIR *dp;
    struct dirent *dirp;
    
    if (argc!=2)
        printf("usage: myls directory_name");
    
    dp=opendir(argv[1]);
    
    if (dp==NULL)
        printf("can't open %s", argv[1]);
    
    while ((dirp=readdir(dp))!=NULL)
        printf("%s\n", dirp->d_name);
    
    
    closedir(dp);
    
    exit(0);

}