/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 15:51:21 by sunlee            #+#    #+#             */
/*   Updated: 2025/07/05 15:51:23 by sunlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line_bonus.h"

static char	*ft_free(char **backup)
{
	if (*backup)
	{
		free(*backup);
		*backup = NULL;
	}
	return (NULL);
}

static char	*make_line(char **backup, int read_size)
{
	char	*line;
	char	*tmp;
	size_t	index;

	tmp = NULL;
	if (read_size < 0 || !*backup || (*backup)[0] == '\0')
		return (ft_free(backup));
	if (read_size == 0 && !ft_strchr(*backup, '\n'))
	{
		line = ft_strdup(*backup);
		return (ft_free(backup), line);
	}
	index = 0;
	while ((*backup)[index] && (*backup)[index] != '\n')
		index++;
	if ((*backup)[index] == '\n')
		line = ft_substr(*backup, 0, index + 1);
	else
		line = ft_substr(*backup, 0, index);
	if (!line)
		return (ft_free(backup));
	if (ft_strlen(*backup) > index + 1)
		tmp = ft_substr(*backup, index + 1, ft_strlen(*backup) - index - 1);
	ft_free(backup);
	return (*backup = tmp, line);
}

static int	read_to_backup(int fd, char **backup, char **buf)
{
	char		*tmp;
	int			read_size;

	read_size = read(fd, *buf, BUFFER_SIZE);
	while (read_size > 0)
	{
		(*buf)[read_size] = '\0';
		if (*backup)
			tmp = ft_strjoin(*backup, *buf);
		else
			tmp = ft_strdup(*buf);
		ft_free(backup);
		if (!tmp)
			return (-1);
		*backup = tmp;
		if (ft_strchr(*backup, '\n'))
			break ;
		read_size = read(fd, *buf, BUFFER_SIZE);
	}
	ft_free(buf);
	return (read_size);
}

char	*get_next_line(int fd)
{
	static char	*backup[1024];
	char		*buf;
	int			read_size;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	read_size = read_to_backup(fd, &backup[fd], &buf);
	if (read_size == -1)
		return (ft_free(&buf), ft_free(&backup[fd]));
	return (make_line(&backup[fd], read_size));
}
