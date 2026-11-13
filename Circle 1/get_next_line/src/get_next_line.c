/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npillet <npillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 10:43:05 by npillet           #+#    #+#             */
/*   Updated: 2025/12/09 11:33:21 by npillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
		newstock = ft_substr(stock, (i + 1), len);
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
	static char	*stock;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (stock == NULL)
		stock = ft_strdup("");
	if (!ft_strchr(stock, '\n'))
		stock = readline(fd, stock);
	if (stock == NULL)
		return (NULL);
	if (*stock == '\0')
	{
		free(stock);
		stock = NULL;
		return (NULL);
	}
	line = fillline(stock);
	stock = clearbuffer(stock);
	return (line);
}
