/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:43:22 by gunjkim           #+#    #+#             */
/*   Updated: 2023/03/22 19:35:46 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void    my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

int	is_scope(t_pixel p, t_camera *var)
{
	if (p.x < 0 || p.x >= (int)var->w_w)
		return (-1);
	if (p.y < 0 || p.y >= (int)var->w_h)
		return (-1);
	return (1);
}

void	draw_line_high(t_pixel p0, t_pixel p1, t_camera *var, t_data *data)
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
		if (is_scope(p0, var) == 1)
			my_mlx_pixel_put(data, p0.x, p0.y, p0.trgb);
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

void	draw_line_low(t_pixel p0, t_pixel p1, t_camera *var, t_data *data)
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
		if (is_scope(p0, var) == 1)
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

void	draw_line(t_pixel p0, t_pixel p1, t_camera *var, t_data *data)
{
	if (abs(p1.y - p0.y) < abs(p1.x - p0.x))
	{
		if (p0.x > p1.x)
			draw_line_low(p1, p0, var, data);
		else
			draw_line_low(p0, p1, var, data);
	}
	else
	{
		if (p0.y > p1.y)
			draw_line_high(p1, p0, var, data);
		else
			draw_line_high(p0, p1, var, data);
	}
}
