/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abigeddi <abigeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 20:54:25 by abigeddi          #+#    #+#             */
/*   Updated: 2022/05/30 10:36:50 by abigeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include "so_long.h"

int	key_hook(int keycode, t_map *vars)
{
	int	i;

	if (keycode == 2 || keycode == 124)
		to_right(&vars);
	else if (keycode == 0 || keycode == 123)
		to_left(&vars);
	else if (keycode == 13 || keycode == 126)
		to_up(&vars);
	else if (keycode == 1 || keycode == 125)
		to_down(&vars);
	else if (keycode == 53)
	{
		i = 0;
		while (vars->map[i])
		{
			free(vars->map[i]);
			i++;
		}
		free(vars->map);
		ft_printf("END\n");
		mlx_destroy_window(vars->mlx_ptr, vars->mlx_win);
		exit (1);
	}
	return (0);
}

int	quit(t_map *v)
{
	int	i;

	i = 0;
	while (v->map[i])
	{
		free (v->map[i]);
		i++;
	}
	free(v->map);
	ft_printf("END\n");
	mlx_destroy_window(v->mlx_ptr, v->mlx_win);
	exit (1);
	return (0);
}

void	exit_door(t_map ***v)
{
	int	i;

	i = 0;
	while ((**v)->map[i])
	{
		free ((**v)->map[i]);
		i++;
	}
	free((**v)->map);
	ft_printf("END\n");
	mlx_destroy_window((**v)->mlx_ptr, (**v)->mlx_win);
	exit (1);
}

void	put_text(t_map ***v)
{
	char	*num;

	num = ft_itoa(++(**v)->moves);
	ft_printf("STEPS :%s\n", num);
	free(num);
}
