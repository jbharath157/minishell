#include "main.h"

pid_t pid;
int status; //need global declaration since using in other file as well orelse can avoid by passing as function parameter
void execute_external_commands(char *input_string)
{
    pid=fork(); //create child process for externel commands

    int return_status;
    if(pid == -1)
    {
        perror("fork");
        exit(1);
    }
    else if(pid == 0) //Child process logic 
    {
        return_status=system(input_string);
        if(return_status == 0)
        {
            exit(0);
        }
        else
        {
            exit(1);
        }
    }
    else //parent process logic
    { 
        wait(&status);  //wait untill child complete its task
        if(WIFEXITED(status)) //condition for termination
        {
            printf("Child terminated normally with %d pid \n",pid);
            pid=0;
        }
        else if( WIFSIGNALED(status)) //condition for termination by signal
        {
            printf("Child terminated by signal with %d pid \n",pid);
            printf("Sig# %d \n",WTERMSIG(status));
            pid=0;  //reassign to zero,since it will give conflict in signal_handler function 
        }
    }
}
