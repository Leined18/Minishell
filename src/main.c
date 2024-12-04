/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:21:58 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/04 11:50:09 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "shell.h"

void	ft_mtprint_key_list(t_mt *node)
{
	while (node)
	{
		ft_printf("%s\n", node->key);
		node = node->right;
	}
}

int	main(int ac, char **av, char **ev)
{
	t_memory	*mem;
	t_env		*env;

	if (ac >= 3)
	{
		ft_printf("Usage temporal: %s <string>\n", av[0]);
		return (0);
	}
	mem = init_memory(ev);
	if (!mem)
		return (ft_error(ERROR, 0), 1);
	env = (t_env *)mem->ht->methods.search_data(mem->ht, "envp");
	if (env)
	{
		ft_mtprint_key_list(env->path);
		ft_printf("\n");
		ft_mtprint_key_list(env->mt_env);
	}
	mem->ht->methods.print(mem->ht);
	clean_up(mem);
	return (ft_successful(SUCCESS, 1), 0);
}
