/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smrabet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/09 16:59:07 by smrabet           #+#    #+#             */
/*   Updated: 2017/09/09 16:59:10 by smrabet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RT_H
# define RT_H

# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <errno.h>
# include <pthread.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <fcntl.h>
# include <stdio.h>

# define NB_THREAD	100

# define FOV		2.0

# define BLACK		0x000000
# define GRAY		0x686868

# define WIN_W		800
# define WIN_H		800

# define KEYPRESS (2)
# define KEYPRESSMASK (1L << 0)

# define I mlx->i
# define J mlx->j
# define K mlx->k

# define ESC		53

# define KEY_B		11
# define KEY_R		15
# define KEY_E		14
# define KEY_F		3
# define KEY_X		7
# define KEY_Z		6
# define KEY_G		5
# define TAB		48

# define KEY_MOIN	27
# define KEY_PLUS	24

# define PLUS		69
# define MOIN		78

# define KEY_A		0
# define KEY_S		1
# define KEY_D		2
# define KEY_W		13

# define LEFT		123
# define RIGHT		124
# define DOWN		125
# define UP			126
# define PAGE_DOWN	121
# define PAGE_UP	116

# define POSX mlx->cam_pos.x
# define POSY mlx->cam_pos.y
# define POSZ mlx->cam_pos.z

# define MSP mlx_string_put
# define TMP mlx->tmp

# define LAMBERT tab[3]

# define PREF1 mlx->pref == 1 && tmp2->type != 3
# define PREF2 mlx->pref == 1 && tmp->type != 3
# define COND1 mlx->spec == 1 && tmp2->type != 3
# define COND2 mlx->spec == 1 && tmp->type != 3

typedef struct		s_color
{
	float			red;
	float			green;
	float			blue;
}					t_color;

typedef struct		s_obj
{
	int				type;
	float			size;
	t_vec			rot;
	t_vec			pos;
	t_color			col;
	struct s_obj	*next;
}					t_obj;

typedef struct		s_mlx
{
	int				nbl;
	int				bpp;
	int				size_line;
	int				endian;
	int				hud;
	int				selection;
	int				maxref;
	int				pref;
	int				aa;
	char			*d;
	char			*pos;
	char			*rot;
	char			**scene;
	void			*mlx;
	void			*win;
	void			*img;
	t_vec			i;
	t_vec			j;
	t_vec			k;
	t_vec			cam_pos;
	t_vec			cam_dir;
	t_vec			ray_dir;
	t_vec			norm;
	t_vec			ref;
	t_vec			dist;
	t_vec			refpos;
	t_obj			*obj;
	t_obj			*tmp;
	t_obj			*light;
	unsigned int	type_color;
	float			spec;
	float			t0;
	float			t1;
	float			t;
	float			a;
	float			b;
	float			c;
}					t_mlx;

typedef struct		s_tab_th
{
	t_mlx			*mlx;
	int				i;
}					t_tab_th;

typedef struct		s_th
{
	int				bpp;
	int				size_line;
	int				maxref;
	int				pref;
	int				cpt;
	int				ty;
	int				tx;
	int				aa;
	char			*d;
	t_vec			i;
	t_vec			j;
	t_vec			k;
	t_vec			cam_pos;
	t_vec			cam_dir;
	t_vec			ray_dir;
	t_vec			norm;
	t_vec			ref;
	t_vec			dist;
	t_vec			refpos;
	t_obj			*obj;
	t_obj			*light;
	float			spec;
	float			t0;
	float			t1;
	float			t;
	float			a;
	float			b;
	float			c;
}					t_th;

int					ft_draw(t_mlx *mlx);
int					ft_parser(t_mlx *mlx);
int					close_hook(t_mlx *mlx);
int					ft_linelen(char *buf, int k);
int					key_hook(int keycode, t_mlx *mlx);
int					ft_pref_key(int keycode, t_mlx *mlx);
int					ft_free_lists(t_obj *lgt, t_obj *obj);
int					ft_parameters(int keycode, t_mlx *mlx);
int					ft_objects_rot(int keycode, t_mlx *mlx);
int					ft_add_light(t_mlx *mlx, int *k, int i);
int					ft_add_plane(t_mlx *mlx, int *k, int i);
int					ft_add_sphere(t_mlx *mlx, int *k, int i);
int					ft_free_arg(t_mlx *mlx, char *buf, int r);
int					ft_check_objects(t_mlx *mlx, t_obj *objects);
int					ft_mouse(int button, int x, int y, t_mlx *mlx);
int					ft_add_cyl_cone(t_mlx *mlx, int *k, int t, int i);

void				ft_hud(t_mlx *mlx);
void				ft_instructions(void);
void				ft_string_put(t_mlx *mlx);
void				ft_init_mlx_var(t_mlx *mlx);
void				ft_copy(t_mlx *mlx, t_th *th);
void				ft_put_pixel(t_th *mlx, int x, int y, int color);

double				ft_inter_cone(t_th *mlx, t_obj *node, t_vec ray,
		t_vec pos);
double				ft_inter_cylinder(t_th *mlx, t_obj *node, t_vec ray,
		t_vec pos);
double				ft_inter_plane(t_th *mlx, t_obj *node, t_vec ray,
		t_vec pos);
double				ft_inter_sphere(t_th *mlx, t_obj *node, t_vec ray,
		t_vec pos);

t_vec				ft_norm(t_th *mlx, t_obj *tmp, t_vec pos);

t_obj				*copy_obj(t_obj *obj);
t_obj				*ft_add_light_link(t_mlx *mlx, t_obj *link);
t_obj				*ft_add_object_link(t_mlx *mlx, t_obj *link);
t_obj				*ft_intersection(t_th *mlx, t_obj *node, t_vec ray,
		t_vec pos);

float				*ft_average(float *r, float *tab);
float				*ft_endlight(t_obj *tmp, t_obj *light, float *tab,
		float d);
float				*ft_lambert(t_th *mlx, t_obj *tmp, t_obj *light,
		float *tab);
float				ft_spec(t_th *mlx, t_vec dist, float d,
		float lambert);

int					ft_key_color(t_mlx *mlx);
int					verif_input(char *file);

#endif
