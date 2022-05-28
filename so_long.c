/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abigeddi <abigeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 20:12:04 by abigeddi          #+#    #+#             */
/*   Updated: 2022/05/28 08:19:44 by abigeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void var_init(t_map *var)
{
	var->collectible = 0;
	var->player = 0;
	var->exit = 0;
}

void	open_exit(t_map **var)
{
	int			y;
	int			x;
	int			height;
	int			img_w;
	int			img_h;

	y = 0;
	height = get_height((*var)->map);
	while (y != height)
	{
		x = 0;
		while ((*var)->map[y][x] != '\0')
		{
			if ((*var)->map[y][x] == 'E')
			{
				(*var)->img = mlx_xpm_file_to_image(
						(*var)->mlx_ptr, "./img/exit.xpm", &img_w, &img_h);
				mlx_put_image_to_window((*var)->mlx_ptr,
					(*var)->mlx_win, (*var)->img, x * 64, y * 64);
			}
			x++;
		}
		y++;
	}
}