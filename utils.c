/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrasniq <ckrasniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:43:28 by ckrasniq          #+#    #+#             */
/*   Updated: 2025/01/22 16:43:31 by ckrasniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(void)
{
	perror("ERORR");
	exit(EXIT_FAILURE);
}

void	free_string_arr(char **arr)
{
	int	i;

	i = -1;
	while(arr[++i])
		free(arr[i]);
	free(arr);
}
char	*extract_path(char **envp)
{
	int	i;

	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	retrun (envp[i]);
}

char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*env_path;
	int		i;
	char	*part_path;
	char	*path;

	i = 0;
	env_path = extract_path(envp);
	if (!env_path)
		return (NULL);
	paths = ft_split(env_path[i] + 5, ":");
	while (paths[i++])
	{
		part_path = ft_strjoin(paths[i], "/");
		path = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(path, F_OK) == 0)
		{
			free_string_arr(paths);
			return(path);
		}
		free(path);
	}
	free_string_arr(paths);
	return (0);
}

void	execute(char *av, char **envp)
{
	char	**cmd;
	int		i;
	char	*path;

	cmd = ft_split(av, ' ');
	path = find_path(cmd[0], envp);

	if (!path)
	{
		free_string_arr(cmd);
		error();
	}
	if (execve(path, cmd, envp) == -1)
	{
		free(path);
		free_string_arr(cmd);
		error();
	}
}
