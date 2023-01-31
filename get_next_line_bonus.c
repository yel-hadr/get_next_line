/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr <yel-hadr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 14:36:54 by yel-hadr          #+#    #+#             */
/*   Updated: 2022/11/05 19:10:30 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	find_newline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_get_line(char *rest)
{
	int		new_line;
	char	*line;

	if (!rest || !*rest)
		return (NULL);
	new_line = find_newline(rest);
	if (new_line == -1)
	{
		line = ft_strdup(rest);
		return (line);
	}
	line = ft_calloc(new_line + 2, sizeof(char));
	line = ft_memmove(line, rest, new_line + 1);
	return (line);
}

char	*ft_get_rest(char *rest)
{
	int		len_rest;
	int		new_line;
	char	*tmp;

	if (!rest)
		return (NULL);
	len_rest = ft_strlen(rest);
	new_line = find_newline(rest);
	if (new_line != -1 && rest[new_line + 1])
	{
		tmp = ft_strdup(&rest[new_line + 1]);
		free (rest);
		rest = tmp;
		return (rest);
	}
	if (rest)
	{
		free (rest);
		rest = NULL;
	}
	return (rest);
}

char	*ft_read_fd(int fd, char *rest)
{
	int		read_size;
	char	*buffer;

	read_size = 1;
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (NULL);
	while (read_size > 0 && find_newline(buffer) == -1)
	{
		read_size = read(fd, buffer, BUFFER_SIZE);
		if (read_size > 0)
		{
			if (read_size != BUFFER_SIZE)
				buffer[read_size] = '\0';
			rest = ft_strjoin(rest, buffer);
		}
	}
	free (buffer);
	return (rest);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*rest[OPEN_MAX];

	if (BUFFER_SIZE <= 0 || (fd < 0 && fd > OPEN_MAX))
		return (NULL);
	rest[fd] = ft_read_fd(fd, rest[fd]);
	line = ft_get_line(rest[fd]);
	rest[fd] = ft_get_rest(rest[fd]);
	return (line);
}
