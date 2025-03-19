#include "minishell.h"

int	main(int ac, char **av, char **ev)
{
	t_hash_table	*mem;
	t_data			*data;

	if (ac >= 3)
		return (ft_printf(USAGE, av[0]), 0);
	mem = init_memory(ev, 5);
	if (!mem)
		return (ft_error(ERROR, 0), 1);
	data = mem->methods.search_data(mem, "data");
	ft_set_ignore(data->ignore, 3);
	ft_load_history(data->envp->path_history);
	shell_loop(data);
	return (clean_up(mem), 0);
}
