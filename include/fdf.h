/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:05:27 by gunjkim           #+#    #+#             */
/*   Updated: 2023/03/21 23:19:07 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "parser.h"
# include "error.h"
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <math.h>

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_camera {
	double	f;
}	t_camera;

void    my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif