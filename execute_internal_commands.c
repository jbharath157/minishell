#include "main.h"

extern int status;
void execute_internal_commands(char *input_string)
{
    if( strcmp(input_string,"pwd") == 0 )
    {
        status=system("pwd");
    }
    else if( strcmp(input_string, "exit") == 0 )
    {
        exit(0);
    }
    else if( strncmp(input_string,"cd",2) == 0 )
    {
        char *tmp,*path;

        tmp=strtok(&input_string[3]," ");            //using strtok() to eliminate spaces
        while( tmp != NULL )
        {
            path=tmp;
            tmp=strtok(NULL," ");
        }
        status=chdir(path); //chdir() changes the current working directory of the calling process to the directory specified in path.
    }

    if( strncmp(input_string,"echo",4) == 0 )
    {
        echo(input_string,status);
    }

}


void echo(char *input_string, int status)
{
    if( strncmp(input_string+5, "$?",2) == 0 ) 
    {
        printf("status : %d\n",status); 
    }
    else if ( strncmp(input_string+5, "$$",2) == 0 )
    {
        printf("PID of the msh shell [%d]\n",getpid());
    }
    else if( strncmp(input_string+5,"$SHELL",6) == 0 )
    {
        system("which $SHELL");
    }
}



