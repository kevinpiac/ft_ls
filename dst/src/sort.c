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

static int 	modif_time(void *file1, void *file2)
{
	t_filedata	*f1;
	t_filedata 	*f2;

	f1 = (t_filedata *)file1;
	f2 = (t_filedata *)file2;
	if (f1->stat->st_mtime < f2->stat->st_mtime)
		return (1);
	return (0);
}

static int 	lexico(void *file1, void *file2)
{
	t_filedata	*f1;
	t_filedata 	*f2;

	f1 = (t_filedata *)file1;
	f2 = (t_filedata *)file2;
	if (ft_strcmp(f1->filename, f2->filename) > 0)
		return (1);
	return (0);
}

void 		sort(t_vector *v, t_opm_params *opm)
{
	if (opm_issetoption(opm->config, "r"))
		ft_vectbubblesort(v, &lexico, -1);
	else if (opm_issetoption(opm->config, "t"))
		ft_vectbubblesort(v, &modif_time, 1);
	else
		ft_vectbubblesort(v, &lexico, 1);
}
