/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huates <huates@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:01:10 by huates            #+#    #+#             */
/*   Updated: 2023/10/21 18:29:06 by huates           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>

static int ft_format(va_list arg, char flag)
{
    if (flag == 'c')
        return (ft_putchar(va_arg(arg, int)));
    else if (flag == 's')
        return (ft_putstr(va_arg(arg, char *)));
    else if (flag == 'p')
        return (ft_pointer(va_arg(arg, unsigned long long)));
    return (0);
}

static int ft_flag_check(const char *str, int i)
{
    return (str[i] == '%' && (str[i + 1] == 'c' || str[i + 1] == 'd'
			|| str[i + 1] == 'i' || str[i + 1] == 'u'
			|| str[i + 1] == 'x' || str[i + 1] == 'X'
			|| str[i + 1] == 'p' || str[i + 1] == 's' || str[i + 1] == '%'));
}

int ft_printf(const char *str, ...)
{
    va_list arg;
    int i;
    int rtn;

    i = -1;
    rtn = 0;
    va_start(arg, str);
    while (str[++i])
    {
        if (ft_flag_check(str, i))
            rtn += ft_format(arg, str[++i]);
    }
    va_end(arg);
    return (rtn);
}
#include <stdio.h>

int main()
{
    int a,b,sonuc;
    int *ptr;

    a = 32;
    ptr = &a;
    sonuc = ft_printf("%p", ptr);
    printf("\n");
    printf("Sonuc:%d", sonuc);
    printf("\n");
    sonuc = printf("%p", ptr);
    printf("\n");
    printf("Sonuc:%d", sonuc);
    printf("\n");
}