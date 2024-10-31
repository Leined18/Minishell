/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect_output.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:54:50 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/31 09:38:58 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

void	redirect_output(int fd)
{
	if (dup2(fd, STDOUT_FILENO) == -1)
		ft_error("Error redirigiendo la salida estándar\n", 0);
	close(fd);
}
