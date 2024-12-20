/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 11:58:48 by cabo-ram          #+#    #+#             */
/*   Updated: 2024/12/20 16:44:03 by cabo-ram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	error(void)
{
	perror("Error");
	exit(EXIT_FAILURE);
}

void	child_process (char **av, char **envp, int *fd)
{
	int filein;

	filein = open(av[1], O_RDONLY);
	if (filein == -1)
		error();
	dup2(fd[1], STDOUT_FILENO);
	dup2(filein, STDIN_FILENO);
	close(fd[0]);
	execute(av[2], envp);
}

void	parent_process (char **av, char **envp, int *fd)
{
	int	fileout;

	fileout = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fileout == -1)
		error();
	dup2(fd[0], STDIN_FILENO);
	dup2(fileout, STDOUT_FILENO);
	close(fd[1]);
	execute(av[3], envp);
}

int	main (int ac, char **av, char **envp)
{
	int pipefd[2];
	pid_t childpid;

	if (ac == 5)
	{
		if (pipe(pipefd) == -1)
			error();
		childpid = fork();
		if (childpid == -1)
			error();
		if (childpid == 0)
			child_process (av, envp, pipefd);
		waitpid(childpid, NULL, 0);
		parent_process (av, envp, pipefd);
	}
	else
	{
		ft_putstr_fd("Error: Invalid number of arguments\n", 2);
		ft_putstr_fd("It should be: ./pipex file1 cmd1 cmd2 file2\n", 2);
	}
	return (0);
}
