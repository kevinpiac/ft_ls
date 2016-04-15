/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 16:16:41 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/15 20:24:36 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	dir_showcontent(const char *dirname)
{
	DIR				*dp;
	struct dirent	*ret;

	if (!(dp = opendir(dirname)))
	{
		perror("ls");
		return ;
	}
	while ((ret = readdir(dp)))
	{
		ft_putendl(ret->d_name);
	}
	(void)closedir(dp);
}

void	dir_storecontent(const char *dirname, t_vector *v)
{
	DIR				*dp;
	struct dirent	*ret;
	t_filedata		*filedata;

	if (!(dp = opendir(dirname)))
	{
		perror("ls");
		return ;
	}
	while ((ret = readdir(dp)))
	{
		filedata = file_initdata(ret->d_name); // add the path, not only the name;
		ft_vectadd(v, (t_filedata *)filedata);
	}
	(void)closedir(dp);
}
