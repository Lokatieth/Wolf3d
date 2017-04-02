/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbauguen <vbauguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 17:57:51 by vbauguen          #+#    #+#             */
/*   Updated: 2016/08/23 20:05:40 by vbauguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_next_map(t_id *s)
{
	ft_start_new_map(s);
	s->fd = open(s->niveau[s->level], O_RDONLY);
	s->nl = 0;
	while ((get_next_line(s->fd, &s->line)) > 0)
	{
		s->nc = ft_get_number_of_words(s->line, ' ');
		++s->nl;
		free(s->line);
		s->line = NULL;
	}
	s->map = (int **)malloc(sizeof(int *) * s->nl);
	s->tmp = s->nc;
	s->nl = 0;
	close(s->fd);
	s->fd = open(s->niveau[s->level], O_RDONLY);
	ft_check_map(s);
	ft_check_borders(s);
	ft_check_negatives(s);
	close(s->fd);
	ft_corps(s);
}

void	ft_corps(t_id *s)
{
	int x;

	x = -1;
	while (++x < W_X)
	{
		ft_start_initialisation(x, s);
		ft_ray_direction(s);
		ft_dda(s);
		ft_calc_pixl_place(s);
		ft_calc_floor_place(s);
		ft_draw_ceiling(x, s);
		if (x == W_X - 1)
			mlx_put_image_to_window(s->mlx, s->win, s->wall[13], MU, II);
		ft_draw_floor(x, s);
		ft_draw_walls(x, s);
	}
	mlx_put_image_to_window(s->mlx, s->win, s->img, 0, 0);
	ft_static_xpm(s);
}

int		ft_check_borders(t_id *s)
{
	int i;
	int j;

	j = 0;
	if (s->posx >= s->nl - 1 || s->posy >= s->nc - 1 ||
		s->posx <= 0 || s->posy <= 0)
		ft_error("Incorrect spawn position.\n");
	if (s->nl < 3 || s->nc < 3)
		ft_error("Map too small. The minimum size of a valid map is 3 x 3.\n");
	while (j < s->nl)
	{
		i = 0;
		while (i < s->nc)
		{
			if (i == 0 || i == s->nc - 1 || j == 0 || j == s->nl - 1)
				if (s->map[j][i] <= 3 || s->map[j][i] > 9)
					ft_error("The map is not bordered by solid walls.\n");
			i++;
		}
		j++;
	}
	return (1);
}

void	ft_first_spawn(t_id *s, char **argv)
{
	s->posx = ft_atoi(argv[2]);
	s->posy = ft_atoi(argv[3]);
	s->fd = open(argv[1], O_RDONLY);
	s->nl = 0;
	while ((get_next_line(s->fd, &s->line)) > 0)
	{
		s->nc = ft_get_number_of_words(s->line, ' ');
		++s->nl;
		free(s->line);
	}
	s->map = (int **)malloc(sizeof(int *) * s->nl);
	s->nl = 0;
	s->tmp = s->nc;
	close(s->fd);
	s->fd = open(argv[1], O_RDONLY);
	ft_check_map(s);
	ft_check_borders(s);
	ft_check_negatives(s);
	close(s->fd);
}

int		main(int argc, char **argv)
{
	t_id	s;
	int		i;

	i = -1;
	s.niveau = (char**)ft_memalloc(sizeof(char*) * 5);
	while (++i < 5)
		s.niveau[i] = (char*)ft_memalloc(sizeof(char) * 25);
	i = -1;
	s.weapon = (char**)ft_memalloc(sizeof(char*) * 10);
	while (++i < 10)
		s.weapon[i] = (char*)ft_memalloc(sizeof(char) * 25);
	s.mlx = mlx_init();
	s.win = mlx_new_window(s.mlx, W_X, W_Y, WIN_NAME);
	ft_weapons_and_maps(&s);
	if (argc != 4)
		ft_error("Incorrect number of arguments.\n");
	ft_first_spawn(&s, argv);
	ft_initialisation(&s);
	free(s.map);
	return (0);
}
