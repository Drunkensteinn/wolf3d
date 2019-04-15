/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_source.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ablizniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/14 22:17:41 by ablizniu          #+#    #+#             */
/*   Updated: 2019/04/14 22:20:20 by ablizniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

/*
** open and close fd, no lseek, F**K the Subject
*/

void		validation_source(t_wolf3d *wolf, int32_t fd, char *path)
{
	size_t	i;
	size_t	j;

	i = 0;
	close(fd);
	if (!(fd = open(path, O_RDWR)) || fd < 0)
		print_error(BAD_ACCESS);
	while (i < wolf->len_array_y)
	{
		j = 0;
		while (j < wolf->len_array_x)
		{
			ft_putnbr_fd(wolf->map[i][j].texture, fd);
			ft_putchar_fd(' ', fd);
			j++;
		}
		ft_putchar_fd('\n', fd);
		i++;
	}
}
