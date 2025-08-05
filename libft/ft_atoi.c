/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:05:42 by vsenniko          #+#    #+#             */
/*   Updated: 2025/01/06 12:52:13 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isspace(char ch)
{
	if ((ch >= '\t' && ch <= '\r') || ch == ' ')
		return (1);
	return (0);
}

/** 
 * The  atoi() function converts the initial portion of the string pointed 
 * to by nptr to int. The behavior is the same as strtol(nptr, NULL, 10);
 * except that atoi() does not detect errors.
 * 
 * @param str 
 * It is a pointer to a null-terminated sting, which represent the a integer.
 *  It can have one '+' or one '-'and a bunch of spaces.
 * 
 * @return	  
 * The converted value or 0 on error.
 * 
 * @note	  
 * Spaces checked with static func. 
 * 
*/
long	ft_atoi(const char *str)
{
	int		i;
	int		minus;
	long	result;

	i = 0;
	minus = 0;
	result = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-')
	{
		minus = 1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	if (minus)
		result *= -1;
	return (result);
}
