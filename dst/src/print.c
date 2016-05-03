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

char 					*get_time(t_filedata *file)
{
	time_t		time;
	char 			*d;
	char			*date;

	time = file->stat->st_mtime;
	d = ft_strsub(ctime(&time), 4, 12);
	date = ft_strjoin(d, " ");
	free(d);
	return (date);
}

int 			get_total_blocks(t_vector *v)
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

static void		print_size(int	max_size, t_filedata *file)
{
	int		i;
	int		filesize;

	filesize = file->stat->st_size;
	i = filesize ? 0 : 1;
	while (filesize > 0)
	{
		filesize /= 10;
		i++;
	}
	max_size = max_size - i;
	while (max_size > 0)
	{
		ft_putchar(' ');
		max_size--;
	}
	ft_putnbr(file->stat->st_size);
}

static void		print_long(t_vector *v)
{
	int					i;
	t_filedata	*file;
	int					max_size;

	max_size = get_biggestsize(v);
	i = 0;
	while (i < v->total)
	{
		file = ft_vectget(v, i);
		ft_putstr(get_rights(file));
		ft_putstr("  ");
		ft_putnbr(file->stat->st_nlink);
		ft_putstr(" ");
		ft_putstr(get_user(file));
		ft_putstr("  ");
		ft_putstr(get_group(file));
		ft_putstr("  ");
		print_size(max_size, file);
		ft_putstr(" ");
		ft_putstr(get_time(file));
		ft_putendl(file->filename);
		i++;
	}
}

static void		print_filename(t_filedata *file)
{
	ft_putendl(file->filename);
}

void				print_all(char *dirname, t_vector *v, t_opm_params *opm)
{
	int					once;

	once = 0;
	if (!once && dirname && opm->params->total > 1)
		ft_putendl("");
	if (!once && dirname)
		ft_putendl(ft_strjoin(dirname, ":"));
	once++;
	if (opm_issetoption(opm->config, "l"))
	{
		if (dirname)
		{
			ft_putstr("total ");
			ft_putnbr(get_total_blocks(v));
			ft_putendl("");
		}
		print_long(v);
	}
	else
		ft_vectforeach(v, (void *)&print_filename);
}
