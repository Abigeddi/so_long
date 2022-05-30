/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abigeddi <abigeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 20:42:43 by abigeddi          #+#    #+#             */
/*   Updated: 2022/05/30 10:28:34 by abigeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_height(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		i++;
	return (i);
}

int	ft_strlen_nl(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

void	ft_free(t_map ***var, char *err)
{
	int	i;

	i = 0;
	while ((**var)->map[i])
	{
		free((**var)->map[i]);
		i++;
	}
	free((**var)->map);
	ft_putendl_fd(err, 2);
	exit(1);
}

void	is_rectangular(t_map **var)
{
	int	tmp;
	int	i;

	i = 0;
	(*var)->imgheight = get_height((*var)->map);
	(*var)->imgwidth = ft_strlen_nl((*var)->map[i]);
	tmp = (*var)->imgheight;
	while (tmp > 0)
	{
		if ((*var)->imgwidth != ft_strlen_nl((*var)->map[i]))
			ft_free(&var, "Error: Map is not revtangular");
		i++;
		tmp--;
	}
}

void	check_map(t_map *var)
{
	is_rectangular(&var);
	check_walls(&var);
	check_content(&var);
}
