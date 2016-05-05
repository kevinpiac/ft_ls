/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 15:18:19 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/30 18:05:54 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

#include <stdio.h>
#include "../libft/libft.h"
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>
#include <string.h>
#include <errno.h>

typedef struct		s_files
{
	t_vector		*files;
	t_vector		*dirs;
}					t_files;

/*
**	DISPATCH.C
*/

t_files					*dispatch(t_opm_params *opm);

/*
**	LIST.C
*/

void 					list(t_files *to_list, t_opm_params *opm);
void					list_dir(char *path, t_opm_params *opm);
void 					list_files(t_vector *files, t_opm_params *opm);
void 					list_directories(t_vector *dirs, t_opm_params *opm);

/*
**	FILE.C
*/

typedef struct			s_filedata
{
	char				*basepath;
	char				*filename;
	char				*path;
	struct stat			*stat;
}						t_filedata;

t_filedata				*file_initdata(const char *basepath, char *filename);
void					file_recursive(t_vector *v, t_opm_params *opm);
/*
**	PRINT.C
*/

void					print_all(char *dirname, t_vector *v, t_opm_params *opm);

/*
**	IS.C
*/

t_bool				is_reg(const char *path);
t_bool				is_dir(const char *path);

/*
**	DIR.C
*/

char					*dir_storecontent(const char *dirname, t_vector *v, t_opm_params *opm);
void					dir_showcontent(const char *dirname);
t_list					*dir_contenttolist(const char *dirname);

/*
** SORT.C
*/

void 					sort(t_vector *v, t_opm_params *opm);
void					sort_lexico(t_vector *v);

/*
** GET.c
*/

char					*get_user(t_filedata *file);
char					*get_group(t_filedata *file);
char					*get_rights(t_filedata *file);

char					get_filetype(t_filedata *file);

/*
** GET_2.c
*/

char					*get_time(t_filedata *file);

int						get_total_blocks(t_vector *v);

void 					get_padding(t_vector *v, int padding[]);


#endif
