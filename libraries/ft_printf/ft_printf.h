/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 09:29:42 by cabo-ram          #+#    #+#             */
/*   Updated: 2024/11/12 12:52:33 by cabo-ram         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_putint(int n);
int	ft_putuint(unsigned int n);
int	ft_puthexa(unsigned int n, const char format);
int	ft_putptr(void *nbr);
int	ft_putchar(char c);
int	ft_putstr(const char *str);
int	ft_printf(const char *str, ...);

#endif