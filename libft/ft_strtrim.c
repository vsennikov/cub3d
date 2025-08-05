/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:56:21 by vsenniko          #+#    #+#             */
/*   Updated: 2024/09/13 12:11:47 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	part_of_set(char const *set, char ch)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == ch)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start_pos;
	int		last_pos;
	char	*res;

	start_pos = 0;
	while (part_of_set(set, s1[start_pos]) == 1)
		start_pos++;
	last_pos = (int) ft_strlen((char *)s1) - 1;
	while (part_of_set(set, s1[last_pos]) == 1)
		last_pos--;
	res = ft_substr(s1, start_pos, (last_pos - start_pos) + 1);
	return (res);
}
