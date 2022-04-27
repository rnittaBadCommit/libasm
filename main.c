#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t	ft_strlen(char *s);
char	*ft_strcpy(char *s1, const char *s2);
int	ft_strcmp(const char *s1, const char *s2);
int	ft_write(int fd, char *, int i);
char	*ft_strdup(char *s);

#define S1_NUM 5
#define S2_NUM 7
#define STRLEN(x) (printf("%s", (strlen(x) == ft_strlen(x) ? "OK\n" : ft_catcpy("NO: ft_strlen, ", x))))
#define STRCPY(x) 

char	*ft_catcpy(char *s1, char *s2)
{
	char	*ret;
	int		i;

	ret = malloc(strlen(s1) + strlen(s2) + 1);
	i = -1;
	while (*s1)
		ret[++i] = *s1++;
	while (*s2)
		ret[++i] = *s2++;
	ret[++i] = 0;
	return (ret);
}

int	case_ok()
{
	printf("OK\n");
	return (0);
}

int	check_strlen(char *s)
{
	int	actual;
	int	expected;

	actual = ft_strlen(s);
	expected = strlen(s);
	if (actual == expected)
		return (case_ok());
	else
	{
		printf("NO: ft_strlen(\"%s\")  actual: %ud, expected: %d\n", s, actual, expected);
		return (-1);
	}
}

int	check_strcpy(char *s)
{
	char *dst;
	char *ret;

	dst = malloc(strlen(s) + 1);
	ret = ft_strcpy(dst, s);

	if (ret == dst && !strcmp(dst, s))
		return (case_ok());
	else
	{
		printf("NO: ft_strcpy(\"%s\")  \nactual return:\t\t%p, actual dest:\t%s\nexpected return:\t%p, expected dest:\t%s\n", s, ret, dst, dst, s);
		return (-1);
	}
}

int	check_strcmp(char *s1, char *s2)
{
	int	actual;
	int	expected;

	actual = ft_strcmp(s1, s2);
	expected = strcmp(s1, s2);
	if (actual == expected && 0)
		return (case_ok());
	else
	{
		printf("NO: ft_strcmp(\"%s\", \"%s\")  actual: %d, expected: %d\n", s1, s2, actual, expected);
		return (-1);
	}
}

int	check_strdup(char *s)
{
	char	*new;

	new = ft_strdup(s);
	if (!new)
	{
		printf("==============malloc error============\n");
		return (1);
	}
	else if (!strcmp(new, s))
		return (case_ok());
	else
	{
		printf("NO: ft_strdup(\"%s\")  actual: %s, expected: %s\n", s, new, s);
		return (-1);
	}
}

int main()
{
	char	s1[][11] = {"0123456789", "a", "", "\200", "\200abc\200", "\0", "\255"};
	char	s2[][11] = {"0123456788", "a", "b", "asdf", "", "\201", "\200abc\201", "\0", "\255"};
	int		i;
	int		j;
	int		f;

	i = -1;
	f = 0;
	while (++i < S1_NUM)
	{
		f |= !!check_strlen(s1[i]);
		f |= !!check_strcpy(s1[i]);
		j = -1;
		while (++j < S2_NUM)
			f |= !!check_strcmp(s1[i], s2[j]);
		f |= !!check_strdup(s1[i]);
	}
	if (!f)
		printf("\n\n==========ALL OK!===========\n\n");
	else
		printf("\n\n==========NOT OK===========\n\n");



	printf("%d\n", ft_strcmp("", "asdf"));
	printf("%d\n", strcmp("", "asdf"));
}
