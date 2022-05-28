/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abigeddi <abigeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 14:05:47 by abigeddi          #+#    #+#             */
/*   Updated: 2022/05/28 18:17:36 by abigeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_map(t_map *vars)
{
	int	y1;
	int	y_map;
	int	backup_w;
	int	x1;
	int	x_map;

	y1 = 0;
	y_map = 0;
	backup_w = vars->imgwidth;
	while (vars->imgheight > 0)
	{
		x1 = 0;
		x_map = 0;
		while (vars->imgwidth > 0)
		{
			put_image_to_map(vars->map[y_map][x_map], x1, y1, &vars);
			x_map++;
			x1 += 64;
			vars->imgwidth--;
		}
		vars->imgwidth = backup_w;
		y_map++;
		y1 += 64;
		vars->imgheight--;
	}
}

void	put_image(t_map ***v, int x, int y, char *img)
{
	int		img_w;
	int		img_h;

	(**v)->img = mlx_xpm_file_to_image((**v)->mlx_ptr, img, &img_w, &img_h);
	mlx_put_image_to_window((**v)->mlx_ptr, (**v)->mlx_win, (**v)->img, x, y);
}

void	put_image_to_map(char p, int x1, int y1, t_map **v)
{
	if (p == '1')
		put_image(&v, x1, y1, "./img/tile1.xpm");
	else if (p == 'C')
	{
		put_image(&v, x1, y1, "./img/tile0.xpm");
		put_image(&v, x1, y1, "./img/fish.xpm");
	}
	else if (p == 'E')
		put_image(&v, x1, y1, "./img/exit.xpm");
	else if (p == 'P')
	{
		(*v)->y_player = y1;
		(*v)->x_player = x1;
		put_image(&v, x1, y1, "./img/tile0.xpm");
		put_image(&v, x1, y1, "./img/player_1.xpm");
	}
	else
		put_image(&v, x1, y1, "./img/tile0.xpm");
}

