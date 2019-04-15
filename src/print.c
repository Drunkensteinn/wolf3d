/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 21:00:27 by ablizniu          #+#    #+#             */
/*   Updated: 2019/04/14 22:36:37 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void				print_error(const char *error)
{
	ft_putendl(error);
	exit(0);
}

static void			print_fps(t_wolf3d *wolf)
{
	char buff[16];

	if (wolf->fps)
	{
		if (60.0 - wolf->frame_time < 0)
			snprintf(buff, 15, "%f", 0.0);
		else
			snprintf(buff, 15, "%f", 60.0 - wolf->frame_time);
		mlx_string_put(wolf->mlx->mlx_ptr, wolf->mlx->mlx_window,
				25, 15, 0xffffff, buff);
	}
}

static void			print_tips(t_wolf3d *wolf)
{
	mlx_string_put(wolf->mlx->mlx_ptr, wolf->mlx->mlx_window, 25,
				35, 0xffffff, "\tW - move forward.");
	mlx_string_put(wolf->mlx->mlx_ptr, wolf->mlx->mlx_window, 25,
				50, 0xffffff, "\tS - move back.");
	mlx_string_put(wolf->mlx->mlx_ptr, wolf->mlx->mlx_window, 25,
				65, 0xffffff, "\tA - turn left.");
	mlx_string_put(wolf->mlx->mlx_ptr, wolf->mlx->mlx_window, 25,
				80, 0xffffff, "\tD - turn right.");
	mlx_string_put(wolf->mlx->mlx_ptr, wolf->mlx->mlx_window, 25,
				100, 0xffffff, "\tM - mouse lock.");
	mlx_string_put(wolf->mlx->mlx_ptr, wolf->mlx->mlx_window, 25,
				115, 0xffffff, "\tE - swing right.");
	mlx_string_put(wolf->mlx->mlx_ptr, wolf->mlx->mlx_window, 25,
				130, 0xffffff, "\tQ - swing left.");
	mlx_string_put(wolf->mlx->mlx_ptr, wolf->mlx->mlx_window, 25,
				160, 0xffffff, "\tL_SHIFT - speed up.");
	mlx_string_put(wolf->mlx->mlx_ptr, wolf->mlx->mlx_window, 25,
				180, 0xffffff, "\tSPACE - turn off the texture mapping.");
	mlx_string_put(wolf->mlx->mlx_ptr, wolf->mlx->mlx_window, 25,
				200, 0xffffff, "\tESC - end the program, or the red cross.");
}

void				print_help(t_wolf3d *wolf)
{
	if (!wolf->help)
		mlx_string_put(wolf->mlx->mlx_ptr, wolf->mlx->mlx_window, 50,
				50, 0xff0000, "Press 'H' to show tips.");
	else
	{
		if (!wolf->fps)
			mlx_string_put(wolf->mlx->mlx_ptr, wolf->mlx->mlx_window, 25,
					15, 0xffffff, "Press 'F' to show FPS.");
		else
			print_fps(wolf);
		print_tips(wolf);
	}
}
