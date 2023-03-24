/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 13:28:54 by gunjkim           #+#    #+#             */
/*   Updated: 2023/03/24 14:08:46 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHICS_H
# define GRAPHICS_H

# include "parser.h"
# include "mlx_util.h"

void	draw_line(t_pixel *p0, t_pixel *p1, t_camera *camera, t_data *data);
int		render(t_vars *var);

#endif
