#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t ft_strlen(char *s);
char *ft_strcpy(char *s1, const char *s2);

#define TEST_NUM 3
#define STRLEN(x) (printf("%s", (strlen(x) == ft_strlen(x) ? "OK\n" : ft_catcpy("NO: ft_strlen, ", x))))

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

int main()
{
	char	s[][11] = {"0123456789", "a", ""};
	int		i;

	i = -1;
	while (++i < TEST_NUM)
	{
		STRLEN(s[i]);
	}
}
