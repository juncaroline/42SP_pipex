/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:59:24 by cabo-ram          #+#    #+#             */
/*   Updated: 2025/01/02 09:21:47 by cabo-ram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libraries/libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>

char	*get_path(char *cmd, char **envp);
void	execute(char *av, char **envp);
void	error(void);
void	child_process(char **av, char **envp, int *fd);
void	parent_process(char **av, char **envp, int *fd);

#endif