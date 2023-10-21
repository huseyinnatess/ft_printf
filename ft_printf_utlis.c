/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utlis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huates <huates@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:15:40 by huates            #+#    #+#             */
/*   Updated: 2023/10/21 18:23:41 by huates           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

int ft_putchar(char c)
{
    return(write(1, &c, 1));
}

int ft_putstr(char *str)
{
    int i;

    i = -1;
    while (str[++i])
        write(1, &str[i], 1);
    return (i);
}

int ft_hexadecimal(unsigned long long number, char c)
{
    int rtn;

    rtn = 0;
    if (number >= 16)
        rtn += ft_hexadecimal(number / 16, c);
    if (c == 'X')
        write(1, &"0123456789ABCDEF"[number % 16], 1);
    if (c == 'x')
        write(1, &"0123456789abcdef"[number % 16], 1);
    return (rtn + 1);
}

int ft_pointer(unsigned long long number)
{
    int rtn;

    rtn = 0;
    rtn += write(1, "0x", 2);    
    rtn += ft_hexadecimal(number, 'x');
    return (rtn);
}