#include "minishell.h"

int	main(int ac, char **av, char **ev)
{
	t_hash_table	*mem;

	if (ac >= 3)
	{
		ft_printf("Usage temporal: %s <string>\n", av[0]);
		return (0);
	}
	mem = init_memory(ev, 5);
	if (!mem)
		return (ft_error(ERROR, 0), 1);
	shell_loop(mem);
	mem->methods.print(mem);
	clean_up(mem);
	return (ft_successful(SUCCESS, 1), 0);
}
