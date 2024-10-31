/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_handle_parent.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danpalac <danpalac@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 12:55:40 by danpalac          #+#    #+#             */
/*   Updated: 2024/10/31 09:27:19 by danpalac         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "commands.h"

void	handle_parent(int *pipefd, pid_t pid1, pid_t pid2)
{
	close(pipefd[0]);
	close(pipefd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
}
