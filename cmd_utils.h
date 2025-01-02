/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 17:17:52 by lfiorell          #+#    #+#             */
/*   Updated: 2024/12/23 18:56:01 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CMD_UTILS_H
# define CMD_UTILS_H

# include "cmd.h"

typedef enum s_parsing_state
{
	PS_TEXT,
	PS_QUOTE,
	PS_DQUOTE,
	PS_WHITESPACE,
}					t_parsing_state;

typedef enum s_bool
{
	FALSE,
	TRUE,
}					t_bool;

typedef struct s_parsed_cmd
{
	char			*cmd;
	t_bool			is_args;
	char			**args;
}					t_parsed_cmd;

typedef struct s_parse_cmd_state
{
	t_parsing_state	state;
	int				i;
	char			buffer[2048];
	t_bool			is_cmd;
	int				argn;
	t_parsed_cmd	cmd;
}					t_parse_cmd_state;

t_parsed_cmd		parse_cmd(char const *cmd);
void				free_parsed_cmd(t_parsed_cmd *cmd);

#endif
