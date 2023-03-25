/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:02:43 by gunjkim           #+#    #+#             */
/*   Updated: 2023/03/26 00:34:49 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_H
# define HOOK_H

# include "mlx_util.h"

# define KEY_ESC 53
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_UP 126
# define KEY_DOWN 125
# define ZOOM_IN 24
# define ZOOM_OUT 27
# define ROTATE_X 7
# define ROTATE_Z 6
# define ROTATE_Y 16
# define KEY_ISO 34
# define KEY_PAR 35

int	key_hooks(int keycode, t_vars *vars);
int	click_red_cross(t_vars *vars);

#endif