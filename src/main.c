/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:21:58 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/15 11:28:32 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "shell.h"

int	ft_strcmp(void *s1, void *s2)
{
	return (ft_strncmp(s1, s2, ft_strlen(s1)));
}

int	main(int ac, char **av, char **ev)
{
	t_memory	mem;
	t_mt		*mt;

	mem = (t_memory){0};
	if (ac >= 3)
	{
		ft_printf("Usage temporal: %s <string>\n", av[0]);
		return (0);
	}
	if (!init_memory(&mem, ac, av, ev))
		return (0);
	mt = NULL;
	tokenize(av[1], &mt);
	(void)mt;
	/* sigaction_setup(&sigaction_handler);
	if (!shell_loop(&mem))
		return (clean_up(&mem), ft_error(ERROR, 0), 0); */
	ft_printf(BLUE"Matrix commandos:\n"RESET);
	ft_mtprint(mt, 1, " ");
    ft_mterase(&mt);
    ft_mtprint(mt, 1, " ");
	ft_printf(GREEN"Matrix memoria:\n"RESET);
	ft_mtprint(chaosmatrix(0,0,1), 0, "\n");
	return (ft_successful(SUCCESS, 1), 0);
}
