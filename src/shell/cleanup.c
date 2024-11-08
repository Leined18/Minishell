/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:23:35 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/08 23:48:41 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	clean_up(t_memory *mem)
{
	if (mem->list)
		ft_lstclear(&mem->list, ft_refdel);
	mem->list = NULL;
	return (1);
}
