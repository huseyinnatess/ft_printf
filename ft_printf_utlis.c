/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utlis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huates <huates@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:15:40 by huates            #+#    #+#             */
/*   Updated: 2023/10/24 14:37:37 by huates           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

int	ft_putstr(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[++i])
	{
		if ((write(1, &str[i], 1)) < 0)
			return (-1);
	}
	return (i);
}

int	ft_hexadecimal(unsigned int number, char c)
{
	int	rtn;
	int	tmp;

	rtn = 0;
	if (number >= 16)
	{
		tmp = ft_hexadecimal(number / 16, c);
		if (tmp < 0)
			return (-1);
		rtn += tmp;
	}
	if (c == 'X')
		tmp = write(1, &"0123456789ABCDEF"[number % 16], 1);
	if (c == 'x')
		tmp = write(1, &"0123456789abcdef"[number % 16], 1);
	if (tmp < 0)
		return (-1);
	return (rtn + 1);
}

int	ft_pointer(unsigned long int number, int check)
{
	int	rtn;
	int	tmp;

	rtn = 0;
	if (check)
		if ((write(1, "0x", 2)) < 0)
			return (-1);
	if (check)
		rtn += 2;
	if (number >= 16)
	{
		tmp = ft_pointer(number / 16, 0);
		if (tmp < 0)
			return (-1);
		rtn += tmp;
	}
	tmp = write(1, &"0123456789abcdef"[number % 16], 1);
	if (tmp < 0)
		return (-1);
	return (rtn + 1);
}

int	ft_print_number(long int number)
{
	char	*str;
	int		rtn;

	str = ft_itoa(number);
	if (!str)
		return (-1);
	rtn = ft_putstr(str);
	free(str);
	return (rtn);
}

int	ft_print_unsigned(unsigned int number)
{
	return (ft_print_number(number));
}
