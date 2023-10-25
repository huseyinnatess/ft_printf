/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huates <huates@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 15:59:43 by huates            #+#    #+#             */
/*   Updated: 2023/10/24 14:37:46 by huates           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

int		ft_printf(const char *str, ...);
int		ft_putstr(char *str);
int		ft_pointer(unsigned long int number, int check);
int		ft_hexadecimal(unsigned int number, char c);
int		ft_print_number(long int number);
char	*ft_itoa(long int number);
int		ft_print_unsigned(unsigned int number);

#endif