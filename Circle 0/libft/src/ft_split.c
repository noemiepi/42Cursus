/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npillet <npillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 12:12:54 by npillet           #+#    #+#             */
/*   Updated: 2025/10/30 12:30:27 by npillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_countwords(char const *s, char c)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			word++;
		i++;
	}
	return (word);
}

static char	**ft_freeall(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return (NULL);
	while (tab[i] != NULL)
	{
		if (tab[i])
			free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static	char	*ft_filltab(char const *s, char c)
{
	int		len;
	char	*str;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	str = ft_substr(s, 0, len);
	if (!str)
		return (NULL);
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	j;
	size_t	word;

	if (!s)
		return (NULL);
	word = ft_countwords(s, c);
	tab = malloc(sizeof(char *) * (word + 1));
	if (!tab)
		return (NULL);
	j = 0;
	while (j < word)
	{
		while (*s == c)
			s++;
		tab[j] = ft_filltab(s, c);
		if (tab[j] == NULL)
			return (ft_freeall(tab));
		while (*s && *s != c)
			s++;
		j++;
	}
	tab[j] = 0;
	return (tab);
}
