/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 08:34:01 by danpalac          #+#    #+#             */
/*   Updated: 2025/03/07 11:06:41 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	if (sig == SIGINT)
	{
	}
}

void	handle_child_signal(int sig)
{
	if (sig == SIGINT)
	{
	}
}

void	ft_set_handler(int *sigs, int n_sigs, void(funtion)(int sig))
{
	int	i;

	if (!sigs || n_sigs < 0 || !funtion)
		return ;
	i = 0;
	while (i < n_sigs)
	{
		signal(sigs[i], funtion);
		i++;
	}
}

void	ft_set_ignore(int *sigs, int n_sigs)
{
	int i;

	if (!sigs || n_sigs < 0)
		return ;
	i = 0;
	while (i < n_sigs)
	{
		signal(sigs[i], SIG_IGN);
		i++;
	}
}