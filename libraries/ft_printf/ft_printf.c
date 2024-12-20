/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 09:18:19 by cabo-ram          #+#    #+#             */
/*   Updated: 2024/11/12 12:48:15 by cabo-ram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write (1, &c, 1);
	return (1);
}

int	ft_putstr(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

static int	convert(const char ltr, va_list args)
{
	if (ltr == '%')
		return (ft_putchar('%'));
	else if (ltr == 'c')
		return (ft_putchar(va_arg(args, int)));
	else if (ltr == 's')
		return (ft_putstr(va_arg(args, const char *)));
	else if (ltr == 'p')
		return (ft_putptr(va_arg(args, void *)));
	else if (ltr == 'd' || ltr == 'i')
		return (ft_putint(va_arg(args, int)));
	else if (ltr == 'u')
		return (ft_putuint(va_arg(args, unsigned int)));
	else if (ltr == 'x' || ltr == 'X')
		return (ft_puthexa(va_arg(args, unsigned int), ltr));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		length;
	va_list	args;

	i = 0;
	length = 0;
	if (str == NULL)
	{
		return (-1);
	}
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			length += convert(str[i + 1], args);
			i++;
		}
		else
			length += ft_putchar(str[i]);
		i++;
	}
	va_end(args);
	return (length);
}
