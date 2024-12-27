#include "main.h"

void extract_external_commands(char **external_commands)
{
    int fd,i=0,j=0;
    char buffer[20]={'\0'};
    char ch;
    fd=open("external_commands.txt",O_RDONLY);

    if(fd == -1)
    {
        perror("open");
        exit(1);
    }
    
    while(read(fd,&ch,1)) //read char by char from file 
    {
        if( ch != '\n' )
        {
            buffer[i++]=ch;
        }
        else 
        {
            buffer[i]='\0';
            char *tmp = malloc(sizeof(buffer)+1);
            strcpy(tmp,buffer);
            external_commands[j++]=tmp;
            i=0;
        }
    }
}
