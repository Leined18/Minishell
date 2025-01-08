/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 11:23:35 by danpalac          #+#    #+#             */
/*   Updated: 2025/01/08 11:52:04 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	clean_up(t_hash_table *mem)
{
	if (mem)
		mem->methods.free_table(mem);
	mem = NULL;
	return (1);
}
