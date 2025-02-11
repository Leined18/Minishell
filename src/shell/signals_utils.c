/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 08:34:01 by danpalac          #+#    #+#             */
/*   Updated: 2025/02/11 14:17:39 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	(void)context; // No lo usamos, pero es requerido por la firma de la función
	(void)info;
	if (sig == SIGINT)
	{
		printf("\n");
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
	}
}

void	handle_child_signal(int sig)
{
	if (sig == SIGINT) // control + c
	{
		printf("\n");           // Nueva línea para manejar Ctrl+C
		rl_on_new_line();       // Indicar que se comienza una nueva línea
		rl_replace_line("", 0); // Reemplazar la línea actual (vaciarla)
		rl_redisplay();
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
	int	i;

	if (!sigs || n_sigs < 0)
		return ;
	i = 0;
	while (i < n_sigs)
	{
		signal(sigs[i], SIG_IGN);
		i++;
	}
}

void	ft_setmod_signal(t_data *data, int ignore, int set,
		void(handler)(int sig))
{
	if (!data)
		return ;
	ft_set_ignore(data->singals[1], ignore);
	ft_set_handler(data->singals[0], set, handler);
}
