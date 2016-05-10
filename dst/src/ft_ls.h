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

# include <stdio.h>
# include "../libft/libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
# include <string.h>
# include <errno.h>

typedef struct			s_files
{
	t_vector			*files;
	t_vector			*dirs;
}						t_files;

/*
**	FILES.C
*/

void					files_del(void *this);

/*
**	FILTER.C
*/

t_bool					filter_is_to_store(t_opm_params *opm, char *filename);


/*
**	DISPATCH.C
*/

t_files					*dispatch(t_opm_params *opm);

/*
**	LIST.C
*/

void					list(t_files *to_list, t_opm_params *opm);
void					list_dir(char *path, t_opm_params *opm);
void					list_files(t_vector *files, t_opm_params *opm);
void					list_directories(t_vector *dirs, t_opm_params *opm);

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
void					file_del(void *file);

/*
**	PRINT.C
*/

void					print_all(char *dirname, t_vector *v,
								t_opm_params *opm);

/*
**	IS.C
*/

t_bool					is_reg(const char *path);
t_bool					is_dir(const char *path);

/*
**	DIR.C
*/

char					*dir_storecontent(const char *dirname, t_vector *v,
							t_opm_params *opm);
t_list					*dir_contenttolist(const char *dirname);

/*
** SORT.C
*/

void					sort(t_vector *v, t_opm_params *opm);
void					sort_lexico(t_vector *v);

/*
** GET.c
*/

char					*get_user(t_filedata *file);
char					*get_group(t_filedata *file);
char					get_type(mode_t stmode);

/*
** GET_2.c
*/

int						get_total_blocks(t_vector *v);

void					get_padding(t_vector *v, int padding[]);

/*
** SET.C
*/

void					set_padding_l(char *src, char *dst, int padding);
void					set_padding_r(char *src, char *dst, int padding);
void					append_link(t_filedata *file, char *line);
void					set_time(time_t time, time_t tv_sec, char *line);

/*
** MODE.C
*/

char					mode_get_type(mode_t st_mode);

void					mode_set(mode_t st_mode, char *mode);
void					mode_set_owner(mode_t st_mode, char *mode);
void					mode_set_group(mode_t st_mode, char *mode);
void					mode_set_other(mode_t st_mode, char *mode);

#endif
