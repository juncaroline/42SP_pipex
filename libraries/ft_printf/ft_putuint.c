/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putuint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 12:20:35 by cabo-ram          #+#    #+#             */
/*   Updated: 2024/10/31 10:42:52 by cabo-ram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	uint_digits(unsigned int n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static void	print_uint(unsigned int n)
{
	static char	digits[] = "0123456789";

	if (n >= 10)
		print_uint(n / 10);
	ft_putchar(digits[n % 10]);
}

int	ft_putuint(unsigned int n)
{
	print_uint(n);
	return (uint_digits(n));
}
