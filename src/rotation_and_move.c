/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_and_move.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 14:32:17 by ablizniu          #+#    #+#             */
/*   Updated: 2019/03/29 20:10:29 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int keys(int32_t code, t_wolf3d *wolf)
{
	rotating(wolf, code);
	movement(wolf, code);
	ft_bzero(wolf->mlx->data_buff, (size_t)(H * W * wolf->mlx->bpp));
	mlx_clear_window(wolf->mlx->mlx_ptr, wolf->mlx->mlx_window);
	matrix_mult(wolf);
	main_draw_function(wolf);
	mlx_do_sync(wolf->mlx->mlx_ptr);
	return (0);
}

void	rotating(t_wolf3d *wolf, int32_t code)
{
	double x;
	double y;

	if (code == A_KEY)
	{
		x = wolf->player[1][0];
		y = wolf->player[1][1];
		wolf->player[1][0] = x * cos((-5.9 * M_PI) / 180) + y * sin((-5.9 * M_PI) / 180);
		wolf->player[1][1] = (-x * sin((-5.9 * M_PI) / 180)) + y * cos((-5.9 * M_PI) / 180);
		printf("A - ");
		printf("dir vectors - x: %G y: %G \n" , (double)wolf->player[1][0], (double)wolf->player[1][1]);
	}
	else if (code == D_KEY)
	{
		x = wolf->player[1][0];
		y = wolf->player[1][1];
		wolf->player[1][0] = x * cos((5.9 * M_PI) / 180) + y * sin((5.9 * M_PI) / 180);
		wolf->player[1][1] = (-x * sin((5.9 * M_PI) / 180)) + y * cos((5.9 * M_PI) / 180);
		printf("D - ");
		printf("dir vectors - x: %G y: %G \n" , (double)wolf->player[1][0], (double)wolf->player[1][1]);
	}
}

void	make_step(t_wolf3d *wolf, t_bool direction)
{
	if (direction)
	{
		wolf->player_coord_y += 10;
		wolf->map_pos_y = (size_t)(wolf->player_coord_y / DEFAULT_SCALE);
	}
	else
	{
		wolf->player_coord_y -= 10;
		wolf->map_pos_y = (size_t)(wolf->player_coord_y / DEFAULT_SCALE);
	}
}

void	movement(t_wolf3d *wolf, int32_t code)
{
	if (code == W_KEY)
	{
		make_step(wolf, 1);
	}
	else if (code == S_KEY)
	{
		make_step(wolf, 0);
	}
}