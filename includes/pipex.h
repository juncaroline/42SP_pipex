/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:59:24 by cabo-ram          #+#    #+#             */
/*   Updated: 2024/12/20 16:18:02 by cabo-ram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "../libft/libft.h"

char	*get_path(char *cmd, char **envp);
void	execute (char *av, char **envp);
void	child_process (char **av, char **envp, int *fd);
void	parent_process (char **av, char **envp, int *fd);
int	    main (int ac, char **av, char **envp);

#endif