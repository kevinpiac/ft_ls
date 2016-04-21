/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 20:15:18 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/21 14:15:53 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char	*file_getpath(char *basepath, char *filename)
{
	char		*path;

	if (basepath[ft_strlen(basepath) - 1] != '/')
		basepath = ft_strjoin(basepath, "/");
	path = ft_strjoin(basepath, filename);
	return (path);
}

void	file_putname(t_filedata *item)
{
	if (S_ISDIR(item->stat->st_mode))
		ft_putstr("DIR: ");
	if (S_ISREG(item->stat->st_mode))
		ft_putstr("REG: ");
	ft_putendl(item->filename);
}

// recursive concept is working but require changes.
void	file_recursive(t_vector *v)
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
			{
				ft_putendl(item->path);
				file_ls(item->path);
			}
		}
		i++;
	}
}


// this function is working but require changes.
void	file_ls(char *path)
{
	t_vector	*v;
	int			recursive;
	int			i;

	i = 0;
	recursive = 1;
	v = ft_vectnew();
	dir_storecontent(path, v);
	file_putallname(v);
	file_recursive(v);
}

void	file_putallname(t_vector *v)
{
	ft_vectforeach(v, (void *)&file_putname);
}

t_filedata	*file_initdata(const char *basepath, char *filename)
{
	t_filedata *filedata;

	if (!(filedata = ft_memalloc(sizeof(t_filedata) * 1)))
		return (NULL);
	filedata->basepath = ft_strdup(basepath);
	filedata->filename = ft_strdup(filename);
	filedata->path = file_getpath(filedata->basepath, filedata->filename); // should fix the const char issue.
	if (!(filedata->stat = ft_memalloc(sizeof(struct stat) * 1)))
		return (NULL);
	lstat(filedata->path, filedata->stat);
	return (filedata);
}
