#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <pwd.h>
int main(void)
{
    struct passwd *pwd;
    uid_t UID=getuid();
    printf("UID=%d\n", UID);
    uid_t eUID=geteuid();
    printf("UID=%d\n", eUID);
    pwd=getpwuid(UID);
    printf("---------------------------------------------------------\n");
    printf("|\t user name	      \t\t| %20s \t|\n", pwd->pw_name);
    printf("|\t encrypted password	\t| %20s \t|\n", pwd->pw_passwd);
    printf("|\t numerical user ID	\t| %20u \t|\n", pwd->pw_uid);
    printf("|\t numerical group ID	\t| %20u \t|\n", pwd->pw_gid);
    printf("|\t comment field	      \t\t| %20s \t|\n", pwd->pw_gecos);
    printf("|\t home directory	      \t\t| %20s \t|\n", pwd->pw_dir);
    printf("|\t default shell	      \t\t| %20s \t|\n", pwd->pw_shell);
    printf("|\t user class	      \t\t| %20s \t|\n", pwd->pw_class);
    printf("---------------------------------------------------------\n");
    return 0;
    }
