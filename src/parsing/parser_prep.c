/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_prep.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 16:36:35 by vsenniko          #+#    #+#             */
/*   Updated: 2026/02/09 15:38:17 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	basic_error_exit(char *msg)
{
	printf("Error\n%s\n", msg);
	exit(1);
}

int	name_validation(char *name)
{
	int		i;
	char	*extension;

	i = 0;
	while (name[i])
	{
		if (name[i] == '.' && name[i + 4] == '\0' && i != 0)
		{
			extension = ft_substr(name, i, 5);
			if (!extension)
				basic_error_exit("ft_substr failed");
			if (ft_strncmp(extension, ".cub", 5) != 0)
			{
				free(extension);
				basic_error_exit("map format not .cub");
			}
			else
				return (free(extension), 1);
		}
		i++;
	}
	basic_error_exit("map not .cub");
	return (1);
}
