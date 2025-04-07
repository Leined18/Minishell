/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 12:04:35 by mvidal-h          #+#    #+#             */
/*   Updated: 2025/03/26 12:17:40 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
