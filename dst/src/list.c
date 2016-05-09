/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 16:16:41 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/30 18:11:33 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			list_dir(char *path, t_opm_params *opm)
{
	t_vector		*v;
	int				i;
	char			*error;

	i = 0;
	v = ft_vectnew();
	if ((error = dir_storecontent(path, v, opm)))
	{
		if (opm->params->total > 1 || opm_issetoption(opm->config, "R"))
			ft_putendl(ft_strjoin(path, ":"));
		ft_putendl(ft_strjoin("ls: ", error));
	}
	else
	{
		sort(v, opm);
		print_all(path, v, opm);
		if (opm_issetoption(opm->config, "R"))
			file_recursive(v, opm);
	}
	ft_vectdel(v, file_del);
}

void			list_files(t_vector *files, t_opm_params *opm)
{
	if (files->total)
		print_all(NULL, files, opm);
}

void			list_directories(t_vector *dirs, t_opm_params *opm)
{
	int				i;
	t_filedata		*dir;

	i = 0;
	while (i < dirs->total)
	{
		dir = ft_vectget(dirs, i);
		list_dir(dir->filename, opm);
		i++;
	}
}

void			list(t_files *to_list, t_opm_params *opm)
{
	list_files(to_list->files, opm);
	list_directories(to_list->dirs, opm);
	files_del(to_list);
}
