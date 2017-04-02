/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbauguen <vbauguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/02 06:33:34 by vbauguen          #+#    #+#             */
/*   Updated: 2016/06/06 14:45:53 by vbauguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_xpm_textures(t_id *s)
{
	int width;
	int height;
	int x;
	int y;

	s->xpm = (void**)malloc(sizeof(void*) * 15);
	s->xpm[0] = mlx_xpm_file_to_image(s->mlx, s->weapon[0], &x, &y);
	s->xpm[1] = mlx_xpm_file_to_image(s->mlx, s->weapon[1], &x, &y);
	s->xpm[2] = mlx_xpm_file_to_image(s->mlx, s->weapon[2], &x, &y);
	s->xpm[3] = mlx_xpm_file_to_image(s->mlx, s->weapon[3], &x, &y);
	s->xpm[4] = mlx_xpm_file_to_image(s->mlx, s->weapon[4], &x, &y);
	s->xpm[5] = mlx_xpm_file_to_image(s->mlx, s->weapon[5], &x, &y);
	s->xpm[6] = mlx_xpm_file_to_image(s->mlx, s->weapon[6], &x, &y);
	s->wall[0] = mlx_xpm_file_to_image(s->mlx, GREY, &width, &height);
	s->wall[1] = mlx_xpm_file_to_image(s->mlx, TEL, &width, &height);
	s->wall[2] = mlx_xpm_file_to_image(s->mlx, DOOR, &width, &height);
	s->wall[3] = mlx_xpm_file_to_image(s->mlx, GREY, &width, &height);
	s->wall[4] = mlx_xpm_file_to_image(s->mlx, EAGLE, &width, &height);
	s->wall[5] = mlx_xpm_file_to_image(s->mlx, MOSS, &width, &height);
	s->wall[6] = mlx_xpm_file_to_image(s->mlx, WOOD, &width, &height);
	s->wall[7] = mlx_xpm_file_to_image(s->mlx, RUBEN, &width, &height);
	s->wall[8] = mlx_xpm_file_to_image(s->mlx, BENJ, &width, &height);
	s->wall[10] = mlx_xpm_file_to_image(s->mlx, GRASS, &width, &height);
	s->wall[13] = mlx_xpm_file_to_image(s->mlx, SKYB, &width, &height);
}

void	ft_weapons_and_maps(t_id *s)
{
	s->niveau[0] = ft_strcpy(s->niveau[0], "Maps/niveau1");
	s->niveau[1] = ft_strcpy(s->niveau[1], "Maps/niveau2");
	s->niveau[2] = ft_strcpy(s->niveau[2], "Maps/niveau3");
	s->niveau[3] = ft_strcpy(s->niveau[3], "Maps/niveau4");
	s->niveau[4] = ft_strcpy(s->niveau[4], "Maps/niveau5");
	s->weapon[0] = ft_strcpy(s->weapon[0], "Textures/weapon1.xpm");
	s->weapon[1] = ft_strcpy(s->weapon[1], "Textures/weapon2.xpm");
	s->weapon[2] = ft_strcpy(s->weapon[2], "Textures/weapon3.xpm");
	s->weapon[3] = ft_strcpy(s->weapon[3], "Textures/weapon4.xpm");
	s->weapon[4] = ft_strcpy(s->weapon[4], "Textures/weapon5.xpm");
	s->weapon[5] = ft_strcpy(s->weapon[5], "Textures/weapon6.xpm");
	s->weapon[6] = ft_strcpy(s->weapon[6], "Textures/weapon7.xpm");
}

void	ft_start_initialisation(int x, t_id *s)
{
	s->camerax = 2 * x / (double)W_X - 1;
	s->rayposx = s->posx;
	s->rayposy = s->posy;
	s->raydirx = s->dirx + s->planex * s->camerax;
	s->raydiry = s->diry + s->planey * s->camerax;
	s->mapx = (int)s->rayposx;
	s->mapy = (int)s->rayposy;
	s->deltadistx = sqrt(1 + (pow(s->raydiry, 2)) / (pow(s->raydirx, 2)));
	s->deltadisty = sqrt(1 + (pow(s->raydirx, 2)) / (pow(s->raydiry, 2)));
	s->hit = 0;
}

void	ft_static_xpm(t_id *s)
{
	int i;
	int j;

	if (s->gun == 1)
		mlx_put_image_to_window(s->mlx, s->win, GU, W_X / 2, DE);
	if (s->map[(int)s->posx][(int)s->posy] == 2)
	{
		s->tp = malloc(sizeof(void*));
		s->tp = mlx_xpm_file_to_image(s->mlx, "Textures/tp.xpm", &i, &j);
		mlx_put_image_to_window(s->mlx, s->win, s->tp, WX2, W_Y / 2 - 100);
	}
}

int		red_cross(void)
{
	exit(0);
	return (0);
}
