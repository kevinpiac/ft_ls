/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 16:16:41 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/30 18:11:33 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			files_del(void *f)
{
	t_files		*this;

	this = (t_files *)f;
	if (!this)
		return ;
	if (this->dirs)
		ft_vectdel(this->dirs, file_del);
	if (this->files)
		ft_vectdel(this->files, file_del);
	free(this);
}
