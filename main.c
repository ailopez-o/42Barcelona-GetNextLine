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
    int     fd;
    char    *line;
	char *name = "files/lines_around_10.txt";

	fd = open(name, O_RDONLY);
	///* 1 */ test_gnl(fd, "0123456789\n");
	line = get_next_line(fd);
    printf("Expected: %s MiGet %s", "0123456789\n", line);
    ///* 2 */ test_gnl(fd, "012345678\n");
	line = get_next_line(fd);    
    printf("Expected: %s MiGet %s", "012345678\n", line);  
	close(fd);
	char *temp;
	do
	{
	    temp = get_next_line(fd);
		free(temp);
	} while (temp != NULL);
	///* 3 */ test_gnl(fd, NULL);
	line = get_next_line(fd);    
    printf("Expected: %s MiGet %s", "NULL", line);
	fd = open(name, O_RDONLY);
	///* 4 */ test_gnl(fd, "0123456789\n");
	line = get_next_line(fd);    
    printf("Expected: %s MiGet %s", "0123456789\n", line); 	
    ///* 5 */ test_gnl(fd, "012345678\n");
	line = get_next_line(fd);    
    printf("Expected: %s MiGet %s", "012345678\n", line);  
	///* 6 */ test_gnl(fd, "90123456789\n");
	line = get_next_line(fd);    
    printf("Expected: %s MiGet %s", "90123456789\n", line);
	///* 7 */ test_gnl(fd, "0123456789\n");
	line = get_next_line(fd);    
    printf("Expected: %s MiGet %s", "0123456789\n", line);		
    ///* 8 */ test_gnl(fd, "xxxx\n");
	line = get_next_line(fd);    
    printf("Expected: %s MiGet %s", "xxxx\n", line);	
    ///* 9 */ test_gnl(fd, NULL);
	line = get_next_line(fd);    
    printf("Expected: %s MiGet %s", "NULL", line);	  
	return(0);	
}






