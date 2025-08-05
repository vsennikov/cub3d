/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:39:53 by vsenniko          #+#    #+#             */
/*   Updated: 2024/09/13 13:07:07 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/** 
 * The   memset() function of type void accepts three variable as
 * parameters that copies the character c (an unsigned char) to
 * the first n characters of the string pointed to, by the argument
 * str.
 * This function is used to fill a contiguous block of memory with
 *  a specific value. It also converts the value of a character to
 *  unsigned character and copies it into each of first n character
 *  of the object pointed by the given string. If the n is larger
 *  than string size, it will be undefined.
 * 
 * @param str   
 * This is a pointer to the block of memory to fill.
 * @param c     
 * This is a second parameter of type integer and converts it to 
 * an unsigned char before using it to fill a block of memory.
 * @param n
 * This is the number of bytes to be set to the value. 
 * 
 * @return
 * This function returns a pointer to the memory area str.
 */
void	*ft_memset(void *str, int c, size_t n)
{
	size_t				i;
	unsigned char		*ptr;

	i = 0;
	ptr = (unsigned char *) str;
	while (i < n)
	{
		ptr[i] = (unsigned char) c;
		i++;
	}
	return (str);
}
