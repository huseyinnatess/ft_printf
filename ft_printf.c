/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huates <huates@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 16:01:10 by huates            #+#    #+#             */
/*   Updated: 2023/10/29 11:13:02 by huates           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <unistd.h>

static int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

static int	ft_format(va_list arg, char flag) // Gelen flag'e göre (c, d, i, ...) format fonksiyonunu çağırır.
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
	if (flag == '%') // % işareti basar.
	{
		if (ft_putchar('%') < 0)
			return (-1);
		return (1);
	}
	return (-1); // Fonksiyon int olduğu için herhangi bir değer return etmek zorunda. Fonksiyon çalışmasına etki etmez.
}

static int	ft_flag_check(const char *str, int i) // Gelen stringin i. indexindeki karakter % ise ve bir sonraki karakter format karakteri ise 1 return eder.
{												  // Aksi halde 0 return eder.
	return (str[i] == '%' && (str[i + 1] == 'c' || str[i + 1] == 'd' || str[i
				+ 1] == 'i' || str[i + 1] == 'u' || str[i + 1] == 'x' || str[i
				+ 1] == 'X' || str[i + 1] == 'p' || str[i + 1] == 's' || str[i
				+ 1] == '%'));
}

static int	ft_check_str(const char *str, int *rtn, va_list arg)
{
	int	format; // write fonksiyonunun dönüş değerini tutar.
	int	i;

	i = -1;
	while (str[++i])
	{
		if (ft_flag_check(str, i)) // Bu if bloğu sadece doğru bir format karakteri geldiğinde çalışır.
		{
			format = ft_format(arg, str[++i]);
			if (format == -1)
				return (-1);
			*rtn += format;
		}
		else // Bu else bloğu format karakteri yanlış geldiğinde, sadece % işareti geldiğinde veya string bir karakter geldiğinde çalışır.
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

	// Fonksiyonların dönüş değerlerini format değişkenine atamak zorundayız çünkü direk rtn değerine ekler isek 
	// hatalı sonuçlar alırız. Sebebi için readme.
}

int	ft_printf(const char *str, ...) // Variable arguments fonksiyonu. Sınırsız sayıda argüman alabilir.
{
	va_list	arg; // Argümanları tutar.
	int		rtn;

	rtn = 0;
	va_start(arg, str); // Argümanları almayı başlatır. ilk argüman olarak argümanları tutan değişkeni, ikinci argüman olarak ise hangi veriden sonra argümanları alacağını belirler.
	if (ft_check_str(str, &rtn, arg) < 0)
		return (-1);
	va_end(arg); // Argümanları almayı bitirir.
	return (rtn); // Yazdırılan karakter sayısını return eder.
}
