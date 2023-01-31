/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yel-hadr <yel-hadr@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 14:37:23 by yel-hadr          #+#    #+#             */
/*   Updated: 2022/11/05 19:11:41 by yel-hadr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*ptr;
	int				n;

	n = count * size;
	ptr = malloc(count * size);
	if (!ptr)
		return (NULL);
	while (n-- != 0)
		((unsigned char *)ptr)[n] = '\0';
	return (ptr);
}

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p;

	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (NULL);
	p = ft_calloc((ft_strlen(s1) + ft_strlen(s2)) + 1, sizeof(char));
	if (!p)
		return (NULL);
	ft_memmove(p, s1, ft_strlen(s1));
	ft_memmove(p + ft_strlen(s1), s2, ft_strlen(s2));
	free((char *)s1);
	return (p);
}

char	*ft_strdup(const char *s)
{
	char	*ptr;
	char	*str;
	int		i;

	if (!s)
		return (NULL);
	ptr = ft_calloc((ft_strlen(s) + 1), sizeof(char));
	if (!ptr)
		return (NULL);
	str = (char *)s;
	i = 0;
	while (*str)
		ptr[i++] = *str++;
	ptr[i] = '\0';
	return (ptr);
}

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	if (!dst || !src)
		return (NULL);
	if (src < dst)
	{
		while (len--)
			((unsigned char *)dst)[len] = ((unsigned char *)src)[len];
	}
	else
	{
		while (i < len)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dst);
}
