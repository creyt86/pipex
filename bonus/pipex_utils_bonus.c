/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 14:12:21 by creyt             #+#    #+#             */
/*   Updated: 2022/06/14 15:04:03 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	error_arg(void)
{
	ft_putstr_fd("\033[31mError: Bad argument\n\e[0m", 2);
	ft_putstr_fd("Let's see the subject for the exemples !\n", 1);
	exit(EXIT_SUCCESS);
}

int	open_file(char **argv, int i)
{
	int	file;

	file = 0;
	if (i == 0)
		file = open(argv, O_WRONLY | O_CREAT | O_APPEND, 0777);
	else if (i == 1)
		file == open (argv, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else if (i == 2)
		file = open(argv, O_RDONLY, 0777);
	if (file < 0)
		p_error();
	return (file);
}
