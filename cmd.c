/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 14:16:28 by lfiorell          #+#    #+#             */
/*   Updated: 2024/12/20 17:13:36 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "child.h"
#include "cmd.h"
#include "find.h"
#include "free.h"
#include "libft/export/libft.h"
#include "str_utils.h"
#include <fcntl.h>
#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>

int	ft_putbash(const char *s, const char *t)
{
	if (!s)
		return (2);
	if (t)
	{
		write(2, "-bash: ", 7);
		write(2, t, ft_strlen(t));
		write(2, ": ", 2);
	}
	while (*s)
	{
		write(2, &(*s), 1);
		s++;
	}
	write(2, "\n", 1);
	return (2);
}

static void	init_cmd(t_cmd *c, int pipe)
{
	c->pipe = pipe;
	c->cmd = 0;
	c->args[0] = 0;
}

// extract command and args if any.
// find the path of the command.
static int	prepare_cmd(t_cmd *c, char const *cmd, char const **envp)
{
	char	**args;
	int		i;

	args = ft_splitpath(cmd, ' ');
	if (!args)
		args[0] = ft_strdup(cmd);
	c->cmd = ft_strdup(args[0]);
	if (!c->cmd)
	{
		free_strs(args);
		return (0);
	}
	i = 1;
	while (args[i])
	{
		c->args[i - 1] = ft_strdup(args[i]);
		if (!c->args[i++ - 1])
		{
			free_strs(args);
			return (0);
		}
	}
	c->cmd = ft_pathfind(c->cmd, (char *const *)envp);
	free_strs(args);
	return (1);
}

static void	run_cmds(int *gayosorus, char const **envp, t_cmd *cmd1,
		t_cmd *cmd2)
{
	int	f;

	f = fork();
	if (f < 0)
		return (perror("Fork one"));
	if (!f)
		child_uwu(gayosorus, cmd1, envp);
	f = fork();
	if (f < 0)
		return (perror("Fork two"));
	if (!f)
		child_owo(gayosorus, cmd2, envp);
	child_owo(gayosorus, cmd2, envp);
	free_struct(cmd1);
	free_struct(cmd2);
}

void	pipex(int in, int out, char const **args, char const **envp)
{
	t_cmd	cmd1;
	t_cmd	cmd2;
	int		gayosorus[2];
	int		status;

	status = 0;
	pipe(gayosorus);
	init_cmd(&cmd1, in);
	init_cmd(&cmd2, out);
	if (!prepare_cmd(&cmd1, args[2], envp))
		return ;
	if (!prepare_cmd(&cmd2, args[3], envp))
		return ;
	run_cmds(gayosorus, envp, &cmd1, &cmd2);
	waitpid(-1, &status, 0);
	waitpid(-1, &status, 0);
}
