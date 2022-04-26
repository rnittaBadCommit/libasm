#include <stdio.h>
int ft_strlen(char *s);
int main()
{
	printf("%ul\n", strlen("abcde"));
	printf("%ul\n", strlen(""));
	printf("%ul\n", strlen("a"));
	printf("==========================\n");
	printf("%ul\n", ft_strlen("abcde"));
	printf("%ul\n", ft_strlen(""));
	printf("%ul\n", ft_strlen("a"));
}
