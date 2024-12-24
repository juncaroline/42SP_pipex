/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:02:07 by cabo-ram          #+#    #+#             */
/*   Updated: 2024/12/24 17:21:40 by cabo-ram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	multiple_child_process(char *av, char **envp)
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
		if (dup2(fd[1], STDOUT_FILENO) == -1)
			error();
		close(fd[1]);
		execute(av, envp);
	}
	else
	{
		close(fd[1]);
		if (dup2(fd[0], STDIN_FILENO) == -1)
			error();
		close(fd[0]);
		waitpid(pid, NULL, 0);
	}
}

static void	create_here_doc(int fd[2], char *limiter)
{
	pid_t	reader;
	char 	*line;

	reader = fork();
	if (pipe(fd) == -1)
		error();
	if (reader == 0)
	{
		close(fd[0]);
		while (get_next_line(&line))
		{
			if (line[ft_strlen(line) - 1] == '\n')
				line[ft_strlen(line) - 1] = '\0';
			if (ft_strncmp(line, limiter, ft_strlen(limiter)) == 0)
			{
				free(line);
				exit(EXIT_SUCCESS);
			}
			write(fd[1], line, ft_strlen(line));
			free(line);
		}
		close(fd[1]);
	}
}

void	here_doc(char *limiter, int ac)
{
	int		fd[2];

	if (ac < 6)
		error_msg();
	if (pipe(fd) == -1)
		error();
	create_here_doc(fd, limiter);
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	wait(NULL);
}

int	main(int ac, char **av, char **envp)
{
	int	i;
	int	filein;
	int	fileout;

	if (ac >= 5)
	{
		if (ft_strncmp(av[1], "here_doc", 8) == 0)
		{
			i = 3;
			fileout = open_file(av[ac - 1], 0);
			here_doc(av[2], ac);
		}
		else
		{
			i = 2;
			fileout = open_file(av[ac - 1], 1);
			filein = open_file(av[1], 2);
			dup2(filein, STDIN_FILENO);
		}
		while (i < ac - 2)
			multiple_child_process(av[i++], envp);
		dup2(fileout, STDOUT_FILENO);
		execute(av[ac - 2], envp);
	}
	error_msg();
}
