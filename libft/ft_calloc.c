/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:54:05 by vsenniko          #+#    #+#             */
/*   Updated: 2024/11/28 19:35:45 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** 
 * The calloc() function is used to allocates the requested 
 * memory and returns a pointer to it. It reserves a block of 
 * memory for array of objects and initialize all bytes in the 
 * allocated storage to zero.
 * If we try to read the value of the allocated memory without 
 * initializing it, we will get 'zero' because it has already been 
 * initialized to 0 by calloc().

 * @param nitems   
 * It represents the number of element to be allocated.
 * @param size
 * It represents the size of each element. 
 * 
 * @return 
 * Returns pointer to allocated memory with all bytes 
 * initialized to zero.If the allocation fails, then it
 * returns a null pointer.
*/
void	*ft_calloc(size_t nitems, size_t size)
{
	unsigned char	*arr;
	size_t			i;

	i = 0;
	arr = (unsigned char *)malloc(nitems * size);
	if (arr == NULL)
		return (NULL);
	while (i != nitems * size)
	{
		arr[i] = 0;
		i++;
	}
	return (arr);
}
