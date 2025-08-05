/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/04 18:27:46 by vsenniko          #+#    #+#             */
/*   Updated: 2024/09/20 17:50:08 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/** 
 * Allocates (with malloc(3)) and returns an array
 * of strings obtained by splitting ’s’ using the
 * character ’c’ as a delimiter. The array must end
 * with a NULL pointer.
 * 
 * @param s   
 * The string to be split
 * @param c     
 * The delimiter character.
 * 
 * @return
 * The array of new strings resulting from the split.
 * NULL if the allocation fails.
 * 
 * @note
 * If s contain only delimetr chars, we call special func
 * that returns **res with 1 el which = 0.
 * In other case we call trim to delete delimetr from begging
 * and end of str. Than call create_arr() which is calculating
 * numb of delimets + 2 (example: we have 2 words with 1 delim, in
 * that case we will create arr with size 3(2 for words and 1 for 
 * 0)). After that we start fullfill arr with substr().
 * Also free trimed_arr after trim() 
 */
static char	**create_arr(char const *s, char c)
{
	char	**res;
	int		i;
	int		res_size;

	res_size = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			while (s[i] == c && s[i] != '\0')
				i++;
			res_size++;
		}
		if (s[i] != '\0')
			i++;
	}
	res = (char **)ft_calloc((res_size + 2), sizeof(char *));
	if (res == NULL)
		return (NULL);
	res[res_size + 1] = 0;
	return (res);
}

static void	*free_arr(char **res)
{
	int	i;

	i = 0;
	while (res[i] != 0)
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (NULL);
}

static char	**fullfill_arr(char const *s, char c, char **res)
{
	int		start_pos;
	int		i;
	char	*temp;
	int		j;

	i = 0;
	start_pos = 0;
	j = 0;
	while (i <= (int)ft_strlen((char *)s))
	{
		if (s[i] == c || s[i] == '\0')
		{
			temp = ft_substr(s, start_pos, i - start_pos);
			if (temp == NULL)
				return (free_arr(res));
			res[j++] = temp;
			while (i < (int)ft_strlen((char *)s) && s[i] == c && s[i + 1] == c)
				i++;
			start_pos = i + 1;
		}
		if (s[i] == '\0')
			break ;
		++i;
	}
	return (res);
}

static char	**arr_of_delim(void)
{
	char	**res;

	res = (char **)malloc(sizeof(char *));
	if (res == NULL)
		return (NULL);
	res[0] = 0;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	char	*trimed;

	i = 0;
	while (s[i] == c && s[i] != '\0')
		i++;
	if (i == (int)ft_strlen((char *) s))
		return (arr_of_delim());
	trimed = ft_strtrim(s, &c);
	if (trimed == NULL)
		return (NULL);
	res = create_arr(trimed, c);
	if (res == NULL)
	{
		free(trimed);
		return (NULL);
	}
	res = fullfill_arr(trimed, c, res);
	free(trimed);
	if (res == NULL)
		return (NULL);
	return (res);
}
