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
#include "proyect/get_next_line.h"
#include <stdio.h> 
#include <fcntl.h> 

/*
int main (int argv, char **argc)
{
    int fd;
    char *line;
    int i;

    if (argv < 2)
        return(0);
    fd = open(argc[1], O_RDONLY | O_CREAT);

    line = get_next_line(fd);
    printf("LINEA %s", line);
    free (line); 
    i = 5;
    while (i--)
    {
        line = get_next_line(fd);
        if (line)
        {   
            printf("LINEA %s", line);
            free (line);
        }
    }      
    close (fd);
}
*/


int main (void)
{
    int     fd;
    char    *line;
    char    arg[] = "files/42_with_nl";
    char    c;

    fd = open(arg, O_RDONLY | O_CREAT);

    line = get_next_line(fd);
    printf("LINEA %s", line);
    free (line); 
    read(fd, &c, 1);
    printf("caracter %c\n", c);
    line = get_next_line(fd);
    printf("LINEA2 %s", line); 
    return (0);
    while (line)
    {
        line = get_next_line(fd);
        printf("LINEA2 %s", line);
        if (line)
            free (line);
    }      
    close (fd);
}





