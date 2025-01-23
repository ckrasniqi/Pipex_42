/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrasniq <ckrasniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:43:28 by ckrasniq          #+#    #+#             */
/*   Updated: 2025/01/23 20:41:27 by ckrasniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}

void	free_string_arr(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
		free(arr[i]);
	free(arr);
}

char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	int		i;
	char	*part_path;
	char	*path;

	i = 0;
	while (ft_strnstr(envp[i], "PATH=", 5) == 0)
		i++;
	paths = ft_split(envp[i] + 5, ':');
	i = 0;
	while (paths[i])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, X_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	free_string_arr(paths);
	return (NULL);
}

void	execute(char *av, char **envp)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(av, ' ');
	path = find_path(cmd[0], envp);
	if (!path)
	{
		free_string_arr(cmd);
		error();
	}
	if (execve(path, cmd, envp) == -1)
		error();
}
