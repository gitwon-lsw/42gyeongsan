/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 13:21:37 by sunlee            #+#    #+#             */
/*   Updated: 2025/05/03 13:21:40 by sunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join_str;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	join_str = (char *)malloc(s1_len + s2_len + 1);
	if (!join_str)
		return (NULL);
	ft_memcpy(join_str, s1, s1_len);
	ft_memcpy(join_str + s1_len, s2, s2_len);
	join_str[s1_len + s2_len] = '\0';
	return (join_str);
}
