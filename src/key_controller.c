/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_kontroller.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 22:25:22 by ablizniu          #+#    #+#             */
/*   Updated: 2019/04/14 22:27:04 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int				exit_wolf(t_wolf3d *wolf)
{
	(void)wolf;
	exit(0);
	return (0);
}

int				mouse_event(int x, int y, t_wolf3d *wolf)
{
	static int	x_prev;

	(void)y;
	if (wolf->mouse_lock)
	{
		if (x >= 0 && x <= W)
		{
			if (x_prev - x < 0)
				rotate(wolf, 6, true);
			else if (x_prev - x > 0)
				rotate(wolf, 6, false);
			x_prev = x;
		}
	}
	return (0);
}

int				keys_unpress(int code, t_wolf3d *wolf)
{
	if (code == W_KEY)
		wolf->button_w = false;
	else if (code == A_KEY)
		wolf->button_l = false;
	else if (code == S_KEY)
		wolf->button_s = false;
	else if (code == D_KEY)
		wolf->button_d = false;
	else if (code == Q_KEY)
		wolf->button_q = false;
	else if (code == E_KEY)
		wolf->button_e = false;
	else if (code == SHIFT)
		wolf->speed_up = false;
	return (0);
}

int				keys_press(int code, t_wolf3d *wolf)
{
	if (code == W_KEY)
		wolf->button_w = true;
	else if (code == A_KEY)
		wolf->button_l = true;
	else if (code == S_KEY)
		wolf->button_s = true;
	else if (code == D_KEY)
		wolf->button_d = true;
	else if (code == Q_KEY)
		wolf->button_q = true;
	else if (code == E_KEY)
		wolf->button_e = true;
	else if (code == SPACE)
		wolf->untextured = !wolf->untextured;
	else if (code == SHIFT)
		wolf->speed_up = true;
	else if (code == ESC)
		exit(0);
	else if (code == M_KEY)
		wolf->mouse_lock = !wolf->mouse_lock;
	else if (code == F_KEY)
		wolf->fps = !wolf->fps;
	else if (code == H_KEY)
		wolf->help = !wolf->help;
	return (0);
}
