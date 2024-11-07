/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_set.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 17:51:27 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/11/06 18:07:52 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_setenv(const char *name, const char *value, int overwrite, t_env	***envp)
{
	char	*str;
	int		len;
	int		i;

	str = NULL;
	len = ft_strlen(name);
	i = 0;
	while(!str && *envp[i])
		str = ft_strnstr(*envp[i], name, len);
	if(str)
	{

	}
	else
	{

	}
}