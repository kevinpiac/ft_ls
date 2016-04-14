/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dir.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 16:16:41 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/13 17:15:05 by kpiacent         ###   ########.fr       */
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
