#include <sys/types.h>
#include <sys/param.h> /* for NGROUPS_MAX */
#include <limits.h>
#include <unistd.h>
#include <stdio.h>
#include <grp.h>        /* for getgrgid() and getgrnam() */
//#define NGROUPS_MAX 16
int main(void)
{
    int num_groups;
    gid_t grouplist[NGROUPS_MAX];
    gid_t *gi;
    struct group *ptrID;
    
    num_groups=getgroups(NGROUPS_MAX, grouplist);
    printf("There are %d supplementary groups\n", num_groups);
    
     for (gi=grouplist; gi!=NULL; gi++)
     {
         ptrID   = getgrgid(*gi);  //Function 2  Returns a pointer to the group struct gr means entire GROUP.
         
         printf("group %d\n", *gi);
         printf("| group name    | %20s \t|\n",     ptrID->gr_name  );
         printf("| group password| %20s \t|\n",     ptrID->gr_passwd);
         printf("| group ID      | %20d \t|\n\n\n", ptrID->gr_gid   );

     }

    for (int i=0; i<num_groups; i++)
    {
        printf("group %d\n", grouplist[i]);
    }
    return 0;
}