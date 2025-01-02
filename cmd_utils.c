/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:33:50 by lfiorell          #+#    #+#             */
/*   Updated: 2024/12/23 19:57:06 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd_utils.h"
#include "libft/export/libft.h"

static void	handle_whitespace(char const *cmd, t_parse_cmd_state *state)
{
	int	j;

	j = 0;
	while (ft_ciswhite(cmd[state->i + j]))
		j++;
	state->i += j;
	state->state = PS_TEXT;
}

static void	handle_text(char const *cmd, t_parse_cmd_state *state)
{
	if (cmd[state->i] == '\'')
		state->state = PS_QUOTE;
	else if (cmd[state->i] == '\"')
		state->state = PS_DQUOTE;
	else if (ft_ciswhite(cmd[0]))
	{
		state->state = PS_WHITESPACE;
		if (state->is_cmd)
			state->cmd.args[state->argn++] = ft_strdup(state->buffer);
		else
		{
			state->cmd.cmd = ft_strdup(state->buffer);
			state->is_cmd = TRUE;
		}
		ft_bzero(state->buffer, 2048);
	}
	else
	{
		while (!ft_ciswhite(cmd[state->i]))
		{
			state->buffer[state->i] = cmd[state->i];
			state->i++;
		}
	}
	state->i++;
}

static void	handle_until(char const *cmd, t_parse_cmd_state *state, char c)
{
	state->i++;
	while (cmd[state->i] != c && cmd[state->i])
	{
		state->buffer[state->i] = cmd[state->i];
		state->i++;
	}
	state->i++;
	state->state = PS_WHITESPACE;
	if (state->is_cmd)
		state->cmd.args[state->argn++] = ft_strdup(state->buffer);
	else
	{
		state->cmd.cmd = ft_strdup(state->buffer);
		state->is_cmd = TRUE;
	}
}

t_parsed_cmd	parse_cmd(char const *cmd)
{
	t_parse_cmd_state	state;

	state.state = PS_WHITESPACE;
	state.i = 0;
	state.cmd.cmd = 0;
	state.argn = 0;
	state.is_cmd = FALSE;
	state.cmd.is_args = FALSE;
	ft_bzero(state.buffer, 2048);
	while (cmd[state.i])
	{
		if (state.state == PS_WHITESPACE)
			handle_whitespace(cmd, &state);
		else if (state.state == PS_TEXT)
			handle_text(cmd, &state);
		else if (state.state == PS_QUOTE)
			handle_until(cmd, &state, '\'');
		else if (state.state == PS_DQUOTE)
			handle_until(cmd, &state, '\"');
	}
	if (state.is_cmd)
		state.cmd.args[state.argn++] = ft_strdup(state.buffer);
	else
		state.cmd.cmd = ft_strdup(state.buffer);
	return (state.cmd);
}
