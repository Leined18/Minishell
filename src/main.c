/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:21:58 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/31 17:14:47 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief funcion auxiliar para executar nodos de prioridad 4
 *
 * @param node
 * @return int devuelve 1 si se a ejecutado correctamente, sino devuelve 0
 */
int	exe_word(t_mt *node) // to build, execute commands
{
	if (!node)
		return (0);
	printf("key: %s\n", (char *)node->key);
	printf("Data: %s\n", (char *)node->data);
	printf("State: %d\n", node->values.state);
	printf("priority: %d\n", node->values.priority);
	return (1);
} // por implementar
int	exe_operator(t_mt *node, int (*funt)(t_mt *, void *), void *param)
		// use a funtion pointer to execute the node operator
{
	if (!node)
		return (0);
	if (funt && funt(node, param))
		return (0);
	if (node->vect.left) // execute left node to redirect
		(exe_word(node->vect.left), node->vect.left->values.state = END);
	if (node->vect.right) // execute right node with redirection
		(exe_word(node->vect.right), node->vect.right->values.state = END);
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
int	exe(t_mt *list, void *p) // funtion to execute
{
	if (!list)
		return (-1);
	if (!ft_mtsearch(list, p, pred)) 
	// busca si no hay otro nodo igual en la lista con la prioridad actual (p)
	{
		*(int *)p += 1; // incrementa el contador de prioridad actual
		return (exe(list, p));
		// recursiva para avanzar hasta la prioridad minima existente
	}
	if (list->values.priority == 0 && *(int *)p == 0) // parentesis
		return (ft_execute_list(list->aux, NULL, exe));
	else if (list->values.priority == 1 && *(int *)p == 1) // logic op
		return (1);                                        // por implementar
	else if (list->values.priority == 2 && *(int *)p == 2) // redirections
		return (1);                                        // por implementar
	else if (list->values.priority == 3 && *(int *)p == 3) // operators
		return (exe_operator(list, NULL, NULL));           // por implementar
	else if (list->values.priority == 4 && *(int *)p == 4) // words
		return (exe_word(list));                           // por implementar
	else if (list->values.priority == 5 && *(int *)p == 5) // assignaments
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
		ft_printf("\n");
	list = parse_input("ls -l | grep .c | wc -l"); // input
	ft_set_priority(list, NULL, set_node_priority); // set priority to nodes
	// se usa antes de execute_list,
	ft_execute_list(list, NULL, exe); // execute list with priority
	// para usar en el shell loop, depende de set_priority
	ft_mtclear(&list);
	mem->ht->methods.print(mem->ht);
	clean_up(mem);
	return (ft_successful(SUCCESS, 1), 0);
}
