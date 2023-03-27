/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_util.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:54:56 by gunjkim           #+#    #+#             */
/*   Updated: 2023/03/27 17:33:47 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTIL_H
# define MLX_UTIL_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>

# define DEFAULT_W 1500
# define DEFAULT_H 900

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	trgb;
}	t_point;

typedef struct s_map
{
	t_point	*map;
	int		m_w;
	int		m_h;
}	t_map;

typedef struct s_data {
	void	*i_p;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_pixel {
	float	x;
	float	y;
	float	z;
	int		h;
	float	r;
	float	g;
	float	b;
	int		trgb;
}	t_pixel;

typedef struct s_camera {
	int		f;
	int		w_w;
	int		w_h;
	int		m_w;
	int		m_h;
	int		o_w;
	int		o_h;
	float	x_a;
	float	y_a;
	float	z_a;
	int		method;
}	t_camera;

typedef struct s_vars
{
	void		*mlx;
	void		*win;
	t_pixel		*img;
	t_camera	camera;
	t_map		map;
	t_data		data;
}	t_vars;

typedef struct s_line
{
	int	dx;
	int	dy;
	int	step_x;
	int	step_y;
	int	err;
	int	err_d;
}	t_line;

void	rotate_x(t_pixel *p, float a);
void	rotate_y(t_pixel *p, float a);
void	rotate_z(t_pixel *p, float a);
void	parse_map(t_map *map, char *map_path);
void	error_exit(char *err_msg);
void	error_clear_exit(t_vars *var);
void	get_min_max(t_map *map, int *min, int *max);
int		get_height_color(int z, int min, int max);
void	get_color(t_pixel *p0, t_pixel *p1, t_pixel *tmp);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_line(t_pixel *p0, t_pixel *p1, t_camera *camera, t_data *data);
void	isomeric(t_pixel *img, t_camera *camera, int i_max);
void	parallel(t_pixel *img, t_camera *camera, int i_max);
void	check_w_h(t_map *map, char *map_path);
void	map_to_point(t_map *map, char *map_path);

int		render(t_vars *var);

#endif