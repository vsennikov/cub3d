/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:40:28 by vsenniko          #+#    #+#             */
/*   Updated: 2024/09/13 12:44:16 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** 
 * The  bzero()  function  erases  the  data  in the n bytes of the memory
 * starting at the location pointed to by s, by writing zeros (bytes  con‐
 * taining '\0') to that area.

 * @param s   
 * Points to at the location of the memory which should be rewrited
 * @param n	  
 * Number of bytes which sould be rewritten 
 * 
 * @return	  
 * None.
 * 
 * @note	  
 * Call ft_memset and passing '\0'. 
*/
void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, '\0', n);
}
