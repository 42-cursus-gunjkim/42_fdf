/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:02:43 by gunjkim           #+#    #+#             */
/*   Updated: 2023/03/25 18:49:58 by gunjkim          ###   ########.fr       */
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
# define ZOOM_IN 34
# define ZOOM_OUT 31
# define ROTATE_X 7
# define ROTATE_Z 6
# define ROTATE_Y 16
# define KEY_AMP 4

int		key_hooks(int keycode, t_vars *vars);

#endif