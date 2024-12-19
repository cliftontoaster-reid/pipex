/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfiorell <lfiorell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 13:28:04 by lfiorell          #+#    #+#             */
/*   Updated: 2024/12/13 09:25:35 by lfiorell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cmd.h"
#include "free.h"
#include "libft/export/ft_printf.h"
#include "libft/export/libft.h"
#include <errno.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

int	main(int argc, char const *argv[], char const *envp[])
{
	int	f1;
	int	f2;

	if (argc != 5)
		return (ft_putbash("Invalid number of arguments.", 0));
	if (check_empty(argv[2]) || check_empty(argv[3]))
		return (1);
	f1 = open(argv[1], O_RDONLY);
	f2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (f1 < 0)
		return (ft_putbash(strerror(errno), argv[1]));
	if (f2 < 0)
		return (ft_putbash(strerror(errno), argv[4]));
	pipex(f1, f2, argv, envp);
	if (close(f1) < 0 || close(f2) < 0)
		return (ft_putbash(strerror(errno), 0));
	return (0);
}
