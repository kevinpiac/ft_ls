/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 13:17:58 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/30 14:57:58 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		sort_lexico(t_vector *v)
{
	int			i;
	t_filedata	*tmp;
	t_filedata	*file;
	t_filedata	*next;

	i = 0;
	while (i < v->total - 1)
	{
		file = ft_vectget(v, i);
		next = ft_vectget(v, i + 1);
		if (ft_strcmp(file->filename, next->filename) > 0)
		{
			tmp = v->items[i];
			v->items[i] = v->items[i + 1];
			v->items[i + 1] = tmp;
			i = -1;
		}
		i++;
	}
}

void		sort_lexico_inverted(t_vector *v)
{
	int			i;
	t_filedata	*tmp;
	t_filedata	*file;
	t_filedata	*next;

	i = 0;
	while (i < v->total - 1)
	{
		file = ft_vectget(v, i);
		next = ft_vectget(v, i + 1);
		if (ft_strcmp(file->filename, next->filename) < 0)
		{
			tmp = v->items[i];
			v->items[i] = v->items[i + 1];
			v->items[i + 1] = tmp;
			i = -1;
		}
		i++;
	}
}

static void sort_date(t_vector *v)
{
	int			i;
	t_filedata	*tmp;
	t_filedata	*file;
	t_filedata	*next;

	i = 0;
	while (i < v->total - 1)
	{
		file = ft_vectget(v, i);
		next = ft_vectget(v, i + 1);
		if (file->stat->st_mtime < next->stat->st_mtime)
		{
			tmp = v->items[i];
			v->items[i] = v->items[i + 1];
			v->items[i + 1] = tmp;
			i = -1;
		}
		i++;
	}
}

void 		sort(t_vector *v, t_opm_params *opm)
{
	if (opm_issetoption(opm->config, "r"))
		sort_lexico_inverted(v);
	else if (opm_issetoption(opm->config, "t"))
		sort_date(v);
	else
		sort_lexico(v);
}
