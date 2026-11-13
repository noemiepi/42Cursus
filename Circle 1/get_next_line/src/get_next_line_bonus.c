/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npillet <npillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/25 09:59:12 by npillet           #+#    #+#             */
/*   Updated: 2025/12/08 12:09:19 by npillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*clearbuffer(char *stock)
{
	char	*newstock;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(stock);
	while (stock[i] != '\n' && stock[i] != '\0')
		i++;
	if (stock[i] == '\0')
		newstock = ft_strdup("");
	else
		newstock = ft_substr(stock, (i + 1), (len - i));
	free(stock);
	return (newstock);
}

char	*fillline(char *stock)
{
	char	*line;
	int		i;

	i = 0;
	while (stock[i] != '\n' && stock[i] != '\0')
		i++;
	if (stock[i] == '\0')
		line = ft_substr(stock, 0, i);
	else
		line = ft_substr(stock, 0, (i + 1));
	return (line);
}

char	*freeall(char *buffer, char *stock)
{
	free(buffer);
	free(stock);
	return (NULL);
}

char	*readline(int fd, char *stock)
{
	char	*buffer;
	char	*temp;
	ssize_t	byteread;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	temp = NULL;
	if (!buffer)
		return (NULL);
	byteread = 1;
	while (byteread > 0)
	{
		byteread = read(fd, buffer, BUFFER_SIZE);
		if (byteread == -1)
			return (freeall(buffer, stock));
		buffer[byteread] = '\0';
		temp = stock;
		stock = ft_strjoin(temp, buffer);
		free(temp);
		if (ft_strchr(stock, '\n'))
			break ;
	}
	free(buffer);
	return (stock);
}

char	*get_next_line(int fd)
{
	static char	*stock[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (stock[fd] == NULL)
		stock[fd] = ft_strdup("");
	if (!ft_strchr(stock[fd], '\n'))
		stock[fd] = readline(fd, stock[fd]);
	if (stock[fd] == NULL)
		return (NULL);
	if (*stock[fd] == '\0')
	{
		free(stock[fd]);
		stock[fd] = NULL;
		return (NULL);
	}
	line = fillline(stock[fd]);
	stock[fd] = clearbuffer(stock[fd]);
	return (line);
}
