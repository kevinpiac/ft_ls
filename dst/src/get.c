/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 15:05:07 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/30 17:53:17 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char			*get_user(t_filedata *file)
{
	struct passwd	*pwd;
	uid_t			id;

	id = file->stat->st_uid;
	if ((pwd = getpwuid(id)))
		return (pwd->pw_name);
	return (ft_itoa(id));
}

char			*get_group(t_filedata *file)
{
	struct group	*grp;
	gid_t			id;

	id = file->stat->st_gid;
	if ((grp = getgrgid(id)))
		return (grp->gr_name);
	return (ft_itoa(id));
}

char 			*get_mode(mode_t st_mode)
{
	char	*mode;

	mode = ft_strnew(10 + 2); // 2 for spaces
	mode[0] = mode_get_type(st_mode);
	mode_set_owner(st_mode, &mode[1]);
	mode_set_group(st_mode, &mode[4]);
	mode_set_other(st_mode, &mode[7]);
	mode[10] = ' ';
	mode[11] = ' ';
	return (mode);
}
