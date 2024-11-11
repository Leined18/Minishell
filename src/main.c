/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:21:58 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/11 11:11:58 by danpalac         ###   ########.fr       */
/*                                                                            */
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
	/* sigaction_setup(&sigaction_handler);
	if (!shell_loop(&mem))
		return (clean_up(&mem), ft_error(ERROR, 0), 0); */
	return (clean_up(&mem), ft_successful(SUCCESS, 1), 0);
}
