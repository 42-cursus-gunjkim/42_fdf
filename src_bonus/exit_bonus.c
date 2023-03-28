/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:15:58 by gunjkim           #+#    #+#             */
/*   Updated: 2023/03/28 00:23:20 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include_bonus/mlx_util_bonus.h"

void	error_exit(char *err_msg)
{
	perror(err_msg);
	exit(-1);
}

void	clear_exit(t_vars *var)
{
	free(var->map.map);
	free(var->img);
	mlx_destroy_window(var->mlx, var->win);
	exit(0);
}
