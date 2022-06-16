/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailopez- <ailopez-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:52:00 by ailopez-          #+#    #+#             */
/*   Updated: 2022/06/14 13:52:01 by ailopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	dlen;
	size_t	slen;

	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	if (dstsize == 0 || dstsize <= dlen)
		return (slen + dstsize);
	i = 0;
	j = dlen;
	while (*(src + i) != '\0' && i < dstsize - dlen - 1)
	{
		*(dst + j) = *(src + i);
		i++;
		j++;
	}
	*(dst + j) = '\0';
	return (dlen + slen);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(src);
	if (dstsize == 0)
		return (len);
	i = 0;
	while (i < dstsize)
	{
		if (*(src + i) == '\0')
		{
			*(dst + i) = *(src + i);
			return (len);
		}
		*(dst + i) = *(src + i);
		i++;
	}
	*(dst + i - 1) = '\0';
	return (len);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*(s + i) != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ptr;
	int		lens1;
	int		lens2;

	lens1 = ft_strlen(s1);
	lens2 = ft_strlen(s2);
	ptr = malloc (sizeof(char) * (lens1 + lens2 + 1));
	if (!ptr)
		return (NULL);
	ft_strlcpy(ptr, s1, lens1 + 1);
	ft_strlcat(ptr, s2, lens1 + lens2 + 1);
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	char	myc;

	myc = (char)c;
	while (*s != '\0' && *s != myc)
		s++;
	if (*s == myc)
		return ((char *)s);
	return (0);
}
