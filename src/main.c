/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:21:58 by danpalac          #+#    #+#             */
/*   Updated: 2025/01/08 10:20:50 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief funcion auxiliar para executar nodos de prioridad 4
 *
 * @param node
 * @return int devuelve 1 si se a ejecutado correctamente, sino devuelve 0
 */
int	exe_word(t_mt *node)
{
	if (!node)
		return (0);
	printf("key: %s\n", (char *)node->key);
	printf("Data: %s\n", (char *)node->data);
	printf("State: %d\n", node->values.state);
	printf("priority: %d\n", node->values.priority);
	return (1);
} // por implementar
/**
 * @brief executa por orden de prioridad,
	funcion que será pasada por parametro a ft_execute_list
 *
 * @param list nodos enlazados
 * @param i parametro para identificar cuantos quedan de la prioridad actual
 * @return int
 */
int	exe(t_mt *list, void *i)
{
	if (!list)
		return (-1);
	if (!ft_mtsearch(list, i, pred))
		*(int *)i += 1;
	if (list->values.priority == 0 && *(int *)i == 0) // parentesis
		return (ft_execute_list(list->aux, NULL, exe));
	else if (list->values.priority == 1 && *(int *)i == 1) // logic op
		return (1);                                        // por implementar
	else if (list->values.priority == 2 && *(int *)i == 2) // redirections
		return (1);                                        // por implementar
	else if (list->values.priority == 3 && *(int *)i == 3) // operators
		return (1);                                        // por implementar
	else if (list->values.priority == 4 && *(int *)i == 4) // words
		return (exe_word(list));                           // por implementar
	else if (list->values.priority == 5 && *(int *)i == 5) // assignaments
		return (1);
	return (0);
}

int	main(int ac, char **av, char **ev)
{
	t_memory	*mem;
	t_mt		*list;
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
		ft_printf("found \n");
	list = parse_input("hola como estas");
	ft_set_priority(list, NULL, set_node_priority);
	// se usa antes de execute_list,
	ft_execute_list(list, NULL, exe);
	// para usar en el shell loop, depende de set_priority
	ft_mtclear(&list);
	mem->ht->methods.print(mem->ht);
	clean_up(mem);
	return (ft_successful(SUCCESS, 1), 0);
}
