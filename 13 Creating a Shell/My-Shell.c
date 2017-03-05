#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define LSH_TOK_DELIM " \t\r\n\a"

//FUNCTIONS DECLARATIONS
char *Read(void);
bool Execute(char **args);
char **Parse(char *line);
void Check_buffer(char *buffer);
void Check_tokens(char **token);

//MAIN FUNCTION
int main(int argc, char **argv)
{
    char *line, **args;
    bool status = true;
    // Running the loop have 3 componants
    do {
        printf("# MY-SHELL > ");
        line   = Read();
        args   = Parse(line);
        status = Execute(args);
        //Deallocating and cleanups
        free(line);
        free(args);
    } while (status == true);
    return EXIT_SUCCESS;
}

// FUNCTIONS DEFINITIONS
char *Read(void)
{
    int bufsize = 1024, position = 0, c;
    char *buffer = malloc(sizeof(char) * bufsize);
    while (1) {
        Check_buffer(buffer);
        // Read a character
        c = getchar(); //Reads characters from stdin.
        // If we hit EOF
        if (c == EOF || c == '\n') {
            buffer[position] = '\0'; //Replace it with a null character.
            return buffer;
        } else
            buffer[position] = c;
        position++;
        // If we have exceeded the buffer, reallocate.
        if (position >= bufsize) {
            bufsize += 1024;
            buffer = realloc(buffer, bufsize);
        }
    }
}
char **Parse(char *line)
{
    int bufsize = 64, position = 0;
    char **tokens = malloc(bufsize * sizeof(char*));
    char *token;
    Check_tokens(&token);
    //The strtok() function breaks a string into a sequence of zero or more nonempty tokens
    token = strtok(line, LSH_TOK_DELIM);
    while (token != NULL) {
        tokens[position] = token;
        position++;
        if (position >= bufsize) {
            bufsize += 64;
            tokens = realloc(tokens, bufsize * sizeof(char*));
            Check_tokens(&token);
        }
        token = strtok(NULL, LSH_TOK_DELIM);
    }
    tokens[position] = NULL;
    return tokens;
}

bool Execute(char **args) {
    pid_t wpid;
    int status;
    if (args[0] == NULL) // No args...
        return true;
    if ( strncmp(args[0],"exit", 4) == 0 ){         // if arg => "exit"
        printf("My-Shell terminated\n");
        return false;
    }
    if ( strncmp(args[0],"cd", 2) == 0 ){           // If arg => "cd /some/path/"
        if (args[1] == NULL)
            fprintf(stderr, "ERROR: Provide 2nd argv\"cd\"\n");
        else {
            if (chdir(args[1]) == 0) {
                printf("Directory changed successfully\n");
                return true;
            }
        }
        return false;
    }
    pid_t pid = fork(); //THIS WILL EXECUTE A FILE: Here we fork()...
    if ( pid<0 )                                      // ERROR IN FORKING
        perror("ERROR: PID<0 \n");
    if (pid == 0 && (execvp(args[0], args) == -1))    // CHILD needs to execute the new program
        exit(EXIT_FAILURE);
    if (pid == 1){                                     // PARENT needs to wait for the child to terminate
        do {
            wpid = waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
    return true;
}
void Check_buffer(char *buffer){
    if (!buffer){
        fprintf(stderr, "ERROR: Read Allocation failed\n");
        exit(EXIT_FAILURE);
    }
}
void Check_tokens(char **token){
    if (!token) {
        fprintf(stderr, "ERROR: Parse Allocation failed\n");
        exit(EXIT_FAILURE);
    }
}