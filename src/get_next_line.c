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
#include "../inc/get_next_line.h"

char	*ft_extract_line(char *buffer)
{
	char	*line;
	int		size;

	size = ft_linelen(buffer) + 1;
	line = malloc(size * sizeof (char));
	if (line == NULL)
		return (NULL);
	ft_memmove(line, buffer, ft_linelen(buffer) + 1);
	line [size - 1] = '\0';
	if (buffer[0] == '\0')
		return (NULL);
	return (line);
}

char	*ft_trim(int size, char *str)
{
	char	*trim;

	trim = malloc((size + 1) * sizeof(char));
	if (trim == NULL)
		return (NULL);
	trim = ft_memcpy(trim, str, size);
	trim [size] = '\0';
	free (str);
	return (trim);
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
		reading = malloc(BUFFER_SIZE * sizeof (char));
		if (reading == NULL)
			return (buffer);
		bytesread = read(fd, reading, BUFFER_SIZE);
		if (bytesread < BUFFER_SIZE)
		{
			reading = ft_trim(bytesread, reading);
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
	int	size;
	int	start;

	start = ft_linelen(buffer);
	size = ft_strlen(buffer) - start;
	return (ft_substr(buffer, start, size));
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;
	char		*new_buffer;

	if (!buffer[fd])
	{
		buffer[fd] = malloc(BUFFER_SIZE * sizeof (char));
		read(fd, buffer, BUFFER_SIZE);
	}
	buffer[fd] = ft_read(fd, buffer[fd]);
	line = ft_extract_line(buffer[fd]);
	new_buffer = ft_remove_line(buffer[fd]);
	free (buffer[fd]);
	buffer[fd] = new_buffer;
	return (line);
}
