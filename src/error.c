/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 21:37:59 by gunjkim           #+#    #+#             */
/*   Updated: 2023/01/31 16:34:23 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error_and_exit(const char *error_msg)
{
	perror(error_msg);
	exit(0);
}

void	lst_free_double(void *content)
{
	char	**arr_tmp;

	arr_tmp = ((t_line *)content)->element;
	free_double_arr(arr_tmp);
	free((t_line *)content);
}

void	free_double_arr(char **arr)
{
	char	**arr_tmp;

	arr_tmp = arr;
	if (arr == NULL)
		return ;
	while (*arr_tmp != NULL)
	{
		free(*arr_tmp);
		arr_tmp++;
	}
	free(arr);
}
