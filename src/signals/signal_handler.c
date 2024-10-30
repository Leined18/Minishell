/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:55:35 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/30 10:11:49 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#include "signals.h"

/**
 * signal_handler - Manejador de señales avanzado
 * @signal: Tipo de señal recibida
 * @info: Información adicional sobre la señal
 * @context: Contexto de ejecución (no usado aquí)
 *
 * Este manejador imprime detalles específicos de la señal,
 * como el PID del proceso remitente, y maneja cada señal de forma única.
 */

void	sigaction_handler(int signal, siginfo_t *info, void *context)
{
	printf("Señal recibida: %d\n", signal);
	if (signal == SIGUSR1)
	{
		printf("Señal SIGUSR1 recibida del proceso %d\n", info->si_pid);
	}
	else if (signal == SIGUSR2)
	{
		printf("Señal SIGUSR2 recibida del proceso %d\n", info->si_pid);
		send_signal(info->si_pid, SIGUSR1);
	}
	else if (signal == SIGINT)
	{
		printf("Exit\n");
		printf("%p", context);
		exit(0);
	}
}

void	signal_handler(int signum)
{
	if (signum == SIGUSR1)
	{
		ft_printf("Padre: señal SIGUSR1 recibida\n");
	}
	else if (signum == SIGUSR2)
	{
		ft_printf("Hijo: señal SIGUSR2 recibida\n");
		send_signal(getppid(), SIGUSR1);
	}
}
