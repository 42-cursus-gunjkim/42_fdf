/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 16:17:49 by gunjkim           #+#    #+#             */
/*   Updated: 2023/03/22 19:36:46 by gunjkim          ###   ########.fr       */
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
	t_pixel	*pixel;

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
	pixel = (t_pixel *)malloc(sizeof(t_pixel) * max);
	while (i < max)
	{
		pixel[i].x = f * ((map->map[i].x - map->map[i].y) * cos(0.523599)) + 750;
		pixel[i].y = f * (-(map->map[i].z) + (map->map[i].x + map->map[i].y) * sin(0.523599)) + 450;
		pixel[i].trgb = 0xFFFFFF;
		i++;
	}//isometric하면서 회전변환혹은 변환을 완료하고 이부분에서 키후킹
	t_camera camera;
	camera.w_w = 1500;
	camera.w_h = 900;
	int h_i = 0;
	int w_i = 0;
	int	m_i;
	while (h_i < map->m_h)
	{
		w_i = 0;
		m_i = h_i * map->m_w;
		while (w_i < map->m_w)
		{
			if (m_i == 0 || m_i % map->m_w != map->m_w - 1)
				draw_line(pixel[m_i], pixel[m_i + 1], &camera, &img);
			if (h_i != map->m_h - 1)
				draw_line(pixel[m_i], pixel[m_i + map->m_w], &camera, &img);
			w_i++;
			m_i++;
		}
		h_i++;
	}//라인그리기//라인그리는 함수 수정 필요
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
	return (0);
}