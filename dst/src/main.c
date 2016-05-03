/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpiacent <kpiacent@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/11 15:13:31 by kpiacent          #+#    #+#             */
/*   Updated: 2016/04/30 17:53:40 by kpiacent         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		main(int ac, char **av)
{
	t_vector		*arm;
	t_vector		*config;
	t_opm_params	*opm;

	arm = arm_init(ac, av);
	config = opm_config_init("l,r,a|All|all,R|Recursive|recursive,t,u,f,g,d");
	opm = opm_init(arm, config);
//	arm_debug(arm);
//	opm_debug(opm);
	if (!opm->params->total)
		ft_vectadd(opm->params, arm_argument_new("./", "param"));
	sort_lexico(opm->params);
	list_files(opm);
	list_directories(opm);
	return (1);
}
