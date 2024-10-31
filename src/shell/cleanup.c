/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:23:35 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/31 14:09:54 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	clean_up(t_memory *mem)
{
	if (mem->list)
		ft_lstclear(&mem->list, free_null);
	return (1);
}
