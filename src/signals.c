/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:22:14 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/17 12:22:21 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	signal_setup(void)
{
	signal(SIGUSR1, signal_handler);
}

void	send_signal(int pid, int signal)
{
	if (kill(pid, signal) == -1)
		ft_error("Failed to send signal", 1);
}

void	signal_handler(int signum)
{
	if (signum == SIGUSR1)
	{
		// Aquí solo interrumpimos pause() para reiniciar el ciclo
	}
}