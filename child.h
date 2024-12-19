/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:56:25 by lfiorell          #+#    #+#             */
/*   Updated: 2024/12/13 09:09:19 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHILD_H
# define CHILD_H
# include "cmd.h"

void	child_uwu(int *pipefd, t_cmd *c, char const **envp);
void	child_owo(int *pipefd, t_cmd *c, char const **envp);

#endif