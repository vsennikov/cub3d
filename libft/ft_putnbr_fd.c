/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 12:00:53 by vsenniko          #+#    #+#             */
/*   Updated: 2024/09/13 12:01:33 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	write_from_end(char *str, int index, int fd)
{
	while (index >= 0)
	{
		write(fd, &str[index], sizeof(char));
		index--;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	long	numb;
	int		i;
	char	str[11];

	i = 0;
	numb = n;
	if (numb == 0)
		write(fd, "0", sizeof(char));
	else if (numb < 0)
	{
		numb *= -1;
		write(fd, "-", sizeof(char));
	}
	while (numb > 0)
	{
		str[i] = numb % 10 + '0';
		numb /= 10;
		i++;
	}
	str[i] = '\0';
	write_from_end(str, i - 1, fd);
}
