/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect_input.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:54:38 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/31 09:38:53 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

void	redirect_input(int fd)
{
	if (dup2(fd, STDIN_FILENO) == -1)
		ft_error("Error redirigiendo la entrada estándar\n", 0);
	close(fd);
}
