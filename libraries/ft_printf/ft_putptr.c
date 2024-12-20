/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:53:24 by cabo-ram          #+#    #+#             */
/*   Updated: 2024/10/31 10:57:56 by cabo-ram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ptr_digits(unsigned long n)
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

static void	print_hexa_ptr(unsigned long n)
{
	static char	i[] = "0123456789abcdef";

	if (n >= 16)
		print_hexa_ptr(n / 16);
	ft_putchar(i[n % 16]);
}

int	ft_putptr(void *n)
{
	size_t			len;
	unsigned long	ptr;

	ptr = (unsigned long) n;
	len = 2;
	if (ptr == 0)
		return (write (1, "(nil)", 5));
	else
	{
		write (1, "0x", 2);
		print_hexa_ptr(ptr);
		len = len + ptr_digits(ptr);
	}
	return (len);
}
