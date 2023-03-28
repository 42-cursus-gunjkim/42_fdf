/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:02:43 by gunjkim           #+#    #+#             */
/*   Updated: 2023/03/28 00:24:19 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_BONUS_H
# define HOOK_BONUS_H

# include "mlx_util_bonus.h"

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
# define ROTATE_X_M 1
# define ROTATE_Y_M 17
# define ROTATE_Z_M 0
# define KEY_ISO 18
# define KEY_PAR1 19
# define KEY_PAR2 20
# define KEY_PAR3 21
# define MAXIMIZE 46
# define MINIMIZE 45

int	key_hooks(int keycode, t_vars *vars);
int	click_red_cross(t_vars *vars);

#endif