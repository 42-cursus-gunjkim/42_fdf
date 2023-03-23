/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:17:49 by gunjkim           #+#    #+#             */
/*   Updated: 2023/03/23 22:15:12 by gunjkim          ###   ########.fr       */
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
	t_vars		var;

	if (argc < 2)
		error_exit("Too few arguments");
	parse_map(&(var.map), argv[1]);
	var.mlx = mlx_init();
	init_camera(var.mlx, &(var.map), &(var.camera));
	var.win = mlx_new_window(var.mlx, var.camera.win_w, var.camera.win_h, "fdf");
	mlx_hook(var.win, 02, 1L << 0, key_hooks, &var);
	//mlx_hook(var.win, 17, 1L << 5, red_cross_hook, &var);
	mlx_loop_hook(var.mlx, render, &var);
	mlx_loop(var.mlx);
	return (0);
}
