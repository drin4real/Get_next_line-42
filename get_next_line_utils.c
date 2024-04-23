/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dbislimi <dbislimi@student.42nice.fr>      #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-04-23 12:22:19 by dbislimi          #+#    #+#             */
/*   Updated: 2024-04-23 12:22:19 by dbislimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	size_t	i;

	i = 0;
	dup = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!dup)
		return (NULL);
	while (s[i])
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	srclen;
	size_t	i;
	size_t	j;

	i = 0;
	srclen = ft_strlen(src);
	j = ft_strlen(dst);
	if (size <= j)
		return (size + srclen);
	while (src[i] && j + 1 < size)
		dst[j++] = src[i++];
	dst[j] = 0;
	return (ft_strlen(src + i) + j);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	size_t	s1len;
	size_t	s2len;

	s1len = ft_strlen(s1);
	s2len = ft_strlen(s2);
	joined = (char *)malloc(sizeof(char) * (s1len + s2len + 1));
	if (!joined)
		return (0);
	*joined = 0;
	ft_strlcat(joined, s1, s1len + 1);
	ft_strlcat(joined, s2, s1len + s2len + 1);
	return (joined);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)s + i);
	return (NULL);
}
