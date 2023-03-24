/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_util.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:54:56 by gunjkim           #+#    #+#             */
/*   Updated: 2023/03/24 14:54:31 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTIL_H
# define MLX_UTIL_H

# include "parser.h"
# include "color.h"
# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include <math.h>

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

void	rotate_x(t_map *map);
void	rotate_z(t_map *map);
int		is_scope(int x, int y, t_camera *camera);
int		get_abs_max(t_map *map);
int		get_height_color(int z, int abs_max);
void	get_beauty(t_pixel *p0, t_pixel *p1, t_pixel *tmp);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif