#include "ft_ls.h"

void            list_dir(char *path, t_opm_params *opm)
{
  t_vector	*v;
  int			i;

  i = 0;
  v = ft_vectnew();
  dir_storecontent(path, v, opm);
  sort_lexico(v); // replace by a unique print function.
  ft_putendl("");
  ft_putendl(ft_strjoin(path, ":"));
  ft_putendl("total 123");
  print_all(v, opm);
  if (opm_issetoption(opm->config, "R"))
    file_recursive(v, opm);
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
    {
        sort_lexico(v);
        print_all(v, opm);
    }
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
