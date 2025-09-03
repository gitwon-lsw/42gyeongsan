/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 17:14:10 by sunlee            #+#    #+#             */
/*   Updated: 2025/07/06 17:14:11 by sunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	int					len;
	unsigned long long	addr;

	if (!ptr)
		return (write(1, "(nil)", 5));
	len = 0;
	addr = (unsigned long long)ptr;
	len += write(1, "0x", 2);
	len += ft_puthex_ulong(addr);
	return (len);
}
