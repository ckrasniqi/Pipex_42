/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrasniq <ckrasniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:47:47 by ckrasniq          #+#    #+#             */
/*   Updated: 2025/01/23 21:23:37 by ckrasniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>
# include <unistd.h>

// Pipex
pid_t	execute_second_cmd(char *cmd, char *av, char **envp);
void	execute_first_cmd(char *av, char **envp);
int		infile_redirect(char *av);

// Utilities
void	error(void);
void	free_string_arr(char **arr);
char	*find_path(char *cmd, char **envp);
void	execute(char *av, char **envp);

#endif
