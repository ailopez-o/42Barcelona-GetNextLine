/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ailopez- <ailopez-@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 13:51:43 by ailopez-          #+#    #+#             */
/*   Updated: 2022/06/14 13:51:46 by ailopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/get_next_line.h"

int ft_linelen(char *s)
{
    size_t	i;

	i = 0;
	while (*(s + i) != '\n')
		i++;
	return (i);
}

char *ft_extract_line(char *buffer)
{
    char    *line;

    line = malloc((ft_linelen(buffer) + 1) * sizeof (char));
    ft_memmove(line, buffer, ft_linelen(buffer) + 1);
    return(line);
}

char *ft_read(int fd, char *buffer)
{
    char        *new_buffer;
    char        *reading;

    if (!buffer)
    {
        buffer = malloc(BUFFER_SIZE * sizeof (char));
        read(fd, buffer, BUFFER_SIZE);
    } 
    reading = malloc(BUFFER_SIZE * sizeof (char)); 
    while (ft_strchr(buffer, '\n') == 0)
    {
        read(fd, reading, BUFFER_SIZE);
        new_buffer = ft_strjoin(buffer, reading);
        free (buffer);
        buffer = new_buffer;
    }
    free (reading);
    return(new_buffer);
}

char *ft_remove_line(char *buffer)
{
    int     size;
    int     start;

    start = ft_linelen(buffer) + 1;
    size = ft_strlen(buffer) - start;
    return (ft_substr(buffer,start, size));
}

char *get_next_line(int fd)
{
    static char *buffer[1024];
    char        *line;
    char        *new_buffer;

    buffer[fd] = ft_read(fd, buffer[fd]);
    line = ft_extract_line(buffer[fd]);
    new_buffer = ft_remove_line(buffer[fd]);
    free (buffer[fd]);
    buffer[fd] = new_buffer;
    return (line);
}

