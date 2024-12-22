/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 16:42:09 by cabo-ram          #+#    #+#             */
/*   Updated: 2024/12/22 15:20:36 by cabo-ram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

static char	**get_directories(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] && ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	if (envp[i] == NULL)
		return (NULL);
	return (ft_split(envp[i] + 5, ':'));
}

static void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split && split[i])
		free(split[i++]);
	free(split);
}

char	*get_path(char *cmd, char **envp)
{
	char	**valid_path;
	char	*fullpath;
	char	*part_path;
	int		i;

	valid_path = get_directories(envp);
	if (valid_path == NULL)
		return (NULL);
	i = 0;
	while (valid_path[i])
	{
		part_path = ft_strjoin(valid_path[i], "/");
		fullpath = ft_strjoin(part_path, cmd);
		free(part_path);
		if (access(fullpath, F_OK) == 0)
		{
			free_split(valid_path);
			return (fullpath);
		}
		free(fullpath);
		i++;
	}
	free_split(valid_path);
	return (NULL);
}

void	execute(char *av, char **envp)
{
	char	**cmd;
	char	*path;
	int		i;

	cmd = ft_split(av, ' ');
	path = get_path(cmd[0], envp);
	i = 0;
	if (path == NULL)
	{
		while (cmd[i])
			free (cmd[i++]);
		free (cmd);
		error();
	}
	if (execve(path, cmd, envp) == -1)
		error();
}
