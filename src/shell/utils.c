/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 12:14:31 by danpalac          #+#    #+#             */
/*   Updated: 2024/11/08 17:39:46 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

char	*ft_strdup_ref(const char *src, t_ref **ref, char *name)
{
	t_ref	*new_ref;
	char	*str;

	str = ft_strdup(src);
	if (!str)
		return (NULL);
	new_ref = ft_refnew((void **)&str, name, STRING);
	if (!new_ref)
		return (free_null((void **)&str), NULL);
	ft_refadd(ref, &new_ref, NULL);
	return (str);
}

void	*ft_calloc_ref(int count, size_t size, t_ref **ref, char *name)
{
	t_ref	*new_ref;
	void	*memory;
	int		type;

	if (size == sizeof(char))
		type = STRING;
	else if (size == sizeof(int))
		type = INT_ARRAY;
	else if (size == sizeof(char *))
		type = STRING_ARRAY;
	else
		type = 1;
	memory = malloc(count * size);
	if (!memory)
		return (NULL);
	(ft_bzero(memory, count * size), new_ref = ft_refnew(&memory, name, type));
	if (!new_ref)
		return (free_null(&memory), NULL);
	ft_refadd(ref, &new_ref, NULL);
	return (memory);
}

t_memory	*memget(t_memory **mem, int b)
{
	static t_memory	*memory = NULL;

	if (mem)
		memory = *mem;
	if (b)
		return (memory);
	return (NULL);
}
