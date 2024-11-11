/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:21:58 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/11 14:21:41 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "shell.h"

int	main(int ac, char **av, char **ev)
{
	t_memory	mem;

	mem = (t_memory){0};
	if (ac >= 3)
	{
		write(1, "Usage: ./minishell\n", 19);
		return (0);
	}
	if (!init_memory(&mem, ac, av, ev))
		return (0);
	/* sigaction_setup(&sigaction_handler);
	if (!shell_loop(&mem))
		return (clean_up(&mem), ft_error(ERROR, 0), 0); */
	return (clean_up(&mem), ft_successful(SUCCESS, 1), 0);
}
