/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvidal-h <mvidal-h@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 08:34:01 by danpalac          #+#    #+#             */
/*   Updated: 2025/03/20 12:06:15 by mvidal-h         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	ft_set_handler(int *sigs, int n_sigs, void(funtion)(int sig))
// {
// 	int	i;

// 	if (!sigs || n_sigs < 0 || !funtion)
// 		return ;
// 	i = 0;
// 	while (i < n_sigs)
// 	{
// 		signal(sigs[i], funtion);
// 		i++;
// 	}
// }

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

void	ft_set_default(int *sigs, int n_sigs)
{
	int	i;

	if (!sigs || n_sigs < 0)
		return ;
	i = 0;
	while (i < n_sigs)
	{
		signal(sigs[i], SIG_DFL);
		i++;
	}
}
