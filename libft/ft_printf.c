/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 12:58:57 by vsenniko          #+#    #+#             */
/*   Updated: 2024/09/26 13:06:26 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	write_char(int c)
{
	return (write(1, &c, 1));
}

int	write_str(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (write(1, "(null)", 6));
	while (str[i] != '\0')
	{
		write_char((int)str[i]);
		i++;
	}
	return (i);
}

static int	choose_func(char c, va_list ap)
{
	int	j;

	j = 0;
	if (c == 'c')
		j += write_char(va_arg(ap, int));
	else if (c == 's')
		j += write_str(va_arg(ap, char *));
	else if (c == '%')
		j += write_char('%');
	else if (c == 'd' || c == 'i')
		j += ft_putnbr_decimal(va_arg(ap, int), "0123456789");
	else if (c == 'u')
		j += ft_putnbr_base(va_arg(ap, unsigned int), "0123456789");
	else if (c == 'x')
		j += ft_putnbr_base(va_arg(ap, unsigned int), "0123456789abcdef");
	else if (c == 'X')
		j += ft_putnbr_base(va_arg(ap, unsigned int), "0123456789ABCDEF");
	else if (c == 'p')
		j += ft_putnbr_add(va_arg(ap, unsigned long), "0123456789abcdef");
	else
	{
		j += write_char('%');
		j += write_char(c);
	}
	return (j);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		i;
	int		counter;

	va_start(ap, format);
	i = 0;
	counter = 0;
	if (format == NULL)
		return (-1);
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			counter += choose_func(format[++i], ap);
		else
			counter += write(1, &format[i], 1);
		i++;
	}
	va_end(ap);
	return (counter);
}

// #include <limits.h>
// int    main(void)
// {
// 	int counter; 

// 	counter = ft_printf(NULL);
// 	printf("%d\n", counter);
// 	counter = printf(NULL);
// 	printf("%d", counter);

// }
// 	int	counter;
// 	//%c
	// counter = ft_printf("%c\n", 'a');
	// printf("ft_printf counter = %d\n", counter);
	// counter = printf("%c\n", 'a');
	// printf("printf counter = %d\n", counter);
	// printf("============================\n");
	// counter = ft_printf("%c\n", 127);
	// printf("ft_printf counter = %d\n", counter);
	// counter = printf("%c\n", 127);
	// printf("printf counter = %d\n", counter);
	// printf("============================\n");
	// counter = ft_printf("%c\n", '\0');
	// printf("ft_printf counter = %d\n", counter);
	// counter = printf("%c\n", '\0');
	// printf("printf counter = %d\n", counter);
	// printf("============================\n");
	// counter = ft_printf("%c\n", NULL);
	// printf("ft_printf counter = %d\n", counter);
	// counter = printf("%c\n", NULL);
	// printf("printf counter = %d\n", counter);
	// printf("============================\n");
	// counter = ft_printf("%c\n", "NULL");
	// printf("ft_printf counter = %d\n", counter);
	// counter = printf("%c\n", "NULL");
	// printf("printf counter = %d\n", counter);
	// printf("============================\n");
	// counter = ft_printf("%c\n", "");
	// printf("ft_printf counter = %d\n", counter);
	// counter = printf("%c\n", "");
	// printf("printf counter = %d\n", counter);
	// printf("============================\n");

	//%s
	// counter = ft_printf("Hello world!\n");
	// printf("ft_printf counter = %d\n", counter);
	// counter = printf("Hello world\n");
	// printf("printf counter = %d\n", counter);
	// printf("============================\n");
	// counter = ft_printf("Hello%s !%s\n", "world");
	// printf("ft_printf counter = %d\n", counter);
	// counter = printf("Hello%s !%s\n", "world");
	// printf("printf counter = %d\n", counter);
	// printf("============================\n");
	// counter = ft_printf("Hello%s !\n", NULL);
	// printf("ft_printf counter = %d\n", counter);
	// counter = printf("Hello%s !\n", NULL);
	// printf("printf counter = %d\n", counter);
	// printf("============================\n");

	//%p
	// void *p1 = 10;
	// counter = ft_printf("%p\n", p1);
	// printf("ft_printf counter = %d\n", counter);
	// counter = printf("%p\n", p1);
	// printf("printf counter = %d\n", counter);
	// printf("============================\n");
	// void *p2;
	// counter = ft_printf("%p\n", p2);
	// printf("ft_printf counter = %d\n", counter);
	// counter = printf("%p\n", p2);
	// printf("printf counter = %d\n", counter);
	// printf("============================\n");
	// char *str = "regpfdjve ";
	// void *p3 = &str;
	// counter = ft_printf("%p\n", p3);
	// printf("ft_printf counter = %d\n", counter);
	// counter = printf("%p\n", p3);
	// printf("printf counter = %d\n", counter);
	// printf("============================\n");
	// counter = ft_printf("%p %p\n", LONG_MIN, LONG_MAX);
	// printf("ft_printf counter = %d\n", counter);
	// counter = printf("%p %p\n", LONG_MIN, LONG_MAX);
	// printf("printf counter = %d\n", counter);
	// printf("============================\n");

	//%d %i
	// counter = ft_printf("%d\n", INT_MIN);
	// printf("ft_printf counter = %d\n", counter);
	// counter = printf("%d\n", INT_MIN);
	// printf("printf counter = %d\n", counter);
	// printf("============================\n");
	// counter = ft_printf("%d\n", INT_MAX);
	// printf("ft_printf counter = %d\n", counter);
	// counter = printf("%d\n", INT_MAX);
	// printf("printf counter = %d\n", counter);
	// printf("============================\n");
	// counter = ft_printf("%d\n", INT_MAX + 1);
	// printf("ft_printf counter = %d\n", counter);
	// counter = printf("%d\n", INT_MAX + 1);
	// printf("printf counter = %d\n", counter);
	// printf("============================\n");
	// long long lnb = LLONG_MAX - 10;
	// counter = ft_printf("%d\n", lnb);
	// printf("ft_printf counter = %d\n", counter);
	// counter = printf("%d\n", lnb);
	// printf("printf counter = %d\n", counter);
	// printf("============================\n");

	//%u
	// counter = ft_printf("%u\n", UINT_MAX);
	// printf("ft_printf counter = %d\n", counter);
	// counter = printf("%u\n", UINT_MAX);
	// printf("printf counter = %d\n", counter);
	// printf("============================\n");	
	// counter = ft_printf("%u\n", 0);
	// printf("ft_printf counter = %d\n", counter);
	// counter = printf("%u\n", 0);
	// printf("printf counter = %d\n", counter);
	// printf("============================\n");
	// counter = ft_printf("%u\n", NULL);
	// printf("ft_printf counter = %d\n", counter);
	// counter = printf("%u\n", NULL);
	// printf("printf counter = %d\n", counter);
	// printf("============================\n");
	// counter = ft_printf("%u\n", "Hello");
	// printf("ft_printf counter = %d\n", counter);
	// counter = printf("%u\n", "Hello");
	// printf("printf counter = %d\n", counter);
	// printf("============================\n");	
	// counter = ft_printf("%u\n", INT_MIN);
	// printf("ft_printf counter = %d\n", counter);
	// counter = printf("%u\n", INT_MIN);
	// printf("printf counter = %d\n", counter);
	// printf("============================\n");	

	//%x
	// counter = ft_printf("%x\n", INT_MIN);
	// printf("ft_printf counter = %d\n", counter);
	// counter = printf("%x\n", INT_MIN);
	// printf("printf counter = %d\n", counter);
	// printf("============================\n");
	// counter = ft_printf("%x\n", INT_MAX);
	// printf("ft_printf counter = %d\n", counter);
	// counter = printf("%x\n", INT_MAX);
	// printf("printf counter = %d\n", counter);
	// printf("============================\n");
	// counter = ft_printf("%x\n", LLONG_MAX);
	// printf("ft_printf counter = %d\n", counter);
	// counter = printf("%x\n", LLONG_MAX);
	// printf("printf counter = %d\n", counter);
	// printf("============================\n");
	// counter = ft_printf("%x\n", LONG_MIN);
	// printf("ft_printf counter = %d\n", counter);
	// counter = printf("%x\n", LONG_MIN);
	// printf("printf counter = %d\n", counter);
	// printf("============================\n");
	// counter = ft_printf("%x\n", -1);
	// printf("ft_printf counter = %d\n", counter);
	// counter = printf("%x\n", -1);
	// printf("printf counter = %d\n", counter);
	// printf("============================\n");

	//%X
	// counter = ft_printf("%X\n", INT_MIN);
	// printf("ft_printf counter = %d\n", counter);
	// counter = printf("%X\n", INT_MIN);
	// printf("printf counter = %d\n", counter);
	// printf("============================\n");
	// counter = ft_printf("%X\n", INT_MAX);
	// printf("ft_printf counter = %d\n", counter);
	// counter = printf("%X\n", INT_MAX);
	// printf("printf counter = %d\n", counter);
	// printf("============================\n");
	// counter = ft_printf("%X\n", LLONG_MAX);
	// printf("ft_printf counter = %d\n", counter);
	// counter = printf("%X\n", LLONG_MAX);
	// printf("printf counter = %d\n", counter);
	// printf("============================\n");
	// counter = ft_printf("%X\n", LONG_MIN);
	// printf("ft_printf counter = %d\n", counter);
	// counter = printf("%X\n", LONG_MIN);
	// printf("printf counter = %d\n", counter);
	// printf("============================\n");
	// counter = ft_printf("%X\n", -1);
	// printf("ft_printf counter = %d\n", counter);
	// counter = printf("%X\n", -1);
	// printf("printf counter = %d\n", counter);
	// printf("============================\n");

	//%%
// 	counter = ft_printf("%%\n");
// 	printf("ft_printf counter = %d\n", counter);
// 	counter = printf("%%\n");
// 	printf("printf counter = %d\n", counter);
// 	printf("============================\n");
	// counter = ft_printf("%%%\n");
	// printf("ft_printf counter = %d\n", counter);
	// counter = printf("%%%\n");
	// printf("printf counter = %d\n", counter);
	// printf("============================\n");

	//smt
	// counter = ft_printf("%ww%w\n", 10, 20);
	// printf("ft_printf counter = %d\n", counter);
	// counter = printf("%ww%w\n", 10, 20);
	// printf("printf counter = %d\n", counter);
	// printf("============================\n");
// }
