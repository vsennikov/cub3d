/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:42:52 by vsenniko          #+#    #+#             */
/*   Updated: 2024/09/13 16:57:08 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** 
 * The ft_strlcat() copy and concatenate strings respectively. 
 * It take the full size of the buffer (not just the length) and
 *  guarantee to NUL-terminate the result (as long as there is at
 *  least one byte free in dst). Note that a byte for the NUL should
 *  be included in size. Also note that  strlcat() only operate on true
 *  ''C'' strings. This means that  for strlcat() both src and dst must 
 * be NUL-terminated.
 * The strlcat() function appends the NUL-terminated string src to the end
 * of dst. It will append at most size - strlen(dst) - 1 bytes, 
 * NUL-terminating the result.
 * 
 * @param dst   
 * Null-terminated string where we will copy src.
 * @param src     
 * Null-terminated string wich we will copy.
 * @param size
 * size of the dst + src
 * 
 * @return
 * The initial length of dst plus the length of src.
 * 
 * @note
 * 
 */
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	to_copy;
	size_t	dest_size;

	j = 0;
	dest_size = ft_strlen(dst);
	i = dest_size;
	if (size <= dest_size)
		return (ft_strlen((char *)src) + size);
	else
		to_copy = size - ft_strlen(dst) - 1;
	while (j != to_copy && src[j] != '\0')
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dest_size + ft_strlen((char *)src));
}
