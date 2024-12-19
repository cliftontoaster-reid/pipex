/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:53:31 by lfiorell          #+#    #+#             */
/*   Updated: 2024/12/13 09:43:52 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void	child_uwu(int *pipefd, t_cmd *c, char const **envp)
{
	if (dup2(c->pipe, STDIN_FILENO) < 0 || dup2(pipefd[1], STDOUT_FILENO) < 0)
		return (perror("Child one"));
	close(pipefd[0]);
	if (execve(c->cmd, c->args, (char *const *)envp) != -1)
	{
		free(c->cmd);
		exit(EXIT_SUCCESS);
	}
	exit(EXIT_FAILURE);
}

void	child_owo(int *pipefd, t_cmd *c, char const **envp)
{
	if (dup2(c->pipe, STDOUT_FILENO) < 0 || dup2(pipefd[0], STDIN_FILENO) < 0)
		return (perror("Child two"));
	close(pipefd[1]);
	if (execve(c->cmd, c->args, (char *const *)envp) != -1)
	{
		free(c->cmd);
		exit(EXIT_SUCCESS);
	}
	exit(EXIT_FAILURE);
}
