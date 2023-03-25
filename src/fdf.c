/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:17:49 by gunjkim           #+#    #+#             */
/*   Updated: 2023/03/26 00:36:22 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mlx_util.h"
#include "../include/hook.h"

void	init_camera(void *mlx, t_map *map, t_camera *camera)
{
	int	max_w_w;
	int	max_w_h;
	int	f_tmp;

	f_tmp = 1;
	mlx_get_screen_size(mlx, &max_w_w, &max_w_h);
	if (map->m_w > max_w_w || map->m_h > max_w_h)
		error_exit("map is too big");
	while ((map->m_w * f_tmp < 0.3 * DEFAULT_W) \
	|| (map->m_h * f_tmp < 0.3 * DEFAULT_H))
		f_tmp++;
	camera->f = f_tmp;
	camera->x_a = 0;
	camera->y_a = 0;
	camera->z_a = 0;
	camera->w_w = DEFAULT_W;
	camera->w_h = DEFAULT_H;
	camera->o_w = (int)(camera->w_w / 2);
	camera->o_h = (int)(camera->w_h / 2);
	camera->method = 1;
}

int	main(int argc, char *argv[])
{
	t_vars		var;

	if (argc != 2)
		error_exit("Too few arguments");
	parse_map(&(var.map), argv[1]);
	var.mlx = mlx_init();
	var.img = (t_pixel *)malloc(sizeof(t_pixel) * var.map.m_w * var.map.m_h);
	init_camera(var.mlx, &(var.map), &(var.camera));
	var.win = mlx_new_window(var.mlx, var.camera.w_w, var.camera.w_h, "fdf");
	mlx_hook(var.win, 02, 1L << 0, key_hooks, &var);
	mlx_hook(var.win, 17, 0, click_red_cross, &var);
	mlx_loop_hook(var.mlx, render, &var);
	mlx_loop(var.mlx);
	free(var.img);
	free(var.map.map);
	return (0);
}
