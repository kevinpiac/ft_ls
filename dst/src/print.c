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


static void				print_aligned(int	padding, char *str, char direction)
{
	int 	len;
	int 	i;

	len = ft_strlen(str);
	if (direction == 'r')
	{
		i = 0;
		while (i < padding - len)
		{
			ft_putchar(' ');
			i++;
		}
	}
	ft_putstr(str);
	if (direction == 'l')
	{
		i = 0;
		while (i < padding - len)
		{
			ft_putchar(' ');
			i++;
		}
	}
}

static void				print_long(t_vector *v)
{
	int					i;
	t_filedata			*file;
	int 				padding[6];

	get_padding(v, padding);
	i = 0;
	while (i < v->total)
	{
		file = ft_vectget(v, i);
		ft_putstr(get_rights(file));
		ft_putstr("  ");
		print_aligned(padding[0], ft_itoa(file->stat->st_nlink), 'r');
		ft_putstr(" ");
		print_aligned(padding[1], get_user(file), 'l');
		ft_putstr("  ");
		print_aligned(padding[2], get_group(file), 'l');
		ft_putstr("  ");
		if (S_ISCHR(file->stat->st_mode))
		{
			print_aligned(padding[3], ft_itoa(major(file->stat->st_rdev)), 'r');
			ft_putstr(", ");
			print_aligned(padding[4], ft_itoa(minor(file->stat->st_rdev)), 'r');
		}
		else
			print_aligned(padding[5], ft_itoa(file->stat->st_size), 'r');
		ft_putstr(" ");
		ft_putstr(get_time(file));
		// should get and show link if is symlink
		ft_putendl(file->filename);
		i++;
	}
}

static void			print_filename(t_filedata *file)
{
	ft_putendl(file->filename);
}

void				print_all(char *dirname, t_vector *v, t_opm_params *opm)
{
	static int			once;

	once = once ? once : 1;
	if (dirname && once > 1)
		ft_putendl("");
	if (dirname && (once > 1 || opm->params->total > 1))// ok
		ft_putendl(ft_strjoin(dirname, ":"));
	once++;
	if (opm_issetoption(opm->config, "l"))
	{
		if (dirname && v->total)
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
