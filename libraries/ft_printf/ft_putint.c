/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 11:47:27 by cabo-ram          #+#    #+#             */
/*   Updated: 2024/10/30 12:27:32 by cabo-ram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	int_digits(int n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n = -n;
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	print_int(int n)
{
	static char	digits[] = "0123456789";

	if (n >= 10)
		print_int(n / 10);
	ft_putchar(digits[n % 10]);
}

int	ft_putint(int n)
{
	size_t	len;

	if (n == -2147483648)
	{
		write (1, "-2147483648", 11);
		return (11);
	}
	len = int_digits(n);
	if (n < 0)
	{
		write (1, "-", 1);
		n = -n;
		len++;
	}
	print_int (n);
	return (len);
}
