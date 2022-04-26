#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t ft_strlen(char *s);
char *ft_strcpy(char *s1, const char *s2);
int	ft_strcmp(const char *s1, const char *s2);

#define S1_NUM 5
#define S2_NUM 6
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
	if (actual == expected)
		return (case_ok());
	else
	{
		printf("NO: ft_strcmp(\"%s\", \"%s\")  actual: %d, expected: %d\n", s1, s2, actual, expected);
		return (-1);
	}
}

int main()
{
	char	s1[][11] = {"0123456789", "a", "", "\200", "\200abc\200", "\0", "\255"};
	char	s2[][11] = {"0123456788", "a", "b", "", "\201", "\200abc\201", "\0", "\255"};
	int		i;
	int		j;

	i = -1;
	while (++i < S1_NUM)
	{
		check_strlen(s1[i]);
		check_strcpy(s1[i]);
		j = -1;
		while (++j < S2_NUM)
			check_strcmp(s1[1], s2[j]);
	}
}
