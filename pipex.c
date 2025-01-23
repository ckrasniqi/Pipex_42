/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrasniq <ckrasniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:43:11 by ckrasniq          #+#    #+#             */
/*   Updated: 2025/01/23 21:23:40 by ckrasniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	infile_redirect(char *av)
{
	int	infile;

	infile = open(av, O_RDONLY, 0644);
	if (infile == -1)
		return (-1);
	dup2(infile, STDIN_FILENO);
	close(infile);
	return (1);
}

void	execute_first_cmd(char *av, char **envp)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		error();
	pid = fork();
	if (pid == -1)
		error();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[1]);
		execute(av, envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		close(fd[0]);
	}
}

pid_t	execute_second_cmd(char *cmd, char *av, char **envp)
{
	int		outfile;
	pid_t	pid;

	outfile = open(av, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile == -1)
		error();
	pid = fork();
	if (pid == -1)
		error();
	if (pid == 0)
	{
		dup2(outfile, STDOUT_FILENO);
		close(outfile);
		execute(cmd, envp);
	}
	else
		close(outfile);
	return (pid);
}

int	main(int ac, char **av, char **envp)
{
	int		status;
	int		exit_code;
	pid_t	pid1;

	if (ac != 5)
		error();
	if (ac == 5)
	{
		if (infile_redirect(av[1]) > 0)
			execute_first_cmd(av[2], envp);
		pid1 = execute_second_cmd(av[3], av[4], envp);
		waitpid(pid1, &status, 0);
		exit_code = WEXITSTATUS(status);
		return (exit_code);
	}
	return (0);
}
