/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/04 14:44:48 by sunlee            #+#    #+#             */
/*   Updated: 2025/05/04 14:44:50 by sunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static	int	ft_numlen(long n)
{
	int	len;

	len = 1;
	while (n > 9)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*result;
	long	num;
	int		negative;
	int		len;

	negative = 0;
	num = n;
	if (num < 0)
	{
		num = -num;
		negative++;
	}
	len = ft_numlen(num) + negative;
	result = (char *)malloc(len + 1);
	if (!result)
		return (NULL);
	result[len] = '\0';
	while (len-- > negative)
	{
		result[len] = (num % 10) + '0';
		num /= 10;
	}
	if (negative)
		result[0] = '-';
	return (result);
}
