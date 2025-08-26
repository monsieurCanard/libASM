#include <stdio.h>
extern long ft_strlen(const char *str);


int main(void) {
	char *message = "Coucou";
	printf("%ld", ft_strlen(message));
	return 0;
}