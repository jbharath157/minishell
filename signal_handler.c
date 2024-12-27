#include "main.h"

extern pid_t pid;
extern int prompt[30];

void signal_handler(int sig_num)
{
    if( pid != 0 )
    {
        if( sig_num == SIGINT )
        {
            kill(pid, SIGKILL); //The kill() system call can be used to send any signal to any process group or process.
        }
        else if( sig_num == SIGTSTP )
        {
            kill(pid, SIGTSTP );
            printf("PID:[%d]  Stopped   \n");
        }
    }
    else
    {
         printf("\n\033[1m" ANSI_COLOR_GREEN "[%s]$" ANSI_COLOR_RESET "\033[0m" ,prompt);
         fflush(stdout);
    }
}


