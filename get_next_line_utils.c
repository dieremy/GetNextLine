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

char	ft_strchr(const char *s, int c)
{
	int i = 0;
	if (!s)
		s = (char *)malloc(sizeof(char) * 1);
	while (s[i])
	{
		if (s[i] == c)
			return ((char)&s[i]);
		i++;
	}
	if (s[i] == c)
		return ((char)&s[i]);
	return (0);
}

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*out;
	int		i;
	int		j;

	if (!s1)
		s1 = (char *)malloc(sizeof(char) * 1);
	out = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!out)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
		out[j++] = s1[i++];
	i = 0;
	while (s2[i])
		out[j++] = s2[i++];
	out[j] = 0;
	return (out);
}
