/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 20:15:18 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/30 18:05:34 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char			*file_getpath(const char *basepath, char *filename)
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

void			file_recursive(t_vector *v, t_opm_params *opm)
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
				list_dir(item->path, opm);
		}
		i++;
	}
}

void			file_del(void *this)
{
	t_filedata	*file;

	file = (t_filedata *)this;
	if (!file)
		return ;
	if (file->basepath)
		free(file->basepath);
	if (file->filename)
		free(file->filename);
	if (file->path)
		free(file->path);
	if (file->stat)
		free(file->stat);
	free(file);
}

t_filedata		*file_initdata(const char *basepath, char *filename)
{
	t_filedata	*filedata;
	struct stat	*stat;

	filedata = (t_filedata *)ft_memalloc(sizeof(t_filedata) * 1);
	filedata->basepath = ft_strdup(basepath);
	if (filename)
	{
		filedata->filename = ft_strdup(filename);
		filedata->path = file_getpath(basepath, filename);
	}
	else
	{
		filedata->filename = ft_strdup(basepath);
		filedata->path = ft_strdup(basepath);
	}
	stat = (struct stat *)ft_memalloc(sizeof(struct stat) * 1);
	lstat(filedata->path, stat);
	filedata->stat = stat;
	return (filedata);
}
