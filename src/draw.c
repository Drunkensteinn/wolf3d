/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 17:51:08 by ablizniu          #+#    #+#             */
/*   Updated: 2019/03/23 22:29:49 by ablizniu         ###   ########.fr       */
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

double	calculate_wall(t_wolf3d *wolf, double wall_dist)
{
	double distance;

	distance = get_dist();
	return ((DEFAULT_SCALE * distance) / wall_dist);
}

double_t get_dist(void)
{
	return (((double)W / 2) / (tan(FIELD_OF_VIEW * M_PI / 180) / 2));
}

void	matrix_mult(t_wolf3d *wolf)
{
	wolf->player[0][0] = (Y(A(wolf->player)) * Z(B(wolf->player)) -
			Z(A(wolf->player)) * Y(B(wolf->player)));
	wolf->player[0][1] = (Z(A(wolf->player)) * X(B(wolf->player)) -
			X(A(wolf->player)) * Z(B(wolf->player)));
	wolf->player[0][2] = (X(A(wolf->player)) * Y(B(wolf->player)) -
			Y(A(wolf->player)) * X(B(wolf->player)));
}

void	define_players_vectors(t_wolf3d *wolf)
{
	long double distance;

	distance = get_dist();
	wolf->basis[0] = (t_vector){1, 0, 0};
	wolf->basis[1] = (t_vector){0, 1, 0};
	wolf->player[2] = (t_vector){0, 0, 1};
	wolf->player[1] = (t_vector){0, 1, 0};
	matrix_mult(wolf);/*right vector*/
	Y(wolf->player[1]) = distance * Y(wolf->basis[1]);
}

size_t	len_vector(long double x0, long double x1)
{
	size_t size;

	size = (size_t)sqrt((double)(x0 * x0 + x1 * x1));
	return (size);
}

t_vector 	ft_zero_vector(t_vector vector)
{
	size_t i;

	i = 0;
	while (i < DIMENSION)
	{
		vector[i] = 0;
		i++;
	}
	return (vector);
}

t_vector norm_vector(t_vector vector, double len)
{
	size_t i;

	i = 0;
	while (i < DIMENSION)
	{
		vector[i] = vector[i] / len;
		i++;
	}
	return (vector);
}

void	define_current_delta_pos_x(t_wolf3d *wolf, t_bool sign)
{
	size_t x0;
	size_t x1;

	x0 = (size_t)wolf->player_coord_x / DEFAULT_SCALE;
	x0 *= DEFAULT_SCALE;
	x1 = x0 + DEFAULT_SCALE;
	if (sign)
		wolf->pos_delta_x = wolf->player_coord_x - x0;
	else
		wolf->pos_delta_x = x1 - wolf->player_coord_x;
}

void	define_current_delta_pos_y(t_wolf3d *wolf, t_bool sign)
{
	size_t y0;
	size_t y1;

	y0 = (size_t)wolf->player_coord_y / DEFAULT_SCALE;;
	y0 *= DEFAULT_SCALE;;
	y1 = y0 + DEFAULT_SCALE;
	wolf->pos_delta_y = wolf->player_coord_y - y0;
}

void	define_ray_angle(t_wolf3d *wolf, t_bool *sign)
{
	t_vector	plane;

	plane = ft_zero_vector(plane);
	wolf->half_plane = (size_t)W / 2;
	if (wolf->half_plane - wolf->x_column_fov > 0)
		*sign = true;
	else
		*sign = false;
	plane[0] = (FT_ABS(wolf->half_plane - wolf->x_column_fov)) * (X(wolf->player[0]) * (*sign) ? (-1.0) : (1.0));
	plane += wolf->player[1];
	plane = norm_vector(plane, len_vector(plane[0], plane[1]));
	if (*sign)
		wolf->curr_tan = FT_ABS(plane[1] / plane[0]);
	else
		wolf->curr_tan = FT_ABS(plane[0] / plane[1]);
	if (wolf->curr_tan >= INFINITY)
		wolf->curr_tan = 0;
}

void	first_inter_x(t_wolf3d *wolf, t_bool sign)
{
	define_current_delta_pos_y(wolf, false);
	wolf->intersection.x = (wolf->curr_tan * wolf->pos_delta_y) + wolf->player_coord_x;
	wolf->intersection.y = wolf->map_pos_y * DEFAULT_SCALE;
	wolf->current_delta_y = DEFAULT_SCALE;
	wolf->current_delta_x = wolf->curr_tan * wolf->pos_delta_y;
	wolf->init_len_x = wolf->current_delta_x;
	wolf->init_len_y = wolf->pos_delta_y;
}

