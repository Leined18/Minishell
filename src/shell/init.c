/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:11:29 by danpalac          #+#    #+#             */
/*   Updated: 2025/03/26 12:14:18 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	init_data(t_data **data, char **envp)
{
	(*data) = ft_calloc(1, sizeof(t_data));
	if (!(*data))
		return (0);
	(*data)->envp = copy_envp(envp);
	(*data)->ppid = getpid();
	(*data)->ignore[0] = SIGQUIT;
	(*data)->ignore[1] = SIGTSTP;
	(*data)->ignore[2] = SIGINT;
	return (1);
}

t_hash_table	*init_memory(char **envp, int size)
{
	t_hash_table	*mem;
	t_data			*data;

	if (size < 1 || !envp)
		return (0);
	data = NULL;
	mem = NULL;
	mem = ft_mthash_new_table(size, "memory");
	if (!(mem))
		return (0);
	if (!init_data(&data, envp))
		return (0);
	mem->methods.insert(mem, "data", data, NONE);
	mem->methods.set_free_func(mem, "data", clean_data);
	return (mem);
}
