/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huates <huates@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 23:24:49 by huates            #+#    #+#             */
/*   Updated: 2023/10/22 16:48:55 by huates           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>

static int	ft_count(long num)
{
	int	n;
	int	i;

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

char	*ft_itoa(int number)
{
	int		len;
	char	*str;
	long	nmb;

	nmb = number;
	len = ft_count(number);
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (NULL);
	if (nmb < 0)
	{
		str[0] = '-';
		nmb = -nmb;
	}
	str[len--] = '\0';
	while (nmb > 9)
	{
		str[len--] = (nmb % 10) + 48;
		nmb /= 10;
	}
	str[len] = (nmb % 10) + 48;
	return (str);
}
