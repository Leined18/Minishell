/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:23:35 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/29 11:28:59 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	clean_up(t_memory *mem)
{
	if (mem->data)
		free_null((void *)&mem->data);
	if (mem->tree)
		free_null((void *)&mem->tree);
	if (mem->node)
		free_null((void *)&mem->node);
	return (1);
}
