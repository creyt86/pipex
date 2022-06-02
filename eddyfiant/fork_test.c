/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 13:54:51 by creyt             #+#    #+#             */
/*   Updated: 2022/06/02 14:05:36 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/wait.h>
#include <fcntl.h>

int	main(void)
{
	int	id;

	id = fork();
	if (id == 0)
		printf("born to be child id [%d]\n", id);
	else
		printf("born to be parent id [%d]\n", id);
}
