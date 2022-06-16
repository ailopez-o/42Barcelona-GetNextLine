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

	size = ft_linelen(buffer) + 1;
	line = malloc(size * sizeof (char));
	if (line == NULL)
		return (NULL);
	ft_strlcpy(line, buffer, ft_linelen(buffer) + 1);
	line [size - 1] = '\0';
	if (buffer[0] == '\0')
		return (NULL);
	return (line);
}

char	*ft_read(int fd, char *buffer)
{
	char	*new_buffer;
	char	*reading;
	int		endfile;
	int		bytesread;

	endfile = 0;
	while (ft_strchr(buffer, '\n') == 0 && endfile == 0)
	{
		reading = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (reading == NULL)
			return (buffer);
		reading[BUFFER_SIZE] = '\0';
		bytesread = read(fd, reading, BUFFER_SIZE);
		//printf("\nBYTES[%d] - Cadena [%s]\n", bytesread, reading);
		if (bytesread < BUFFER_SIZE)
		{
			ft_strlcpy (reading, reading, bytesread + 1);
			endfile = 1;
		}
		new_buffer = ft_strjoin(buffer, reading);
		free (buffer);
		free (reading);
		buffer = new_buffer;
	}
	return (buffer);
}

char	*ft_remove_line(char *buffer)
{
	int		size;
	int		start;
	char	*newbuffer;

	start = ft_linelen(buffer);
	size = ft_strlen(buffer) - start;
	newbuffer = malloc (size * sizeof (char));
	if (newbuffer == NULL)
		return (NULL);
	buffer = buffer + start;
	while (*buffer)
	{
		*newbuffer = *buffer;
		newbuffer++;
		buffer++;
	}
	*newbuffer = *buffer;
	return (newbuffer - size);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;
	char		*new_buffer;

	if (fd < 1 || fd > 1023 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (NULL);
	if (!buffer[fd])
	{
		buffer[fd] = malloc(BUFFER_SIZE * sizeof (char));
		if (buffer[fd] == NULL)
			return (NULL);
	}
	buffer[fd] = ft_read(fd, buffer[fd]);
	line = ft_extract_line(buffer[fd]);
	new_buffer = ft_remove_line(buffer[fd]);
	free (buffer[fd]);
	buffer[fd] = new_buffer;
	return (line);
}
