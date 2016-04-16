/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 16:16:41 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/16 09:06:49 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	dir_showcontent(const char *dirpath)
{
	DIR				*dp;
	struct dirent	*ret;

	if (!(dp = opendir(dirpath)))
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

void	dir_storecontent(const char *dirpath, t_vector *v)
{
	DIR				*dp;
	struct dirent	*ret;
	t_filedata		*filedata;

	if (!(dp = opendir(dirpath)))
	{
		perror("ls");
		return ;
	}
	while ((ret = readdir(dp)))
	{
		filedata = file_initdata(dirpath, ret->d_name);
		ft_vectadd(v, (t_filedata *)filedata);
	}
	(void)closedir(dp);
}
