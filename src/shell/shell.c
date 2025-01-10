/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:29:32 by danpalac          #+#    #+#             */
/*   Updated: 2025/01/10 17:59:38 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_exit(char *cmd)
{
	if (ft_pmatch_str(cmd->command, "exit", 4) == 0)
	{
		if (cmd->args)
		{
			if (!ft_isstrnum(cmd->args[0]))
				return (1);
			else if (cmd->args[1])
				return (0);
		}
		return (1);
	}
	return (0);
}

/**
 * @brief funcion auxiliar para executar nodos de prioridad 4
 *
 * @param node
 * @return int devuelve 1 si se a ejecutado correctamente, sino devuelve 0
 */
int	exe_word(t_mt *node, t_env *env) // to build, execute commands
{
	t_command	*cmd;

	cmd = create_command(node, env->path);
	if (ft_pmatch_str(cmd->command, "path", 4) == 0)
	{
		print_array2d(env->path);
		free_command(cmd);
	}
	else if (ft_pmatch_str(cmd->command, "vars", 4) == 0)
	{
		print_lst_data(env->mt_var);
		ft_printf("%d\n", env->num_var);
		free_command(cmd);
	}
	if (is_exit(cmd))
		(free(prompt), free_null((void **)&input), rl_clear_history());
	execution(cmd, env);
	// if (!node)
	// 	return (0);
	// printf("key: %s\n", (char *)node->key);
	// printf("Data: %s\n", (char *)node->data);
	// printf("State: %d\n", node->values.state);
	// printf("priority: %d\n", node->values.priority);
	return (1);
} // por implementar
int	exe_operator(t_mt *node, int (*funt)(t_mt *, void *), void *param)
// use a funtion pointer to execute the node operator
{
	if (!node)
		return (0);
	if (funt && funt(node, param))
		return (0);
	if (node->vect[LEFT]) // execute left node to redirect
		(exe_word(node->vect[LEFT]), node->vect[LEFT]->values.state = END);
	if (node->vect[RIGHT]) // execute right node with redirection
		(exe_word(node->vect[RIGHT]), node->vect[RIGHT]->values.state = END);
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
int	exe(t_mt *list, void *p, t_env *env) // funtion to execute
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
		return (exe_word(list, env));                           // por implementar
	else if (list->values.priority == 5 && *(int *)p == 5) // assignaments
		return (1);
	return (0);
}

int	process_input(char *input, t_hash_table *ht)
{
	t_mt	*list;
	int		pid;

	if (!input || !*input)
		return (0);
	pid = 0;
	(void)ht;
	if (pid == 0)
	{
		input[ft_strcspn(input, "\n")] = 0;
		list = ft_parse_input(input);
		ft_set_priority(list, NULL, set_node_priority);
		ft_execute_list(list, NULL, exe);
		ft_mtclear(&list);
		// exit(0); // Asegúrate de salir correctamente en el proceso hijo
	}
	else if (pid > 0)
	{
		waitpid(-1, NULL, 0);
		return (1);
	}
	else if (pid < 0)
		return (ft_error(ERROR, 0), 0);
	return (1);
}

int	shell_loop(t_hash_table *mem)
{
	char	*input;

	while (1)
	{
		// Muestra el prompt y espera la entrada del usuario
		input = readline(PROMPT);
		// Si no puede leer, liberamos historial y salimos con 0(error)
		if (!input)
			return (rl_clear_history(), 0);
		// Si la entrada es "exit" salimos con 1 (correcto)
		if (ft_strlen(input) == 4 && ft_strncmp(input, "exit", 4) == 0)
			return (free_null((void **)&input), rl_clear_history(), 1);
		// Si el usuario escribió algo, se agrega al historial y se procesa.
		if (*input)
		{
			add_history(input);
			//$DIVIDIR ENTRADA EN COMANDOS (PARSEAR Y DEMAS)
			process_input(input, mem);
			//$se encargará de hacer el bucle en todos los comandos (desde solo 1 a n)
		}
		// liberamos input para leer uno nuevo y que no se quede sin liberar.
		free_null((void **)&input);
		usleep(10000);
	}
}

int	process_input_two(char *input, t_env *env)
{
	t_mt	*parsed_lst;

	if (!input || !*input)
		return (0);
	parsed_lst = ft_parse_input(input);
	ft_set_priority(parsed_lst, NULL, set_node_priority);
	ft_execute_list(parsed_lst, NULL, env, exe);
	ft_mtclear(&parsed_lst);
	// exit(0); // Asegúrate de salir correctamente en el proceso hijo
}

int	shell_loop_two(t_hash_table *mem)
{
	char		*input;
	char		*prompt;
	//t_mt		*parsed_lst;
	//t_command	*cmd;
	t_env		*env;

	env = (t_env *)mem->methods.search_data(mem, "envp");
	while (1)
	{
		prompt = generate_prompt(env->mt_env);
		input = readline(prompt);
		if (input == NULL)
			return (free(prompt), rl_clear_history(), 1);
		if (*input)
		{
			add_history(input);
			//parsed_lst = ft_parse_input(input);
			if (is_exit(cmd))
				(free(prompt), free_null((void **)&input), rl_clear_history());
			process_input_two(input, env);
			//cmd = create_command(parsed_lst, env->path);
			//ft_mtclear(&parsed_lst);
			// print_command(cmd);
			// if (ft_pmatch_str(cmd->command, "path", 4) == 0)
			// {
			// 	print_array2d(env->path);
			// 	(free_command(cmd), free(prompt), free_null((void **)&input));
			// 	continue;
			// }
			// else if (ft_strchr(cmd->command, '='))
			// {
			// 	ft_assignation(cmd, env);
			// 	(free_command(cmd), free(prompt), free_null((void **)&input));
			// 	continue;
			// }
			// else if (ft_pmatch_str(cmd->command, "vars", 4) == 0)
			// {
			// 	print_lst_data(env->mt_var);
			// 	ft_printf("%d\n", env->num_var);
			// 	(free_command(cmd), free(prompt), free_null((void **)&input));
			// 	continue;
			// }
			// if (is_exit(cmd))
			// 	(free(prompt), free_null((void **)&input), rl_clear_history());
			// execution(cmd, env);
			// free_command(cmd);
		}
		(free(prompt), free_null((void **)&input));
	}
}
