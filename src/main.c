/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:21:58 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/07 14:26:41 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */

#include "builtins.h"
#include "config.h"
#include "input.h"
#include "minishell.h"
#include "shell.h"
#include "signals.h"

int	main(int argc, char **argv, char **envp)
{
	t_memory	mem;

	mem = (t_memory){0};
	if (!parse_arguments(&mem, argc, argv, envp))
		return (clean_up(&mem), ft_error(ERROR, 0), 0);
	/* cd_builtin(NULL);
	env_builtin(mem.data->envp->env);
	ft_printf("\n\n");
	env_builtin(mem.data->envp->path); */
	return (clean_up(&mem), ft_successful(SUCCESS, 1), 0);
}
