/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:05:27 by gunjkim           #+#    #+#             */
/*   Updated: 2023/03/23 22:38:30 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "error.h"
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include "parser.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# define DEFAULT_W 1500
# define DEFAULT_H 900

typedef struct s_data {
	void	*img_plane;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_pixel {
	int		x;
	int		y;
	int		height;
	float	r;
	float	g;
	float	b;
	int		trgb;
}	t_pixel;

typedef struct s_camera {
	int		f;
	int		win_w;
	int		win_h;
	int		offset_w;
	int		offset_h;
}	t_camera;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_camera	camera;
	t_map		map;
	t_data		data;
}	t_vars;

# define KEY_ESC 53

int		get_abs_max(t_map *map);
int		get_height_color(int z, int abs_max);
int		is_scope(int x, int y, t_camera *camera);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	get_beauty(t_pixel *p0, t_pixel *p1, t_pixel *tmp);
void	draw_line(t_pixel *p0, t_pixel *p1, t_camera *camera, t_data *data);
t_pixel	*isomeric(t_map *map, t_camera *camera);
int		render(t_vars *var);
int		key_hooks(int keycode, t_vars *vars);

#endif