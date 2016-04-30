/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
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

char			*get_rights(t_filedata *file)
{
	char	*rights;
	int		i;

	i = 0;
	rights = ft_strnew(10);
	rights[i++] = (S_ISDIR(file->stat->st_mode)) ? 'd' : '-';
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

int				get_biggestsize(t_vector *v)
{
	int			i;
	int			size;
	t_filedata	*file;

	size = 0;
	i = 0;
	while (i < v->total)
	{
		file = ft_vectget(v, i);
		if (size < file->stat->st_size)
			size = file->stat->st_size;
		i++;
	}
	i = 0;
	while (size > 0)
	{
		size /= 10;
		i++;
	}
	return (i);
}

static void		print_size(int	max_size, t_filedata *file)
{
	int		i;
	int		filesize;

	filesize = file->stat->st_size;
	i = 0;
	while (filesize > 0)
	{
		filesize /= 10;
		i++;
	}
	while (max_size - i > 1)
	{
		ft_putchar(' ');
		max_size--;
	}
	ft_putnbr(file->stat->st_size);
}

static void		print_long(t_vector *v)
{
	int			i;
	t_filedata	*file;
	char		*rights;
	int			max_size;

	max_size = get_biggestsize(v);
	i = 0;
	while (i < v->total)
	{
		file = ft_vectget(v, i);
		rights = get_rights(file);
		ft_putstr(rights);
		ft_putstr("  ");
		ft_putnbr(6);
		ft_putstr(" ");
		ft_putstr(get_user(file));
		ft_putstr("  ");
		ft_putstr(get_group(file));
		ft_putstr("  ");
		print_size(max_size, file);
		ft_putstr(" Apr 16 09:09 "); // should add the real date here. and think about devices.
		ft_putendl(file->filename);
		i++;
	}
}

static void		print_filename(t_filedata *file)
{
	ft_putendl(file->filename);
}

void			print_all(t_vector *v, t_opm_params *opm)
{
	if (opm_issetoption(opm->config, "l"))
		print_long(v);
	else
		ft_vectforeach(v, (void *)&print_filename);
}
