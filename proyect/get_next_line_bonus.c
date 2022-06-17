/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailopez- <ailopez-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:51:43 by ailopez-          #+#    #+#             */
/*   Updated: 2022/06/16 11:06:59 by aitorlope        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	ft_linelen(char *s)
{
	size_t	i;

	i = 0;
	while (*(s + i) != '\n' && *(s + i) != '\0')
		i++;
	if (*(s + i) == '\0')
		return (i);
	return (i + 1);
}

char	*ft_extract_line(char *buffer)
{
	char	*line;
	int		size;

	if (buffer[0] == '\0')
		return (NULL);
	size = ft_linelen(buffer) + 1;
	line = ft_calloc(size, sizeof (char));
	if (line == NULL)
		return (NULL);
	ft_strlcpy(line, buffer, size);
	return (line);
}

char	*ft_read(int fd, char *buffer)
{
	char	*new_buffer;
	char	*reading;
	int		bytes;

	bytes = 1;
	while (ft_strchr(buffer, '\n') == 0 && bytes > 0)
	{
		reading = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
		if (reading == NULL)
			return (buffer);
		bytes = read(fd, reading, BUFFER_SIZE);
		new_buffer = ft_strjoin(buffer, reading);
		free (reading);
		free (buffer);
		buffer = new_buffer;
	}
	return (buffer);
}

char	*ft_remove_line(char *buffer)
{
	int		size;
	int		start;
	char	*newbuffer;
	int		i;

	start = ft_linelen(buffer);
	size = ft_strlen(buffer) - start;
	newbuffer = ft_calloc (size + 1, sizeof (char));
	if (newbuffer == NULL)
		return (NULL);
	i = 0;
	while (buffer[start + i] != '\0')
	{
		newbuffer[i] = buffer[start + i];
		i++;
	}
	newbuffer[i] = buffer[start + i];
	free (buffer);
	return (newbuffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;

	if (fd < 0 || fd > 1023 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!buffer[fd])
	{
		buffer[fd] = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
		if (buffer[fd] == NULL)
			return (NULL);
		if (read(fd, buffer[fd], BUFFER_SIZE) < 1)
			return (NULL);
	}
	buffer[fd] = ft_read(fd, buffer[fd]);
	line = ft_extract_line(buffer[fd]);
	buffer[fd] = ft_remove_line(buffer[fd]);
	if (line == NULL)
		free (buffer[fd]);
	return (line);
}
