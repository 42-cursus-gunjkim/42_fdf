/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:42:23 by gunjkim           #+#    #+#             */
/*   Updated: 2023/02/07 14:52:09 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "color.h"
# include "struct.h"
# include "error.h"
# include <math.h>
# include "../mlx/mlx.h"

void	isomeric(t_vars *var);
void	draw_line(t_pixel p0, t_pixel p1, t_vars *var);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif