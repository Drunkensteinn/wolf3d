/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preparation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 15:05:03 by ablizniu          #+#    #+#             */
/*   Updated: 2019/03/17 16:24:32 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void	define_players_coord(t_wolf3d *wolf)
{
	wolf->player_coord_x = (((double)wolf->len_array_x / 2) * DEFAULT_SCALE);
	wolf->player_coord_y = (((double)wolf->len_array_y / 2) * DEFAULT_SCALE);
}

void	preparation(t_wolf3d *wolf)
{
	define_players_coord(wolf);
}
