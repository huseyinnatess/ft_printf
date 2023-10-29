/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utlis.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huates <huates@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:15:40 by huates            #+#    #+#             */
/*   Updated: 2023/10/29 10:55:31 by huates           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

int	ft_putstr(char *str)
{
	int	i;

	i = -1;
	if (!str) // Eğer gelen string NULL ise "(null)" basar.
		return (write(1, "(null)", 6));
	while (str[++i])
	{
		if ((write(1, &str[i], 1)) < 0)
			return (-1);
	}
	return (i);
}

int	ft_hexadecimal(unsigned int number, char c) // Gelen sayıyı hexadecimal olarak basar. Recursive olarak çalışır.
{
	int	rtn; // return değerini tutar.
	int	tmp; // write fonksiyonunun dönüş değerini tutar.

	rtn = 0;
	if (number >= 16)
	{
		tmp = ft_hexadecimal(number / 16, c); 
		if (tmp < 0) // Eğer write fonksiyonu başarısız olursa -1 döndürür.
			return (-1);
		rtn += tmp; // return değerine yazdırılan karakter sayısını ekler.
	}
	if (c == 'X')
		tmp = write(1, &"0123456789ABCDEF"[number % 16], 1);
	if (c == 'x')
		tmp = write(1, &"0123456789abcdef"[number % 16], 1);
	if (tmp < 0)
		return (-1);
	return (rtn + 1); // return değerine yazdırılan karakter sayısını ekler. Her seferinde mantıken 1 karakter yazdırıldığı için 1 eklenir.
}

int	ft_pointer(unsigned long int number, int check) // Gelen sayının adresini hexadecimal olarak basar. Recursive olarak çalışır.
{
	int	rtn;
	int	tmp;

	rtn = 0;
	if (check) // Recursive olarak çalıştığı için tekrar tekrar 0x yazdırmamak için kontrol eder.
		if ((write(1, "0x", 2)) < 0) // Adres formatı 0x ile başlar. Eğer write fonksiyonu başarısız olursa -1 döndürür.
			return (-1);
	if (check)
		rtn += 2; // "0x" yazdırıldığı için return değerine 2 ekler.
	if (number >= 16)
	{
		tmp = ft_pointer(number / 16, 0); // Recursive olarak çalıştığı için check değeri 0 olarak gönderilir. "0x" tekrar tekrar yazdırılmaması için.
		if (tmp < 0)
			return (-1);
		rtn += tmp;
	}
	tmp = write(1, &"0123456789abcdef"[number % 16], 1);
	if (tmp < 0)
		return (-1);
	return (rtn + 1);
}

int	ft_print_number(long int number) // Gelen sayıyı basar.
{
	char	*str; // Sayıyı string olarak tutar.
	int		rtn;

	str = ft_itoa(number); // Sayıyı string olarak çevirir.
	if (!str) // Eğer malloc fonksiyonu başarısız olursa NULL döndürür.
		return (-1);
	rtn = ft_putstr(str);
	free(str); // Malloc fonksiyonu ile ayrılan alanı free fonksiyonu ile geri verir.
	return (rtn);
}

int	ft_print_unsigned(unsigned int number)
{
	return (ft_print_number(number));
}
