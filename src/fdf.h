/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:56:08 by gunjkim           #+#    #+#             */
/*   Updated: 2023/02/02 14:22:36 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"
# include "color.h"
# include "error.h"
# include "struct.h"
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

int		map_init(const char *path, t_vars *var);
int		render(t_vars *vars);

#endif