/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 17:47:06 by mvidal-h          #+#    #+#             */
/*   Updated: 2024/11/04 18:47:56 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_num_args(char **args)
{
	int	i;

	i = 0;
	while(args[i])
		i++;
	return (i);

}

void	bltn_cd(t_command *cmd)
{
	int	num_args;

	num_args = count_num_args(cmd->args);
	ft_printf("numero de argumentos = %d\n");
	if (!num_args)
	{

	}
	else if (num_args == 1)
	{
		
	}
	else
		ft_error("cd: too many arguments", 0);
}