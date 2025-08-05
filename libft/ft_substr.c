/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:55:18 by vsenniko          #+#    #+#             */
/*   Updated: 2025/01/02 19:13:05 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	real_size;

	i = 0;
	real_size = ft_strlen((char *) s);
	if ((start > real_size - 1 && real_size != 0))
		len = 0;
	else if (real_size == 0 && start > real_size)
		len = 0;
	else
		real_size = ft_strlen((char *) s + start);
	if (real_size < len)
		len = real_size;
	substr = (char *)ft_calloc(33, sizeof(char));
	if (substr == NULL)
		return (NULL);
	while (i < len && s[start])
	{
		substr[i] = s[start];
		i++;
		start++;
	}
	substr[i] = '\0';
	return (substr);
}
