/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:52:29 by vsenniko          #+#    #+#             */
/*   Updated: 2024/09/13 12:43:09 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** 
 * The  memchr() function of type void accepts three agruments
 *  that searches for the first occurrence of the character c 
 * (an unsigned char) in the first n bytes of the string pointed
 *  to, by the argument str.

 * @param str   
 * This is the pointer to the memory block where the
 * search is performed. 
 * @param c     
 * This is the value to be passed as an int, but the
 * function performs a byte per byte search using the unsigned 
 * char conversion of this value.
 * @param n
 * This is the number of bytes to be analyzed. 
 * 
 * @return	  
 * This function returns a pointer to the matching byte
 * or NULL if the character does not occur in the given memory 
 * area.
*/
void	*ft_memchr(const void *str, int c, size_t n)
{
	unsigned char	*uc_str;

	uc_str = (unsigned char *) str;
	while (n != 0)
	{
		if (*uc_str == (unsigned char) c)
			return (uc_str);
		uc_str++;
		n--;
	}
	return (NULL);
}
