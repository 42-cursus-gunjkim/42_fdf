/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:39:13 by gunjkim           #+#    #+#             */
/*   Updated: 2023/02/02 19:13:53 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.h"
#include "struct.h"
#include "error.h"
#include <math.h>
#include "../mlx/mlx.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->len + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

void	draw_line_high(t_pixel p0, t_pixel p1, t_data *data)
{
	int	dx;
	int	dy;
	int	x_step;
	int	d;

	dx = p1.x - p0.x;
	dy = p1.y - p0.y;
	x_step = 1;
	if (dy < 0)
	{
		x_step = -1;
		dx = -dx;
	}
	d = 2 * dx - dy;
	while (p0.y < p1.y)
	{
		if (p0.z != 0 && p1.z != 0)
			my_mlx_pixel_put(data, p0.x, p0.y, 0x00FF00);
		else
			my_mlx_pixel_put(data, p0.x, p0.y, 0xFF0000);
		if (d > 0)
		{
			p0.x = p0.x + x_step;
			d = d + 2 * dx - 2 * dy;
		}
		else
			d = d + 2 * dx;
		p0.y = p0.y + 1;
	}
}

void	draw_line_low(t_pixel p0, t_pixel p1, t_data *data)
{
	int	dx;
	int	dy;
	int	y_step;
	int	d;

	dx = p1.x - p0.x;
	dy = p1.y - p0.y;
	y_step = 1;
	if (dy < 0)
	{
		y_step = -1;
		dy = -dy;
	}
	d = 2 * dy - dx;
	while (p0.x < p1.x)
	{
		if (p0.z != 0 && p1.z != 0)
			my_mlx_pixel_put(data, p0.x, p0.y, p0.trgb);
		else
			my_mlx_pixel_put(data, p0.x, p0.y, p0.trgb);
		if (d > 0)
		{
			p0.y = p0.y + y_step;
			d = d + 2 * dy - 2 * dx;
		}
		else
			d = d + 2 * dy;
		p0.x = p0.x + 1;
	}
}

void	draw_line(t_pixel p0, t_pixel p1, t_data *data)
{
	if (abs(p1.y - p0.y) < abs(p1.x - p0.x))
	{
		if (p0.x > p1.x)
			draw_line_low(p1, p0, data);
		else
			draw_line_low(p0, p1, data);
	}
	else
	{
		if (p0.y > p1.y)
			draw_line_high(p1, p0, data);
		else
			draw_line_high(p0, p1, data);
	}
}

void	isomeric(t_vars *var)
{
	size_t	w_index;
	size_t	h_index;
	size_t	m_index;
	int		tmp_x;
	int		tmp_y;
	int		tmp_z;

	h_index = 0;
	while (h_index < var->map_h)
	{
		w_index = 0;
		m_index = h_index * var->map_w;
		while (w_index < var->map_w)
		{
			tmp_x = var->map[m_index].x;
			tmp_y = var->map[m_index].y;
			tmp_z = var->map[m_index].z;
			var->map[m_index].x = (int)((tmp_x - tmp_z)/sqrt(2)) + 300;
			var->map[m_index].y = (int)((tmp_x + 2 * tmp_y + tmp_z) / sqrt(6));
			var->map[m_index].trgb = tmp_z * 0xFFFFFF;
			w_index++;
			m_index++;
		}
		h_index++;
	}
}

void	make_img(t_vars *var)
{
	size_t	w_index;
	size_t	h_index;
	size_t	m_index;

	h_index = 0;
	while (h_index < var->map_h)
	{
		w_index = 0;
		m_index = h_index * var->map_w;
		while (w_index < var->map_w)
		{
			if (m_index == 0 || m_index % var->map_w != var->map_w - 1)
				draw_line(var->map[m_index], var->map[m_index + 1], var->data);
			if (h_index != var->map_h - 1)
				draw_line(var->map[m_index], var->map[m_index + var->map_w], var->data);
			w_index++;
			m_index++;
		}
		h_index++;
	}
}

int	render(t_vars *var)
{
	isomeric(var);
	make_img(var);
	mlx_put_image_to_window(var->mlx, var->win, var->data->img, 0, 0);
	return (0);
}
