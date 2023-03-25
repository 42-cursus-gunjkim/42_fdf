/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:15:58 by gunjkim           #+#    #+#             */
/*   Updated: 2023/03/25 18:45:51 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mlx_util.h"

void	error_exit(char *err_msg)
{
	perror(err_msg);
	exit(-1);
}

void	error_clear_exit(t_vars *var)
{
	free(var->map.map);
	mlx_destroy_image(var->mlx, var->data.i_p);
	mlx_destroy_window(var->mlx, var->win);
	exit(0);
}
