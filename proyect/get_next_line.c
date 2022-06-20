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

	if (!buffer || buffer[0] == '\0')
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
	int		byte_read;

	if (ft_strchr(buffer, '\n') != 0)
		return (buffer);
	reading = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (reading == NULL)
		return (buffer);
	while (ft_strchr(reading, '\n') == 0)
	{
		byte_read = read(fd, reading, BUFFER_SIZE);
		if (byte_read < 1)
		{
			free(reading);
			return (buffer);
		}
		reading[byte_read] = '\0';
		new_buffer = ft_strjoin(buffer, reading);
		free (buffer);
		buffer = new_buffer;
	}
	free (reading);
	return (buffer);
}

char	*ft_remove_line(char *buffer)
{
	int		size;
	int		start;
	char	*newbuffer;
	int		i;

	if (!buffer)
		return (NULL);
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

	if (fd < 0 || fd > 1023 || BUFFER_SIZE < 1)
		return (NULL);
	if (read(fd, 0, 0) < 0	&& !buffer[fd])
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
