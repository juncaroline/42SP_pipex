/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:02:05 by cabo-ram          #+#    #+#             */
/*   Updated: 2025/01/03 16:55:29 by cabo-ram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

void	error_msg(void)
{
	ft_putstr_fd("Error: Invalid arguments\n", 2);
	ft_putstr_fd("Example: ./pipex <file1> <cmd1> <cmd2> <...> <file2>\n", 1);
	ft_putstr_fd
		("Or: ./pipex \"here_doc\" <LIMITER> <cmd> <cmd> <...> <file>\n", 1);
}

int	open_file(char *av, int i)
{
	int	file;

	file = 0;
	if (i == 0)
		file = open(av, O_WRONLY | O_CREAT | O_APPEND, 0777);
	else if (i == 1)
		file = open(av, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else if (i == 2)
		file = open(av, O_RDONLY, 0777);
	if (file == -1)
		error();
	return (file);
}
