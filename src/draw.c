/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 17:51:08 by ablizniu          #+#    #+#             */
/*   Updated: 2019/03/19 20:38:33 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

inline void		put_image(t_mlx *mlx, int x, int y, int color)
{
	if ((x >= 0 && x < W) && (y >= 0 && y < H))
		*(int *)(mlx->data_buff + (y * W + x) * mlx->bpp) = color;
}

void	write_line(t_wolf3d *wolf, int32_t from, int32_t to, int32_t attribute)
{
	while (from < to)
	{
		put_image(wolf->mlx, (int32_t)wolf->x_column_fov, from, attribute);
		from++;
	}
}

double		ray_dist_y(t_wolf3d *wolf)
{
	int32_t	x0;
	int32_t x1;
	double	opp_y;
	double	delta_x;

	opp_y = 0;
	delta_x = 0;
	x0 = (int32_t)wolf->player_coord_x;
	x1 = x0 + 1;
	if (wolf->cam < 0)
	{
		delta_x = wolf->player_coord_x - x0;
		wolf->vectors->delta_x = delta_x;
		opp_y = delta_x * tan((180 - wolf->curr_angle) * M_PI / 180);
		wolf->intersection_y.x = x0 / (double)DEFAULT_SCALE;
	}
	else if (wolf->cam > 0)
	{
		delta_x = x1 - wolf->player_coord_x;
		wolf->vectors->delta_x = delta_x;
		opp_y = delta_x * tan(wolf->curr_angle * M_PI / 180);
		wolf->intersection_y.x = x1 / (double)DEFAULT_SCALE;
	}
	else if (wolf->cam == 0)
	{
		wolf->intersection_y.y = wolf->len_array_y - (wolf->player_coord_y - wolf->vectors->delta_y) / DEFAULT_SCALE;
		wolf->intersection_y.x = wolf->player_coord_x / (double)DEFAULT_SCALE;
		return ((wolf->len_array_y * DEFAULT_SCALE) - (wolf->player_coord_y - wolf->vectors->delta_y));
	}
	if ((wolf->player_coord_y / DEFAULT_SCALE) - opp_y / DEFAULT_SCALE > 0)
		wolf->intersection_y.y = (wolf->player_coord_y / DEFAULT_SCALE) - opp_y / DEFAULT_SCALE;
	else
		wolf->intersection_y.y = 0;
	return (sqrt(opp_y * opp_y + delta_x * delta_x));
}

double		ray_dist_x(t_wolf3d *wolf)
{
	int32_t	y0;
	double	opp_x;
	double	delta_y;

	opp_x = 0;
	delta_y = 0;
	y0 = (int32_t)wolf->player_coord_y;
	if (wolf->cam < 0)
	{
		delta_y = wolf->player_coord_y - y0;
		wolf->vectors->delta_y = delta_y;
		wolf->intersection_x.y = (double)y0 / DEFAULT_SCALE;
		opp_x = delta_y * tan((wolf->curr_angle - 90) * M_PI / 180);
	}
	else if (wolf->cam > 0)
	{
		delta_y = wolf->player_coord_y - y0;
		wolf->vectors->delta_y = delta_y;
		wolf->intersection_x.y = (double)y0 / DEFAULT_SCALE;
		opp_x = delta_y * (tan((wolf->curr_angle + 90) * M_PI / 180) * (-1));
	}
	else if (wolf->cam == 0)
	{
		wolf->intersection_x.y = y0 / (double)DEFAULT_SCALE;
		wolf->intersection_x.x = wolf->player_coord_x /  (double)DEFAULT_SCALE;
		return (wolf->player_coord_y - y0);
	}
	if ((wolf->player_coord_x / DEFAULT_SCALE) - opp_x / DEFAULT_SCALE > 0)
		wolf->intersection_x.x = (wolf->player_coord_x / DEFAULT_SCALE) - opp_x / DEFAULT_SCALE;
	else
		wolf->intersection_x.x = 0;
	return (sqrt(opp_x * opp_x + delta_y * delta_y));
}

double	ray_delta_x(t_wolf3d *wolf)
{
	double	opp_x;

	opp_x = 0;
	if (wolf->cam < 0)
		opp_x = DEFAULT_SCALE * tan((wolf->curr_angle - 90) * M_PI / 180);
	else if (wolf->cam > 0)
		opp_x = DEFAULT_SCALE * (tan((wolf->curr_angle + 90) * M_PI / 180 )* (-1));
	else if (wolf->cam == 0)
	{
		wolf->intersection_x.y -= 1;
		return (DEFAULT_SCALE);
	}
	if (wolf->cam < 0)
	{
		if (wolf->intersection_x.x - opp_x / DEFAULT_SCALE > 0)
			wolf->intersection_x.x -= opp_x / DEFAULT_SCALE;
		else
			wolf->intersection_x.x = 0;
		if (wolf->intersection_x.y - 1 > 0)
			wolf->intersection_x.y -= 1;
		else
			wolf->intersection_x.y = 0;
	}
	else
	{
		if (wolf->intersection_x.x + opp_x / DEFAULT_SCALE < wolf->len_array_x)
			wolf->intersection_x.x += opp_x / DEFAULT_SCALE;
		else
			wolf->intersection_x.x = (double)wolf->len_array_x;
		if (wolf->intersection_x.y + 1 < wolf->len_array_y)
			wolf->intersection_x.y += 1;
		else
			wolf->intersection_x.y = (double)wolf->len_array_y;
	}
	return (sqrt(opp_x * opp_x + DEFAULT_SCALE * DEFAULT_SCALE));
}

double	ray_delta_y(t_wolf3d *wolf)
{
	double opp_y;

	opp_y = 0;
	if (wolf->cam < 0)
		opp_y = DEFAULT_SCALE * tan((180 - wolf->curr_angle) * M_PI / 180);
	else if (wolf->cam > 0)
		opp_y = DEFAULT_SCALE * tan(wolf->curr_angle * M_PI / 180);
	else if (wolf->cam == 0)
	{
		wolf->intersection_y.y -= 1;
		return (DEFAULT_SCALE);
	}
	if (wolf->intersection_y.y - opp_y / DEFAULT_SCALE > 0)
		wolf->intersection_y.y -= opp_y / DEFAULT_SCALE;
	else
		wolf->intersection_y.y = 0;
	if (wolf->intersection_y.x - 1 > 0)
		wolf->intersection_y.x -= 1;
	else
		wolf->intersection_y.x = 0;
	return (sqrt(opp_y * opp_y + DEFAULT_SCALE * DEFAULT_SCALE));
}

int32_t	rounding(double num)
{
	int32_t buff;

	buff = 0;
	buff = (int32_t)num;
	if (num - (double)buff > 0.5)
		return (buff + 1);
	else
		return (buff);
}

void	ray_total_len_x(t_wolf3d *wolf)
{
	int32_t hit;

	hit = 0;
	wolf->vectors->dist_x += ray_dist_x(wolf);
	while (!hit)
	{
		hit = wolf->map[(int)wolf->intersection_x.y][rounding(wolf->intersection_x.x)].texture;
		wolf->vectors->dist_x += ray_delta_x(wolf);
	}
}

void	ray_total_len_y(t_wolf3d *wolf)
{
	int32_t hit;

	hit = 0;
	wolf->vectors->dist_y += ray_dist_y(wolf);
	while (!hit)
	{
		hit = wolf->map[rounding(wolf->intersection_y.y)][(int)wolf->intersection_y.x].texture;
		wolf->vectors->dist_y += ray_delta_y(wolf);
	}
}

double	calculate_wall(t_wolf3d *wolf, double wall_dist)
{
	double distance;

	distance = ((double)W / 2) / (tan(FIELD_OF_VIEW * M_PI / 180) / 2);
	return ((DEFAULT_SCALE * distance) / wall_dist);
}

void	draw_wall(t_wolf3d *wolf)
{
	if (wolf->vectors->dist_x > wolf->vectors->dist_y)
	{
		write_line(wolf, (int32_t)((double)H / 2 - calculate_wall(wolf, wolf->vectors->dist_y) / 2), H / 2, 0xffffff);
		write_line(wolf, H / 2, (int32_t)((double)H - calculate_wall(wolf, wolf->vectors->dist_y) / 2), 0xffffff);
	}
	else
	{
		write_line(wolf, (int32_t)((double)H / 2 - calculate_wall(wolf, wolf->vectors->dist_x) / 2), H / 2, 0xff0000);
		write_line(wolf, H / 2, (int32_t)((double)H - calculate_wall(wolf, wolf->vectors->dist_x) / 2), 0xff0000);
	}
	wolf->vectors->dist_y = 0;
	wolf->vectors->dist_x = 0;
}

void	main_draw_function(t_wolf3d *wolf)
{
	wolf->curr_angle = FIELD_OF_VIEW + 57;
	wolf->vectors->dist_x = 0;
	wolf->vectors->dist_y = 0;
	while (wolf->x_column_fov < W)
	{
		wolf->cam = 2 * (wolf->x_column_fov / (double)W) - 1; // -1 or 0 or 1
		ray_total_len_y(wolf);
		ray_total_len_x(wolf);
		draw_wall(wolf);
		wolf->curr_angle -= (double)ANGLE_NEIBORING_RAYS;
		wolf->x_column_fov++;
	}
	mlx_put_image_to_window(wolf->mlx->mlx_ptr, wolf->mlx->mlx_window, wolf->mlx->image_ptr, 0, 0);
	wolf->x_column_fov = 0;
}