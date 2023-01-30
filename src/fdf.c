/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:25:28 by gunjkim           #+#    #+#             */
/*   Updated: 2023/01/30 22:46:08 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

// int	render(t_vars *vars, t_data *img)
// {
// }

int	var_init(t_vars *var, const char *path)
{
	map_init(path, var);
	var->mlx = mlx_init();
	var->win = mlx_new_window(var->mlx, 1920, 1080, "Hello world!");
	return (0);
}

int	main(int argc, char *argv[])
{
	t_vars	var;
	t_data	img;

	if (argc != 2)
		error_and_exit("FDF needs only one file");
	var_init(&var, argv[1]);
	img.img = mlx_new_image(var.mlx, 1920, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bpp, &img.len, &img.endian);
	var.data = &img;
	// mlx_loop_hook(var.mlx, render, &var);
	mlx_loop(var.mlx);
	return (0);
}
