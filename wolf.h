/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbauguen <vbauguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 15:14:54 by vbauguen          #+#    #+#             */
/*   Updated: 2016/06/06 15:05:36 by vbauguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H
# define W_Y 800
# define W_X 1280
# define WIN_NAME "Wolf3d"
# define PI 3.14159265359
# define KEYPRESS 2
# define KEYPRESSMASK (1L<<0)
# define POINTERMOTIOMMASK (1L<<6)
# define MOTIONNOTIFY 6
# define TEXWIDTH 64
# define TEXHEIGHT 64
# define GREY "Textures/greystone.xpm"
# define TEL "Textures/teleport_64.xpm"
# define DOOR "Textures/door.xpm"
# define EAGLE "Textures/eagle.xpm"
# define MOSS "Textures/mossy.xpm"
# define WOOD "Textures/wood.xpm"
# define RUBEN "Textures/mdr.xpm"
# define BENJ "Textures/ben.xpm"
# define GRASS "Textures/grass.xpm"
# define KEY_W keycode == 13
# define KEY_A keycode == 0
# define KEY_S keycode == 1
# define KEY_D keycode == 2
# define KEY_Q keycode == 12
# define KEY_E keycode == 14
# define KEY_T keycode == 17
# define KEY_UP keycode == 126
# define KEY_DOWN keycode == 125
# define KEY_LEFT keycode == 123
# define KEY_RIGHT keycode == 124
# define KEY_G keycode == 5
# define KEY_PGUP keycode == 116
# define KEY_PGDOWN keycode == 121
# define KEY_ESC keycode == 53
# define DE W_Y - (125 + ((s->display % 7) * 15))
# define GU s->xpm[s->display % 7]
# define WX2 W_X / 2 - 100
# define SKYB "Textures/panosci.xpm"
# define MU -s->test * 20.1583333333
# define II -150 + s->decaly

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "mlx.h"
# include <stdio.h>
# include "libft/libft.h"
# include <math.h>

typedef struct		s_img
{
	int				width;
	int				height;
	char			*buffer;
}					t_img;

typedef struct		s_id
{
	double			test;
	char			*line;
	int				tmp;
	int				fd;
	int				sol;
	int				plafond;
	int				texnum;
	double			wallx;
	int				texx;
	int				texy;
	t_img			*wall[15];
	int				display;
	char			**weapon;
	int				level;
	char			**niveau;
	void			**xpm;
	char			*base_wep;
	void			*tp;
	int				gun;
	double			bpp;
	int				bit_per_pixel;
	int				s_line;
	int				endian;
	char			*data;
	void			*img;
	void			*win;
	void			*mlx;
	int				color;
	int				img_x;
	int				nl;
	int				nc;
	int				img_y;
	int				**map;
	int				mapheight;
	int				mapwidth;
	double			rayposx;
	int				mapx;
	int				mapy;
	int				stepx;
	int				stepy;
	int				hit;
	int				side;
	int				lineheight;
	int				drawstart;
	int				drawend;
	int				decaly;
	double			dirx;
	double			diry;
	double			posx;
	double			posy;
	double			planex;
	double			planey;
	double			camerax;
	double			rayposy;
	double			raydirx;
	double			raydiry;
	double			sidedisty;
	double			sidedistx;
	double			deltadistx;
	double			perpwalldist;
	double			deltadisty;
	double			floorxwall;
	double			floorywall;
	double			distwall;
	double			distplayer;
	double			currentdist;
	double			currentfloorx;
	double			currentfloory;
	double			olddirx;
	double			oldplanex;
}					t_id;

void				ft_check_negatives(t_id *s);
int					red_cross();
void				ft_check_map(t_id *s);
void				ft_static_xpm(t_id *s);
void				ft_start_new_map(t_id *s);
void				ft_next_map(t_id *s);
int					ft_movement(int keycode, t_id *s);
void				ft_d_sides(int keycode, t_id *s);
void				ft_was(int keycode, t_id *s);
int					ft_movement(int keycode, t_id *s);
int					ft_recreate(t_id *s);
int					mouse_reaction_click(int button, int x, int y, t_id *s);
int					key_reaction(int keycode, t_id *s);
int					mouse_reaction(int x, int y, t_id *s);
int					getcolor(t_img *img, int x, int y, int fade);
void				ft_draw_floor(int x, t_id *s);
void				ft_calc_floor_place(t_id *s);
void				ft_start_initialisation(int x, t_id *s);
void				ft_ray_direction(t_id *s);
void				ft_dda(t_id *s);
void				ft_calc_pixl_place(t_id *s);
void				ft_draw_ceiling(int x, t_id *s);
void				ft_initialisation(t_id *s);
void				ft_draw_walls(int x, t_id *s);
int					ft_check_borders(t_id *s);
void				ft_xpm_textures(t_id *s);
void				mlx_image_put_pixel(t_id *s, int x, int y, int col);
void				ft_weapons_and_maps(t_id *s);
void				ft_diagonals(int keycode, t_id *s);
int					ft_recreate(t_id *s);
int					*ft_parsing(char *str);
void				ft_corps(t_id *s);

#endif
