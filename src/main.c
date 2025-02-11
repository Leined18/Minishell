#include "minishell.h"

int	main(int ac, char **av, char **ev)
{
	t_hash_table	*mem;
	t_data			*data;
	int				status;

	if (ac >= 3)
		return (ft_printf(USAGE, av[0]), 0);
	mem = init_memory(ev, 5);
	if (!mem)
		return (ft_error(ERROR, 0), 1);
	data = mem->methods.search_data(mem, "data");
	ft_setmod_signal(data, 3, 0, NULL);
	status = shell_loop(mem);
	if (WIFEXITED(status))
		return (clean_up(mem), WEXITSTATUS(status));
	return (clean_up(mem), 0);
}
