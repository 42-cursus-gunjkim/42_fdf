/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:43:22 by gunjkim           #+#    #+#             */
/*   Updated: 2023/03/25 17:59:16 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mlx_util.h"

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
	var->err =var->dx + var->dy;
	p_cur->x = p0->x;
	p_cur->y = p0->y;
	p_cur->trgb = p0->trgb;
	p_cur->h = p0->trgb;
	p_cur->r = (p_cur->trgb >> 16) & 0xFF;
	p_cur->g = (p_cur->trgb >> 8) & 0xFF;
	p_cur->b = (p_cur->trgb) & 0xFF;
}

void	draw_line(t_pixel *p0, t_pixel *p1, t_camera *camera, t_data *data)
{
	t_line	var;
	t_pixel	p_cur;
	int		err_d;

	line_init(&p_cur, &var, p0, p1);
	while (1)
	{
		if (is_scope(p_cur.x, p_cur.y, camera))
			my_mlx_pixel_put(data, p_cur.x, p_cur.y, p_cur.trgb);
		if (p_cur.x == p1->x && p_cur.y == p1->y)
			break ;
		err_d = var.err * 2;
		if (err_d >= var.dy)
		{
			var.err += var.dy;
			p_cur.x += var.step_x;
		}
		if (err_d <= var.dx)
		{
			var.err += var.dx;
			p_cur.y += var.step_y;
		}
		if (p0->h != p1->h)
			get_color(p0, p1, &p_cur);
		else
			p_cur.trgb = p0->trgb;
	}
}
