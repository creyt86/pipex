#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, str, fd);
		i++;
	}
}
int	main(void)
{
	int	fd;

	fd = open("test.txt", O_RDONLY | O_WRONLY);
	ft_putstr_fd("ton oncle\n", fd);
	return (0);
}