void	first_inter_y(t_wolf3d *wolf, t_bool sign)
{
	define_current_delta_pos_x(wolf, sign);
	wolf->intersection.y = (wolf->curr_tan * wolf->pos_delta_x) + wolf->player_coord_y;// не правильно
	wolf->intersection.x = sign ? (wolf->map_pos_x * DEFAULT_SCALE) :
			((wolf->map_pos_x + 1) * DEFAULT_SCALE);
	wolf->current_delta_y = wolf->curr_tan * wolf->pos_delta_x;
	wolf->current_delta_x = DEFAULT_SCALE;
	wolf->init_len_x = wolf->pos_delta_x;
	wolf->init_len_y = wolf->current_delta_y;
}

double	calculate_len_ray_x(t_wolf3d *wolf, t_bool sign)
{
	t_map	point;
	double	len;

	point = find_a_hit(wolf, sign, &first_inter_x);
	len = len_vector(point.x - wolf->player_coord_x, point.y - wolf->player_coord_y);
	return (len);
}

double	calculate_len_ray_y(t_wolf3d *wolf, t_bool sign)
{
	t_map	point;
	double	len;

	point = find_a_hit(wolf, sign, &first_inter_y);
	len = len_vector(point.x - wolf->player_coord_x, point.y - wolf->player_coord_y) ;
	return (len);
}

t_map	find_a_hit(t_wolf3d *wolf, t_bool sign, void (*f)(t_wolf3d *, t_bool))
{
	double hit;
	double total_len_y;
	double total_len_x;
	size_t pos_x;
	size_t pos_y;

	hit = 0;
	f(wolf, sign);
	pos_x = wolf->map_pos_x;
	pos_y = wolf->map_pos_y;
	total_len_y = wolf->init_len_y;
	total_len_x = wolf->init_len_x;
	while (!hit)
	{
		if (total_len_x < total_len_y)
		{
			total_len_x += wolf->current_delta_x;
			if (sign && pos_x > 0)
				pos_x--;
			else if (!sign && pos_x <= wolf->len_array_x)
				pos_x++;
		}
		else
		{
			total_len_y += wolf->current_delta_y;
			if (sign && pos_y > 0)
				pos_y--;
			else if (!sign && pos_y < wolf->len_array_y)
				pos_y++;
		}
		hit = wolf->map[pos_y][pos_x].texture;
	}
	return (wolf->map[pos_y][pos_x]);
}

void	draw_wall(t_wolf3d *wolf, double len_x, double len_y)
{
	double lineHeight;

	if (len_x < len_y)
	{
		lineHeight = calculate_wall(wolf, len_x);
		int drawStart = (int)(-lineHeight / 2 + ((double)H / 2));
		if(drawStart < 0)
			drawStart = 0;
		int drawEnd = (int)lineHeight / 2 + (H / 2);
		if(drawEnd >= H)
			drawEnd = H - 1;
		write_line(wolf, drawStart, drawEnd, 0xff0000);
	}
	else
	{
		lineHeight = calculate_wall(wolf, len_y);
		int drawStart = (int)(-lineHeight / 2 + (double)H / 2);
		if(drawStart < 0)
			drawStart = 0;
		int drawEnd = (int)lineHeight / 2 + (H / 2);
		if(drawEnd >= H)
			drawEnd = H - 1;
		write_line(wolf, drawStart, drawEnd, 0xffffff);
	}
}

void	main_draw_function(t_wolf3d *wolf)
{
	t_bool sign;
	size_t iter;
	double ray_x;
	double ray_y;

	iter = 0;
	sign = false;
	wolf->half_plane = (size_t)W / 2;
	define_players_vectors(wolf);
	while (wolf->x_column_fov < W)
	{
		define_ray_angle(wolf, &sign);;
		ray_y = calculate_len_ray_y(wolf, sign);
		ray_x = calculate_len_ray_x(wolf, sign);
		printf("iter %zu ray y - %f ray x - %f \n",iter++ ,ray_y, ray_x);
		draw_wall(wolf, ray_x, ray_y);
		wolf->x_column_fov++;
	}
	mlx_put_image_to_window(wolf->mlx->mlx_ptr,
			wolf->mlx->mlx_window, wolf->mlx->image_ptr, 0, 0);
}