/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 16:14:43 by gunjkim           #+#    #+#             */
/*   Updated: 2023/03/28 00:23:41 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/mlx_util_bonus.h"

void	isomeric(t_pixel *img, t_camera *camera, int i_max)
{
	int		i;
	float	tmp_x;
	float	a;

	i = 0;
	a = 0.523599;
	while (i < i_max)
	{
		tmp_x = img[i].x;
		img[i].x = round(((tmp_x - img[i].y) * cos(a)) + camera->o_w);
		img[i].y = round((-img[i].z) + (tmp_x + img[i].y) * sin(a) \
		+ camera->o_h);
		i++;
	}
}

void	parallel_yz(t_pixel *img, t_camera *camera, int i_max)
{
	int	i;

	i = 0;
	if (camera->method == PARAL_YZ)
	{
		while (i < i_max)
		{
			img[i].x = round(img[i].y + camera->o_w);
			img[i].y = round(-img[i].z + camera->o_h);
			i++;
		}
	}
}

void	rotate_x(t_pixel *p, float a)
{
	float	tmp_y;

	tmp_y = p->y;
	p->y = (tmp_y * cos(a) - p->z * sin(a));
	p->z = (tmp_y * sin(a) + p->z * cos(a));
}

void	rotate_y(t_pixel *p, float a)
{
	float	tmp_x;

	tmp_x = p->x;
	p->x = (tmp_x * cos(a) + p->z * sin(a));
	p->z = (-tmp_x * sin(a) + p->z * cos(a));
}

void	rotate_z(t_pixel *p, float a)
{
	float	tmp_x;

	tmp_x = p->x;
	p->x = (tmp_x * cos(a) - p->y * sin(a));
	p->y = (tmp_x * sin(a) + p->y * cos(a));
}
