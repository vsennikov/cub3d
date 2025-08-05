/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/03 16:46:24 by vsenniko          #+#    #+#             */
/*   Updated: 2024/09/13 13:00:43 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** 
 * The  memcmp() function can be used to compare two blocks of memory. 
 * In general, it is used to compare the binary data or raw data.
 * memcmp() accepts three variable as parameters that compares the first n bytes 
 * of memory area str1 and memory area str2.

 * @param str1   
 * This is the pointer to the first block of memory. 
 * @param str2     
 * This is the pointer to the second block of memory.
 * @param n
 * This parameter define the number of bytes to be compared. 
 * 
 * @return
 * If the return value < 0, it indicates str1 is less than str2.
 * If the return value > 0, it indicates str2 is less than str1.
 * If the return value == 0, it represents str1 is equivalent to the str2.
 */
int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*uc_str1;
	unsigned char	*uc_str2;

	uc_str1 = (unsigned char *)str1;
	uc_str2 = (unsigned char *)str2;
	if (n == 0)
		return (0);
	while (*uc_str1 == *uc_str2 && n - 1 != 0)
	{
		uc_str1++;
		uc_str2++;
		n--;
	}
	return (*uc_str1 - *uc_str2);
}
