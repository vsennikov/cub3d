/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:41:37 by vsenniko          #+#    #+#             */
/*   Updated: 2024/09/13 13:04:16 by vsenniko         ###   ########.fr       */
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
 *  It is type-casted to a pointer of type void*.
 * @param n
 * This parameter define the number of bytes to be copied. 
 * 
 * @return
 * This function returns a pointer to destination.
 * 
 * @note
 * We make additional check if dest stands after src and if dest start
 * in src range, than we start copying from the end of the source, in 
 * other case - we call memcpy().
 */
void	*ft_memmove(void *dest_str, const void *src_str, size_t numBytes)
{
	unsigned char	*dest;
	unsigned char	*src;

	dest = (unsigned char *) dest_str;
	src = (unsigned char *) src_str;
	if (dest > src && src + numBytes > dest)
	{
		dest += numBytes - 1;
		src += numBytes - 1;
		while (numBytes != 0)
		{
			*dest = *src;
			dest--;
			src--;
			numBytes--;
		}
	}
	else
		dest = ft_memcpy(dest_str, src_str, numBytes);
	return (dest_str);
}
