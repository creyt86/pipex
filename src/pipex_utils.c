/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:32:18 by creyt             #+#    #+#             */
/*   Updated: 2022/06/02 16:46:23 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*find_path(char *cmd, char envp)
{
	char	**getpath;
	char	*path;
	char	*part_path;
	int		i;

	i = 0;
	while(ft_strnstr(envp[i], "PATH", 4) == 0)

}
