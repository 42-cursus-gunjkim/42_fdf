/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:43:22 by gunjkim           #+#    #+#             */
/*   Updated: 2023/03/28 00:23:58 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/mlx_util_bonus.h"

int	is_scope(int x, int y, t_camera *camera)
{
	if (x < 0 || x >= camera->w_w)
		return (0);
	if (y < 0 || y >= camera->w_h)
		return (0);
	return (1);
}

void	line_init(t_pixel *p_cur, t_line *var, t_pixel *p0, t_pixel *p1)
{
	var->dx = ft_abs(p0->x - p1->x);
	var->dy = -ft_abs(p0->y - p1->y);
	var->step_x = -1;
	if (p0->x < p1->x)
		var->step_x = 1;
	var->step_y = -1;
	if (p0->y < p1->y)
		var->step_y = 1;
	var->err = var->dx + var->dy;
	*p_cur = *p0;
	p_cur->r = (p_cur->trgb >> 16) & 0xFF;
	p_cur->g = (p_cur->trgb >> 8) & 0xFF;
	p_cur->b = (p_cur->trgb) & 0xFF;
}

void	draw_line(t_pixel *p0, t_pixel *p1, t_camera *camera, t_data *data)
{
	t_line	var;
	t_pixel	p_cur;

	line_init(&p_cur, &var, p0, p1);
	while (1)
	{
		if (is_scope(p_cur.x, p_cur.y, camera))
			my_mlx_pixel_put(data, p_cur.x, p_cur.y, p_cur.trgb);
		if (p_cur.x == p1->x && p_cur.y == p1->y)
			break ;
		var.err_d = var.err * 2;
		if (var.err_d >= var.dy)
		{
			var.err += var.dy;
			p_cur.x += var.step_x;
		}
		if (var.err_d <= var.dx)
		{
			var.err += var.dx;
			p_cur.y += var.step_y;
		}
		if (p0->h != p1->h)
			get_color(p0, p1, &p_cur);
	}
}

void	parallel_xy(t_pixel *img, t_camera *camera, int i_max)
{
	int	i;

	i = 0;
	while (i < i_max)
	{
		img[i].x = round(img[i].x + camera->o_w);
		img[i].y = round(img[i].y + camera->o_h);
		i++;
	}
}

void	parallel_xz(t_pixel *img, t_camera *camera, int i_max)
{
	int	i;

	i = 0;
	while (i < i_max)
	{
		img[i].x = round(img[i].x + camera->o_w);
		img[i].y = round(-img[i].z + camera->o_h);
		i++;
	}
}
