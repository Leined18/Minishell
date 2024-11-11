/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:23:35 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/11 14:15:37 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	clean_up(t_memory *mem)
{
	if (mem->list)
		ft_lstclear(&mem->list, free);
	mem->list = NULL;
	mem->data = NULL;
	mem->tree = NULL;
	mem->node = NULL;
	return (1);
}
