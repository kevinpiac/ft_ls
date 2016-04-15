/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 15:13:31 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/15 20:27:20 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int ac, char **av)
{
	t_vector	*v;
	t_filedata	*fdata;

	(void)ac;

	v = ft_vectnew();
	dir_storecontent(av[1], v);
	fdata = ft_vectget(v, 0);
	ft_putstr(fdata->filename);
	fdata = ft_vectget(v, 1);
	ft_putstr(fdata->filename);
}
