/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_cmd_path.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/16 11:07:44 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/31 10:08:30 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

static char	*get_env_value(char *cmd, char **envp)
{
	int		i;
	size_t	len;

	len = ft_strlen(cmd);
	i = 0;
	while (envp[i])
	{
		if (strncmp(envp[i], cmd, len) == 0 && envp[i][len] == '=')
			return (&envp[i][len + 1]);
		i++;
	}
	return (NULL);
}

static char	*join_path(const char *dir, const char *cmd)
{
	char	*full_path;
	char	*tmp;

	tmp = ft_strjoin(dir, "/");
	if (!tmp)
		return (NULL);
	full_path = ft_strjoin(tmp, cmd);
	if (!full_path)
		return (free_null((void *)&tmp), NULL);
	free_null((void *)&tmp);
	return (full_path);
}

char	*get_cmd_path(char *cmd, char **envp)
{
	char	*path_env;
	char	**paths;
	char	*full_path;
	int		i;

	path_env = get_env_value("PATH", envp);
	if (!path_env)
		return (NULL);
	paths = ft_split(path_env, ':');
	if (!paths)
		return (NULL);
	i = 0;
	while (paths[i])
	{
		full_path = join_path(paths[i], cmd);
		if (!full_path)
			return (free_2d(paths), NULL);
		if (access(full_path, X_OK) == 0)
			return (free_2d(paths), full_path);
		free_null((void *)&full_path);
		i++;
	}
	free_2d(paths);
	return (NULL);
}
