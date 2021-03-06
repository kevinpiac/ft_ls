/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 16:16:41 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/30 18:11:33 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char			*dir_storecontent(const char *dirpath, t_vector *v,
					t_opm_params *opm)
{
	DIR				*dp;
	struct dirent	*ret;
	t_filedata		*filedata;

	if (is_reg(dirpath))
		ft_vectadd(v, file_initdata(dirpath, NULL));
	else
	{
		if (!(dp = opendir(dirpath)))
			return (strerror(errno));
		else
		{
			while ((ret = readdir(dp)))
			{
				if (filter_is_to_store(opm, ret->d_name))
				{
					filedata = file_initdata(dirpath, ret->d_name);
					ft_vectadd(v, filedata);
				}
			}
			(void)closedir(dp);
		}
	}
	return (NULL);
}
