/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation_and_move.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 14:32:17 by ablizniu          #+#    #+#             */
/*   Updated: 2019/04/15 12:21:19 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void				rotate(t_wolf3d *wolf, double angle, t_bool direction)
{
	double			x;
	double			y;

	if (direction)
	{
		x = wolf->player[1][0];
		y = wolf->player[1][1];
		wolf->player[1][0] = x * cos((-angle * M_PI) / 180) +
				y * sin((-angle * M_PI) / 180);
		wolf->player[1][1] = (-x * sin((-angle * M_PI) / 180)) +
				y * cos((-angle * M_PI) / 180);
	}
	else
	{
		x = wolf->player[1][0];
		y = wolf->player[1][1];
		wolf->player[1][0] = x * cos((angle * M_PI) / 180) +
				y * sin((angle * M_PI) / 180);
		wolf->player[1][1] = (-x * sin((angle * M_PI) / 180)) +
				y * cos((angle * M_PI) / 180);
	}
}

static void			make_step_forward_back(t_wolf3d *wolf, t_bool direction)
{
	int32_t			coef;

	coef = 10 * ((wolf->speed_up) ? (2) : (1));
	if (direction)
	{
		if (wolf->map[(int32_t)(wolf->player_coord_y +
		(coef * wolf->player[1][1])) / DEFAULT_SCALE]
		[(int32_t)(wolf->player_coord_x) / DEFAULT_SCALE].texture == 0)
			wolf->player_coord_y += coef * wolf->player[1][1];
		if (wolf->map[(int32_t)(wolf->player_coord_y) / DEFAULT_SCALE]
		[(int32_t)(wolf->player_coord_x + (coef * wolf->player[1][0])) /
		DEFAULT_SCALE].texture == 0)
			wolf->player_coord_x += coef * wolf->player[1][0];
	}
	else
	{
		if (wolf->map[(int32_t)(wolf->player_coord_y -
		(coef * wolf->player[1][1])) / DEFAULT_SCALE]
		[(int32_t)(wolf->player_coord_x) / DEFAULT_SCALE].texture == 0)
			wolf->player_coord_y -= coef * wolf->player[1][1];
		if (wolf->map[(int32_t)(wolf->player_coord_y) / DEFAULT_SCALE]
		[(int32_t)(wolf->player_coord_x - (coef * wolf->player[1][0])) /
		DEFAULT_SCALE].texture == 0)
			wolf->player_coord_x -= coef * wolf->player[1][0];
	}
}

static void			make_swing_right_left(t_wolf3d *wolf, t_bool direction)
{
	int32_t			coef;

	coef = 10 * ((wolf->speed_up) ? (2) : (1));
	if (direction)
	{
		if (wolf->map[(int32_t)(wolf->player_coord_y +
		(coef * wolf->player[0][1])) / DEFAULT_SCALE]
		[(int32_t)(wolf->player_coord_x) / DEFAULT_SCALE].texture == 0)
			wolf->player_coord_y += coef * wolf->player[0][1];
		if (wolf->map[(int32_t)(wolf->player_coord_y) / DEFAULT_SCALE]
		[(int32_t)(wolf->player_coord_x + (coef * wolf->player[0][0])) /
		DEFAULT_SCALE].texture == 0)
			wolf->player_coord_x += coef * wolf->player[0][0];
	}
	else
	{
		if (wolf->map[(int32_t)(wolf->player_coord_y -
		(coef * wolf->player[0][1])) / DEFAULT_SCALE]
		[(int32_t)(wolf->player_coord_x) / DEFAULT_SCALE].texture == 0)
			wolf->player_coord_y -= coef * wolf->player[0][1];
		if (wolf->map[(int32_t)(wolf->player_coord_y) / DEFAULT_SCALE]
		[(int32_t)(wolf->player_coord_x - (coef * wolf->player[0][0])) /
		DEFAULT_SCALE].texture == 0)
			wolf->player_coord_x -= coef * wolf->player[0][0];
	}
}

void				rotating(t_wolf3d *wolf)
{
	if (wolf->button_d)
		rotate(wolf, 5.9, true);
	else if (wolf->button_l)
		rotate(wolf, 5.9, false);
}

void				movement(t_wolf3d *wolf)
{
	if (wolf->button_w)
		make_step_forward_back(wolf, 1);
	else if (wolf->button_s)
		make_step_forward_back(wolf, 0);
	if (wolf->button_e)
		make_swing_right_left(wolf, 1);
	else if (wolf->button_q)
		make_swing_right_left(wolf, 0);
}
