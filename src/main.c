/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:21:58 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/02 15:26:33 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtins.h"
#include "config.h"
#include "minishell.h"
#include "shell.h"
#include "signals.h"

int	main(int argc, char **argv, char **envp)
{
	t_memory	mem;
	t_command	*v;

	mem = (t_memory){0};
	if (argc >= 2)
	{
		write(1, "Usage: ./minishell\n", 19);
		return (1);
	}
	if (!init_memory(&mem, argc, argv, envp))
		return (clean_up(&mem), ft_error(ERROR, 0), 1);
	ft_hold_mem(1, &mem.data->list, &v);
	/* sigaction_setup(sigaction_handler);
	if (!shell_loop(envp, getpid()))
	return (clean_up(&mem), ft_error(ERROR, 0), 1);*/
	return (clean_up(&mem), ft_successful(SUCCESS, 1), 0);
}
