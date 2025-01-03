/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:02:07 by cabo-ram          #+#    #+#             */
/*   Updated: 2025/01/03 16:55:35 by cabo-ram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

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

int	main(int ac, char **av, char **envp)
{
	int	i;
	int	filein;
	int	fileout;

	if (ac >= 5)
	{
		i = 2;
		fileout = open_file(av[ac - 1], 1);
		filein = open_file(av[1], 2);
		dup2(filein, STDIN_FILENO);
		while (i < ac - 2)
			multiple_child_process(av[i++], envp);
		dup2(fileout, STDOUT_FILENO);
		execute(av[ac - 2], envp);
	}
	error_msg();
}
