/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:49:47 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/11/08 23:40:26 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "env.h"

// Finds the line that starts with "PATH=" in env, and, if exists
// creates and array splitting the line with ":" and returns it.
char	**split_path_env(char *env[], t_ref **ref)
{
	int		i;
	char	*path;
	char	**path_array;

	i = 0;
	path = NULL;
	path_array = NULL;
	if (!env)
		return (NULL);
	while (!path && env[i])
	{
		path = ft_strnstr(env[i], "PATH=", 5);
		i++;
	}
	if (path)
	{
		path += 5;
		path_array = ft_split(path, ':');
		i = 0;
	}
	ft_refadd_front(ref, ft_refnew((void **)&(path_array), "path_env",
			STRING_ARRAY));
	return (path_array);
}

// Genera una copia del entorno en una variable de tipo t_env (mirar minishell.h)
int	copy_envp(t_env **environ, char **envp, t_ref **ref)
{
	int	counter;

	counter = 0;
	(*environ) = ft_calloc_ref(1, sizeof(t_env), ref, "environ");
	if (!(*environ))
		return (0);
	while (envp[counter])
		counter++;
	(*environ)->num_env = counter;
	(*environ)->env = ft_calloc_ref((*environ)->num_env + 1, sizeof(char *),
			ref, "env");
	if (!(*environ)->env)
	{
		free((*environ));
		return (0);
	}
	while (--counter >= 0)
		(*environ)->env[counter] = ft_strdup(envp[counter]);
	(*environ)->path = split_path_env((*environ)->env, ref);
	return (1);
}
