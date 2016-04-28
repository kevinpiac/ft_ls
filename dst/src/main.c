/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 15:13:31 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/28 16:12:07 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int ac, char **av)
{
	t_vector		*arm;
	t_vector		*config;
	t_opm_params	*opm;
	int				i;
	char			*path;

	arm = arm_init(ac, av);
	config = opm_config_init("l,r,a|All|all,R|Recursive|recursive,t,u,f,g,d");
	opm = opm_init(arm, config);
	arm_debug(arm);
	opm_debug(opm);
	i = 0;
	while (i < opm->params->total)
	{
		path = arm_getparam_name(opm->params, i);
		file_ls(path, opm_issetoption(opm->config, "R"));
		i++;
	}
	return (1);
}
