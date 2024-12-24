/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/20 17:02:05 by cabo-ram          #+#    #+#             */
/*   Updated: 2024/12/24 16:59:10 by cabo-ram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

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

static char	*expand_buffer(char *buffer, int *buffer_size, int i)
{
	int		j;
	char	*new_buffer;

	if (i >= *buffer_size - 1)
	{
		*buffer_size *= 2;
		new_buffer = (char *)malloc(*buffer_size);
		if (new_buffer == NULL)
		{
			free(buffer);
			return (NULL);
		}
		j = 0;
		while (j < i)
		{
			new_buffer[j] = buffer[j];
			j++;
		}
		free (buffer);
		return (new_buffer);
	}
	return (buffer);
}

static int	read_line(char **buffer, int *buffer_size, int *i)
{
	char	temp;
	int		bytes_read;

	bytes_read = read(0, &temp, 1);
	while (bytes_read > 0 && temp != '\n' && temp != '\0')
	{
		*buffer = expand_buffer(*buffer, buffer_size, *i);
		if (*buffer == NULL)
			return (-1);
		(*buffer)[*i] = temp;
		(*i)++;
		bytes_read = read(0, &temp, 1);
	}
	return (bytes_read);
}

int	get_next_line(char **line)
{
	char	*buffer;
	int		i;
	int		bytes_read;
	int		buffer_size;

	i = 0;
	buffer_size = 100;
	buffer = (char *)malloc(buffer_size);
	if (buffer == NULL)
		return (-1);
	bytes_read = read_line(&buffer, &buffer_size, &i);
	if (bytes_read == -1)
	{
		free(buffer);
		return (-1);
	}
	buffer[i] = '\0';
	*line = buffer;
	if (bytes_read == 0 && i == 0)
		return (0);
	return (1);
}
