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

void 				print_line_long(t_filedata *file, int p[])
{
	char		*line;

	line = ft_strnew(p[0] + p[1] + p[2] + p[3] + p[4] + p[5] + p[6] + 250);
	mode_set(file->stat->st_mode, line);
	set_padding_r(ft_itoa(file->stat->st_nlink), line, p[0]);
	ft_strcat(line, " ");
	set_padding_l(get_user(file), line, p[1]);
//	ft_strcat(line, "  ");
	set_padding_l(get_group(file), line, p[2]);
//	ft_strcat(line, "  ");
	if (S_ISCHR(file->stat->st_mode))
	{
		set_padding_r(ft_itoa(major(file->stat->st_rdev)), line, p[3]);
		ft_strcat(line, ", ");
		set_padding_r(ft_itoa(minor(file->stat->st_rdev)), line, p[4]);
	}
	else
		set_padding_r(ft_itoa(file->stat->st_size), line, p[5]);
	ft_strcat(line, " ");
	set_time(file->stat->st_mtime, line);
	// should get and show link if is symlink
	ft_strcat(line, file->filename);
	S_ISLNK(file->stat->st_mode) ? append_link(file, line) : 1;
	ft_putstr(line);
	free(line);
}

static void				print_long(t_vector *v)
{
	int					i;
	t_filedata			*file;
	int 				padding[7];

	get_padding(v, padding);
	i = 0;
	while (i < v->total)
	{
		file = ft_vectget(v, i);
		print_line_long(file, padding);
		ft_putchar('\n');
		i++;
	}
}

static void			print_filename(t_filedata *file)
{
	ft_putstr(file->filename);
	ft_putchar('\n');
}

void				print_all(char *dirname, t_vector *v, t_opm_params *opm)
{
	static int			once;

	once = once ? once : 1;
	if (dirname && once > 1)
		ft_putendl("");
	if (dirname && (once > 1 || opm->params->total > 1))
	{
		ft_putstr(dirname);
		ft_putendl(":");
	}
	once++;
	if (opm_issetoption(opm->config, "l"))
	{
		if (dirname && v->total)
		{
			ft_putstr("total ");
			ft_putnbr(get_total_blocks(v));
			ft_putchar('\n');
		}
		print_long(v);
	}
	else
		ft_vectforeach(v, (void *)&print_filename);
}
