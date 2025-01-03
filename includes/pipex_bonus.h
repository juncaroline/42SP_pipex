/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 10:07:45 by cabo-ram          #+#    #+#             */
/*   Updated: 2025/01/03 16:56:10 by cabo-ram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include "../libraries/libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>

void	multiple_child_process(char *av, char **envp);
void	error_msg(void);
int		open_file(char *av, int i);
void	execute(char *av, char **envp);
void	error(void);

#endif