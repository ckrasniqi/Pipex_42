/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckrasniq <ckrasniq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 16:47:47 by ckrasniq          #+#    #+#             */
/*   Updated: 2025/01/22 16:48:35 by ckrasniq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include <stdio.h>
# include <sys/wait.h>
# include <fcntl.h>


// Pipex
void	child_process(char **av, int *fd, char **envp);
void	parent_process(char **av, int *fd, char **envp);

// Utilities
void	error(void);
void	free_string_arr(char **arr);
char	*extract_path(char **envp);
char	*find_path(char *cmd, char **envp);
void	execute(char *av, char **envp);


#endif
