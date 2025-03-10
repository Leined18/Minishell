/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:23:35 by danpalac          #+#    #+#             */
/*   Updated: 2025/03/10 11:52:01 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	clean_data(void **data)
{
	t_data	*data_s;

	data_s = (t_data *)*data;
	if (data_s)
	{
		ft_env_free_func((void **)&data_s->envp);
		free(data_s);
	}
	*data = NULL;
}

int	clean_up(t_hash_table *mem)
{
	if (mem)
		mem->methods.free_table(mem);
	mem = NULL;
	rl_clear_history();
	return (1);
}
