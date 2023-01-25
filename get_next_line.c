#include "get_next_line.h"

char	*get_next_line(int fd)
{

	static char	*line;
	char		*buf;
	char		*puntnewline; 
	int			i;
	int			b;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	b = 1;
	while (!(ft_strchr(line, '\n') && b > 0))
	{
		b = read(fd, buf, BUFFER_SIZE);
		if (b == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[b] = '\0';
		line = ft_strjoin(line, buf);
		//line = buf;
	}
	free(buf);
	i = 0;
	while (line[i] && line[i] != '\n')
		i++;
	puntnewline= (char *)malloc(sizeof(char) * (i + 2));
	if (!puntnewline)
		return NULL;
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		puntnewline[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
	{
		puntnewline[i] = '\n';
		i++;
	}
	puntnewline[i] = 0;
	return (puntnewline);
}

// int main()
// {
// 	static char *line;
// 	int i;
// 	int f1;
// 	int f2;

// 	f1 = open("test1.txt", O_RDONLY);

// 	i = 0;
// 	while (i < 3)
// 	{
// 		line = get_next_line(f1);
// 		printf("line t1: %s\n", line);
// 		// free(line);
// 		i++;
// 	}

// 		close(f1);

// 	// f1 = open("test2.txt", O_RDONLY);
// 	// 	line = get_next_line(f1);
// 	// 	printf("line t2: %s\n", line);
// 	// 	free(line);
// 	// 	close(f1);

// 	//f1 = open("test1.txt", O_RDONLY);


// 	// line = get_next_line(f1);
// 	// printf("line t1: %s\n", line);
// 	// free(line);
// 	// close(f1);

// }