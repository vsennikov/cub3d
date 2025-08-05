/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:53:08 by vsenniko          #+#    #+#             */
/*   Updated: 2024/09/13 11:53:38 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	n;

	i = 0;
	j = 0;
	if (little[j] == 0)
		return ((char *)big);
	while (big[i] != '\0' && i != len)
	{
		if (big[i] == little[j])
		{
			n = i;
			while (big[n] == little[j] && n != len && little[j] != '\0')
			{
				n++;
				j++;
			}
			if (little[j] == '\0')
				return ((char *)&big[n - j]);
			j = 0;
		}
		i++;
	}
	return (NULL);
}
