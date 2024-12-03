/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:23:35 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/03 11:15:07 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int	clean_up(t_memory *mem)
{
	if (mem->ht)
		mem->ht->methods.free_table(mem->ht);
	free(mem);
	return (1);
}
