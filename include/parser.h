/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:17:03 by gunjkim           #+#    #+#             */
/*   Updated: 2023/03/23 17:14:44 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <fcntl.h>

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
	int	trgb;
}	t_point;

typedef struct s_map
{
	t_point	*map;
	int		map_w;
	int		map_h;
}	t_map;

void	parse_map(t_map *map, char *map_path);

#endif