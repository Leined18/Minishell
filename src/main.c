/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:21:58 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/13 14:47:12 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "shell.h"

void	ft_mtpush(t_mt **head, void *data)
{
	t_mt	*new;

	new = chaosmatrix(1, sizeof(t_mt), 0);
	if (!new)
		chaosmatrix(0, 0, -1);
	new->data = data;
	ft_mtadd_back(head, new);
}

int	ft_strcmp(void *s1, void *s2)
{
	return (ft_strncmp(s1, s2, ft_strlen(s1)));
}

int	main(int ac, char **av, char **ev)
{
	t_memory	mem;
	t_env		*envp;
	t_mt		*tmp;

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
	envp = chaosmatrix(1, sizeof(t_env), 0);
	ft_mtpush(&envp->mt_env, ft_strmtdup("PATH"));
	ft_mtpush(&envp->mt_env, ft_strmtdup("PATO"));
	tmp = ft_mtfind_cmp(envp->mt_env, "PATH", ft_strcmp);
	if (tmp)
		printf("Found: %s\n", (char *)tmp->data);
	else
		printf("Not found\n");
	clean_up();
	return (ft_successful(SUCCESS, 1), 0);
}
