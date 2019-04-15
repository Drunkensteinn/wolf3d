/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 20:37:40 by ablizniu          #+#    #+#             */
/*   Updated: 2019/04/14 22:38:28 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		main(int32_t argc, char **argv)
{
	t_wolf3d *main_struct;

	if (argc == 2)
	{
		main_struct = init_wolf3d();
		read_and_valid(main_struct, argv[1]);
		preparation(main_struct);
		init_the_game(main_struct);
		mlx_hook(main_struct->mlx->mlx_window, 17, 1L << 17, exit_wolf,
				main_struct);
		mlx_hook(main_struct->mlx->mlx_window, 6, 1L << 6, mouse_event,
				main_struct);
		mlx_hook(main_struct->mlx->mlx_window, 2, 5, keys_press, main_struct);
		mlx_hook(main_struct->mlx->mlx_window, 3, 5, keys_unpress, main_struct);
		mlx_loop_hook(main_struct->mlx->mlx_ptr, draw_cycle,
				(void *)main_struct);
		mlx_loop(main_struct->mlx->mlx_ptr);
	}
	return (0);
}
