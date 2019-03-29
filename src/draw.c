/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 17:51:08 by ablizniu          #+#    #+#             */
/*   Updated: 2019/03/29 15:30:27 by ablizniu         ###   ########.fr       */
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

double	calculate_wall(t_wolf3d *wolf, double wall_dist)
{
	double distance;

	distance = get_dist();
	return ((DEFAULT_SCALE * distance) / wall_dist);
}

double_t get_dist(void)
{
	return (((double)W / 2) / (tan((double)FIELD_OF_VIEW / 2 * M_PI / 180)));
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
	matrix_mult(wolf);/*right vector*/
	Y(wolf->player[1]) = distance * Y(wolf->player[1]);
}

double	len_vector(long double x0, long double x1)
{
	double size;

	size = sqrt((double)(x0 * x0 + x1 * x1));
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

void	define_current_delta_pos_x_y(t_wolf3d *wolf, t_vector vector)
{
	size_t x0;
	size_t y0;

	x0 = (size_t)wolf->map_pos_x * DEFAULT_SCALE;
	y0 = (size_t)wolf->map_pos_y * DEFAULT_SCALE;
	if (X(vector) < 0)
		wolf->pos_delta_x = wolf->player_coord_x - x0;
	else
		wolf->pos_delta_x = (DEFAULT_SCALE - (int32_t)wolf->player_coord_x % DEFAULT_SCALE);
	if (Y(vector) < 0)
		wolf->pos_delta_y = wolf->player_coord_y - y0;
	else
		wolf->pos_delta_y = (DEFAULT_SCALE - (int32_t)wolf->player_coord_y % DEFAULT_SCALE);
}

t_vector vector_scaling(t_vector vector, double num)
{
	vector[0] *= num;
	vector[1] *= num;
	vector[2] *= num;
	return (vector);
}

void	define_ray_angle(t_wolf3d *wolf)
{
	wolf->ray = ft_zero_vector(wolf->ray);
	wolf->ray = vector_scaling(wolf->player[0], wolf->x_column_fov - (double)W / 2);
	wolf->ray += wolf->player[1];
	wolf->ray = norm_vector(wolf->ray, len_vector(wolf->ray[0], wolf->ray[1]));
	define_current_delta_pos_x_y(wolf, wolf->ray);
	wolf->curr_tan = FT_ABS(wolf->ray[1] / wolf->ray[0]);//могут быть траблы из-за тангенса inf или ноль
}

void first_inter_x(t_wolf3d *wolf)
{
	double x_delta;
	double y_delta;

	x_delta = wolf->pos_delta_y / wolf->curr_tan;
	y_delta = DEFAULT_SCALE;
	wolf->current_delta_x = x_delta;
	wolf->current_delta_y = y_delta;
	if (X(wolf->ray) < 0)
		wolf->intersection.x = wolf->player_coord_x - x_delta;
	else
		wolf->intersection.x = wolf->player_coord_x + x_delta;
	if (Y(wolf->ray) < 0)
		wolf->intersection.y = (size_t)(wolf->map_pos_y * DEFAULT_SCALE);
	else
		wolf->intersection.y = (size_t)(wolf->map_pos_y * DEFAULT_SCALE) + DEFAULT_SCALE;
//	printf("RAY X | x - %f y - %f \n", wolf->intersection.x, wolf->intersection.y);

}

void first_inter_y(t_wolf3d *wolf)
{
	double x_delta;
	double y_delta;

	x_delta = DEFAULT_SCALE;
	y_delta = wolf->pos_delta_x * wolf->curr_tan;
	wolf->current_delta_x = x_delta;
	wolf->current_delta_y = y_delta;
	if (X(wolf->ray) < 0)
		wolf->intersection.x = (size_t)(wolf->map_pos_x * DEFAULT_SCALE);
	else
		wolf->intersection.x = (size_t)(wolf->map_pos_x * DEFAULT_SCALE) + DEFAULT_SCALE;
	if (Y(wolf->ray) < 0)
		wolf->intersection.y = wolf->player_coord_y - y_delta;
	else
		wolf->intersection.y = wolf->player_coord_y + y_delta;
//	printf("RAY Y | x - %f y - %f \n",  wolf->intersection.x, wolf->intersection.y);
}

double	calculate_len_ray(t_wolf3d *wolf, void (*f)(t_wolf3d *))
{
	t_map	point;
	double	y;
	double 	x;
	double	len;

	point = find_a_hit(wolf, f);
	y = wolf->hit_coords_y - wolf->player_coord_y;
	x = wolf->hit_coords_x - wolf->player_coord_x;
	len = len_vector(y, x);
	return (len);
}

size_t *transfer_coords(t_wolf3d *wolf, double x, double y)
{
	size_t *arr;

	if (!(arr = (size_t *)ft_memalloc(sizeof(size_t) * 2)))
		return (NULL);
	if (x >= 0 && x < wolf->len_array_x * DEFAULT_SCALE)
		arr[INDEX(1)] = (size_t)(x / DEFAULT_SCALE);
	else if (x >= wolf->len_array_x * DEFAULT_SCALE)
		arr[INDEX(1)] =  wolf->len_array_x - 1;
	else if (x < 0)
		arr[INDEX(1)] = 0;
	if (y >= 0 && y < wolf->len_array_y * DEFAULT_SCALE)
		arr[INDEX(2)] = (size_t)(y / DEFAULT_SCALE);
	else if (y >= wolf->len_array_y * DEFAULT_SCALE)
		arr[INDEX(2)] =  wolf->len_array_y - 1;
	else if (y < 0)
		arr[INDEX(2)] = 0;
	return (arr);
}

t_map	find_a_hit(t_wolf3d *wolf, void (*f)(t_wolf3d *))
{
	double hit;
	double x0;
	double y0;
	size_t *arr;

	hit = 0;
	f(wolf);
	if (wolf->intersection.x > (wolf->len_array_x) * DEFAULT_SCALE)
		x0 = (wolf->len_array_x) * DEFAULT_SCALE;
	else
		x0 = wolf->intersection.x;
	if (wolf->intersection.y > (wolf->len_array_y) * DEFAULT_SCALE)
		y0 = (wolf->len_array_y) * DEFAULT_SCALE;
	else
		y0 = wolf->intersection.y;
	while (!hit)
	{
		arr = transfer_coords(wolf, x0, y0);
		wolf->y = arr[1];
		wolf->x = arr[0];
		ft_memdel((void *)&arr);
		if ((hit = wolf->map[wolf->y][wolf->x].texture))
			continue ;
		if (X(wolf->ray) < 0)
			x0 -= wolf->current_delta_x;
		else if (X(wolf->ray) >= 0)
			x0 += wolf->current_delta_x;
		if (Y(wolf->ray) < 0)
			y0 -= wolf->current_delta_y;
		else if (Y(wolf->ray) >= 0)
			y0 += wolf->current_delta_y;
	}
	wolf->hit_coords_x = x0;
	wolf->hit_coords_y = y0;
//	printf("hit coords x - %f  y - %f \n", x0, y0);
	return (wolf->map[wolf->y][wolf->x]);
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
	double ray_x;
	double ray_y;

//	wolf->map_pos_x = 1;
//	wolf->map_pos_y = 1;
//	wolf->player_coord_x = 80;
//	wolf->player_coord_y = 80;
//	wolf->player[1][0] = 2;
//	wolf->player[1][1] = 2;
//	wolf->x_column_fov = (double)W / 2;
//	define_ray_angle(wolf);
//	ray_y = calculate_len_ray(wolf, &first_inter_y);
//	ray_x = calculate_len_ray(wolf, &first_inter_x);
	while (wolf->x_column_fov < W)
	{
		define_ray_angle(wolf);
		ray_y = calculate_len_ray(wolf, &first_inter_y);
		ray_x = calculate_len_ray(wolf, &first_inter_x);
		draw_wall(wolf, ray_x, ray_y);
		wolf->x_column_fov++;
	}
	mlx_put_image_to_window(wolf->mlx->mlx_ptr,
			wolf->mlx->mlx_window, wolf->mlx->image_ptr, 0, 0);
}
