/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/03 17:19:34 by sunlee            #+#    #+#             */
/*   Updated: 2025/05/03 17:19:36 by sunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static size_t	ft_word_num(const char *s, char c)
{
	size_t	num;

	num = 0;
	while (*s)
	{
		if (*s != c)
		{
			num++;
			while (*s && *s != c)
				s++;
		}
		else
			s++;
	}
	return (num);
}

static void	free_all(char **result, size_t i)
{
	while (i--)
		free(result[i]);
	free(result);
}

static char	*ft_split_word(const char *s, char c)
{
	size_t	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (ft_substr(s, 0, len));
}

char	**ft_split(const char *s, char c)
{
	char	**result;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	result = malloc(sizeof(char *) * (ft_word_num(s, c) + 1));
	if (!result)
		return (NULL);
	while (*s)
	{
		if (*s != c)
		{
			result[i] = ft_split_word(s, c);
			if (!result[i])
				return (free_all(result, i), NULL);
			s += ft_strlen(result[i++]);
		}
		else
			s++;
	}
	result[i] = NULL;
	return (result);
}
