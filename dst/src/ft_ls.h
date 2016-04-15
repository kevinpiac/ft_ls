/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 15:18:19 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/15 21:27:19 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

#include <stdio.h>
#include "../libft/libft.h"
#include <dirent.h>
#include <sys/stat.h>

/*
**	FILE.C
*/

typedef struct			s_filedata
{
	char				*filedir;
	char				*filename;
	struct stat			*stat;
}						t_filedata;

t_filedata				*file_initdata(char *path);
void					file_putallname(t_vector *v);
void					file_putname(t_filedata *item);

/*
**	DIR.C
*/

void					dir_storecontent(const char *dirname, t_vector *v);
void					dir_showcontent(const char *dirname);
t_list					*dir_contenttolist(const char *dirname);

#endif
