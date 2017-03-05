#include <sys/types.h>
#include <sys/param.h> /* for NGROUPS_MAX */
#include <limits.h>
#include <unistd.h>
#include <stdio.h>
#include <grp.h>       // for getgrgid() and getgrnam()

                
int main(void)
{
    gid_t *gi;
    int num_groups;
    struct group *ptrID;
    gid_t grouplist[NGROUPS_MAX];
    num_groups=getgroups(NGROUPS_MAX, grouplist);
    
    printf("There are %d supplementary groups\n", num_groups);

    for (int i=0; i<num_groups; i++)
    {
        ptrID   = getgrgid(grouplist[i]);
        printf("group %d\n", grouplist[i]);
        printf("| group name    | %20s \t|\n",     ptrID->gr_name);
    }
    return 0;
}
