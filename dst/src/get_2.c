/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 15:05:07 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/30 17:53:17 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int					get_total_blocks(t_vector *v)
{
	int				i;
	int				total;
	t_filedata		*file;

	i = 0;
	total = 0;
	while (i < v->total)
	{
		file = ft_vectget(v, i);
		total += file->stat->st_blocks;
		i++;
	}
	return (total);
}

static int			ft_numlen(int n)
{
	int			i;

	i = n < 0 ? 1 : 0;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void			set_minor_major_pad(t_filedata *file, int padding[])
{
	if (S_ISCHR(file->stat->st_mode) || S_ISBLK(file->stat->st_mode))
	{
		if (padding[3] < ft_numlen(major(file->stat->st_rdev)))
			padding[3] = ft_numlen(major(file->stat->st_rdev));
		if (padding[4] < ft_numlen(minor(file->stat->st_rdev)))
			padding[4] = ft_numlen(minor(file->stat->st_rdev));
		if (padding[5] < padding[3] + padding[4] + 2)
			padding[5] = padding[3] + padding[4] + 2;
	}
}

void				get_padding(t_vector *v, int padding[])
{
	int				i;
	t_filedata		*file;

	i = 0;
	while (i < 7)
		padding[i++] = 0;
	i = 0;
	while (i < v->total)
	{
		file = ft_vectget(v, i);
		if (padding[0] < ft_numlen(file->stat->st_nlink))
			padding[0] = ft_numlen(file->stat->st_nlink);
		if (padding[1] < (int)ft_strlen(get_user(file)))
			padding[1] = (int)ft_strlen(get_user(file));
		if (padding[2] < (int)ft_strlen(get_group(file)))
			padding[2] = (int)ft_strlen(get_group(file));
		set_minor_major_pad(file, padding);
		if (padding[5] < ft_numlen(file->stat->st_size))
			padding[5] = ft_numlen(file->stat->st_size);
		if (padding[6] < (int)ft_strlen(file->filename))
			padding[6] = (int)ft_strlen(file->filename);
		i++;
	}
}
