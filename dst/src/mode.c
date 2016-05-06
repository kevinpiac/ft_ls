/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 15:05:07 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/30 17:53:17 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char 			mode_get_type(mode_t st_mode)
{
	if (S_ISBLK(st_mode))
		return ('b');
	else if (S_ISCHR(st_mode))
		return ('c');
	else if (S_ISDIR(st_mode))
		return ('d');
	else if (S_ISLNK(st_mode))
		return ('l');
	else if (S_ISSOCK(st_mode))
		return ('s');
	else if (S_ISFIFO(st_mode))
		return ('p');
	else
		return ('-');
}

void 			mode_set_owner(mode_t st_mode, char *mode)
{
	mode[0] = st_mode & S_IRUSR ? 'r' : '-';
	mode[1] = st_mode & S_IWUSR ? 'w' : '-';
	if (st_mode & S_ISUID && !(st_mode & S_IXUSR))
		mode[2] = 'S';
	else if (st_mode & S_ISUID && st_mode & S_IXUSR)
		mode[2] = 's';
	else if (st_mode & S_IXUSR)
		mode[2] = 'x';
	else
		mode[2] = '-';
}

void 			mode_set_group(mode_t st_mode, char *mode)
{
	mode[0] = st_mode & S_IRGRP ? 'r' : '-';
	mode[1] = st_mode & S_IWGRP ? 'w' : '-';
	if (st_mode & S_ISGID && !(st_mode & S_IXGRP))
		mode[2] = 'S';
	else if (st_mode & S_ISGID && st_mode & S_IXGRP)
		mode[2] = 's';
	else if (st_mode & S_IXGRP)
		mode[2] = 'x';
	else
		mode[2] = '-';
}

void 			mode_set_other(mode_t st_mode, char *mode)
{
	mode[0] = st_mode & S_IROTH ? 'r' : '-';
	mode[1] = st_mode & S_IWOTH ? 'w' : '-';
	if (st_mode & S_ISVTX && !(st_mode & S_IXOTH))
		mode[2] = 'T';
	else if (st_mode & S_ISVTX && st_mode & S_IXOTH)
		mode[2] = 't';
	else if (st_mode & S_IXOTH)
		mode[2] = 'x';
	else
		mode[2] = '-';
}
