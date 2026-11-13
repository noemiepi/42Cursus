/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npillet <npillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:44:29 by npillet           #+#    #+#             */
/*   Updated: 2026/02/17 10:55:31 by npillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main()
{
	int		fd;
	char	*next_line;

	fd = open("test/bible.txt", O_RDONLY);
	// fd = 42; //invalid fd
	// fd = 0; //stdinput
	if (fd < 0)
	{
		printf("File didn't open");
		return (0);
	}
	while (1)
	{
		next_line = get_next_line(fd);
		if (next_line == NULL)
			break ;
		printf("%s", next_line);
		free(next_line);
		next_line = NULL;
	}
	close(fd);
	return (0);
}
