#include "pipex.h"

int main(int ac, char **av, char **envp)
{
	int fd[2];
	pid_t pid;

	if (ac == 5)
	{
		if (pipe(fd) == - 1)
			error();
		pid = fork();
		if (pid == -1)
			error();
		if (pid == 0)
			child_process(av, fd, envp);
		waitpid(pid, NULL, 0);
		parent_process(av, fd, envp);
	}
	else
	{


	}
}
