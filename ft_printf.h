/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huates <huates@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:59:43 by huates            #+#    #+#             */
/*   Updated: 2023/10/22 00:30:10 by huates           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdio.h>

int ft_printf(const char *, ...);
int ft_putchar(char);
int ft_putstr(char *);
int ft_pointer(unsigned long long);
int ft_hexadecimal(unsigned long long, char);
int ft_print_number(int);
char *ft_itoa(int);

#endif