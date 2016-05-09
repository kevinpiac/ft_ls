/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/15 20:15:18 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/30 18:05:34 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_bool			is_dir(const char *path)
{
	struct stat	*stat;

	stat = (struct stat *)ft_memalloc(sizeof(struct stat) * 1);
	lstat(path, stat);
	return (S_ISDIR(stat->st_mode));
}

t_bool			is_reg(const char *path)
{
	struct stat	*stat;

	stat = (struct stat *)ft_memalloc(sizeof(struct stat) * 1);
	lstat(path, stat);
	return (S_ISREG(stat->st_mode));
}
