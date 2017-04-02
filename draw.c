/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbauguen <vbauguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 07:15:58 by vbauguen          #+#    #+#             */
/*   Updated: 2016/06/06 15:01:37 by vbauguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_draw_floor(int x, t_id *s)
{
	int		y;
	int		floor_color;
	double	w;
	int		floortexx;
	int		floortexy;

	y = s->drawend + 1;
	while (s->sol == 1 && y < W_Y - s->decaly)
	{
		s->currentdist = W_Y / (2.0 * y - W_Y);
		w = (s->currentdist - s->distplayer) / (s->distwall - s->distplayer);
		s->currentfloorx = w * s->floorxwall + (1.0 - w) * s->posx;
		s->currentfloory = w * s->floorywall + (1.0 - w) * s->posy;
		floortexx = (int)(s->currentfloorx * TEXWIDTH) % TEXWIDTH;
		floortexy = (int)(s->currentfloory * TEXHEIGHT) % TEXHEIGHT;
		floor_color = getcolor(s->wall[10], floortexx, floortexy, 64);
		floor_color = (floor_color >> 1) & 8355711;
		mlx_image_put_pixel(s, x, y + s->decaly, floor_color);
		y++;
	}
}

void	ft_draw_ceiling(int x, t_id *s)
{
	int		y;
	int		ceiling_color;
	double	w;
	int		floortexx;
	int		floortexy;

	y = s->drawend + 1;
	while (s->plafond > 0 && y - s->decaly < W_Y)
	{
		s->currentdist = W_Y / (2.0 * y - W_Y);
		w = (s->currentdist - s->distplayer) / (s->distwall - s->distplayer);
		s->currentfloorx = w * s->floorxwall + (1.0 - w) * s->posx;
		s->currentfloory = w * s->floorywall + (1.0 - w) * s->posy;
		floortexx = (int)(s->currentfloorx * TEXWIDTH) % TEXWIDTH;
		floortexy = (int)(s->currentfloory * TEXHEIGHT) % TEXHEIGHT;
		ceiling_color = getcolor(s->wall[6], floortexx, floortexy, 64);
		if (s->plafond % 2 == 0)
			mlx_image_put_pixel(s, x, +s->decaly + W_Y - y, 0xFF000000);
		else
			mlx_image_put_pixel(s, x, +s->decaly + W_Y - y, ceiling_color);
		y++;
	}
}

void	ft_draw_walls(int x, t_id *s)
{
	int d;
	int color;
	int y;

	y = s->drawstart;
	while (y < s->drawend)
	{
		d = y * 256 - W_Y * 128 + s->lineheight * 128;
		s->texy = ((d * TEXHEIGHT) / s->lineheight) / 256;
		color = getcolor(s->wall[s->texnum], s->texx, s->texy, 64);
		color = (color >> 1) & 8355711;
		mlx_image_put_pixel(s, x, y + s->decaly, color);
		y++;
	}
}

void	mlx_image_put_pixel(t_id *s, int x, int y, int col)
{
	s->color = mlx_get_color_value(s->mlx, col);
	if (x > 0 && x < W_X && y > 0 && y < W_Y)
		*(unsigned int *)(s->data + ((int)s->bpp * x) +
				(s->s_line * y)) = col;
}

int		*ft_parsing(char *str)
{
	char		**char_to_int;
	int			*tab;
	int			i;

	tab = (int *)malloc(sizeof(int) * ft_get_number_of_words(str, ' '));
	char_to_int = ft_strsplit(str, ' ');
	i = -1;
	while (char_to_int[++i])
		tab[i] = ft_atoi(char_to_int[i]);
	free_tab(char_to_int);
	free(char_to_int);
	char_to_int = NULL;
	return (tab);
}
