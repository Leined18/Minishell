/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:22:14 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/17 12:55:47 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	signal_setup(void)
{
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
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
		// El padre recibe la señal SIGUSR1 del hijo
		ft_printf("Padre: señal SIGUSR1 recibida del hijo\n");
	}
	else if (signum == SIGUSR2)
	{
        
		// El padre envía SIGUSR2 al hijo para que continúe
		ft_printf("Padre: señal SIGUSR2 enviada al hijo\n");
	}
}
