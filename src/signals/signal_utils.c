/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 10:54:40 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/29 11:04:37 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "signals.h"

void	signal_setup(void (funtion)(int signal))
{
	signal(SIGUSR1, funtion);
	signal(SIGUSR2, funtion);
}

int	send_signal(int pid, int signal)
{
	if (kill(pid, signal) == -1)
		return (FALSE);
	return (TRUE);
}
