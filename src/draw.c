/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 17:51:08 by ablizniu          #+#    #+#             */
/*   Updated: 2019/04/15 11:32:06 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

double					wall_config(t_wolf3d *wolf, double ray_x, double ray_y)
{
	if (ray_x < ray_y)
	{
		wolf->ray_to_draw = wolf->saved_ray_x.x;
		wolf->texture_to_draw = (uint32_t)wolf->saved_ray_x.hit_texture;
		if (wolf->texture_to_draw == 9)
			prepare_multi_size(wolf, wolf->saved_ray_x.x, 0);
		return (ray_x);
	}
	else
	{
		wolf->ray_to_draw = wolf->saved_ray_y.y;
		wolf->texture_to_draw = (uint32_t)wolf->saved_ray_y.hit_texture;
		if (wolf->texture_to_draw == 9)
			prepare_multi_size(wolf, 0, wolf->saved_ray_y.y);
		return (ray_y);
	}
}

inline static void		save_y(t_wolf3d *wolf)
{
	wolf->saved_ray_y.x = wolf->hit_coords_x;
	wolf->saved_ray_y.y = wolf->hit_coords_y;
	wolf->saved_ray_y.hit_texture = wolf->texture_to_draw;
}

inline static void		save_x(t_wolf3d *wolf)
{
	wolf->saved_ray_x.x = wolf->hit_coords_x;
	wolf->saved_ray_x.y = wolf->hit_coords_y;
	wolf->saved_ray_x.hit_texture = wolf->texture_to_draw;
}

int						draw_cycle(t_wolf3d *wolf)
{
	wolf->old_time = wolf->time;
	wolf->time = clock();
	wolf->frame_time = (wolf->time - wolf->old_time) / 1000.0;
	rotating(wolf);
	movement(wolf);
	ft_bzero(wolf->mlx->data_buff, (size_t)(H * W * wolf->mlx->bpp));
	mlx_clear_window(wolf->mlx->mlx_ptr, wolf->mlx->mlx_window);
	matrix_mult(wolf);
	main_draw_function(wolf);
	print_help(wolf);
	mlx_do_sync(wolf->mlx->mlx_ptr);
	return (0);
}

void					main_draw_function(t_wolf3d *wolf)
{
	double				ray_x;
	double				ray_y;
	double				resulted;

	wolf->x_column_fov = 0;
	wolf->total_angle = -((double)FIELD_OF_VIEW / 2);
	parse_textures(wolf);
	while (wolf->x_column_fov < W - 1)
	{
		define_ray_angle(wolf);
		ray_y = calculate_len_ray(wolf, &first_inter_y);
		save_y(wolf);
		ray_x = calculate_len_ray(wolf, &first_inter_x);
		save_x(wolf);
		resulted = wall_config(wolf, ray_x, ray_y);
		if (!wolf->untextured)
			texture_draw(wolf, calculate_wall(wolf, resulted));
		else
			draw_untextured_walls(wolf, ray_x, ray_y);
		wolf->x_column_fov++;
		wolf->total_angle += ANGLE_BETWEEN_RAYS;
	}
	mlx_put_image_to_window(wolf->mlx->mlx_ptr,
			wolf->mlx->mlx_window, wolf->mlx->image_ptr, 0, 0);
}
