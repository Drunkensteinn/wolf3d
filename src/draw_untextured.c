/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_untextured.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 23:03:30 by ablizniu          #+#    #+#             */
/*   Updated: 2019/04/15 11:36:25 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void			draw_wall(t_wolf3d *wolf, double len, int32_t attribute)
{
	double		line_height;
	int32_t		draw_start;
	int32_t		draw_end;

	line_height = calculate_wall(wolf, len);
	draw_start = (int32_t)(-line_height / 2 + ((double)H / 2));
	if (draw_start < 0)
		draw_start = 0;
	draw_end = (int32_t)line_height / 2 + (H / 2);
	if (draw_end >= H)
		draw_end = H - 1;
	write_line(wolf, draw_start, draw_end, attribute);
	draw_untextured_floor_celling(wolf, draw_end);
}

void			draw_untextured_floor_celling(t_wolf3d *wolf,
				int32_t end_of_wall)
{
	while (end_of_wall < H - 1)
	{
		put_image(wolf->mlx, (int32_t)wolf->x_column_fov, end_of_wall,
				0x00FA9A);
		put_image(wolf->mlx, (int32_t)wolf->x_column_fov, H - end_of_wall,
				0xD8BFD8);
		end_of_wall++;
	}
}

void			draw_untextured_walls(t_wolf3d *wolf,
				double ray_x, double ray_y)
{
	if (ray_x < ray_y)
		draw_wall(wolf, ray_x, 0x6495ED);
	else
		draw_wall(wolf, ray_y, 0x9932CC);
}
