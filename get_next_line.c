#include "get_next_line.h"

int		ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*new;
	int		i;
	int		j;

	new = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!s)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
		new[j++] = s[i++];
	new[j] = 0;
	return (new);
}

char	*get_next_line(int fd)
{

	char	*line;
	char	buf;
	int		i;
	int		b;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	b = read(fd, &buf, 1);
	i = 0;
	while (b > 0)
	{
		line[i++] = buf;
		if (buf == '\n')
			break;
		b = read(fd, &buf, 1);
	}
	line[i] = 0;
	if (b <= 0 && i == 0)
		return (NULL);
	return (ft_strdup(line));

}

int main()
{
	char *line;
	int i;
	int f1;
	int f2;

	f1 = open("test1.txt", O_RDONLY);
	f2 = open("test2.txt", O_RDONLY);
	i = 1;

	line = get_next_line(f1);
	printf("line t1 [%d]: %s\n", i, line);
	free(line);
	line = get_next_line(f2);
	printf("line t2 [%d]: %s\n", i + 1, line);
	free(line);

	close(f1);
	close(f2);
}