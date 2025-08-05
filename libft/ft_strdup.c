/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:54:26 by vsenniko          #+#    #+#             */
/*   Updated: 2024/09/13 16:47:04 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/**
 * The  strdup() function returns a pointer to a 
 * new string which is a duplicate of the string s.
 * Memory for the new string  is  obtained  with
 * malloc(3), and can be freed with free(3).
 */
char	*ft_strdup(const char *s)
{
	int		i;
	char	*res;

	i = ft_strlen((char *) s) + 1;
	res = (char *)malloc(i * sizeof(char));
	if (res == NULL)
		return (NULL);
	i = 0;
	while (s[i] != '\0')
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}
