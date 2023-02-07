/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:45:17 by gunjkim           #+#    #+#             */
/*   Updated: 2023/02/07 14:57:21 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include <stdio.h>
# include <stdlib.h>
# include "struct.h"
# include "../libft/libft.h"

void	error_and_exit(const char *error_msg);
void	lst_free_double(void *content);
void	free_double_arr(char **arr);

#endif