/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhousse <abhousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 23:18:37 by abhousse          #+#    #+#             */
/*   Updated: 2022/02/10 11:11:26 by abhousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init(t_info *info)
{
	info->mlx = mlx_init();
	info->win = mlx_new_window(info->mlx, HAUTEUR, LARGUER, "fractol");
	info->img = mlx_new_image(info->mlx, HAUTEUR, LARGUER);
	info->buf = mlx_get_data_addr(info->img, &info->pixel_bits,
			&info->line_bytes, &info->endian);
	initjulia(info);
	reset(info);
}

void	ft_error(t_info *info)
{
	printf("passez en parametre \nmandelbrot!\nou julia\nou burningship");
	exit (1);
}

void	ft_mlx(t_info *info)
{
	mlx_hook(info->win, 2, 0, key_press, info);
	mlx_hook(info->win, 4, 0, mouse_press, info);
	mlx_hook(info->win, 17, 0, ft_close, info);
	mlx_hook(info->win, 6, 0, mouse_move, info);
	mlx_loop(info->mlx);
}

int	main(int ac, char **av)
{
	t_info	*info;

	if (ac != 2)
		ft_error(info);
	info = malloc(sizeof(t_info));
	if (!(info))
		return (0);
	init(info);
	info->value = 0;
	if (ft_strcmp(av[1], "mandelbrot") == 0)
		mandelbrot(info);
	else if (ft_strcmp(av[1], "julia") == 0)
	{
		julia(info);
		info->value = 1;
	}
	else if (ft_strcmp(av[1], "burningship") == 0)
	{
		burningship(info);
		info->value = 2;
	}
	else
		ft_error(info);
	ft_mlx(info);
}
