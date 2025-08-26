#include <stdio.h>
extern int ft_strcmp(const char *s1, const char *s2);

int main(void) {
	printf("La difference entre les deux lignes est de :%d", ft_strcmp("aoucou", "coucou"));
}