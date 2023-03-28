/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 18:49:59 by gunjkim           #+#    #+#             */
/*   Updated: 2023/03/28 00:23:12 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/mlx_util_bonus.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	get_height_color(int h, int min, int max)
{
	float	ratio;
	int		mul;

	if (min == max)
		return (0xFFFFFF);
	ratio = 255 / ft_abs(((max - min) / 2));
	mul = round(ft_abs(h - (max + min) / 2) * ratio);
	if (mul > 255)
		mul = 255;
	if (h >= (max + min) / 2)
		return (create_trgb(0, 255 - mul, 255 - mul, 255));
	else
		return (create_trgb(0, 255, 255 - mul, 255 - mul));
}

void	get_color(t_pixel *p0, t_pixel *p1, t_pixel *tmp)
{
	float	rate;

	rate = ft_abs(p0->x - p1->x) + ft_abs(p0->y - p1->y);
	tmp->r = tmp->r + ((p1->trgb >> 16 & 0xFF) - (p0->trgb >> 16 & 0xFF)) \
	/ rate;
	tmp->g = tmp->g + ((p1->trgb >> 8 & 0xFF) - (p0->trgb >> 8 & 0xFF)) / rate;
	tmp->b = tmp->b + (((p1->trgb) & 0xFF) - ((p0->trgb) & 0xFF)) / rate;
	tmp->trgb = create_trgb(0, (int)tmp->r, (int)tmp->g, (int)tmp->b);
}
