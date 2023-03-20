/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:27:02 by gunjkim           #+#    #+#             */
/*   Updated: 2023/03/20 18:57:23 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/util.h"

int	get_hex_value(char c)
{
	int		index;
	char	*hex;
	
	hex = "0123456789ABCDEF";
	index = 0;
	while (hex[index] != '\0')
	{
		if (hex[index] == c)
			return (index);
		index++;
	}
	return (-1);
}

int	hex_to_int(char *hex)
{
	int		t;
	int		r;
	int		g;
	int		b;

	//t = get_hex_value(hex[2]) * 16 + get_hex_value(hex[3]);
	t = 0;
	r = get_hex_value(hex[2]) * 16 + get_hex_value(hex[3]);
	g = get_hex_value(hex[4]) * 16 + get_hex_value(hex[5]);
	b = get_hex_value(hex[6]) * 16 + get_hex_value(hex[7]);
	return (create_trgb(t, r, g, b));
}
