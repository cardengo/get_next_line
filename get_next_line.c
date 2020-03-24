#include "get_next_line.h"

static	int		ft_new_node(int fd, char *str, t_node **node)
{
	t_node	*new_node;

	if (!(new_node = (t_node *)malloc(sizeof(t_node))))
		return (-1);
	new_node->data = str;
	new_node->fd = fd;
	new_node->next = NULL;
	*node = new_node;
	return (2);
}

static	int		ft_push(int fd, char *str, t_node **list)
{
	t_node	*curr;
	char	*cpy;

	if (!(*list))
		return ((ft_new_node(fd, str, list)));
	curr = *list;
	while (curr->fd != fd && curr->next)
		curr = curr->next;
	if (curr->fd == fd)
	{
		if (!(cpy = ft_strjoin(curr->data, str)))
			return (-1);
		free(curr->data);
		free(str);
		curr->data = cpy;
	}
	else
		return (ft_new_node(fd, str, &curr->next));
	return (2);
}

static	int		ft_pull(int fd, t_node **list, char **line, int red)
{
	t_node	*curr;
	char	*cpy;
	int		i;

	curr = *list;
	while (curr->fd != fd && curr->next)
		curr = curr->next;
	i = 0;
	while (curr->data[i] != '\n' && curr->data[i])
		i++;
	if (!(*line = ft_strsub(curr->data, 0, i)) ||
			!(cpy = ft_strsub(curr->data, i + 1, ft_strlen(curr->data) - i)))
		return (-1);
	if (curr->data[i] == '\n')
		i = -3;
	free(curr->data);
	curr->data = cpy;
	if (red == 0 && ft_strlen(curr->data) == 0 &&
			ft_strlen(*line) == 0 && i != -3)
		return (0);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static	t_node	*list = NULL;
	char			buff[BUFF_SIZE + 1];
	char			*str;
	int				red;

	if (fd < 0 || !line || BUFF_SIZE <= 0)
		return (-1);
	while ((red = read(fd, buff, BUFF_SIZE)))
	{
		if (red == -1 || !(str = ft_strsub(buff, 0, red)))
			return (-1);
		if (ft_push((int)fd, str, &list) == -1)
			return (-1);
		if (ft_strchr(str, '\n'))
			break ;
	}
	return (ft_pull(fd, &list, line, red));
}
