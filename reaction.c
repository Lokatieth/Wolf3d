/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reaction.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbauguen <vbauguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 07:32:06 by vbauguen          #+#    #+#             */
/*   Updated: 2016/06/03 14:29:50 by vbauguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		mouse_reaction_click(int button, int x, int y, t_id *s)
{
	int		i;

	i = 0;
	(void)x;
	(void)y;
	if (button == 1 || button == 4 || button == 5)
	{
		s->display++;
		ft_recreate(s);
	}
	return (0);
}

int		key_reaction(int keycode, t_id *s)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 116)
		s->plafond++;
	if (keycode == 121)
		s->sol = -s->sol;
	if (keycode == 5)
		s->gun = -s->gun;
	ft_recreate(s);
	return (0);
}

int		mouse_reaction(int x, int y, t_id *s)
{
	double anglerelx;

	(void)y;
	if (y > 0 && y < W_Y)
		s->decaly = 150 - 300 * ((double)y / (double)W_Y);
	anglerelx = 360 - (x * 360 / W_X);
	s->dirx = cos(anglerelx * PI / 180);
	s->diry = sin(anglerelx * PI / 180);
	s->planex = 0.66 * s->diry;
	s->planey = -0.66 * s->dirx;
	if (x > W_X)
		x %= W_X;
	if (x < 0)
		x += W_X;
	if (x < W_X / 2)
		s->test = acos(s->dirx) * 180 / PI;
	else
		s->test = 360 - (acos(s->dirx) * 180 / PI);
	ft_recreate(s);
	return (0);
}

void	ft_initialisation(t_id *s)
{
	s->test = 0;
	s->sol = -1;
	s->gun = -1;
	s->plafond = -1;
	s->display = 0;
	s->planex = 0;
	s->planey = 0.66;
	s->dirx = -1;
	s->diry = 0;
	s->level = 0;
	s->img = mlx_new_image(s->mlx, W_X, W_Y);
	s->data = mlx_get_data_addr(s->img, &s->bit_per_pixel, &s->s_line,
			&s->endian);
	s->bpp = s->bit_per_pixel / 8;
	ft_xpm_textures(s);
	ft_corps(s);
	mlx_mouse_hook(s->win, mouse_reaction_click, s);
	mlx_key_hook(s->win, key_reaction, s);
	mlx_hook(s->win, 17, (1L << 17), red_cross, s);
	mlx_hook(s->win, KEYPRESS, KEYPRESSMASK, ft_movement, s);
	mlx_hook(s->win, MOTIONNOTIFY, POINTERMOTIOMMASK, mouse_reaction, s);
	mlx_loop(s->mlx);
}

int		ft_recreate(t_id *s)
{
	if (s->img)
		mlx_destroy_image(s->mlx, s->img);
	s->img = mlx_new_image(s->mlx, W_X, W_Y);
	s->data = mlx_get_data_addr(s->img, &s->bit_per_pixel, &s->s_line,
			&s->endian);
	s->bpp = s->bit_per_pixel / 8;
	ft_corps(s);
	return (1);
}
