/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 20:37:40 by ablizniu          #+#    #+#             */
/*   Updated: 2019/03/15 22:21:28 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int main(int32_t argc, char **argv)
{
	t_wolf3d *main_struct;

	if (argc == 2)
	{
		main_struct = init_wolf3d();
		read_and_valid(main_struct, argv[1]);
		preparation(main_struct);
		main_draw_function(main_struct);
		mlx_loop(main_struct->mlx->mlx_ptr);
	}
	return (0);
}