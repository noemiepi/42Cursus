/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_main_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npillet <npillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 10:32:49 by npillet           #+#    #+#             */
/*   Updated: 2026/01/15 12:59:05 by npillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	main()
{
	int		fd1;
	int		fd2;
	int		fd3;
	char	*next_line1;
	char	*next_line2;
	char	*next_line3;

	fd1 = open("test/test.txt", O_RDONLY);
	fd2 = open("test/canard.txt", O_RDONLY);
	fd3 = open("test/nl.txt", O_RDONLY);
	// fd2 = 42; //invalid fd
	// fd2 = 0; //stdinput
	if (fd1 < 0 || fd2 < 0 || fd3 < 0)
	{
		printf("File didn't open");
		return (0);
	}
	while (1)
	{
		next_line1 = get_next_line(fd1);
		if (next_line1 == NULL && next_line2 == NULL && next_line3 == NULL)
			break ;
		printf("%s(fd1)\n", next_line1);
		free(next_line1);
		next_line2 = get_next_line(fd2);
		if (next_line2 == NULL && next_line1 == NULL && next_line3 == NULL)
			break ;
		printf("%s(fd2)\n", next_line2);
		free(next_line2);
		next_line3 = get_next_line(fd3);
		if (next_line3 == NULL && next_line1 == NULL && next_line2 == NULL)
			break ;
		printf("%s(fd3)\n", next_line3);
		free(next_line3);
	}
	close(fd1);
	close(fd2);
	close(fd3);
	return (0);
}
