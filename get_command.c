#include "main.h"

//extract the command until the space is encountered 
char *get_command(char *input_string)
{
    static char command[30]={'\0'};
    int i=0;

    while( *input_string != ' '  && *input_string != '\0' )
    {   
        command[i++]=*input_string;
        input_string++;
    }
    command[i]='\0';

    return command;

}
