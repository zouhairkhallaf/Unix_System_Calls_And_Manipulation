#include <unistd.h>
#include <pwd.h>
#include <stdio.h>

int main(void){
    
    struct passwd *ptr;
    
    setpwent(); // Function 1
    
    while ((ptr=getpwent())!=NULL) // Function 2
    {
        printf("user %s name %s\n", ptr->pw_name, ptr->pw_gecos);
    }
    
    endpwent(); // Function 3
    
    return 0;
}