/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 16:16:41 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/30 18:11:33 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_bool		filter_is_to_store(t_opm_params *opm, char *filename)
{
	char	*opt_param;

	if (opm_issetoption(opm->config, "a"))
		return (true);
	if (opm_issetoption(opm->config, "o"))
	{
		opt_param = opm_findoption_param(opm->config, "o");
		if (!ft_strequ(opt_param, filename))
			return (false);
	}
	if (opm_issetoption(opm->config, "c"))
	{
		opt_param = opm_findoption_param(opm->config, "c");
		if (!ft_strstr(filename, opt_param))
			return (false);
	}
	if (filename[0] == '.')
		return (false);
	else
		return (true);
}
