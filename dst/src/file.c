/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 20:15:18 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/15 21:30:49 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	file_putname(t_filedata *item)
{
	ft_putendl(item->filename);
}
void	file_putallname(t_vector *v)
{
	ft_vectforeach(v, (void *)&file_putname);
}

t_filedata	*file_initdata(char *path)
{
	t_filedata *filedata;

	if (!(filedata = ft_memalloc(sizeof(t_filedata) * 1)))
		return (NULL);
	filedata->filedir = ft_strdup("test");
	filedata->filename = path;
	stat(path, filedata->stat);
	return (filedata);
}
