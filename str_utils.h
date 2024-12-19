/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 16:16:02 by lfiorell          #+#    #+#             */
/*   Updated: 2024/12/13 10:15:11 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	**ft_splitpath(char const *s, char c);
void	free_strs(char **split);
int		count_words(const char *s, char c);
int		ft_strfreq(char *str, char c);
