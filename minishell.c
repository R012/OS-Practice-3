#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <signal.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

#include "internals.h"
#include "execute.h"
#include "jobs.h"
#include "minishell_input.h"

int main(int argc, char *argv[])
{
	char buf[BUFSIZ];

	for(;;){
		print_prompt();
		read_command_line(buf);
		if(is_internal_command(buf)==1){
				printf("This function has not yet been implemented.\n");
		}else if(strcmp(buf, "exit")==0){
			jobs_free_mem();
			exit(0);
		}else{
			execute_external_command(buf);
		}
	}
	return 0;
}
