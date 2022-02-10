/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhousse <abhousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/18 03:20:12 by abhousse          #+#    #+#             */
/*   Updated: 2022/02/10 09:38:53 by abhousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_close(t_info *info)
{
	ft_exit(info);
	return (0);
}

void	dessine(t_info *info)
{
	if (info->value == 0)
		mandelbrot(info);
	else if (info->value == 1)
		julia(info);
	else if (info->value == 2)
		burningship(info);
}

void	coloring(t_info *info)
{
	info->color = info->iteration * 4;
	if (info->iteration == info->maxiteration)
		info->color = 1337 + 42 + info->couleur;
	info->pixel = (info->x + info->y * LARGUER) * 4;
	info->buf[info->pixel + 0] = info->color + info->couleur * 3.72;
	info->buf[info->pixel + 1] = info->color + info->couleur * 0.47;
	info->buf[info->pixel + 2] = info->color + info->couleur * 2;
}

void	reset(t_info *info)
{
	info->xcentre = 2.0;
	info->ycentre = 2.0;
	info->xzoom = (4.0 / LARGUER);
	info->yzoom = (4.0 / LARGUER);
	info->maxiteration = 50;
	info->vcouleur = log(6.7) + sin(2.3);
	info->tcouleur = sin(4.32) * log(0.364);
	info->couleur = info->vcouleur * sin(info->tcouleur);
}

int	ft_strcmp(char *s1, char *s2)
{
	int		i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}
