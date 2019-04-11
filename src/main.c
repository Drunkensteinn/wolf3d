/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 20:37:40 by ablizniu          #+#    #+#             */
/*   Updated: 2019/04/08 21:36:54 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	init_the_game(t_wolf3d *wolf)
{
	wolf->player[2] = (t_vector){0, 0, 1};
	wolf->player[1] = (t_vector){-1, 0, 0};
	matrix_mult(wolf);
	main_draw_function(wolf);
}

int		main(int32_t argc, char **argv)
{
	t_wolf3d *main_struct;

	if (argc == 2)
	{
		main_struct = init_wolf3d();
		read_and_valid(main_struct, argv[1]);
		preparation(main_struct);
		init_the_game(main_struct);
		mlx_hook(main_struct->mlx->mlx_window,2,5,keys, main_struct);
		mlx_loop(main_struct->mlx->mlx_ptr);
	}
	return (0);
}