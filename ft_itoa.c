/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huates <huates@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 23:24:49 by huates            #+#    #+#             */
/*   Updated: 2023/10/24 14:16:25 by huates           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static int	ft_count(long int num)
{
	long int	n;
	int			i;

	i = 0;
	n = num;
	while (n)
	{
		n /= 10;
		i++;
	}
	i += (num == 0 || num < 0);
	return (i);
}

char	*ft_itoa(long int number)
{
	int		len;
	char	*str;

	len = ft_count(number);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	if (number < 0)
	{
		str[0] = '-';
		number = -number;
	}
	str[len--] = '\0';
	while (number > 9)
	{
		str[len--] = (number % 10) + 48;
		number /= 10;
	}
	str[len] = (number % 10) + 48;
	return (str);
}
