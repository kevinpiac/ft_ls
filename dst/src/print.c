/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 15:05:07 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/30 16:01:48 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static	char	*get_rights(t_filedata *file)
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

static void		print_long(t_vector *v)
{
	int			i;
	t_filedata	*file;
	char		*rights;

	i = 0;
	while (i < v->total)
	{
		file = ft_vectget(v, i);
		rights = get_rights(file);
		ft_putstr(rights);
		ft_putstr("  ");
		ft_putnbr(6);
		ft_putstr(" ");
		ft_putstr("kpiacent ");
		ft_putstr("2015_paris ");
		ft_putstr("9949");
		ft_putendl(file->filename);
		i++;
		// need to change this.
	}
}

void			print_all(t_vector *v, t_opm_params *opm)
{
	if (opm_issetoption(opm->config, "l"))
		print_long(v);
}
