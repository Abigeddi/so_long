/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abigeddi <abigeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 22:54:22 by abigeddi          #+#    #+#             */
/*   Updated: 2022/05/28 15:13:07 by abigeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	collected(t_map ***v)
{
	int		img_w;
	int		img_h;

	(**v)->collectible--;
	(**v)->map[((**v)->y_player / 64)][((**v)->x_player / 64)] = '0';
	(**v)->img = mlx_xpm_file_to_image(
			(**v)->mlx_ptr, "./img/tile0.xpm", &img_w, &img_h);
	mlx_put_image_to_window(
		(**v)->mlx_ptr, (**v)->mlx_win, (**v)->img, (**v)->x_player, (**v)->y_player);
}

void	to_left(t_map **v)
{
	int		img_w;
	int		img_h;

	(*v)->img = mlx_xpm_file_to_image(
			(*v)->mlx_ptr, "./img/tile0.xpm", &img_w, &img_h);
	mlx_put_image_to_window(
		(*v)->mlx_ptr, (*v)->mlx_win, (*v)->img, (*v)->x_player, (*v)->y_player);
	if ((*v)->map[((*v)->y_player / 64)][((*v)->x_player / 64) - 1] == 'E')
	{
		if ((*v)->collectible <= 0)
			exit_door(&v);
	}
	else if ((*v)->map[((*v)->y_player / 64)][((*v)->x_player / 64) - 1] != '1')
	{
		(*v)->x_player -= 64;
		put_text(&v);
	}
	if ((*v)->map[((*v)->y_player / 64)][((*v)->x_player / 64)] == 'C')
		collected(&v);
	(*v)->img = mlx_xpm_file_to_image(
			(*v)->mlx_ptr, "./img/player_1.xpm", &img_w, &img_h);
	mlx_put_image_to_window(
		(*v)->mlx_ptr, (*v)->mlx_win, (*v)->img, (*v)->x_player, (*v)->y_player);
}

void	to_down(t_map **v)
{
	int		img_w;
	int		img_h;

	(*v)->img = mlx_xpm_file_to_image(
			(*v)->mlx_ptr, "./img/tile0.xpm", &img_w, &img_h);
	mlx_put_image_to_window(
		(*v)->mlx_ptr, (*v)->mlx_win, (*v)->img, (*v)->x_player, (*v)->y_player);
	if ((*v)->map[((*v)->y_player / 64) + 1][((*v)->x_player / 64)] == 'E')
	{
		if ((*v)->collectible <= 0)
			exit_door(&v);
	}
	else if ((*v)->map[((*v)->y_player / 64) + 1][((*v)->x_player / 64)] != '1')
	{
		(*v)->y_player += 64;
		put_text(&v);
	}
	if ((*v)->map[((*v)->y_player / 64)][((*v)->x_player / 64)] == 'C')
		collected(&v);
	(*v)->img = mlx_xpm_file_to_image(
			(*v)->mlx_ptr, "./img/player_1.xpm", &img_w, &img_h);
	mlx_put_image_to_window(
		(*v)->mlx_ptr, (*v)->mlx_win, (*v)->img, (*v)->x_player, (*v)->y_player);
}

void	to_up(t_map **v)
{
	int		img_w;
	int		img_h;

	(*v)->img = mlx_xpm_file_to_image(
			(*v)->mlx_ptr, "./img/tile0.xpm", &img_w, &img_h);
	mlx_put_image_to_window(
		(*v)->mlx_ptr, (*v)->mlx_win, (*v)->img, (*v)->x_player, (*v)->y_player);
	if ((*v)->map[((*v)->y_player / 64) - 1][((*v)->x_player / 64)] == 'E')
	{
		if ((*v)->collectible <= 0)
			exit_door(&v);
	}
	else if ((*v)->map[((*v)->y_player / 64) - 1][((*v)->x_player / 64)] != '1')
	{
		(*v)->y_player -= 64;
		put_text(&v);
	}
	if ((*v)->map[((*v)->y_player / 64)][((*v)->x_player / 64)] == 'C')
		collected(&v);
	(*v)->img = mlx_xpm_file_to_image(
			(*v)->mlx_ptr, "./img/player_1.xpm", &img_w, &img_h);
	mlx_put_image_to_window(
		(*v)->mlx_ptr, (*v)->mlx_win, (*v)->img, (*v)->x_player, (*v)->y_player);
}

void	to_right(t_map **v)
{
	int		img_w;
	int		img_h;

	(*v)->img = mlx_xpm_file_to_image(
			(*v)->mlx_ptr, "./img/tile0.xpm", &img_w, &img_h);
	mlx_put_image_to_window(
		(*v)->mlx_ptr, (*v)->mlx_win, (*v)->img, (*v)->x_player, (*v)->y_player);
	if ((*v)->map[((*v)->y_player / 64)][((*v)->x_player / 64) + 1] == 'E')
	{
		if ((*v)->collectible <= 0)
			exit_door(&v);
	}
	else if ((*v)->map[((*v)->y_player / 64)][((*v)->x_player / 64) + 1] != '1')
	{
		(*v)->x_player += 64;
		put_text(&v);
	}
	if ((*v)->map[((*v)->y_player / 64)][((*v)->x_player / 64)] == 'C')
		collected(&v);
	(*v)->img = mlx_xpm_file_to_image(
			(*v)->mlx_ptr, "./img/player_1.xpm", &img_w, &img_h);
	mlx_put_image_to_window(
		(*v)->mlx_ptr, (*v)->mlx_win, (*v)->img, (*v)->x_player, (*v)->y_player);
}

