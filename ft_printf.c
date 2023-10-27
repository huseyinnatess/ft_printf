/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huates <huates@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:01:10 by huates            #+#    #+#             */
/*   Updated: 2023/10/25 16:31:54 by huates           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

static int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

static int	ft_format(va_list arg, char flag)
{
	if (flag == 'c')
		return (ft_putchar(va_arg(arg, int)));
	else if (flag == 's')
		return (ft_putstr(va_arg(arg, char *)));
	else if (flag == 'p')
		return (ft_pointer(va_arg(arg, unsigned long int), 1));
	else if (flag == 'd' || flag == 'i')
		return (ft_print_number(va_arg(arg, int)));
	else if (flag == 'u')
		return (ft_print_unsigned(va_arg(arg, unsigned int)));
	else if (flag == 'x' || flag == 'X')
		return ((ft_hexadecimal(va_arg(arg, unsigned int), flag)));
	if (flag == '%')
	{
		if (ft_putchar('%') < 0)
			return (-1);
		return (1);
	}
	return (-1);
}

static int	ft_flag_check(const char *str, int i)
{
	return (str[i] == '%' && (str[i + 1] == 'c' || str[i + 1] == 'd' || str[i
				+ 1] == 'i' || str[i + 1] == 'u' || str[i + 1] == 'x' || str[i
				+ 1] == 'X' || str[i + 1] == 'p' || str[i + 1] == 's' || str[i
				+ 1] == '%'));
}

static int	ft_check_str(const char *str, int *rtn, va_list arg)
{
	int	format;
	int	i;

	i = -1;
	while (str[++i])
	{
		if (ft_flag_check(str, i))
		{
			format = ft_format(arg, str[++i]);
			if (format == -1)
				return (-1);
			*rtn += format;
		}
		else
		{
			if (str[i] == '%')
				return (0);
			format = write(1, &str[i], 1);
			if (format == -1)
				return (-1);
			*rtn += format;
		}
	}
	return (0);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		rtn;

	rtn = 0;
	va_start(arg, str);
	if (ft_check_str(str, &rtn, arg) < 0)
		return (-1);
	va_end(arg);
	return (rtn);
}
