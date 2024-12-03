/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:14:31 by danpalac          #+#    #+#             */
/*   Updated: 2024/12/03 12:15:26 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

void	insert_ptr(t_hash_table *mem, char *parent, char *description,
		void *data, char *child)
{
	mem->methods.insert_child(mem, parent, child, data, PTR);
	if (description)
		mem->methods.insert(mem, parent, ft_strdup(description), STRING);
}
