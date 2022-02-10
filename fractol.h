/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abhousse <abhousse@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 23:14:02 by abhousse          #+#    #+#             */
/*   Updated: 2022/02/10 10:54:50 by abhousse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <math.h>
# include <mlx.h>
# define LARGUER 500
# define HAUTEUR 500

typedef struct s_info
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*buf;
	int				pixel_bits;
	int				line_bytes;
	int				endian;
	int				x;
	int				y;
	int				iteration;
	int				maxiteration;
	int				pixel;
	int				color;
	int				value;
	int				clique;
	double			z_r;
	double			z_i;
	double			c_r;
	double			c_i;
	double			xcentre;
	double			ycentre;
	double			xzoom;
	double			yzoom;
	double			vcouleur;
	double			tcouleur;
	double			couleur;
	double			cr_julia;
	double			ci_julia;
}					t_info;

int		key_press(int key, t_info *info);
int		key_press2(int key, t_info *info);
int		mouse_press(int button, int x, int y, t_info *info);
void	mandelbrot(t_info *info);
void	julia(t_info *info);
void	burningship(t_info *info);
void	ft_calcul(t_info *info);
void	ft_calcul2(t_info *info);
void	initjulia(t_info *info);
int		ft_close(t_info *info);
void	dessine(t_info *info);
void	coloring(t_info *info);
void	reset(t_info *info);
int		mouse_move(int x, int y, t_info *info);
int		ft_strcmp(char *s1, char *s2);
int		ft_exit(t_info *info);

#endif
