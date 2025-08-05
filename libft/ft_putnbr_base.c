/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:54:50 by vsenniko          #+#    #+#             */
/*   Updated: 2024/09/19 20:30:04 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	print_symbols(unsigned int nbr, char *base, unsigned int size)
{
	char	ch;
	int		counter;

	counter = 0;
	if (nbr >= size)
		counter += print_symbols(nbr / size, base, size);
	ch = base[nbr % size];
	counter += write(1, &ch, 1);
	return (counter);
}

int	ft_putnbr_base(unsigned int nbr, char *base)
{
	unsigned int	i;

	i = 0;
	while (base[i] != '\0')
		i++;
	return (print_symbols(nbr, base, i));
}

int	ft_putnbr_decimal(int nbr, char *base)
{
	int		counter;
	long	lnbr;

	counter = 0;
	lnbr = nbr;
	if (lnbr < 0)
	{
		counter += write(1, "-", 1);
		lnbr *= -1;
	}
	counter += ft_putnbr_base(lnbr, base);
	return (counter);
}

static int	print_symbols_long(unsigned long nbr, char *base, unsigned int size)
{
	char	ch;
	int		counter;

	counter = 0;
	if (nbr >= size)
		counter += print_symbols_long(nbr / size, base, size);
	ch = base[nbr % size];
	counter += write(1, &ch, 1);
	return (counter);
}

int	ft_putnbr_add(unsigned long add, char *base)
{
	int	counter;

	counter = 0;
	if (add == 0)
		return (write_str("(nil)"));
	counter += write_str("0x");
	counter += print_symbols_long((unsigned long) add, base, 16);
	return (counter);
}
