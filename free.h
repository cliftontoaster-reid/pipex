/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 17:09:31 by lfiorell          #+#    #+#             */
/*   Updated: 2024/12/13 09:25:08 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FREE_H
# define FREE_H

int		free_arr(char **path);
void	free_struct(t_cmd *c);
int		check_empty(const char *s);
void	error_msg(char *c);

#endif