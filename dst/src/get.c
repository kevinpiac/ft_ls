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

char 	get_filetype(t_filedata *file)
{
	if (S_ISBLK(file->stat->st_mode))
		return ('b');
	else if (S_ISCHR(file->stat->st_mode))
		return ('c');
	else if (S_ISDIR(file->stat->st_mode))
		return ('d');
	else if (S_ISLNK(file->stat->st_mode))
		return ('l');
	else if (S_ISSOCK(file->stat->st_mode))
		return ('s');
	else if (S_ISFIFO(file->stat->st_mode))
		return ('p');
	else
		return ('-');
}

char			*get_rights(t_filedata *file)
{
	char	*rights;
	int		i;

	i = 0;
	rights = ft_strnew(10);
	rights[i++] = get_filetype(file);
	rights[i++] = (file->stat->st_mode & S_IRUSR) ? 'r' : '-';
	rights[i++] = (file->stat->st_mode & S_IWUSR) ? 'w' : '-';
	rights[i++] = (file->stat->st_mode & S_IXUSR) ? 'x' : '-';
	rights[i++] = (file->stat->st_mode & S_IRGRP) ? 'r' : '-';
	rights[i++] = (file->stat->st_mode & S_IWGRP) ? 'w' : '-';
	rights[i++] = (file->stat->st_mode & S_IXGRP) ? 'x' : '-';
	rights[i++] = (file->stat->st_mode & S_IROTH) ? 'r' : '-';
	rights[i++] = (file->stat->st_mode & S_IWOTH) ? 'w' : '-';
	rights[i++] = (file->stat->st_mode & S_IXOTH) ? 'x' : '-';
	return (rights);
}
