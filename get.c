#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

size_t	ft_strlen(char	*str)
{
	size_t	result;

	result = 0;
	while (*str)
	{
		result++;
		str++;
	}
	return (result);
}

char	*get_next_line(int fd)
{
	char	*str;
	int		i;
	char	buf;
	int		flag;

	i = 0;
	str = malloc(9999);
	if (!str)
		return (NULL);
	while ((flag = read(fd, &buf, 1)))
	{
		str[i] = buf;
		if (str[i] == '\n' || str[i] == '\0')
			break ;
		i++;
	}
	if (i == 0 || flag < 0)
	{
		free(str);
		return (NULL);
	}
	str[++i] = '\0';
	return (str);
}

int	main(void)
{
	int	fd;
	char *str;

	fd = open("asdf.txt", O_RDONLY);
	str = get_next_line(fd);
	while (str)
	{
		printf("%s\n", str);
		str = get_next_line(fd);
	}
}