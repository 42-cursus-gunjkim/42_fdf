/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 15:12:52 by gunjkim           #+#    #+#             */
/*   Updated: 2023/03/24 14:23:15 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXIT_H
# define EXIT_H

# include <stdio.h>
# include <stdlib.h>
# include "mlx_util.h"

void	error_exit(char *err_msg);
void	error_clear_exit(t_vars *var);

#endif