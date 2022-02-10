/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhousse <abhousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 03:05:56 by abhousse          #+#    #+#             */
/*   Updated: 2022/02/10 11:26:43 by abhousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_exit(t_info *info)
{
	mlx_destroy_image(info->mlx, info->img);
	mlx_destroy_window(info->mlx, info->win);
	free(info);
	exit(0);
}

int	key_press2(int key, t_info *info)
{
	if (key == 126)
		info->ycentre = info->ycentre - 30 * info->yzoom;
	if (key == 125)
		info->ycentre = info->ycentre + 30 * info->yzoom;
	if (key == 124)
		info->xcentre = info->xcentre + 30 * info->xzoom;
	if (key == 123)
		info->xcentre = info->xcentre - 30 * info->xzoom;
	if (key == 78)
		info->maxiteration -= 20;
	if (key == 69)
		info->maxiteration += 20;
	if (key == 15)
		reset(info);
	return (0);
}

int	key_press(int key, t_info *info)
{
	static int	i = 0;

	key_press2(key, info);
	if (key == 17 && i < 15)
	{
		info->vcouleur += 1.7;
		info->tcouleur *= 2.3;
		info->couleur *= 4.2;
		i++;
	}
	if (key == 16 && i >= 0)
	{
		info->vcouleur -= 1.7;
		info->tcouleur /= 2.3;
		info->couleur /= 4.2;
		i--;
	}
	if (key == 53)
		ft_exit(info);
	dessine(info);
	return (0);
}

int	mouse_press(int touch, int x, int y, t_info *info)
{
	if (touch == 5)
	{
		info->xzoom *= 0.5;
		info->yzoom *= 0.5;
		info->xcentre = info->xcentre - (x * info->xzoom);
		info->ycentre = info->ycentre - (y * info->yzoom);
		info->maxiteration += 20;
	}
	else if (touch == 4 && info->maxiteration > 30)
	{
		info->xcentre = info->xcentre + (x * info->xzoom);
		info->ycentre = info->ycentre + (y * info->yzoom);
		info->xzoom /= 0.5;
		info->yzoom /= 0.5;
		info->maxiteration -= 20;
	}
	else if (touch == 1 || touch == 3)
		info->clique += 1;
	dessine(info);
	return (0);
}

int	mouse_move(int x, int y, t_info *info)
{
	if (info->clique % 2 == 0)
	{
		if (x >= 0 && x <= LARGUER && y >= 0 && y <= HAUTEUR)
		{
			info->cr_julia = x * info->xzoom - info->xcentre;
			info->ci_julia = y * info->yzoom - info->ycentre;
		}
		else
			return (0);
	}
	else if (info->clique % 2 != 0)
	{
		info->cr_julia = info->cr_julia;
		info->ci_julia = info->ci_julia;
	}
	if (info->value == 1)
		julia(info);
	return (0);
}
