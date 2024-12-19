/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:41:37 by lfiorell          #+#    #+#             */
/*   Updated: 2024/12/13 09:24:20 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_H
# define CMD_H

typedef struct s_cmd
{
	char	*cmd;
	char	*args[100];
	int		pipe;
}			t_cmd;

void		pipex(int in, int out, char const **args, char const **envp);
void		run(t_cmd *cmd1, t_cmd *cmd2, char **envp);
int			ft_putbash(const char *s, const char *t);

#endif
