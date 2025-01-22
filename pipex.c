/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrasniq <ckrasniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:43:11 by ckrasniq          #+#    #+#             */
/*   Updated: 2025/01/22 16:43:15 by ckrasniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	child_process(char **av, int *fd, char **envp)
{
	int	file_in = open(av[1], O_RDONLY, 0777);
	if (file_in == -1)
		error();
	dup2(fd[1], STDOUT_FILENO);
	dup2(file_in, STDIN_FILENO);
	close(fd[0]);
	execute(av[2], envp);
}

void	parent_process(char **av, int *fd, char **envp)
{
	int	file_out = open(av[4], O_RDONLY, O_CREAT, O_TRUNC, 0777);

	if (file_out == -1)
		error();
	dup2(fd[1], STDIN_FILENO);
	dup2(file_out, STDOUT_FILENO);
	close(fd[1]);
	execute(av[3], envp);
}

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
		ft_putstr_fd("Wrong input\n", 1);
		ft_putstr_fd("Example: ./pipex file1 cmd1 cmd2 file2\n", 1);
	}
	return (0);
}
