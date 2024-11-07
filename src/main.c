/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:21:58 by danpalac          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2024/11/07 10:16:47 by danpalac         ###   ########.fr       */
=======
/*   Updated: 2024/11/06 14:21:16 by mvidal-h         ###   ########.fr       */
>>>>>>> origin/builtins
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
		return (clean_up(&mem), ft_error(ERROR, 0), 1);
	ft_hold_mem(1, &mem.data->list, &v);
	/* sigaction_setup(sigaction_handler);
	if (!shell_loop(envp, getpid()))
	return (clean_up(&mem), ft_error(ERROR, 0), 1);*/
	cd_builtin(NULL); //probando cd
	env_builtin(mem.envp->env); //probando env
	ft_printf("\n\n");
	env_builtin(mem.envp->path); //imprimiendo splited path para comprobar que esá bien.
	return (clean_up(&mem), ft_successful(SUCCESS, 1), 0);
}
