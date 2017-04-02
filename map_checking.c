/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checking.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbauguen <vbauguen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/06 14:53:16 by vbauguen          #+#    #+#             */
/*   Updated: 2016/06/06 15:21:36 by vbauguen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	ft_check_map(t_id *s)
{
	while ((get_next_line(s->fd, &s->line)) > 0)
	{
		s->map[s->nl] = ft_parsing(s->line);
		s->nc = ft_get_number_of_words(s->line, ' ');
		if (s->nc != s->tmp)
			ft_error("The map lenght is not uniform\n");
		s->nl++;
		free(s->line);
		s->line = NULL;
	}
}

void	ft_check_negatives(t_id *s)
{
	int i;
	int j;

	i = 0;
	while (i < s->nl)
	{
		j = 0;
		while (j < s->nc)
		{
			if (s->map[i][j] < 0)
				ft_error("There must be no negatives in the map file.\n");
			j++;
		}
		i++;
	}
}
