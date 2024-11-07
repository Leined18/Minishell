/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:49:47 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/11/06 14:23:22 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//Finds the line that starts with "PATH=" in env, and, if exists 
//creates and array splitting the line with ":" and returns it.
char	**split_path_env(char *env[])
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
	return (path_array);
}
//Genera una copia del entorno en una variable de tipo t_env (mirar minishell.h)
t_env	*generate_copy_envp(char **envp)
{
	t_env	*environ; //Falta liberarlo fuera!!
	int		counter;

	counter = 0;
	environ = malloc(sizeof(t_env));
	if (!environ)
		ft_error("Error creating env copy", 1);
	while (envp[counter])
		counter++;
	environ->num_env = counter;
	environ->env = ft_calloc(environ->num_env + 1, sizeof(char *));
	if (!environ->env)
	{
		free(environ);
		ft_error("Error creating env copy", 1);
	}
	while(--counter >= 0)
		environ->env[counter] = ft_strdup(envp[counter]);
	environ->path = split_path_env(envp);
	return (environ);
}
