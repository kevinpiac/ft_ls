/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 16:16:41 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/30 11:32:15 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

//unused at this time
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
	ft_putendl(dirpath);
	while ((ret = readdir(dp)))
	{
		filedata = file_initdata(dirpath, ret->d_name);
		ft_vectadd(v, filedata); // cause issue with small vect capacity.
	}
	(void)closedir(dp);
}
