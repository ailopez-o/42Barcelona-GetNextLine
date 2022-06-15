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

char *ft_line(char *buffer)
{
    buffer = buffer + 1;
    buffer = buffer - 1;
    return(ft_strdup("Linea leida)"));

}

char *get_next_line(int fd)
{
    static char *buffer;
    char        *new_buffer;
    char        *reading;
    char        *line;

    if (!buffer)
    {
        buffer = malloc(BUFFER_SIZE * sizeof (char));
        read(fd, buffer, BUFFER_SIZE);
    } 
    printf("FD [%d] -- BUFFER[%d]\n %s\n", fd, BUFFER_SIZE, buffer);
    reading = NULL;
    while (ft_strchr(buffer, '\n') == 0)
    {
        printf("Buffer read\n");
        read(fd, reading, BUFFER_SIZE);
        new_buffer = ft_strjoin(buffer, reading);
        free (buffer);
        free (reading);
        buffer = new_buffer;
    }
    line = ft_line(buffer);
    return (line);
}

