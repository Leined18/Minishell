/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 12:29:32 by danpalac          #+#    #+#             */
/*   Updated: 2025/01/22 16:36:54 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * @brief funcion auxiliar para executar nodos de prioridad 4
 *
 * @param node
 * @return int devuelve 1 si se a ejecutado correctamente, sino devuelve 0
 */
int	exe_word(t_mt *node, t_env *env) // to build, execute commands
{
	t_command *cmd;

	if (!node || !env)
		return (0);
	cmd = create_command(node, env);
	// print_command(cmd);
	if (ft_pmatch_str(cmd->command, "path", 4) == 0)
		print_array2d(env->path);
	else if (ft_pmatch_str(cmd->command, "vars", 4) == 0)
		print_lst_data(env->mt_var);
	else
		execution(cmd, env, 0);
	node->values.state = END;
	free_command(cmd);
	return (1);
}

int	exe_operator(t_mt *node, int (*funt)(t_mt *, void *), void *param)
// use a funtion pointer to execute the node operator
{
	if (!node)
		return (0);
	if (funt && funt(node, param))
		return (0);

	if (!ft_pmatch_str(node->data, "|", 1))
		return (exe_pipes(node, (t_env *)param)); // Manejar pipes
	// else if (!ft_strcmp(node->data, "&"))
	// 	return (exe_background(node, param)); // Manejar segundo plano
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
		return (exe(list, p, env));
		// recursiva para avanzar hasta la prioridad minima existente
	}
	if (list->values.priority == 0 && *(int *)p == 0) // parentesis
		return (ft_execute_list(list->aux, NULL, env, exe));
	else if (list->values.priority == 1 && *(int *)p == 1) // logic op
		return (1);                                        // por implementar
	else if (list->values.priority == 2 && *(int *)p == 2) // redirections
		return (1);                                        // por implementar
	else if (list->values.priority == 3 && *(int *)p == 3)
		// operators (pipes y &)
		return (exe_operator(list, NULL, env));            // por implementar
	else if (list->values.priority == 4 && *(int *)p == 4) // words
		return (exe_word(list, env));
	else if (list->values.priority == 5 && *(int *)p == 5) // assignaments
		return (ft_assignation(list, env));
	return (0);
}

int	process_input(t_env *env)
{
	t_mt	*parsed_lst;

	if (!env->input || !*env->input)
		return (0);
	parsed_lst = ft_parse_input(env->input);
	ft_set_priority(parsed_lst, NULL, set_node_priority);
	ft_execute_list(parsed_lst, NULL, env, exe);
	ft_mtclear(&parsed_lst);
	return (1);
}

void	handle_signal(int sig)
{
	if (sig == SIGINT)
	{
		printf("\n");           // Nueva línea para manejar Ctrl+C
		rl_on_new_line();       // Indicar que se comienza una nueva línea
		rl_replace_line("", 0); // Reemplazar la línea actual (vaciarla)
		rl_redisplay();         // Redistribuir el prompt
	}
	else if (sig == SIGUSR1)
	{
		printf("\n");     // Nueva línea
		rl_on_new_line(); // Indicar que estamos en una nueva línea
		rl_redisplay();   // Redistribuir el prompt
	}
}

int	shell_loop(t_hash_table *mem)
{
	t_env	*env;

	signal(SIGINT, handle_signal);  // Maneja Ctrl+C
	signal(SIGUSR1, handle_signal); // Maneja
	signal(SIGQUIT, SIG_IGN);       // Ignora Ctrl+'\'
	signal(SIGTSTP, SIG_IGN);       // Ignora Ctrl+Z
	env = (t_env *)mem->methods.search_data(mem, "envp");
	while (1)
	{
		env->prompt = generate_prompt(env->mt_env);
		env->input = readline(env->prompt);
		if (env->input == NULL)
			return (free(env->prompt), rl_clear_history(), 0);
		if (*env->input)
		{
			add_history(env->input);
			process_input(env);
		}
		(free(env->prompt), free_null((void **)&env->input));
	}
	return (0);
}
