/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npillet <npillet@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 13:31:01 by npillet           #+#    #+#             */
/*   Updated: 2025/11/21 09:43:55 by npillet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	main()
{
	int	i;

		ft_printf("Test :\n\n"); //1 arg

	ft_printf("ft_printf : ");
	i = ft_printf("Bonjour tout le monde");
	ft_printf("\nprintf :    ");
	printf("Bonjour tout le monde\n");
	ft_printf("Letter count : %d", i);

		ft_printf("\n\nTest suivant :\n\n"); //1 arg vide

	ft_printf("ft_printf : ");
	i = ft_printf("");
	ft_printf("\nprintf :    ");
	printf("\n");
	ft_printf("Letter count : %d", i);

		ft_printf("\n\nTest suivant : Character\n\n"); //%c

	char	c;
	c = 'b';
	ft_printf("ft_printf : ");
	i = ft_printf("%c", c);
	ft_printf("\nprintf :    ");
	printf("%c\n", c);
	ft_printf("Letter count : %d", i);

		ft_printf("\n\nTest suivant : String\n\n"); //%s

	char	*str;

	str = "Kikou les copaings";
	ft_printf("ft_printf : ");
	i = ft_printf("%s", str);
	ft_printf("\nprintf :    ");
	printf("%s\n", str);
	ft_printf("Letter count : %d", i);

		ft_printf("\n\nTest suivant : String vide\n\n"); //%s

	str = "";
	ft_printf("ft_printf : ");
	i = ft_printf("%s", str);
	ft_printf("\nprintf :    ");
	printf("%s\n", str);
	ft_printf("Letter count : %d", i);

		ft_printf("\n\nTest suivant : String NULL\n\n"); //%s

	str = NULL;
	ft_printf("ft_printf : ");
	i = ft_printf("%s", str);
	// ft_printf("\nprintf :    ");
	// printf("%s\n", str);
	ft_printf("\nLetter count : %d", i);

		ft_printf("\n\nTest suivant : Percent sign\n\n"); //%%

	ft_printf("ft_printf : ");
	i = ft_printf("%%");
	ft_printf("\nprintf :    ");
	printf("%%\n");
	ft_printf("Letter count : %d", i);

		ft_printf("\n\nTest suivant : Decimal\n\n"); //%d

	int	d;

	d = -156486;
	ft_printf("ft_printf : ");
	i = ft_printf("%d", d);
	ft_printf("\nprintf :    ");
	printf("%d\n", d);
	ft_printf("Letter count : %d", i);

		ft_printf("\n\nTest suivant : Integer\n\n"); //%i

	ft_printf("printf : ");
	i = ft_printf("%i", d);
	ft_printf("\nprintf :    ");
	printf("%i\n", d);
	ft_printf("Letter count : %d", i);

		ft_printf("\n\nTest suivant : Unsigned decimal\n\n"); //%u

	int	u;

	u = 7483648;
	ft_printf("ft_printf : ");
	i = ft_printf("%u", u);
	ft_printf("\nprintf :    ");
	printf("%u\n", u);
	ft_printf("Letter count : %d", i);

		ft_printf("\n\nTest suivant : Unsigned decimal (neg)\n\n"); //%u

	u = -48;
	ft_printf("ft_printf : ");
	i = ft_printf("%u", u);
	ft_printf("\nprintf :    ");
	printf("%u\n", u);
	ft_printf("Letter count : %d", i);

		ft_printf("\n\nTest suivant : Lower hexadecimal\n\n"); //%x

	int	h;

	h = 255;
	ft_printf("ft_printf : ");
	i = ft_printf("%x", h);
	ft_printf("\nprintf :    ");
	printf("%x\n", h);
	ft_printf("Letter count : %d", i);

		ft_printf("\n\nTest suivant : Lower hexadecimal(0)\n\n"); //%x

	h = 0;
	ft_printf("ft_printf : ");
	i = ft_printf("%x", h);
	ft_printf("\nprintf :    ");
	printf("%x\n", h);
	ft_printf("Letter count : %d", i);

		ft_printf("\n\nTest suivant : Lower hexadecimal(neg)\n\n"); //%x

	h = -30;
	ft_printf("ft_printf : ");
	i = ft_printf("%x", h);
	ft_printf("\nprintf :    ");
	printf("%x\n", h);
	ft_printf("Letter count : %d", i);

		ft_printf("\n\nTest suivant : Upper hexadecimal (int max)\n\n"); //%x

	h = INT_MAX;
	ft_printf("ft_printf : ");
	i = ft_printf("%x", h);
	ft_printf("\nprintf :    ");
	printf("%x\n", h);
	ft_printf("Letter count : %d", i);

		ft_printf("\n\nTest suivant : Upper hexadecimal (int min)\n\n"); //%x

	h = INT_MIN;
	ft_printf("ft_printf : ");
	i = ft_printf("%x", h);
	ft_printf("\nprintf :    ");
	printf("%x\n", h);
	ft_printf("Letter count : %d", i);

		ft_printf("\n\nTest suivant : Upper hexadecimal\n\n"); //%X

	h = 234;
	ft_printf("ft_printf : ");
	i = ft_printf("%X", h);
	ft_printf("\nprintf :    ");
	printf("%X\n", h);
	ft_printf("Letter count : %d", i);

			ft_printf("\n\nTest suivant : Upper hexadecimal (0)\n\n"); //%X

	h = 0;
	ft_printf("ft_printf : ");
	i = ft_printf("%X", h);
	ft_printf("\nprintf :    ");
	printf("%X\n", h);
	ft_printf("Letter count : %d", i);

			ft_printf("\n\nTest suivant : Upper hexadecimal (neg)\n\n"); //%X

	h = -46;
	ft_printf("ft_printf : ");
	i = ft_printf("%X", h);
	ft_printf("\nprintf :    ");
	printf("%X\n", h);
	ft_printf("Letter count : %d", i);

		ft_printf("\n\nTest suivant : Upper hexadecimal (int max)\n\n"); //%X

	h = INT_MAX;
	ft_printf("ft_printf : ");
	i = ft_printf("%X", h);
	ft_printf("\nprintf :    ");
	printf("%X\n", h);
	ft_printf("Letter count : %d", i);

		ft_printf("\n\nTest suivant : Upper hexadecimal (int min)\n\n"); //%X

	h = INT_MIN;
	ft_printf("ft_printf : ");
	i = ft_printf("%X", h);
	ft_printf("\nprintf :    ");
	printf("%X\n", h);
	ft_printf("Letter count : %d", i);

		ft_printf("\n\nTest suivant : Address pointer (pointer)\n\n"); //%p

	void	*ptr;

	ptr = &u;
	ft_printf("ft_printf : ");
	i = ft_printf("%p", ptr);
	ft_printf("\nprintf :    ");
	printf("%p\n", ptr);
	ft_printf("Letter count : %d", i);

		ft_printf("\n\nTest suivant : Address pointer (address)\n\n"); //%p

	ft_printf("ft_printf : ");
	i = ft_printf("%p", &ptr);
	ft_printf("\nprintf :    ");
	printf("%p\n", &ptr);
	ft_printf("Letter count : %d", i);;

		ft_printf("\n\nTest suivant : Address pointer (NULL)\n\n"); //%p

	ptr = NULL;
	ft_printf("ft_printf : ");
	i = ft_printf("%p", ptr);
	ft_printf("\nprintf :    ");
	printf("%p\n", ptr);
	ft_printf("Letter count : %d", i);
}
