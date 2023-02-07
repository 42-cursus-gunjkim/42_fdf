/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 21:49:12 by gunjkim           #+#    #+#             */
/*   Updated: 2023/02/07 14:59:33 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "fcntl.h"
#include "error.h"
#include "struct.h"
#include <math.h>

size_t	count_element(char **element)
{
	size_t	count;

	count = 0;
	while (element[count] != NULL)
		count++;
	return (count);
}

int	count_validate_map(t_list *head, t_vars *var)
{
	size_t	i_h;

	i_h = 0;
	var->map_h = ft_lstsize(head);
	var->map_w = count_element(((t_line *)(head->content))->element);
	while (head)
	{
		if (var->map_w != count_element(((t_line *)(head->content))->element))
			return (0);
		((t_line *)(head->content))->i_h = i_h;
		i_h++;
		head = head->next;
	}
	return (1);
}

int	read_map(const char *file_path, t_list **head)
{
	char	*tmp;
	int		fd;
	t_line	*line_tmp;

	fd = open(file_path, O_RDONLY);
	if (fd == -1)
		return (-1);
	tmp = get_next_line(fd);
	while (tmp != NULL)
	{
		line_tmp = (t_line *)malloc(sizeof(t_line));
		line_tmp->element = ft_split(tmp, ' ');
		ft_lstadd_back(head, ft_lstnew(line_tmp));
		free(tmp);
		tmp = get_next_line(fd);
	}
	return (0);
}

void	map_to_pixel(t_line	*line, t_vars *var)
{
	size_t	i_w;
	size_t	o_w;
	size_t	o_h;

	i_w = 0;
	o_w = (var->win_w / 2) - ((var->map_w / 2) * var->interval);
	o_h = (var->win_h / 2) - ((var->map_h / 2) * var->interval);
	while (i_w < var->map_w)
	{
		var->map[line->i_h * var->map_w + i_w].x = i_w * var->interval + o_w;
		var->map[line->i_h * var->map_w + i_w].y = line->i_h * var->interval + o_h;
		var->map[line->i_h * var->map_w + i_w].z = ft_atoi(line->element[i_w]) * var->interval;
		var->map[line->i_h * var->map_w + i_w].trgb = 0xFFFFFF;
		i_w++;
	}
}

void	deter_win(t_vars *var)
{
	size_t	max_interval;
	size_t	tmp_interval;
	size_t	win_w_tmp;
	size_t	win_h_tmp;

	win_w_tmp = 2180;
	win_h_tmp = 1080;
	max_interval = 50;
	tmp_interval = win_w_tmp / var->map_w;
	if (tmp_interval > win_h_tmp / var->map_h)
		tmp_interval = win_h_tmp / var->map_h;
	if (tmp_interval > 50)
		tmp_interval = 50;
	if (tmp_interval == 0)
		tmp_interval = 1;
	var->interval = tmp_interval;
	var->win_w = var->interval * var->map_w;
	var->win_h = var->interval * var->map_h;
}

void	map_init(const char *file_path, t_vars *var)
{
	t_list	*head;
	t_list	*tmp;

	head = NULL;
	if (read_map(file_path, &head) == -1)
		error_and_exit("Map reading fail");
	if (count_validate_map(head, var) == 0)
		ft_lstclear(&head, lst_free_double);
	var->map = (t_pixel *)malloc(sizeof(t_pixel) * var->map_w * var->map_h);
	if (var->map == NULL)
	{
		ft_lstclear(&head, lst_free_double);
		error_and_exit(NULL);
	}
	deter_win(var);
	tmp = head;
	while (tmp)
	{
		map_to_pixel(tmp->content, var);
		tmp = tmp->next;
	}
	ft_lstclear(&head, lst_free_double);
}
