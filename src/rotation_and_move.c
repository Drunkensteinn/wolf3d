/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_and_move.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 14:32:17 by ablizniu          #+#    #+#             */
/*   Updated: 2019/03/29 16:03:00 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int keys(int code, t_wolf3d *wolf)
{
	double x;
	double y;

	define_players_vectors(wolf);
	if (code == A_KEY)
	{
		x = wolf->player[1][0];
		y = wolf->player[1][1];
		wolf->player[1][0] = x * cos(0.1 * M_PI / 180) - y * sin(0.1 * M_PI / 180);
		wolf->player[1][1] = x * sin(0.1 * M_PI / 180) + y * cos(0.1 * M_PI / 180);
		printf("A ");
		printf("vectors - x: %f y: %f \n" , wolf->player[1][0],wolf->player[1][1]);
	}
	else if (code == D_KEY)
	{
		x = wolf->player[1][0];
		y = wolf->player[1][1];
		wolf->player[1][0] = x * cos(0.1 * M_PI / 180) + y * sin(0.1 * M_PI / 180);
		wolf->player[1][1] = -x * sin(0.1 * M_PI / 180) + y * cos(0.1 * M_PI / 180);
		printf("D ");
		printf("vectors - x: %f y: %f \n" , wolf->player[1][0],wolf->player[1][1]);
	}
	ft_bzero(wolf->mlx->data_buff, H * W);
	mlx_clear_window(wolf->mlx->mlx_ptr, wolf->mlx->mlx_window);
	main_draw_function(wolf);
	return (0);
}