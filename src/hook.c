/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 21:22:54 by gunjkim           #+#    #+#             */
/*   Updated: 2023/03/24 14:55:59 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/hook.h"

int	key_hooks(int keycode, t_vars *var)
{
	if (keycode == KEY_ESC)
		error_clear_exit(var);
	else if (keycode == KEY_UP)
		(var->camera.offset_h)--;
	else if (keycode == KEY_DOWN)
		(var->camera.offset_h)++;
	else if (keycode == KEY_RIGHT)
		(var->camera.offset_w)++;
	else if (keycode == KEY_LEFT)
		(var->camera.offset_w)--;
	else if (keycode == ZOOM_IN)
		(var->camera.f)++;
	else if (keycode == ZOOM_OUT)
		(var->camera.f)--;
	else if (keycode == ROTATE_X)
		rotate_x(&(var->map));
	else if (keycode == ROTATE_Z)
		rotate_z(&(var->map));
	return (1);
}
