/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 20:15:18 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/15 20:20:19 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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
