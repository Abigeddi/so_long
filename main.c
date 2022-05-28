/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abigeddi <abigeddi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 16:48:21 by abigeddi          #+#    #+#             */
/*   Updated: 2022/05/28 14:19:38 by abigeddi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int main(int ac,char **av)
{
    t_map var;
    
    if (ac != 2)
    {
        write (2, "ERROR : wrong use of executable\n", 32);
        exit (1);
    }
    check_file(av[1]);
    var_init(&var);
    var.map = store_map(av[1]);
    if (var.map != NULL)
    {
        check_map(&var);
        var.mlx_ptr = mlx_init();
        var.mlx_win = mlx_new_window(var.mlx_ptr, var.imgwidth * 64,
				var.imgheight * 64, "So_Long");
        render_map(&var);
        ft_printf("\033[1;33m== Start Game ==\033[0m\n");
        mlx_hook(var.mlx_win, 2, 0, key_hook, &var);
		    mlx_hook(var.mlx_win, 17, 0, quit, &var);
	    	mlx_loop(var.mlx_ptr);
    }
}