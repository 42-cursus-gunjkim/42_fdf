/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:43:22 by gunjkim           #+#    #+#             */
/*   Updated: 2023/03/24 22:58:26 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mlx_util.h"

void	update_var_high(int *d, t_pixel *tmp, int dx, int dy)
{
	int	step;

	step = 1;
	if (dx < 0)
	{
		dx = -dx;
		step = -1;
	}
	if (*d > 0)
	{
		tmp->x = tmp->x + step;
		*d = *d + 2 * dx - 2 * dy;
	}
	else
		*d = *d + 2 * dx;
	tmp->y = tmp->y + 1;
}

void	update_var_low(int *d, t_pixel *tmp, int dx, int dy)
{
	int	step;

	step = 1;
	if (dy < 0)
	{
		dy = -dy;
		step = -1;
	}
	if (*d > 0)
	{
		tmp->y = tmp->y + step;
		*d = *d + 2 * (dy - dx);
	}
	else
		*d = *d + 2 * dy;
	tmp->x = tmp->x + 1;
}

void	draw_line_high(t_pixel *p0, t_pixel *p1, t_camera *camera, t_data *data)
{
	int		dx;
	int		dy;
	t_pixel	tmp;
	int		d;

	tmp = *p0;
	tmp.r = (tmp.trgb >> 16) & 0xFF;
	tmp.g = (tmp.trgb >> 8) & 0xFF;
	tmp.b = (tmp.trgb) & 0xFF;
	dx = p1->x - p0->x;
	dy = p1->y - p0->y;
	if (dx < 0)
		d = -2 * dx - dy;
	else
		d = 2 * dx - dy;
	while (tmp.y < p1->y)
	{
		if (is_scope(tmp.x, tmp.y, camera))
			my_mlx_pixel_put(data, tmp.x, tmp.y, tmp.trgb);
		update_var_high(&d, &tmp, dx, dy);
		if (p0->h != p1->h)
			get_color(p0, p1, &tmp);
		else
			tmp.trgb = p0->trgb;
	}
}

void	draw_line_low(t_pixel *p0, t_pixel *p1, t_camera *camera, t_data *data)
{
	int		dx;
	int		dy;
	t_pixel	tmp;
	int		d;

	tmp = *p0;
	tmp.r = (tmp.trgb >> 16) & 0xFF;
	tmp.g = (tmp.trgb >> 8) & 0xFF;
	tmp.b = (tmp.trgb) & 0xFF;
	dx = p1->x - p0->x;
	dy = p1->y - p0->y;
	if (dy < 0)
		d = -2 * dy - dx;
	else
		d = 2 * dy - dx;
	while ((tmp.x < p1->x))
	{
		if (is_scope(tmp.x, tmp.y, camera))
			my_mlx_pixel_put(data, tmp.x, tmp.y, tmp.trgb);
		update_var_low(&d, &tmp, dx, dy);
		if (p0->h != p1->h)
			get_color(p0, p1, &tmp);
		else
			tmp.trgb = p0->trgb;
	}
}

void	draw_line(t_pixel *p0, t_pixel *p1, t_camera *camera, t_data *data)
{
	if (ft_abs(p1->y - p0->y) < ft_abs(p1->x - p0->x))
	{
		if (p0->x > p1->x)
			draw_line_low(p1, p0, camera, data);
		else
			draw_line_low(p0, p1, camera, data);
	}
	else
	{
		if (p0->y > p1->y)
			draw_line_high(p1, p0, camera, data);
		else
			draw_line_high(p0, p1, camera, data);
	}
}
