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
    //char    arg[] = "files/42_with_nl";
    //char    c;

    // INVALID FD
	///* 1 */ test_gnl(-1, NULL);
    line = get_next_line(-1);
    printf("Linea [%s]\n", line);
    ///* 2 */ test_gnl(100, NULL);
    line = get_next_line(100);
    printf("Linea [%s]\n", line);   
	fd = open("files/empty.txt", O_RDONLY);
	close(fd);
	///* 3 */ test_gnl(fd, NULL);
    line = get_next_line(fd);
    printf("Linea [%s]\n", line);  

	// EMPTY
    fd = open("files/empty.txt", O_RDONLY);
	//	/* 1 */ test_gnl(fd, NULL);
    line = get_next_line(fd);
    printf("FD[%d] - Linea [%s]\n", fd, line);   
    //	/* 2 */ test_gnl(fd, NULL);
    line = get_next_line(fd);
    printf("FD[%d] - Linea [%s]\n", fd,line);   

	// 1 CHAR
    fd = open("files/1char.txt", O_RDONLY);
	//	/* 1 */ test_gnl(fd, "0");
    line = get_next_line(fd);
    printf("FD[%d] - Linea [%s]\n", fd,line);   
    free (line);
    //	/* 2 */ test_gnl(fd, NULL);
    line = get_next_line(fd);
    printf("FD[%d] - Linea [%s]\n", fd,line);   	   

}





