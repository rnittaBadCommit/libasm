#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t ft_strlen(char *s);
char *ft_strcpy(char *s1, const char *s2);

#define TEST_NUM 3
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
		printf("NO: ft_strlen(%s)  actual: %ud, expected: %d\n", s, actual, expected);
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
		printf("NO: ft_strcpy(%s)  \nactual return:\t\t%p, actual dest:\t%s\nexpected return:\t%p, expected dest:\t%s\n", s, ret, dst, dst, s);
		return (-1);
	}
}


int main()
{
	char	s[][11] = {"0123456789", "a", ""};
	int		i;

	i = -1;
	while (++i < TEST_NUM)
	{
		check_strlen(s[i]);
		check_strcpy(s[i]);
	}
}
