#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#include "parser.h"
#include "execute.h"
#include "free_args.h"
#include "jobs.h"

void zombie_handler(int signal){
	int child_status;
	wait(&child_status);
}

void execute_external_command(const char *command)
{
	char **args;
	int backgr = 0;
	int child_status;
	pid_t pid;

	if((args=parser_command(command, &backgr))==NULL)
	{
		return;
	}
	else{
		pid = fork();
		if(pid==0){
			execvp(args[0], args);
		}
		else{
			if(backgr==0){
				wait(&child_status);
			}else{
				signal(SIGCHLD, zombie_handler);
			}
		}
	}
	parser_free_args(args);
}
