/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:17:49 by gunjkim           #+#    #+#             */
/*   Updated: 2023/03/23 17:52:39 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void	init_camera(void *mlx, t_map *map, t_camera *camera)
{
	int	max_win_w;
	int	max_win_h;
	int	f_tmp;

	f_tmp = 1;
	mlx_get_screen_size(mlx, &max_win_w, &max_win_h);
	if (map->map_w > max_win_w || map->map_h > max_win_h)
		error_exit("map is too big");
	while ((map->map_w * f_tmp < 0.3 * DEFAULT_W) \
	|| (map->map_h * f_tmp < 0.3 * DEFAULT_H))
		f_tmp++;
	camera->f = f_tmp;
	camera->win_w = DEFAULT_W;
	camera->win_h = DEFAULT_H;
	camera->offset_w = (int)(camera->win_w / 2 - (map->map_w / 2) * f_tmp);
	camera->offset_h = (int)(camera->win_h / 2 - (map->map_h / 2) * f_tmp);
}

int	main(int argc, char *argv[])
{
	t_map		map;
	t_camera	camera;
	t_data		data;
	void		*mlx;
	void		*mlx_win;

	if (argc < 2)
		error_exit("Too few arguments");
	parse_map(&map, argv[1]);
	mlx = mlx_init();
	init_camera(mlx, &map, &camera);
	data.img_plane = mlx_new_image(mlx, camera.win_w, camera.win_h);
	data.addr = mlx_get_data_addr(data.img_plane, &(data.bpp), \
	&(data.line_length), &(data.endian));
	mlx_win = mlx_new_window(mlx, camera.win_w, camera.win_h, "fdf");
	render(&map, &camera, &data);
	mlx_put_image_to_window(mlx, mlx_win, data.img_plane, 0, 0);
	mlx_loop(mlx);
	return (0);
}
