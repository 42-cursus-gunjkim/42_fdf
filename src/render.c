/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:39:13 by gunjkim           #+#    #+#             */
/*   Updated: 2023/01/31 20:42:52 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "struct.h"
#include "error.h"
#include "../mlx/mlx.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_line(t_pixel *p1, t_pixel *p2)
{
	
}

void	make_img(t_vars *var)
{
	size_t	w_index;
	size_t	h_index;

	h_index = 0;
	while (h_index < var->map_h)
	{
		w_index = 0;
		while (w_index < var->map_w)
		{
			if ((var->map[h_index * var->map_w + w_index]).z != 0)
				my_mlx_pixel_put(var->data, w_index * 50, h_index * 50, 0x00FF0000);
			else
				my_mlx_pixel_put(var->data, w_index * 50, h_index * 50, 0x00FFFF00);
			w_index++;
		}
		h_index++;
	}
}

int	render(t_vars *var)
{
	make_img(var);
	mlx_put_image_to_window(var->mlx, var->win, var->data->img, 0, 0);
	return (0);
}
