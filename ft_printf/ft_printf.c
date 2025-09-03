/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/10 18:06:59 by sunlee            #+#    #+#             */
/*   Updated: 2025/08/10 18:07:02 by sunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_format_handler(char specifier, va_list *args)
{
	int	print_len;

	print_len = 0;
	if (specifier == 'c')
		print_len += ft_putchar(va_arg(*args, int));
	else if (specifier == 's')
		print_len += ft_putstr(va_arg(*args, char *));
	else if (specifier == 'p')
		print_len += ft_putptr(va_arg(*args, void *));
	else if (specifier == 'd' || specifier == 'i')
		print_len += ft_putnbr(va_arg(*args, int));
	else if (specifier == 'u')
		print_len += ft_putnbr_unsigned(va_arg(*args, unsigned int));
	else if (specifier == 'x')
		print_len += ft_puthex(va_arg(*args, unsigned int), 0);
	else if (specifier == 'X')
		print_len += ft_puthex(va_arg(*args, unsigned int), 1);
	else if (specifier == '%')
		print_len += ft_putchar('%');
	return (print_len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		printed_len;

	i = 0;
	printed_len = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && format[i + 1])
		{
			printed_len += ft_format_handler(format[i + 1], &args);
			i += 2;
		}
		else
		{
			printed_len += ft_putchar(format[i]);
			i++;
		}
	}
	va_end(args);
	return (printed_len);
}
