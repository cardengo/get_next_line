#include "get_next_line.h"
#include <fcntl.h>

int		get_next_line(const int fd, char **line);

static	void	ft_putline(int fd, char *line, int ret)
{
	
	ft_putstr("\nline: ");
	ft_putstr(line);
	ft_putstr("\nfd: ");
	ft_putnbr(fd);
	ft_putstr("\nreturn: ");
	ft_putnbr(ret);
	ft_putstr("\n");
	free(line);
}

int		main()
{
	char	*line = NULL;
	int		fd0;
	int		fd1;
	int		ret = 1;

	fd0 = open("files/file_to_read_0.txt", O_RDONLY);
	fd1 = open("files/file_to_read_1.txt", O_RDONLY);
	while (ret != 0)
	{
		ret = get_next_line(fd0, &line);
		ft_putline(fd0, line, ret);
		ret = get_next_line(fd1, &line);
		ft_putline(fd1, line, ret);
	}
	fd0 = close(fd0);
	fd1 = close(fd1);
	return (0);
}
