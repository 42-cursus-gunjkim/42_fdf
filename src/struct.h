/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:46:53 by gunjkim           #+#    #+#             */
/*   Updated: 2023/02/07 14:24:14 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include <stdlib.h>

typedef struct s_data{
	void	*img;
	char	*addr;
	int		bpp;
	int		len;
	int		endian;
}	t_data;

typedef struct s_line{
	char	**element;
	size_t	i_h;
}	t_line;

typedef struct s_pixel{
	int	x;
	int	y;
	int	z;
	int	trgb;
}	t_pixel;

typedef struct s_vars{
	void	*mlx;
	void	*win;
	t_pixel	*map;
	t_data	*data;
	size_t	map_w;
	size_t	map_h;
	size_t	win_w;
	size_t	win_h;
	size_t	interval;
}	t_vars;

#endif
