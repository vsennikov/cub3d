/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/27 16:36:44 by vsenniko          #+#    #+#             */
/*   Updated: 2026/02/09 15:46:20 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

char	*trim_whitespace(char *str)
{
	int		i;
	int		j;
	int		len;
	char	*result;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	j = ft_strlen(str) - 1;
	while (j >= i && (str[j] == ' ' || str[j] == '\t' || str[j] == '\n'
			|| str[j] == '\r'))
		j--;
	len = j - i + 1;
	if (len <= 0)
		return (NULL);
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	ft_memcpy(result, str + i, len);
	result[len] = '\0';
	return (result);
}

char	*trim_newlines(char *str)
{
	int		i;
	int		len;
	char	*result;

	if (!str)
		return (NULL);
	len = ft_strlen(str);
	i = len - 1;
	while (i >= 0 && (str[i] == '\n' || str[i] == '\r'))
	{
		i--;
		len--;
	}
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	ft_memcpy(result, str, len);
	result[len] = '\0';
	return (result);
}

int	check_line(char *line, char *identifier)
{
	int	i;

	if (!line || !identifier)
		return (0);
	i = ft_strlen(identifier);
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	while (line[i] && line[i] != ' ' && line[i] != '\t' && line[i] != '\n'
		&& line[i] != '\r')
		i++;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (line[i] && line[i] != '\n' && line[i] != '\r' && line[i] != '\0')
		return (0);
	return (1);
}

int	check_color_line(char *line, char *identifier)
{
	int	i;

	if (!line || !identifier)
		return (0);
	i = ft_strlen(identifier);
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	while (line[i] && ((line[i] >= '0' && line[i] <= '9') || line[i] == ','
			|| line[i] == ' ' || line[i] == '\t'))
		i++;
	while (line[i] && (line[i] == ' ' || line[i] == '\t'))
		i++;
	if (line[i] && line[i] != '\n' && line[i] != '\r' && line[i] != '\0')
		return (0);
	return (1);
}
