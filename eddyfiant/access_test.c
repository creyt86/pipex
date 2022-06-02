/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   access_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:32:19 by creyt             #+#    #+#             */
/*   Updated: 2022/06/02 14:48:06 by creyt            ###   ########.fr       */
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
	int	fd;

	fd = access("/bin/ls", R_OK & W_OK & X_OK & F_OK);
	printf("%d\n", fd);
	perror("Error description : ");
	return (0);
}
