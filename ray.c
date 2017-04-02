/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbauguen <vbauguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 07:06:09 by vbauguen          #+#    #+#             */
/*   Updated: 2016/06/06 14:58:40 by vbauguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_ray_direction(t_id *s)
{
	if (s->raydirx < 0)
	{
		s->stepx = -1;
		s->sidedistx = (s->rayposx - s->mapx) * s->deltadistx;
	}
	else
	{
		s->stepx = 1;
		s->sidedistx = (s->mapx + 1.0 - s->rayposx) * s->deltadistx;
	}
	if (s->raydiry < 0)
	{
		s->stepy = -1;
		s->sidedisty = (s->rayposy - s->mapy) * s->deltadisty;
	}
	else
	{
		s->stepy = 1;
		s->sidedisty = (s->mapy + 1.0 - s->rayposy) * s->deltadisty;
	}
}

void	ft_dda(t_id *s)
{
	while (s->hit == 0)
	{
		if (s->sidedistx < s->sidedisty)
		{
			s->sidedistx += s->deltadistx;
			s->mapx += s->stepx;
			s->side = 0;
		}
		else
		{
			s->sidedisty += s->deltadisty;
			s->mapy += s->stepy;
			s->side = 1;
		}
		if (s->map[s->mapx][s->mapy] > 0)
			s->hit = 1;
	}
}

void	ft_calc_pixl_place(t_id *s)
{
	if (s->side == 0)
		s->perpwalldist = (s->mapx - s->rayposx + (1 - s->stepx)
			/ 2) / s->raydirx;
	else
		s->perpwalldist = (s->mapy - s->rayposy + (1 - s->stepy)
			/ 2) / s->raydiry;
	s->lineheight = (int)(W_Y / s->perpwalldist);
	s->drawstart = -s->lineheight / 2 + W_Y / 2;
	if (s->drawstart < 0)
		s->drawstart = 0;
	s->drawend = s->lineheight / 2 + W_Y / 2;
	if (s->drawend >= W_Y)
		s->drawend = W_Y - 1;
	s->texnum = s->map[s->mapx][s->mapy] - 1;
	if (s->side == 0)
		s->wallx = s->rayposy + s->perpwalldist * s->raydiry;
	else
		s->wallx = s->rayposx + s->perpwalldist * s->raydirx;
	s->wallx -= floor((s->wallx));
	s->texx = (int)(s->wallx * (double)TEXWIDTH);
	if (s->side == 0 && s->raydirx > 0)
		s->texx = TEXWIDTH - s->texx - 1;
	if (s->side == 1 && s->raydiry < 0)
		s->texx = TEXWIDTH - s->texx - 1;
}

void	ft_calc_floor_place(t_id *s)
{
	if (s->side == 0 && s->raydirx > 0)
	{
		s->floorxwall = s->mapx;
		s->floorywall = s->mapy + s->wallx;
	}
	else if (s->side == 0 && s->raydirx < 0)
	{
		s->floorxwall = s->mapx + 1.0;
		s->floorywall = s->mapy + s->wallx;
	}
	else if (s->side == 1 && s->raydiry > 0)
	{
		s->floorxwall = s->mapx + s->wallx;
		s->floorywall = s->mapy;
	}
	else
	{
		s->floorxwall = s->mapx + s->wallx;
		s->floorywall = s->mapy + 1.0;
	}
	s->distwall = s->perpwalldist;
	s->distplayer = 0.0;
	if (s->drawend < 0)
		s->drawend = W_Y;
}

int		getcolor(t_img *img, int x, int y, int fade)
{
	int color;
	int c;

	fade /= 8;
	c = (y * img->width + x) * 4;
	color = img->buffer[c];
	color += img->buffer[c + 1] * 256;
	color += img->buffer[c + 2] * 256 * 256;
	return (color);
}
