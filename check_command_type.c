#include "main.h"

int check_command_type(char *command)
{
    //builtin commands, do "man builtins" to get to know the builtin commands
    char *builtins[] = { 
        "alias", "bg", "bind", "break", "builtin", "case", "cd", "command", "compgen", "complete", 
        "continue", "declare", "dirs", "disown", "echo", "enable", "eval", "exec", "exit", "export", 
        "fc", "fg", "getopts", "hash", "help", "history", "if", "jobs", "kill", "let", "local", 
        "logout", "popd", "printf", "pushd", "pwd", "read", "readonly", "return", "set", "shift", 
        "shopt", "source", "suspend", "test", "times", "trap", "type", "typeset", "ulimit", "umask", 
        "unalias", "unset", "until", "wait", "while",NULL };

    if( !strcmp(command,"\0") )  //check empty command
    {
        return NO_COMMAND;
    }
    
    for(int i=0;builtins[i] != NULL;i++)
    {
        if(!strcmp(builtins[i],command))
        {   
            return BUILTIN;
        }
    }
    
    //extarct the external_commands from the file (can also just try like builtin commands, assigning directly )
    char *external_commands[200]={NULL};
    extract_external_commands(external_commands);

    for(int i=0;external_commands[i]!=NULL;i++)
    {
        if(!strcmp(external_commands[i],command))
        {   
            return EXTERNAL;
        }
    }

    return NOT_VALID_COMMAND;
}
