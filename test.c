/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 10:47:45 by creyt             #+#    #+#             */
/*   Updated: 2022/06/07 11:13:04 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc < 2)
		exit (0);
	if (argc == 2)
		printf("arg 2");
	if (argc > 2)
	{
		perror("\033[31mError");
		exit(EXIT_FAILURE);
	}
	return (0);
}
