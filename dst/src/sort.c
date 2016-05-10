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

static int			lexico(void *file1, void *file2)
{
	t_filedata	*f1;
	t_filedata	*f2;

	f1 = (t_filedata *)file1;
	f2 = (t_filedata *)file2;
	if (ft_strcmp(f1->filename, f2->filename) > 0)
		return (1);
	return (0);
}

static int			modif_time(void *file1, void *file2)
{
	t_filedata	*f1;
	t_filedata	*f2;

	f1 = (t_filedata *)file1;
	f2 = (t_filedata *)file2;
	if (f1->stat->st_mtime == f2->stat->st_mtime)
	{
		if (f1->stat->st_mtimespec.tv_nsec == f2->stat->st_mtimespec.tv_nsec)
			return (lexico(f1, f2));
		if (f1->stat->st_mtimespec.tv_nsec < f2->stat->st_mtimespec.tv_nsec)
			return (1);
		return (0);
	}
	else if (f1->stat->st_mtimespec.tv_sec < f2->stat->st_mtimespec.tv_sec)
		return (1);
	return (0);
}

void				sort(t_vector *v, t_opm_params *opm)
{
	int		reverse;

	reverse = opm_issetoption(opm->config, "r") ? -1 : 1;
	if (opm_issetoption(opm->config, "t"))
		ft_vectbubblesort(v, &modif_time, reverse);
	else if (opm_issetoption(opm->config, "f"))
		return ;
	else
		ft_vectbubblesort(v, &lexico, reverse);
}
