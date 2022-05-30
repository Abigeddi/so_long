/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abigeddi <abigeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 01:33:18 by abigeddi          #+#    #+#             */
/*   Updated: 2022/05/30 10:27:10 by abigeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_walls(t_map **var)
{
	int	i;

	i = 0;
	while (i < (*var)->imgwidth)
	{
		if ((*var)->map[0][i] != '1' ||
			(*var)->map[(*var)->imgheight - 1][i] != '1')
			ft_free(&var, "Error: Wrong wall structure");
		i++;
	}
	i = 0;
	while (i < (*var)->imgheight)
	{
		if ((*var)->map[i][0] != '1' ||
			(*var)->map[i][(*var)->imgwidth - 1] != '1')
			ft_free(&var, "Error wrong wall structure");
		i++;
	}
}

void	error(t_map *var)
{
	if (var->collectible == 0)
	{
		write (2, "Error\nmissing collectible\n", 21);
		exit (1);
	}
	if (var->player == 0)
	{
		write (2, "Error\nmissing player\n", 21);
		exit (1);
	}
	if (var->exit == 0)
	{
		write (2, "Error\nmissing the exit\n", 23);
		exit (1);
	}
}

int	map_content(t_map *var, char c)
{
	if (c != 'E' && c != '0' && c != '1' && c != 'P' && c != 'C')
	{
		write (2, "Error : Unknown content\n", 24);
		exit (1);
	}
	else if (c == 'P')
		var->player++;
	else if (c == 'C')
		var->collectible++;
	else if (c == 'E')
		var->exit++;
	return (1);
}

void	check_content(t_map **var)
{
	int	i;
	int	j;
	int	e;

	i = 0;
	e = (*var)->imgheight;
	j = 0;
	while (i < (*var)->imgwidth)
	{
		while (j < (*var)->imgheight)
		{
			if (map_content((*var), (*var)->map[j][i]))
				i++;
			if ((*var)->map[j][i] == '\0' && e > 0)
			{
				e--;
				i = 0;
				break ;
			}
		}	
		j++;
		if (e == 0)
			break ;
	}
	error (*var);
}
