#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int		ft_atoi_base(char const *str, char const *base);

void	check_atoi(char *s1, char *base)
{
	int	ret;

	ret = ft_atoi_base(s1, base);
	printf("s1: [%s], base: [%s], return: %d\n", s1, base, ret);
}

char	*dupcat(char *s1, char *s2, char *s3)
{
	int		len;
	char	*ret;
	int		i;
	int		j;

	len = strlen(s1) + strlen(s2) + strlen(s3);
	ret = malloc(len + 1);
	j = 0;
	i = -1;
	while (s1[++i])
		ret[j++] = s1[i];
	i = -1;
	while (s2[++i])
		ret[j++] = s2[i];
	i = -1;
	while (s3[++i])
		ret[j++] = s3[i];
	ret[j] = 0;
	return (ret);
}

#define S1_NUM 3
#define S2_NUM 8
#define S3_NUM 11

int		main(void)
{
	char	space[][3] = {"", " ", "  "};
	char	sign[][6] = {"", "+", "-", "+-", "++", "+-+", "-+-", "-++--"};
	char	value[][6] = {"", "0", "1", "2", "12", "123", " 123", "12z34", "z1234", "9b", "ff"};
	int		i[3];
	char	*tmp;
	char	*base1;
	char	*base2;

	base1 = "0123456789";
	base2 = "0123456789abcdef";
	i[0] = -1;
	while (++i[0] < S1_NUM)
	{
		i[1] = -1;
		while (++i[1] < S2_NUM)
		{
			i[2] = -1;
			while (++i[2] < S3_NUM)
			{
				tmp = dupcat(space[i[0]], sign[i[1]], value[i[2]]);
				check_atoi(tmp, base1);
				check_atoi(tmp, base2);
				free(tmp);
			}
		}
	}
	check_atoi("42", "01234509");
	check_atoi("42", "0123450");
	check_atoi("42", "0123456789+");
	check_atoi("42", "0123456789-");
	check_atoi("42", "0123456789 ");
	check_atoi("42", "0123456789\t");
	check_atoi("42", "0123456789+a");
	check_atoi("42", "0123456789-b");
	check_atoi("42", "0123456789 c");
	check_atoi("42", "0123456789\td");
	check_atoi("42", "+0123456789");
	check_atoi("42", "-0123456789");
	check_atoi("42", " 0123456789");
	check_atoi("42", "\t0123456789");

}
