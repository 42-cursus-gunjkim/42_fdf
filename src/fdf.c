/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:25:28 by gunjkim           #+#    #+#             */
/*   Updated: 2023/02/07 14:23:12 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	var_init(t_vars *var, const char *path)
{
	map_init(path, var);
	var->mlx = mlx_init();
	var->win = mlx_new_window(var->mlx, var->win_w, var->win_h, (char *)path);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_vars	var;

	if (argc != 2)
		error_and_exit("FDF needs only one file");
	var_init(&var, argv[1]);
	mlx_loop_hook(var.mlx, render, &var);
	mlx_loop(var.mlx);
	free(var.map);
	return (0);
}
