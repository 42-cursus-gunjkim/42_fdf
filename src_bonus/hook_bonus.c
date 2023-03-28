/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 21:22:54 by gunjkim           #+#    #+#             */
/*   Updated: 2023/03/28 00:23:49 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/hook_bonus.h"

void	change_method(t_camera *camera, int method)
{
	if (method == KEY_ISO)
		camera->method = ISOMERIC;
	else if (method == KEY_PAR1)
		camera->method = PARAL_XY;
	else if (method == KEY_PAR2)
		camera->method = PARAL_XZ;
	else if (method == KEY_PAR3)
		camera->method = PARAL_YZ;
	camera->x_a = 0;
	camera->y_a = 0;
	camera->z_a = 0;
	camera->f = camera->f_origin;
	camera->z_divisor = 1;
}

void	trans_model(t_camera *camera, int c)
{
	if (c == KEY_UP)
		camera->o_h -= 5;
	else if (c == KEY_DOWN)
		camera->o_h += 5;
	else if (c == KEY_RIGHT)
		camera->o_w += 5;
	else if (c == KEY_LEFT)
		camera->o_w -= 5;
}

void	rotate_model(t_camera *camera, int c)
{
	if (c == ROTATE_X)
		camera->x_a -= 0.05;
	else if (c == ROTATE_Z)
		camera->z_a -= 0.05;
	else if (c == ROTATE_Y)
		camera->y_a -= 0.05;
	else if (c == ROTATE_X_M)
		camera->x_a += 0.05;
	else if (c == ROTATE_Z_M)
		camera->z_a += 0.05;
	else if (c == ROTATE_Y_M)
		camera->y_a += 0.05;
}

int	key_hooks(int c, t_vars *var)
{
	if (c == KEY_ESC)
		clear_exit(var);
	else if (c == KEY_UP || c == KEY_DOWN || c == KEY_LEFT || c == KEY_RIGHT)
		trans_model(&var->camera, c);
	else if (c == ZOOM_IN)
		(var->camera.f)++;
	else if (c == ZOOM_OUT && var->camera.f > 1)
		(var->camera.f)--;
	else if (c == MAXIMIZE)
		var->camera.z_divisor += 0.1;
	else if (c == MINIMIZE && var->camera.z_divisor >= 0.1)
		var->camera.z_divisor -= 0.1;
	else if (c == ROTATE_X || c == ROTATE_Y || c == ROTATE_Z \
	|| c == ROTATE_X_M || c == ROTATE_Y_M || c == ROTATE_Z_M)
		rotate_model(&var->camera, c);
	else if (c == KEY_ISO || c == KEY_PAR1 || c == KEY_PAR2 || c == KEY_PAR3)
		change_method(&(var->camera), c);
	return (1);
}

int	click_red_cross(t_vars *var)
{
	clear_exit(var);
	return (1);
}
