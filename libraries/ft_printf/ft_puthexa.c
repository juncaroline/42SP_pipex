/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthexa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 14:17:33 by cabo-ram          #+#    #+#             */
/*   Updated: 2024/10/31 12:14:37 by cabo-ram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	hexa_digits(unsigned int n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

static void	print_hexa(unsigned int n, const char format)
{
	static char	uppercase[] = "0123456789ABCDEF";
	static char	lowercase[] = "0123456789abcdef";

	if (n >= 16)
		print_hexa(n / 16, format);
	if (format == 'X')
		ft_putchar(uppercase[n % 16]);
	else
		ft_putchar(lowercase[n % 16]);
}

int	ft_puthexa(unsigned int n, const char format)
{
	print_hexa(n, format);
	return (hexa_digits(n));
}
