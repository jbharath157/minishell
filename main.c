#include "main.h"

//array to store the prompt
char prompt[30]= "minishell";

int main()
{
    //to clear the screen 
    system("clear");

    //array to store the input
    char input_string[30];

    prompt_scan_input(prompt,input_string);
    
}

void prompt_scan_input(char *prompt, char *input_string)
{
    char *command;
    int command_type;

    signal(SIGINT,signal_handler);      //signal handler for CTRL+C
    signal(SIGTSTP,signal_handler);     //signal handler for CTRL+z

    while(1){

        printf("\033[1m" ANSI_COLOR_GREEN "[%s]$" ANSI_COLOR_RESET "\033[0m" ,prompt); //display prompt

        fflush(stdout); //flush stdout immediately

        scanf("%[^\n]s",input_string);// read input from the terminal

        getchar(); //clear the input buffer "\n"

         //customize the prompt
        if( !strncmp(input_string,"PS1=",4) )
        {
            if(input_string[4] != ' ')
            strcpy(prompt,&input_string[4]);

            memset(input_string,'\0',30);
            continue;
        }

      //get the command form entire input_string
      command=get_command(input_string);

      command_type = check_command_type(command); 

      if( command_type == NO_COMMAND )
      {
            continue;
      }
      else if (command_type == BUILTIN )
      {
            execute_internal_commands(input_string);
            memset(input_string,'\0',30); //clear the input_string for next operation
      }
      else if( command_type == EXTERNAL)
      {
           execute_external_commands(input_string);
           memset(input_string,'\0',30); //clear the input_string for next operation 
      }
      else
      {
          printf("[%s]: Not a valid command\n",command);  
          memset(input_string,'\0',30); //clear the input_string for next operation

      }

    }

}
