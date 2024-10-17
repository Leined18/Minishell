/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:21:58 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/17 12:38:16 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **envp)
{
	pid_t pid;

	if (argc >= 2)
	{
		write(1, "Usage: ./minishell\n", 19);
		return (1);
	}
	(void)argv;
	signal_setup();
	pid = fork();
	if (pid == 0)
	{
		shell_loop(envp, getppid());
	}
	else
	{
		while (1)
		{
			pause();
			kill(pid, SIGUSR2);
		}
	}
	return (0);
}