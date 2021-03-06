all: minishell.o minishell_input.o free_args.o execute.o minishell 

minishell: minishell.o minishell_input.o free_args.o execute.o
	gcc minishell.o minishell_input.o free_args.o execute.o -L./lib/Linux/i686 -lshell -o minishell

minishell.o: minishell.c
	gcc minishell.c -c -o minishell.o

minishell_input.o: minishell_input.c
	gcc minishell_input.c -c -o minishell_input.o

free_args.o: free_args.c
	gcc free_args.c -c -o free_args.o

execute.o: execute.c
	gcc execute.c -c -o execute.o

clean:
	rm *.o minishell
