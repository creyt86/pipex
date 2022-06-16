/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: creyt <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 14:40:07 by creyt             #+#    #+#             */
/*   Updated: 2022/06/16 16:53:05 by creyt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	child_process(char *argv, char **envp)
{
	pid_t	pid;
	int		fd[2];

	if (pipe(fd) == -1)
		p_error();
	pid = fork();
	if (pid < 0)
		p_error();
	if (pid == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		exe_cute(argv, envp);
	}
	else
	{
		close(fd[1]);
		dup2(fd[0], STDIN_FILENO);
		waitpid(pid, NULL, 0);
	}
}

void	dup_two(int fd[2])
{
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	wait(NULL);
}

void	here_doc(char *keyword, int argc)
{
	pid_t	reader;
	int		fd[2];
	char	*line;

	if (argc < 6)
		error_arg();
	if (pipe(fd) == -1)
		p_error();
	reader = fork();
	if (reader == 0)
	{
		close(fd[0]);
		write(1, "heredoc> ", 9);
		while (get_next_line(&line))
		{
			if (ft_strncmp(line, keyword, ft_strlen(keyword)) == 0)
				exit(EXIT_SUCCESS);
			write(fd[1], line, ft_strlen(line));
			write(1, "heredoc> ", 9);
		}
	}
	else
		dup_two(fd);
}

int	main(int argc, char **argv, char **envp)
{
	int	fileout;
	int	filein;
	int	i;

	if (argc >= 5)
	{
		if (ft_strncmp(argv[1], "here_doc", 8) == 0)
		{
			i = 3;
			fileout = open_file(argv[argc - 1], 0);
			here_doc(argv[2], argc);
		}
		else
		{
			i = 2;
			fileout = open_file(argv[argc - 1], 1);
			filein = open_file(argv[1], 2);
			dup2(filein, STDIN_FILENO);
		}
		while (i < argc - 2)
			child_process(argv[i++], envp);
		dup2(fileout, STDOUT_FILENO);
		exe_cute(argv[argc - 2], envp);
	}
	error_arg();
	// while (1)
	// 	;
}

/*{
	char	*line;
	char	*name;

	name = "temp.txt";
	fd = open(name, O_CREAT | O_WRONLY, 0777);
	if (fd == -1)
		p_error();
	while (1)
	{
		line = get_next_line(STDIN_FILENO);
		if (ft_strncmp(keyword, line, ft_strlen(keyword)))
		{
			free(line);
			break ;
		}
		else
		{
			ft_putstr_fd(line, fd);
			free(line);
		}
	}
	close(fd);
	fd = open(name, O_RDONLY);
	unlink(name);
	if (fd == 1)
		p_error();
	free(fd);
}*/
