/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 15:13:31 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/30 17:53:40 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void		case_link(const char *path, t_opm_params *opm, t_files *to_list)
{
	if (opm_issetoption(opm->config, "l"))
		ft_vectadd(to_list->files, file_initdata(path, NULL));
	else
		ft_vectadd(to_list->dirs, file_initdata(ft_strjoin(path, "/"), NULL));
}

t_files			*dispatch(t_opm_params *opm)
{
	t_files		*to_list;
	char		*path;
	int			i;

	to_list = (t_files *)ft_memalloc(sizeof(t_files) * 1);
	to_list->files = ft_vectnew();
	to_list->dirs = ft_vectnew();
	i = 0;
	while (i < opm->params->total)
	{
		path = arm_getparam_name(opm->params, i);
		if (is_reg(path))
			ft_vectadd(to_list->files, file_initdata(path, NULL));
		else if (is_dir(path))
			ft_vectadd(to_list->dirs, file_initdata(path, NULL));
		else if (is_lnk(path))
			case_link(path, opm, to_list);
		else
			perror(ft_strjoin("ls: ", path));
		i++;
	}
	return (to_list);
}
