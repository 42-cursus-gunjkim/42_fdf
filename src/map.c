/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gunjkim <gunjkim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 21:49:12 by gunjkim           #+#    #+#             */
/*   Updated: 2023/01/31 17:14:59 by gunjkim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "fcntl.h"
#include "error.h"
#include "struct.h"

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

t_list	*read_map(const char *file_path)
{
	char	*tmp;
	int		fd;
	t_line	*line_tmp;
	t_list	*head;

	fd = open(file_path, O_RDONLY);
	tmp = get_next_line(fd);
	while (tmp != NULL)
	{
		line_tmp = (t_line *)malloc(sizeof(t_line));
		line_tmp->element = ft_split(tmp, ' ');
		ft_lstadd_back(&head, ft_lstnew(line_tmp));
		free(tmp);
		tmp = get_next_line(fd);
	}
	return (head);
}

void	map_to_pixel(t_line	*line, t_vars *var)
{
	size_t	i_w;

	i_w = 0;
	while (i_w < var->map_w)
	{
		var->map[line->i_h * var->map_w + i_w].x = i_w;
		var->map[line->i_h * var->map_w + i_w].y = line->i_h;
		var->map[line->i_h * var->map_w + i_w].z = ft_atoi(line->element[i_w]);
		var->map[line->i_h * var->map_w + i_w].trgb = 0x00FF0000;
		i_w++;
	}
}

int	map_init(const char *file_path, t_vars *var)
{
	t_list	*head;
	t_list	*tmp;

	head = read_map(file_path);
	if (count_validate_map(head, var) == 0)
		ft_lstclear(&head, lst_free_double);
	var->map = (t_pixel *)malloc(sizeof(t_pixel) * var->map_w * var->map_h);
	if (var->map == NULL)
	{
		ft_lstclear(&head, lst_free_double);
		return (0);
	}
	tmp = head;
	while (tmp)
	{
		map_to_pixel(tmp->content, var);
		tmp = tmp->next;
	}
	ft_lstclear(&head, lst_free_double);
	return (1);
}
