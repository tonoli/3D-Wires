
#include <stdio.h>
int	 ft_char_counter(char *str, char c);

int main(int argc, char **argv)
{
	if (argc != 2)
		return (0);
	int i = ft_char_counter(argv[1], 'Y');
	printf("%s%d%s", "il y a",i, "Y dans cette phrase\n");
	return 0;
}
