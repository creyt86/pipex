/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:59:12 by creyt             #+#    #+#             */
/*   Updated: 2022/06/07 14:25:53 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./pipex.h"

void	child_process(char **argv, char **envp, int *fd)
{
	int	infile;

	infile = open(argv[1], O_RDONLY, 0777);
	if (infile == -1)
		p_error();
	dup2(fd[1], STDOUT_FILENO);
	dup2(infile, STDIN_FILENO);
	close(fd[0]);
	exe_cute(argv[2], envp);
}

void	parent_process(char **argv, char **envp, int *fd)
{
	int	outfile;

	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (outfile == -1)
		p_error();
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(fd[1]);
	exe_cute(argv[3], envp);
}

/*
l. 19 - le 0777 dans les parametres de open donne tous les droits a tout le
monde, chmod 777.
l. 32 - O_CREAT = Creer le fichier s'il n'existe pas.
O_TRUNC = Si le fichier existe, est un fichier régulier, et est ouvert en
écriture (O_RDWR ou O_WRONLY), il sera tronqué (ampute) à une longueur nulle.
Si le fichier est une FIFO ou un périphérique terminal, l'attribut O_TRUNC
est ignoré. Sinon, le comportement de O_TRUNC n'est pas précisé.
Sur de nombreuses versions de Linux, il sera ignoré ; sur d'autres versions
il déclenchera une erreur).
*/
