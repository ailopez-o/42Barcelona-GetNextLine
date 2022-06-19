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


//int main (int argv, char **argc)
int main (void)
{
    int fd;
    char *line;
    int i;

    //if (argv < 2)
    //    return(0);
    //fd = open(argc[1], O_RDONLY | O_CREAT);
    
    fd = open("files/41_no_nl", O_RDONLY | O_CREAT);
    line = get_next_line(fd);
    printf("LINEA %s", line);
    free (line); 
    i = 5;
    while (i--)
    {
        line = get_next_line(fd);
        printf("LINEA %s", line);
        free (line);
    }      
    close (fd);
}






