/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 21:22:54 by gunjkim           #+#    #+#             */
/*   Updated: 2023/03/27 17:33:41 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/hook.h"

int	key_hooks(int keycode, t_vars *var)
{
	if (keycode == KEY_ESC)
		error_clear_exit(var);
	else if (keycode == KEY_UP)
		var->camera.o_h -= 5;
	else if (keycode == KEY_DOWN)
		var->camera.o_h += 5;
	else if (keycode == KEY_RIGHT)
		var->camera.o_w += 5;
	else if (keycode == KEY_LEFT)
		var->camera.o_w -= 5;
	else if (keycode == ZOOM_IN)
		(var->camera.f)++;
	else if (keycode == ZOOM_OUT && var->camera.f > 1)
		(var->camera.f)--;
	else if (keycode == ROTATE_X)
		var->camera.x_a += 0.1;
	else if (keycode == ROTATE_Z)
		var->camera.z_a += 0.1;
	else if (keycode == ROTATE_Y)
		var->camera.y_a += 0.1;
	else if (keycode == KEY_ISO)
	{
		var->camera.method = 1;
		var->camera.x_a = 0;
		var->camera.y_a += 0;
		var->camera.z_a += 0;
	}
	else if (keycode == KEY_PAR)
	{
		var->camera.method = 2;
		var->camera.x_a = 0;
		var->camera.y_a += 0;
		var->camera.z_a += 0;
	}
	return (1);
}

int	click_red_cross(t_vars *var)
{
	error_clear_exit(var);
	return (1);
}
