/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:36:30 by gunjkim           #+#    #+#             */
/*   Updated: 2023/02/07 14:52:49 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "render.h"

void	isomeric(t_vars *var)
{
	size_t	w_i;
	size_t	h_i;
	size_t	m_i;
	int		tmp_x;
	int		tmp_y;
	int		tmp_z;

	h_i = 0;
	while (h_i < var->map_h)
	{
		w_i = 0;
		m_i = h_i * var->map_w;
		while (w_i < var->map_w)
		{
			tmp_x = var->map[m_i].x;
			tmp_y = var->map[m_i].y;
			tmp_z = var->map[m_i].z;
			var->map[m_i].x = (int)((tmp_x - tmp_z)/sqrt(2));
			var->map[m_i].y = (int)((tmp_x + 2 * tmp_y + tmp_z) / sqrt(6));
			w_i++;
			m_i++;
		}
		h_i++;
	}
}
