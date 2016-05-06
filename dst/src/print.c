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

void 		set_padding(char *src, char *dst, int padding, char direction)
{
	int 	len;
	int 	i;
	int 	j;
	int 	pad;

	len = ft_strlen(src);
	pad = ABS(padding - len);
	j = 0;
	i = pad;
	while (*dst)
		++dst;
	if (direction == 'r')
	{
		while (j < i)
			dst[j++] = ' ';
	}
	i = 0;
	while (src[i])
		dst[j++] = src[i++];
	if (direction == 'l')
	{
		while (j < pad)
			dst[j++] = ' ';
	}
}

void 				print_line_long(t_filedata *file, int p[])
{
	char		*line;

	line = ft_strnew(p[0] + p[1] + p[2] + p[3] + p[4] + p[5] + p[6] + 50);
	mode_set(file->stat->st_mode, line);
	set_padding(ft_itoa(file->stat->st_nlink), line, p[0], 'r');
	ft_strcat(line, " ");
	set_padding(get_user(file), line, p[1], 'l');
	ft_strcat(line, "  ");
	set_padding(get_group(file), line, p[2], 'l');
	ft_strcat(line, "  ");
	if (S_ISCHR(file->stat->st_mode))
	{
		set_padding(ft_itoa(major(file->stat->st_rdev)), line, p[3], 'r');
		ft_strcat(line, ", ");
		set_padding(ft_itoa(minor(file->stat->st_rdev)), line, p[4], 'r');
	}
	else
		set_padding(ft_itoa(file->stat->st_size), line, p[5], 'r');
	ft_strcat(line, " ");
	ft_strcat(line, get_time(file));
	// should get and show link if is symlink
	ft_strcat(line, file->filename);
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
	if (dirname && (once > 1 || opm->params->total > 1))// ok
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
			ft_putendl("");
		}
		print_long(v);
	}
	else
		ft_vectforeach(v, (void *)&print_filename);
}
