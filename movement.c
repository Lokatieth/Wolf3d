/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbauguen <vbauguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 07:50:30 by vbauguen          #+#    #+#             */
/*   Updated: 2016/06/03 11:07:30 by vbauguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

int		ft_movement(int keycode, t_id *s)
{
	if (KEY_T && s->map[(int)s->posx][(int)s->posy] == 2)
		ft_next_map(s);
	ft_diagonals(keycode, s);
	ft_was(keycode, s);
	ft_d_sides(keycode, s);
	ft_recreate(s);
	return (0);
}

void	ft_start_new_map(t_id *s)
{
	s->level++;
	s->posx = 2;
	s->posy = 2;
}

void	ft_diagonals(int keycode, t_id *s)
{
	if (KEY_Q)
	{
		if (s->map[(int)(s->posx + s->dirx * 0.10)][(int)(s->posy)] < 4)
			s->posx += s->dirx * 0.10;
		if (s->map[(int)(s->posx)][(int)(s->posy + s->diry * 0.10)] < 4)
			s->posy += s->diry * 0.10;
		if (s->map[(int)(s->posx - s->diry * 0.10)][(int)(s->posy)] < 4)
			s->posx -= s->diry * 0.10;
		if (s->map[(int)(s->posx)][(int)(s->posy + s->dirx * 0.10)] < 4)
			s->posy += s->dirx * 0.10;
	}
	if (KEY_E)
	{
		if (s->map[(int)(s->posx + s->dirx * 0.15)][(int)(s->posy)] < 4)
			s->posx += s->dirx * 0.15;
		if (s->map[(int)(s->posx)][(int)(s->posy + s->diry * 0.15)] < 4)
			s->posy += s->diry * 0.15;
		if (s->map[(int)(s->posx + s->diry * 0.15)][(int)(s->posy)] < 4)
			s->posx += s->diry * 0.15;
		if (s->map[(int)(s->posx)][(int)(s->posy - s->dirx * 0.15)] < 4)
			s->posy -= s->dirx * 0.15;
	}
}

void	ft_was(int keycode, t_id *s)
{
	if (KEY_UP || KEY_W)
	{
		if (s->map[(int)(s->posx + s->dirx * 0.15)][(int)(s->posy)] < 4)
			s->posx += s->dirx * 0.15;
		if (s->map[(int)(s->posx)][(int)(s->posy + s->diry * 0.15)] < 4)
			s->posy += s->diry * 0.15;
	}
	if (KEY_DOWN || KEY_S)
	{
		if (s->map[(int)(s->posx - s->dirx * 0.15)][(int)(s->posy)] < 4)
			s->posx -= s->dirx * 0.15;
		if (s->map[(int)(s->posx)][(int)(s->posy - s->diry * 0.15)] < 4)
			s->posy -= s->diry * 0.15;
	}
	if (KEY_A)
	{
		if (s->map[(int)(s->posx - s->diry * 0.15)][(int)(s->posy)] < 4)
			s->posx -= s->diry * 0.15;
		if (s->map[(int)(s->posx)][(int)(s->posy + s->dirx * 0.15)] < 4)
			s->posy += s->dirx * 0.15;
	}
}

void	ft_d_sides(int keycode, t_id *s)
{
	if (KEY_D)
	{
		if (s->map[(int)(s->posx + s->diry * 0.15)][(int)(s->posy)] < 4)
			s->posx += s->diry * 0.15;
		if (s->map[(int)(s->posx)][(int)(s->posy - s->dirx * 0.15)] < 4)
			s->posy -= s->dirx * 0.15;
	}
	if (KEY_LEFT)
	{
		s->olddirx = s->dirx;
		s->dirx = s->dirx * cos(0.04) - s->diry * sin(0.04);
		s->diry = s->olddirx * sin(0.04) + s->diry * cos(0.04);
		s->oldplanex = s->planex;
		s->planex = s->planex * cos(0.04) - s->planey * sin(0.04);
		s->planey = s->oldplanex * sin(0.04) + s->planey * cos(0.04);
	}
	if (KEY_RIGHT)
	{
		s->olddirx = s->dirx;
		s->dirx = s->dirx * cos(-0.04) - s->diry * sin(-0.04);
		s->diry = s->olddirx * sin(-0.04) + s->diry * cos(-0.04);
		s->oldplanex = s->planex;
		s->planex = s->planex * cos(-0.04) - s->planey * sin(-0.04);
		s->planey = s->oldplanex * sin(-0.04) + s->planey * cos(-0.04);
	}
}
