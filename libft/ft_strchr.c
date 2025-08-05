/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:44:01 by vsenniko          #+#    #+#             */
/*   Updated: 2024/09/13 12:11:08 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int search_str)
{
	int	i;
	int	size;

	i = 0;
	size = (int) ft_strlen((char *)str);
	while (i <= size)
	{
		if ((unsigned char) str[i] == (unsigned char) search_str)
			return ((char *)(str + i));
		i++;
	}
	return (0);
}
