/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:51:07 by vsenniko          #+#    #+#             */
/*   Updated: 2024/09/13 12:10:04 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;

	i = (int) ft_strlen((char *) str);
	while (i >= 0)
	{
		if ((unsigned char)str[i] == (unsigned char)c)
			return ((char *)str + i);
		i--;
	}
	return (0);
}
