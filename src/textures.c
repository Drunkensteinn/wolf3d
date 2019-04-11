/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 20:28:28 by ablizniu          #+#    #+#             */
/*   Updated: 2019/04/07 20:20:43 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void				parse_textures(t_wolf3d *wolf)
{
	size_t			i;
	char			*name;
	static char		*textures_names[TEXTURES_NUM] = {
					"redbrick.xpm", "bluestone.xpm",
					"colorstone.xpm", "eagle.xpm",
					"greystone.xpm","mossy.xpm",
					"purplestone.xpm", "wood.xpm"};

	i = 0;
	while (i < TEXTURES_NUM)
	{
		name = ft_strjoin(FOLDER, textures_names[i]);
		if (!(wolf->textures[i].ptr = mlx_xpm_file_to_image(wolf->mlx->mlx_ptr, name, &wolf->textures[i].width, &wolf->textures[i].height)))
			print_error(ERROR_ALLOCATION);
		wolf->textures[i].image = mlx_get_data_addr(wolf->textures[i].ptr,
				&wolf->textures[i].bpp, &wolf->textures[i].size_line,
				&wolf->textures[i].endian);
		wolf->textures[i].bpp /= 8;
		ft_strdel(&name);
		i++;
	}
}

