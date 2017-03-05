#include <sys/types.h>
#include <grp.h>        /* for getgrgid() and getgrnam() */
#include <unistd.h>     /* for getgid() */
#include <stdio.h>      /* for printf() */

int main(void)
{
    struct group *ptrID, *ptrName;
    char **userIterator;
    char *uName="zouhairkhallaf";
    char *gName="staff";
    gid_t GID;
    
    GID     = getgid();       //Function 1  for ****>>> GID
    ptrID   = getgrgid(GID);  //Function 2  Returns a pointer to the group struct gr means entire GROUP.
    ptrName = getgrnam(gName);//Function 3
    
    printf("User %s belongs to group %s, with GID=%u\n", uName, gName, GID);
    printf("---------------------------------------------\n");
    printf("|\tgroup name    \t| %20s |\n", ptrID->gr_name  );
    printf("|\tgroup password\t| %20s |\n", ptrID->gr_passwd);
    printf("|\tgroup ID      \t| %20d |\n", ptrID->gr_gid   );
    
    for (userIterator=ptrID->gr_mem; *userIterator!=NULL; userIterator++)
    {
        printf("|\tgroup members\t| %20s |\n", *userIterator);
    }
    
    printf("------------------------------------------------\n");
    
    return 0;
}