/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:55:35 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/29 12:16:32 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"
#include "shell.h"

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
