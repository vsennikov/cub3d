/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:57:28 by vsenniko          #+#    #+#             */
/*   Updated: 2024/09/13 12:38:18 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	calculate_size(long n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i = 1;
		n *= -1;
	}
	else if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	fullfill_itoa(char *res, long n, int minus, int size)
{
	if (n == 0)
		res[0] = '0';
	while (n != 0)
	{
		res[size - 1] = n % 10 + '0';
		n /= 10;
		size--;
	}
	if (minus)
		res[0] = '-';
}

char	*ft_itoa(int n)
{
	char	*res;
	int		j;
	int		minus;
	long	numb;

	j = calculate_size(n) + 1;
	minus = 0;
	numb = n;
	if (numb < 0)
	{
		minus = 1;
		numb *= -1;
	}
	res = (char *)malloc((j) * sizeof(char));
	if (res == NULL)
		return (NULL);
	res[--j] = '\0';
	fullfill_itoa(res, numb, minus, j);
	return (res);
}
