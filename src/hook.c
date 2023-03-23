/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 21:22:54 by gunjkim           #+#    #+#             */
/*   Updated: 2023/03/23 22:49:11 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	key_hooks(int keycode, t_vars *var)
{
	if (keycode == KEY_ESC)
	{
		mlx_destroy_window(var->mlx, var->win);
		exit(0);
	}
	if (keycode == 126)
		var->camera.f++;
	return (1);
}
