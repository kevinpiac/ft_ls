/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 20:15:18 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/30 14:59:02 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*file_getpath(const char *basepath, char *filename)
{
	char		*path;
	char		*basepathendl;

	if (basepath[ft_strlen(basepath) - 1] != '/')
		basepathendl = ft_strjoin(basepath, "/");
	else
		basepathendl = ft_strdup(basepath);
	path = ft_strjoin(basepathendl, filename);
	free(basepathendl);
	return (path);
}

void	file_putname(t_filedata *item) //causes a segfault
{
	if (S_ISDIR(item->stat->st_mode))
		ft_putstr("DIR: ");
	if (S_ISREG(item->stat->st_mode))
		ft_putstr("REG: ");
	ft_putendl(item->filename);
}

void	file_putallname(t_vector *v)
{
	ft_vectforeach(v, (void *)&file_putname);
}

void	file_recursive(t_vector *v, t_opm_params *opm)
{
	int			i;
	t_filedata	*item;

	i = 0;
	while (i < (v->total))
	{
		item = v->items[i];
		if (ft_strcmp(item->filename, ".") && ft_strcmp(item->filename, ".."))
		{
			if (S_ISDIR(item->stat->st_mode))
				file_ls(item->path, opm);
		}
		i++;
	}
}

void	file_ls(char *path, t_opm_params *opm)
{
	t_vector	*v;
	int			i;

	i = 0;
	v = ft_vectnew();
	dir_storecontent(path, v);
	sort_lexico(v);
	file_putallname(v);
	if (opm_issetoption(opm->config, "R"))
		file_recursive(v, opm);
}

t_filedata	*file_initdata(const char *basepath, char *filename)
{
	t_filedata	*filedata;
	struct stat	*stat;

	filedata = (t_filedata *)ft_memalloc(sizeof(t_filedata) * 1);
	filedata->basepath = ft_strdup(basepath);
	filedata->filename = ft_strdup(filename);
	filedata->path = file_getpath(basepath, filename);
	stat = (struct stat *)ft_memalloc(sizeof(struct stat) * 1);
	lstat(filedata->path, stat);
	filedata->stat = stat;
	return (filedata);
}
