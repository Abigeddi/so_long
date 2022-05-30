/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abigeddi <abigeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 19:39:15 by abigeddi          #+#    #+#             */
/*   Updated: 2022/05/29 18:03:40 by abigeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include"ft_printf/ft_printf.h"
# include"get_next_line/get_next_line.h"
# include"libft/libft.h"

typedef struct s_map
{
	int		y_player;
	int		x_player;
	char	**map;
	int		player;
	int		collectible;
	int		exit;
	int		imgheight;
	int		imgwidth;
	void	*mlx_ptr;
	void	*mlx_win;
	int		moves;
	void	*img;
}	t_map;

int		check_file_type(char *s, char *type);
void	check_file(char *s);
void	var_init(t_map *var);
char	**store_map(char *map);
void	check_map(t_map *var);
int		ft_strlen_nl(char *str);
void	ft_free(t_map ***var, char *err);
int		get_height(char **map);
void	is_rectangular(t_map **var);
void	check_walls(t_map **var);
void	check_content(t_map **var);
void	collected(t_map ***v);
void	to_left(t_map **v);
void	to_down(t_map **v);
void	to_up(t_map **v);
void	to_right(t_map **v);
int		key_hook(int keycode, t_map *vars);
int		quit(t_map *v);
void	exit_door(t_map ***v);
void	put_text(t_map ***v);
void	put_image(t_map ***v, int x, int y, char *img);
void	put_image_to_map(char p, int x1, int y1, t_map **v);
void	render_map(t_map *vars);
#endif
