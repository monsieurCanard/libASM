#include <stdio.h>
extern long my_strlen(const char *str);


int main(void) {
	char *message = "Coucou";
	printf("%li", my_strlen(message));
	return 0;
}