#include "ft_ls.h"

void            list_dir(char *path, t_opm_params *opm)
{
    t_vector      *v;
    int           i;
    char          *error;

    i = 0;
    v = ft_vectnew();
    if ((error = dir_storecontent(path, v, opm)))
    {
        if (opm->params->total > 1)
        {
            ft_putendl(ft_strjoin(path, ":"));
        }
        ft_putendl(error);
    }
    else
    {
        sort_lexico(v); // replace by a unique print function.
        print_all(path, v, opm);
        if (opm_issetoption(opm->config, "R"))
        file_recursive(v, opm);
    }
}

void            list_files(t_opm_params *opm)
{
    int         i;
    char        *path;
    t_vector    *v;

    v = ft_vectnew();
    i = 0;
    while (i < opm->params->total)
    {
        path = arm_getparam_name(opm->params, i);
        if (!is_dir(path))
            ft_vectadd(v, file_initdata(path, NULL));
        i++;
    }
    if (v->total)
        print_all(NULL, v, opm);
}

void            list_directories(t_opm_params *opm)
{
    int         i;
    char        *path;

    i = 0;
    while (i < opm->params->total)
    {
      path = arm_getparam_name(opm->params, i);
      if (is_dir(path))
          list_dir(path, opm);
      i++;
    }
}
