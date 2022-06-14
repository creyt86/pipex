/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 15:32:18 by creyt             #+#    #+#             */
/*   Updated: 2022/06/14 15:04:04 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	*find_path(char *command, char **envp)
{
	char	**getpath;
	char	*path;
	char	*part_path;
	int		i;

	i = 0;
	while (ft_strnstr(envp[i], "PATH", 4) == 0)
		i++;
	getpath = ft_split(envp[i] + 5, ':');
	i = 0;
	while (getpath[i])
	{
		part_path = ft_strjoin(getpath[i], "/");
		path = ft_strjoin(part_path, command);
		free(part_path);
		if (access(path, F_OK) == 0)
			return (path);
		free(path);
		i++;
	}
	i = -1;
	while (getpath[++i])
		free(getpath[i]);
	free(getpath);
	return (0);
}

void	p_error(void)
{
	perror("\033[31mError");
	exit(EXIT_FAILURE);
}

void	exe_cute(char *argv, char **envp)
{
	char	**command;
	int		i;
	char	*path;

	i = -1;
	command = ft_split(argv, ' ');
	path = find_path(command[0], envp);
	if (!path)
	{
		while (command[++i])
			free(command[i]);
		free(command);
		p_error();
	}
	if (execve(path, command, envp) == -1)
		p_error();
}

int	get_next_line(char **line)
{
	char	*buffer;
	int		rest;
	int		i;
	char	c;

	rest = 0;
	i = 0;
	buffer = (char *)malloc(10000);
	if (!buffer)
		return (-1);
	rest = read(0, &c, 1);
	while (rest && c != '\n' && c != '\0')
	{
		if (c != '\n' && c != '\0')
			buffer[i] = c;
		i++;
		rest = read(0, &c, 1);
	}
	buffer[i] = '\n';
	buffer[++i] = '\0';
	*line = buffer;
	free(buffer);
	return (rest);
}
