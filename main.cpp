#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include<iostream>
#include<string.h>
#include <stdlib.h>
#include<errno.h>

#define MAX 50

#include "parser.h"

using namespace std;

void err_sys(const char* x) 
{ 
    perror(x); 
    exit(0); 
}

int cd(char *path) {
    return chdir(path);
}

int main()
{

	int i;

	char** temp;
	char input[MAX];
	char* ip;
	pid_t child_pid;
    int stat_loc;

    cout<<"%%";

	while (1) {
        
		fgets(input, 20, stdin);
		
		ip = input;

    	temp = parser(ip);    

    	if(strcmp(temp[0], "exit") == 0){
			break;
		}

    	if (strcmp(temp[0], "cd") == 0) 
    	{
        
            if (cd(temp[1]) < 0) {
                perror(temp[1]);
            }

        }
        else
        {

        child_pid = fork();

        if (child_pid < 0) 
        {
            perror("Fork failed");
            exit(0);
        }

        if (child_pid == 0) 
        {
   			 if (execvp(temp[0], temp) < 0) 
			 {
                cout<<"danger"<<endl;
                exit(1);
             }

        } 


        if ((child_pid = waitpid(child_pid, &stat_loc, 0)) < 0)
			err_sys("waitpid error");

		}

        cout<<"%%";

    }
    exit(0);

}