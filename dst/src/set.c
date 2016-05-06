/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/30 15:05:07 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/30 17:53:17 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void 		set_padding_r(char *src, char *dst, int padding)
{
	int 	len;
	int 	i;
	int 	j;

	len = ft_strlen(src);
	i = padding - len;
	j = 0;
	while (*dst)
		++dst;
	while (j < i)
	{
		dst[j] = ' ';
		j++;
	}
	i = 0;
	while (src[i])
		dst[j++] = src[i++];
}

void 		set_padding_l(char *src, char *dst, int padding)
{
	int 	i;
	int 	j;

	j = 0;
	i = 0;
	while (*dst)
		++dst;
	while (src[i])
		dst[j++] = src[i++];
	while (j < padding + 2) // 2 is to prevent strcat(line, " ") after.
	{
		dst[j] = ' ';
		j++;
	}
}

void 				append_link(t_filedata *file, char *line)
{
	char			buf[250];
	int 			len;

	if ((len = readlink(file->path, buf, sizeof(buf)-1)) != -1)
	    buf[len] = '\0';
	else
		exit(-1);
	ft_strcat(line, " -> ");
	ft_strcat(line, ft_strdup(buf));
}

void 				set_time(time_t time, char *line)
{
	char 	*date;
	int 	start;
	int		end;
	int 	i;

	date = ctime(&time);
	start = 4;
	end = 16;
	i = 0;
	while (*line)
		++line;
	while (start < end)
	{
		line[i] = date[start];
		start++;
		i++;
	}
	line[i] = ' ';
}
