/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 14:17:03 by gunjkim           #+#    #+#             */
/*   Updated: 2023/03/20 16:20:02 by gunjkim          ###   ########.fr       */
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

t_point	*parse_map(char *map_path);

#endif