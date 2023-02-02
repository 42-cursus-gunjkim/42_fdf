/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:25:28 by gunjkim           #+#    #+#             */
/*   Updated: 2023/02/02 18:24:15 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	var_init(t_vars *var, t_data *img, const char *path)
{
	map_init(path, var);
	var->mlx = mlx_init();
	var->win = mlx_new_window(var->mlx, 2180, 1080, "Hello world!");
	img->img = mlx_new_image(var->mlx, 2180, 1080);
	img->addr = mlx_get_data_addr(img->img, &(img->bpp), &(img->len), &(img->endian));
	var->data = img;
	return (0);
}

int	main(int argc, char *argv[])
{
	t_vars	var;
	t_data	img;

	if (argc != 2)
		error_and_exit("FDF needs only one file");
	var_init(&var, &img, argv[1]);
	render(&var);
	//mlx_loop_hook(var.mlx, render, &var);
	free(var.map);
	mlx_loop(var.mlx);
	return (0);
}
