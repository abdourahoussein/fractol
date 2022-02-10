/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhousse <abhousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 16:31:05 by abhousse          #+#    #+#             */
/*   Updated: 2022/02/10 08:45:53 by abhousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	initjulia(t_info *info)
{
	info->cr_julia = -0.8;
	info->ci_julia = 0.156;
}

void	ft_calcul2(t_info *info)
{
	double	tmp;

	tmp = info->z_r;
	info->z_r = (info->z_r * info->z_r) - (info->z_i * info->z_i) + info->c_r;
	info->z_i = 2 * tmp * info->z_i + info->c_i;
	info->iteration++;
}

void	julia(t_info *info)
{
	info->x = 0;
	while (info->x < LARGUER)
	{
		info->y = 0;
		while (info->y < HAUTEUR)
		{
			info->z_r = info->x * info->xzoom - info->xcentre;
			info->z_i = info->y * info->yzoom - info->ycentre;
			info->c_r = info->cr_julia;
			info->c_i = info->ci_julia;
			info->iteration = 0;
			while (info->iteration < info->maxiteration)
			{
				ft_calcul2(info);
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
