/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npillet <npillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 16:09:17 by npillet           #+#    #+#             */
/*   Updated: 2025/11/04 09:10:57 by npillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	main() //isalpha
{
	printf("%d, ",ft_isalpha('A'));
	printf("%d\n",isalpha('A'));
	printf("%d, ",ft_isalpha('c'));
	printf("%d\n",isalpha('c'));
	printf("%d, ",ft_isalpha('4'));
	printf("%d\n",isalpha('4'));
}

int	main() //isdigit
{
	printf("%d, ",ft_isdigit('A'));
	printf("%d\n",isdigit('A'));
	printf("%d, ",ft_isdigit('c'));
	printf("%d\n",isdigit('c'));
	printf("%d, ",ft_isdigit('4'));
	printf("%d\n",isdigit('4'));
}

int	main() //isalnum
{
	printf("%d, ",ft_isalnum('A'));
	printf("%d\n",isalnum('A'));
	printf("%d, ",ft_isalnum('c'));
	printf("%d\n",isalnum('c'));
	printf("%d, ",ft_isalnum('4'));
	printf("%d\n",isalnum('4'));
	printf("%d, ",ft_isalnum('"'));
	printf("%d\n",isalnum('"'));
}

int	main() //isascii
{
	printf("%d, ",ft_isascii('A'));
	printf("%d\n",isascii('A'));
	printf("%d, ",ft_isascii('c'));
	printf("%d\n",isascii('c'));
	printf("%d, ",ft_isascii('4'));
	printf("%d\n",isascii('4'));
	printf("%d, ",ft_isascii('"'));
	printf("%d\n",isascii('"'));
}

int	main() //isprint
{
	printf("%d, ",ft_isprint('A'));
	printf("%d\n",isprint('A'));
	printf("%d, ",ft_isprint('c'));
	printf("%d\n",isprint('c'));
	printf("%d, ",ft_isprint('4'));
	printf("%d\n",isprint('4'));
	printf("%d, ",ft_isprint('\a'));
	printf("%d\n",isprint('\a'));
}

int	main() //strlen
{
	int	i;
	int	j;
	char	str[] = "Coucou tout le monde";

	i = ft_strlen(str);
	j = strlen(str);
	printf("%ld, ", i);
	printf("%ld\n", j);
}

int	main() //memset
{
	char	str[] = "caca";

	ft_memset(str, 65, 4);
	printf("%s", str);
}

int	main() //bzero
{
	char	str[] = "caca";

	ft_bzero(str, 3);
	printf("%s\n", str);
	bzero(str, 3);
	printf("%s\n", str);
}

int	main() //memcpy
{
	char	src[] = "abcdabcd";
	char	dest[] = "Plopy";

	ft_memcpy(dest, src, 2);
	printf("%s", src);
}

int	main() //memmove
{
	char	str[50] = "I am going from Delhi to Gorakhpur";

	ft_memmove(str +10, str +4, 29);
	printf("%s\n", str);
}

int	main() //strlcpy
{
	size_t	n;

	n = 6;
	char	src[] = "Pipou";
	char	dest[n];
	printf("%ld\n", ft_strlcpy(dest, src, n));
}

int main() //strlcat
{
	size_t	n;

	n = 5;
	char	src[] = "Pipo";
	char	dest[] = "Caca";
	int size = ft_strlcat(dest, src, n);
	printf("%s\n taille : %d\n ", dest, size);
}

int main() //toupper
{
	printf("%c\n", ft_toupper('a'));
	printf("%c\n", ft_toupper('v'));
	printf("%c\n", ft_toupper('L'));
}

int main() //tolower
{
	printf("%c\n", ft_tolower('A'));
	printf("%c\n", ft_tolower('V'));
	printf("%c\n", ft_tolower('l'));
}

int	main() //strchr
{
	char	str[] = "lookalike";

	printf("%s\n", strchr(str, 'k'));
	printf("%s\n", ft_strchr(str, 'k'));
}

int main() //strrchr
{
	char	str[] = "bonjour";

	printf("%s\n", strrchr(str, 'b'));
	printf("%s\n", ft_strrchr(str, 'b'));
}

int main() //strncmp
{
	printf("%d, ", ft_strncmp("ABC", "ABC", 3));
	printf("%d\n", strncmp("ABC", "ABC", 3));

	printf("%d, ", ft_strncmp("ABC", "AB", 3));
	printf("%d\n", strncmp("ABC", "AB", 3));

	printf("%d, ", ft_strncmp("ABA", "ABZ", 3));
	printf("%d\n", strncmp("ABA", "ABZ", 3));

	printf("%d, ", ft_strncmp("ABJ", "ABC", 3));
	printf("%d\n", strncmp("ABJ", "ABC", 3));
}

int	main() //memchr
{
	char	*str = ft_memchr("o7", 'b', 0);

	printf("%s", str);
}

int main() //memcmp
{
	int	str1 [] = {54, 85, 20, 63, 21};
	int	str2 [] = {54, 85, 19, 63, 21};
	size_t n = sizeof(int) * 5;

	printf("%d, ", memcmp(str1, str2, n));
	printf("%d\n", ft_memcmp(str1, str2, n));

	printf("%d, ", memcmp(str1, str1, n));
	printf("%d\n", ft_memcmp(str1, str1, n));

	printf("%d, ", memcmp(str2, str1, n));
	printf("%d\n", ft_memcmp(str2, str1, n));
}

int main() //strnstr
{
	const char	*haystack = "The universe is as big as a big mac";
	const char	*needle = "big";
	char		*result;
	result = ft_strnstr(haystack, needle, 40);
	if (result)
		printf("SUCCES. Next: \"%s\"\n", result);
	else
		printf("FAILED\n");
	return (0);
}

int	main() //atoi
{
	char	p[] = "   -2134bfds4576651";

	printf("%d\n", atoi(p));
	printf("%d\n", ft_atoi(p));
}

int main() //calloc
{
	char *m_calloc = (char *)ft_calloc(5, 4); // 20 octets, mis à zéro
	if (m_calloc != NULL && m_calloc[0] == 0 && m_calloc[19] == 0)
		printf("ft_calloc Test 1: ok\n");
	else
		printf("ft_calloc Test 1: failed\n");
	free(m_calloc);
}

int	main() //strdup
{
	char	p[] = "Salut everybody tout le monde";
	char	*result = ft_strdup(p);

	printf("%s\n", result);
	free(result);
}

// fin part 1

int	main() //substr
{
	char	str[] = "Sashimi";
	char	*result = ft_substr(str, 11, 10);

	printf("%s", result);
	free(result);
}

int	main() //strjoin
{
	char	str1[] = "Laquais";
	char	str2[] = "des mers";
	char	*result = ft_strjoin(str1, str2);

	printf("%s", result);
	free(result);
}

int	main() //strtrim
{
	char	str1 [] = "****Bonj**our**";
	char	s[] = "*";
	char	*result = ft_strtrim(str1, s);

	printf("%s", result);
}

int	main() //split
{
	char	str[] = "***J'ai***envie**de****dormir*zzz*";
	char	**p = ft_split(str, '*');
	int		i;

	i = 0;
	while (p[i] != NULL)
	{
		printf("[%s] \n", p[i]);
		i++;
	}
	ft_freeall(p);
}

int	main() //itoa
{
	char	*result = ft_itoa(0);

	printf("%s", result);
	free(result);
}

char f(unsigned int i, char c) //strmapi
{
	c += i;
	return (c);
}

int	main()
{
	char	str[] = "aaaaaa"; //on attends abcdef comme resultat
	char	*result = ft_strmapi(str, &f);

	printf("%s\n", result);
	free(result);
}

void f(unsigned int i, char *c) //striteri
{
	c += i;
}

int	main()
{
	char	str[] = "aaaaaa"; //on attends abcdef comme resultat

	ft_striteri(str, &f);
	printf("%s\n", str);
}

int	main() //putchar_fd
{
	ft_putchar_fd('b', 1);
}

int	main() //putstr_fd
{
	char	str[] = "crotin";

	ft_putstr_fd(str, 0);
	printf("\n");
	ft_putstr_fd(str, 1);
	printf("\n");
	ft_putstr_fd(str, 2);
	printf("\n");
}

int	main() //putendl_fd
{
	char	str[] = "crotin";

	ft_putendl_fd(str, 0);
	ft_putendl_fd(str, 1);
	ft_putendl_fd(str, 2);
}

int	main() //putnbr_fd
{
	ft_putnbr_fd(42, 1);
	printf("\n");
	ft_putnbr_fd(-42, 1);
}

//fin part 2

//pas de main pour lstnew

void	printlst(t_list *list) //pour les bonus
{
	t_list	*list_deux;

	list_deux = list;
	while (list_deux != NULL)
	{
		printf("%s \n", (char *)list_deux->content);
		list_deux = list_deux->next;
	}
}

static void	ft_delete(void *content)
{
	free(content);
}

static void	ft_flstiter(void *content) //pour lstiter
{
	char	*str;
	int		i;

	str = (char *)content;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == 'o' || str[i] == 'O')
			str[i] = '0';
		else if (str[i] == 'a' || str[i] == 'A')
			str[i] = '4';
		else if (str[i] == 'e' || str[i] == 'E')
			str[i] = '3';
		i++;
	}
}

static void	*ft_flstmap(void *content) //pour lstmap
{
	char	*newstr;
	char	*str;
	int		len;
	int		i;

	str = content;
	len = ft_strlen(str);
	newstr = malloc(sizeof(char) * len + 1);
	i = 0;
	while (str[i])
	{
		if (str[i] == 'a' || str[i] == 'A')
			str[i] = ' ';
		newstr[i] = str[i];
		i++;
	}
	str[i] = '\0';
	return ((void *)newstr);
}


int main() //lstadd_front
{
	t_list	*list;
	t_list	*new1;
	t_list	*new2;

	list = NULL;
	new1 = ft_lstnew(ft_strdup("cfe4768es"));
	new2 = ft_lstnew(ft_strdup("petoman"));
	ft_lstadd_front(&list, new1);
	ft_lstadd_front(&list, new2);
	while (list != NULL)
	{
		printf("%s\n", (char *)list->content);
		list = list->next;
	}
	free(new1);
	free(new2);
}

int	main() //lstsize
{
	t_list	*list;
	t_list	*new1;
	t_list	*new2;
	t_list	*new3;

	list = NULL;
	new1 = ft_lstnew(ft_strdup("cfe4768es"));
	new2 = ft_lstnew(ft_strdup("huhw"));
	new3 = ft_lstnew(ft_strdup("67687"));
	ft_lstadd_front(&list, new1);
	ft_lstadd_front(&list, new2);
	ft_lstadd_front(&list, new3);
	printf("%d\n", ft_lstsize(list));
	while (list != NULL)
	{
		printf("%s\n", (char *)list->content);
		list = list->next;
	}
	free(new1);
	free(new2);
	free(new3);
}

int	main() //lstlast
{
	t_list	*list = NULL;
	t_list	*new1 = ft_lstnew(ft_strdup("hello"));
	t_list	*new2 = ft_lstnew(ft_strdup("world"));
	t_list	*new3 = ft_lstnew(ft_strdup("5615"));
	t_list	*last;

	ft_lstadd_front(&list, new1);
	ft_lstadd_front(&list, new2);
	ft_lstadd_front(&list, new3);
	printlst(list);
	last = ft_lstlast(list);
	if (last != NULL)
		printf("\n\n%s \n", (char *)last->content);
	else
		printf("NULL");
	free(new1);
	free(new2);
	free(new3);
}

int	main() //lstadd_back
{
	t_list	*list = NULL;
	t_list	*new1 = ft_lstnew(ft_strdup("rt la street"));
	t_list	*new2 = ft_lstnew(ft_strdup("ca va la miff?"));
	t_list	*new3 = ft_lstnew(ft_strdup("dodo les petits"));

	ft_lstadd_front(&list, new1);
	ft_lstadd_back(&list, new2);
	ft_lstadd_back(&list, new3);
	while (list != NULL)
	{
		printf("%s\n", (char *)list->content);
		list = list->next;
	}
	free(new1);
	free(new2);
}

int	main() //lstdelone
{
	t_list	*list = NULL;
	t_list	*new1 = ft_lstnew(ft_strdup("Hello"));
	t_list	*new2 = ft_lstnew(ft_strdup("Bonjour"));
	t_list	*new3 = ft_lstnew(ft_strdup("Hallo"));
	t_list	*temp;

	ft_lstadd_front(&list, new1);
	ft_lstadd_back(&list, new2);
	ft_lstadd_back(&list, new3);
	temp = new1;
	temp->next = new2->next;
	new1 = temp;
	ft_lstdelone(new2, ft_delete);
	print_list(list);
	free(new1);
	free(new3);
}

int	main() //lstclear
{
	t_list	*list = NULL;
	t_list	*lst2 = NULL;
	t_list	*new1 = ft_lstnew(ft_strdup("bidule"));
	t_list	*new2 = ft_lstnew(ft_strdup("chose"));
	t_list	*new3 = ft_lstnew(ft_strdup("truc"));

	ft_lstadd_front(&list, new1);
	ft_lstadd_front(&list, new2);
	ft_lstadd_front(&list, new3);
	printf("coucou\n\n");
	print_list(list);
	ft_lstclear(&list, ft_delete);
	printf("c'est clear !\n\n");
	print_list(list);
}

int	main() //lstiter
{
	t_list	*list = NULL;
	t_list	*new1 = ft_lstnew(ft_strdup("crotin"));
	t_list	*new2 = ft_lstnew(ft_strdup("pipeau"));
	t_list	*new3 = ft_lstnew(ft_strdup("Oreo"));

	ft_lstadd_front(&list, new1);
	ft_lstadd_back(&list, new2);
	ft_lstadd_back(&list, new3);
	ft_lstiter(list, ft_flstiter);
	while (list != NULL)
	{
		printf("%s\n", (char *)list->content);
		list = list->next;
	}
	free(new1);
	free(new2);
	free(new3);
}

int	main() //lstmap
{
	t_list	*list = NULL;
	t_list	*list2 = NULL;
	t_list	*new1 = ft_lstnew(ft_strdup("Salut je suis new1 a"));
	t_list	*new2 = ft_lstnew(ft_strdup("Aaaah je suis new2"));
	t_list	*new3 = ft_lstnew(ft_strdup("Yahoo je suis new3"));

	ft_lstadd_front(&list, new1);
	ft_lstadd_back(&list, new2);
	ft_lstadd_back(&list, new3);
	print_list(list);
	list2 = ft_lstmap(list, ft_flstmap, ft_delete);
	print_list(list2);
	ft_lstclear(&list, ft_delete);
	ft_lstclear(&list2, ft_delete);
}
