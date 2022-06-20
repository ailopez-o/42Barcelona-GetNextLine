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


void ft_free(char *line)
{
	if (line)
		free(line);
}

//int main (int argv, char **argc)
int main (void)
{
    //int     fd;
    char    *line;
	char *name = "files/lines_around_10.txt";


	int fd_1 = open(name, O_RDONLY);
	int fd_2 = open(name, O_RDONLY);
	int fd_3 = open(name, O_RDONLY);
	
	///* 1 */ test_gnl(fd_1, "0123456789\n");
	line = get_next_line(fd_1);
	printf("1.Expectad %s Get %s", "0123456789\n", line);
	ft_free (line);

	///* 2 */ test_gnl(fd_2, "0123456789\n");
	line = get_next_line(fd_2);	
	printf("2.Expectad %s Get %s", "0123456789\n", line);
	ft_free (line);

	//	/* 3 */ test_gnl(fd_3, "0123456789\n");
	line = get_next_line(fd_3);	
	printf("3.Expectad %s Get %s", "0123456789\n", line);
	ft_free (line);

	// 	/* 4 */ test_gnl(fd_1, "012345678\n");
	line = get_next_line(fd_1);
	printf("4.Expectad %s Get %s", "012345678\n", line);
	ft_free (line);

	//	/* 5 */ test_gnl(fd_2, "012345678\n");
	line = get_next_line(fd_2);
	printf("5.Expectad %s Get %s", "012345678\n", line);
	ft_free (line);

	//	/* 6 */ test_gnl(fd_2, "90123456789\n");
	line = get_next_line(fd_2);
	printf("6.Expectad %s Get %s", "90123456789\n", line);
	ft_free (line);

	int fd_4 = open("files/giant_line_nl.txt", O_RDONLY);

	//	/* 7 */ test_gnl(fd_2, "0123456789\n");
	line = get_next_line(fd_2);
	printf("7.Expectad %s Get %s", "90123456789\n", line);
	ft_free (line);

	//	/* 8 */ test_gnl(fd_3, "012345678\n");
	line = get_next_line(fd_3);
	printf("8.Expectad %s Get %s", "012345678\n", line);
	ft_free (line);

	//	/* 9 */ test_gnl(fd_4, expected);
	line = get_next_line(fd_4);
	printf("9.Expectad %s Get %s", "expected\n", line);
	ft_free (line);

	// 	/* 10 */ test_gnl(fd_2, "xxxx\n");
	line = get_next_line(fd_2);
	printf("10.Expectad %s Get %s", "xxxx\n", line);
	ft_free (line);

	//	/* 11 */ test_gnl(fd_2, NULL);
	line = get_next_line(fd_2);
	printf("11.Expectad %s Get %s", "NULL", line);
	ft_free (line);

	//	/* 12 */ test_gnl(fd_1, "90123456789\n");
	line = get_next_line(fd_1);
	printf("12.Expectad %s Get %s", "90123456789\n", line);
	ft_free (line);

	//	/* 13 */ test_gnl(fd_4, "another line!!!");
	line = get_next_line(fd_4);
	printf("13.Expectad %s Get %s", "another line!!!", line);
	ft_free (line);

	//	/* 14 */ test_gnl(fd_1, "0123456789\n");
	line = get_next_line(fd_1);
	printf("14.Expectad %s Get %s", "90123456789\n", line);
	ft_free (line);

	//	/* 15 */ test_gnl(fd_4, NULL);
	line = get_next_line(fd_4);
	printf("15.Expectad %s Get %s", "NULL", line);
	ft_free (line);

	//	/* 16 */ test_gnl(fd_1, "xxxx\n");
	line = get_next_line(fd_2);
	printf("16.Expectad %s Get %s", "xxxx\n", line);
	ft_free (line);

	//	/* 17 */ test_gnl(fd_4, NULL);
	line = get_next_line(fd_4);
	printf("17.Expectad %s Get %s", "NULL", line);
	ft_free (line);

	//	/* 18 */ test_gnl(fd_3, "90123456789\n");
	line = get_next_line(fd_3);
	printf("18.Expectad %s Get %s", "90123456789\n", line);
	ft_free (line);

	//	/* 19 */ test_gnl(fd_3, "0123456789\n");
	line = get_next_line(fd_3);
	printf("19.Expectad %s Get %s", "90123456789\n", line);
	ft_free (line);

	//	/* 20 */ test_gnl(fd_1, NULL);
	line = get_next_line(fd_1);
	printf("20.Expectad %s Get %s", "NULL", line);
	ft_free (line);

	//	/* 21 */ test_gnl(fd_3, "xxxx\n");
	line = get_next_line(fd_3);
	printf("21.Expectad %s Get %s", "xxxx\n", line);
	ft_free (line);

	//	/* 22 */ test_gnl(fd_3, NULL);
	line = get_next_line(fd_3);
	printf("22.Expectad %s Get %s", "NULL", line);
	ft_free (line);	
}






