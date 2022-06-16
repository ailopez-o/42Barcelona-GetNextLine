/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aitorlopezdeaudicana <marvin@42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 00:01:38 by aitorlope         #+#    #+#             */
/*   Updated: 2022/06/16 00:01:41 by aitorlope        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../inc/get_next_line.h"
#include <stdio.h> 
#include <fcntl.h> 


int main (void)
{
    int fd;
    //int fd2;
    char *line;
    //char *buffer;

/*
    fd2 = open("files/file1.txt", O_RDONLY | O_CREAT);
    buffer = malloc(1000 * sizeof (char)); 
    read(fd2, buffer, 1000);
    close (fd2);
    printf("VERSO %s", buffer); 
*/
    //buffer = malloc(30 * sizeof(char));
    fd = open("files/file1.txt", O_RDONLY | O_CREAT);

    line = get_next_line(fd);
    printf("LINEA %s", line); 
    while (line)
    {
        line = get_next_line(fd);
        if (line)
        {   
            printf("LINEA %s", line);
            free (line);
        }
    }      
    close (fd);
    //read(fd, buffer, 30);
    //printf("FD [%d] - %s",fd, buffer);
}




