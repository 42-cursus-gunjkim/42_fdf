/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:17:49 by gunjkim           #+#    #+#             */
/*   Updated: 2023/03/21 23:34:08 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int	main(int argc, char *argv[])
{
	t_map	*map;
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	int		f;
	int		i;
	int		max;
	int		x;
	int		y;

	if (argc < 2)
		error_exit("Too few arguments");
	map = parse_map(argv[1]);
	mlx = mlx_init();
	img.img = mlx_new_image(mlx, 1500, 900);
	img.addr = mlx_get_data_addr(img.img, &(img.bpp), &(img.line_length), &(img.endian));
	mlx_win = mlx_new_window(mlx, 1500, 900, "exmaple");
	f = ft_atoi(argv[2]);
	i = 0;
	max = map->m_w * map->m_h;
	while (i < max)
	{
		x = f * ((map->map[i].x - map->map[i].y) * cos(0.523599)) + 750;
		y = f * (-(map->map[i].z) + (map->map[i].x + map->map[i].y) * sin(0.523599)) + 450;
		if ( (x >= 0 && x < 1500) && (y >= 0 && y < 900))
			my_mlx_pixel_put(&img, x, y, 0xFFFFFF);
		i++;
	}
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	

	return (0);
}