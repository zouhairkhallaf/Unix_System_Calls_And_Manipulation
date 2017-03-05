#include <unistd.h>
#include <grp.h>        /* for setgrent(), getgrent(), endgrent() */
#include <stdio.h>

int main(void)
{
    struct group *ptr;
    char **userIterator;
    setgrent();
    
    while ((ptr=getgrent())!=NULL)
    {
        printf("group %s name %s\n", ptr->gr_name, ptr->gr_passwd);
        printf("--------------------------------------\n");
        printf("|\tgroup name    \t| %20s |\n", ptr->gr_name    );
        printf("|\tgroup password\t| %20s |\n", ptr->gr_passwd  );
        printf("|\tgroup ID      \t| %20d |\n", ptr->gr_gid     );
        
        for (userIterator=ptr->gr_mem; *userIterator!=NULL; userIterator++)
        {
            printf("|\tgroup members    \t| %20s |\n", *userIterator);
        }
    }
    
    endgrent();
    return 0;
}