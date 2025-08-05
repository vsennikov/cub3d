/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:41:00 by vsenniko          #+#    #+#             */
/*   Updated: 2024/09/13 16:29:20 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** 
 * The  memcpy() function is used to specify the range 
 * of characters which could not exceed the size of the source 
 * memory.
 * @param dest_str   
 * This parameter define a pointer to the destination array where
 * the content is to be copied. It is type-casted to a pointer of
 * type void*
 * @param src_str     
 * This parameter is used to define the source of data to be copied.
 *  It is then type-casted to a pointer of type void*.
 * @param n
 * This parameter define the number of bytes to be copied. 
 * 
 * @return
 * This function returns a pointer to destination.
 * 
 * @note
 * Added checking for Null at dest && src for francinette. But 
 * regular memcpy give error "null passed to a callee that 
 * requires a non-null argument"
 */
void	*ft_memcpy(void *dest_str, const void *src_str, size_t n)
{
	size_t			i;
	unsigned char	*dest;
	unsigned char	*src;

	if (dest_str == NULL && src_str == NULL)
		return (dest_str);
	i = 0;
	dest = (unsigned char *) dest_str;
	src = (unsigned char *) src_str;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
	return (dest);
}
