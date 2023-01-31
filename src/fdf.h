/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:56:08 by gunjkim           #+#    #+#             */
/*   Updated: 2023/01/31 16:23:29 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "color.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

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
}	t_vars;

void	error_and_exit(const char *error_msg);
void	lst_free_double(void *content);
int		map_init(const char *path, t_vars *var);
void	free_double_arr(char **arr);

#endif