/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhousse <abhousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:31:22 by abhousse          #+#    #+#             */
/*   Updated: 2022/02/09 21:10:52 by abhousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	ft_calcul(t_info *info)
{
	double	tmp;

	tmp = info->z_r;
	info->z_r = (info->z_r * info->z_r) - (info->z_i * info->z_i) + info->c_r;
	if (info->z_r < 0)
		info->z_r *= -1;
	info->z_i = 2 * tmp * info->z_i + info->c_i;
	if (info->z_i < 0)
		info->z_i *= -1;
	info->iteration++;
}

void	burningship(t_info *info)
{
	info->x = 0;
	while (info->x < LARGUER)
	{
		info->y = 0;
		while (info->y < HAUTEUR)
		{
			info->c_r = info->x * info->xzoom - info->xcentre;
			info->c_i = info->y * info->yzoom - info->ycentre;
			info->z_r = 0;
			info->z_i = 0;
			info->iteration = 0;
			while (info->iteration < info->maxiteration)
			{
				ft_calcul(info);
				if ((info->z_r * info->z_r + info->z_i * info->z_i) > 4)
					break ;
			}
			coloring(info);
			info->y++;
		}
		info->x++;
	}
	mlx_put_image_to_window(info->mlx, info->win, info->img, 0, 0);
}
