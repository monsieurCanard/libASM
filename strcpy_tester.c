#include <stdio.h>
extern char *ft_strcpy(char *dest, const char *src);


int main(void) {
	char newMessage[50];
	ft_strcpy(newMessage, "cou8cou");
	printf("%s", newMessage);
}