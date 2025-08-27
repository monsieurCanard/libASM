#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

extern size_t ft_strlen(const char *str);
extern char *ft_strcpy(char *dest, const char *src);
extern int ft_strcmp(const char *s1, const char *s2);
extern ssize_t ft_write(int fd, const void *buf, size_t count);
extern ssize_t ft_read(int fd, void *buf, size_t count);
extern char *ft_strdup(const char *s);

void headerTest(char* nameFunction) {
	printf("\n----------------------------------------------------------\n");
	printf("FUNCTION -> %s", nameFunction);
	printf("\n----------------------------------------------------------\n");
}

void endTest(char* nameFunction) {
	printf("\n----------------------------------------------------------\n");
	printf("TEST PASSED 0/0 for %s", nameFunction);
	printf("\n----------------------------------------------------------\n");
}



int main(void) {

		/*
	 ! FT_STRCPY
	*/ 
	headerTest("ft_strlen");
	
	printf("Test Empty: ");
	(ft_strlen("") == strlen("")) ? printf("OK\n") : printf("KO\n");
	
	printf("Test Simple: ");
	(ft_strlen("Squalala") == strlen("Squalala")) ? printf("OK\n") : printf("KO\n");
	(ft_strlen("monsieur") == strlen("madammes")) ? printf("OK\n") : printf("KO\n");
	
	printf("Test Long: ");
	(ft_strlen("lakwjdlakjwdlakwjdlakwjdlakwjdlakwjdlakwjdlajwdlakjwdlakjwdlakjwdlakjwdlakwjdlakjwdlakwjdlakwjdlakwjdlakwjdlakwjdlajwdlakjwdlakjwdlakjwdlakjwdlakwjdlakjwdlakwjdlakwjdlakwjdlakwjdlakwjdlajwdlakjwdlakjwdlakjwdlakjwdlakwjdlakjwdlakwjdlakwjdlakwjdlakwjdlakwjdlajwdlakjwdlakjwdlakjwdlakjwdlakwjdlakjwdlakwjdlakwjdlakwjdlakwjdlakwjdlajwdlakjwdlakjwdlakjwdlakjwdlakwjdlakjwdlakwjdlakwjdlakwjdlakwjdlakwjdlajwdlakjwdlakjwdlakjwdlakjwdlakwjdlakjwdlakwjdlakwjdlakwjdlakwjdlakwjdlajwdlakjwdlakjwdlakjwdlakjwdlakwjdlakjwdlakwjdlakwjdlakwjdlakwjdlakwjdlajwdlakjwdlakjwdlakjwdlakjwdlakwjdlakjwdlakwjdlakwjdlakwjdlakwjdlakwjdlajwdlakjwdlakjwdlakjwdlakjwdlakwjdlakjwdlakwjdlakwjdlakwjdlakwjdlakwjdlajwdlakjwdlakjwdlakjwdlakjwdlakwjdlakjwdlakwjdlakwjdlakwjdlakwjdlakwjdlajwdlakjwdlakjwdlakjwdlakjwdlakwjdlakjwdlakwjdlakwjdlakwjdlakwjdlakwjdlajwdlakjwdlakjwdlakjwdlakjwd") == strlen("lakwjdlakjwdlakwjdlakwjdlakwjdlakwjdlakwjdlajwdlakjwdlakjwdlakjwdlakjwdlakwjdlakjwdlakwjdlakwjdlakwjdlakwjdlakwjdlajwdlakjwdlakjwdlakjwdlakjwdlakwjdlakjwdlakwjdlakwjdlakwjdlakwjdlakwjdlajwdlakjwdlakjwdlakjwdlakjwdlakwjdlakjwdlakwjdlakwjdlakwjdlakwjdlakwjdlajwdlakjwdlakjwdlakjwdlakjwdlakwjdlakjwdlakwjdlakwjdlakwjdlakwjdlakwjdlajwdlakjwdlakjwdlakjwdlakjwdlakwjdlakjwdlakwjdlakwjdlakwjdlakwjdlakwjdlajwdlakjwdlakjwdlakjwdlakjwdlakwjdlakjwdlakwjdlakwjdlakwjdlakwjdlakwjdlajwdlakjwdlakjwdlakjwdlakjwdlakwjdlakjwdlakwjdlakwjdlakwjdlakwjdlakwjdlajwdlakjwdlakjwdlakjwdlakjwdlakwjdlakjwdlakwjdlakwjdlakwjdlakwjdlakwjdlajwdlakjwdlakjwdlakjwdlakjwdlakwjdlakjwdlakwjdlakwjdlakwjdlakwjdlakwjdlajwdlakjwdlakjwdlakjwdlakjwdlakwjdlakjwdlakwjdlakwjdlakwjdlakwjdlakwjdlajwdlakjwdlakjwdlakjwdlakjwdlakwjdlakjwdlakwjdlakwjdlakwjdlakwjdlakwjdlajwdlakjwdlakjwdlakjwdlakjwd")) ? printf("OK\n") : printf("KO\n");

	printf("Test Diff: ");
	(ft_strlen("") != strlen("awkjdhakjdwhakjwdh")) ? printf("OK\n") : printf("KO\n");
	
	endTest("ft_strlen");



	/*
	 ! FT_STRCPY
	*/ 
	headerTest("ft_strcpy");
	char newMessage[50];
	char newMessage2[50];
	
	printf("Test Empty: ");
	ft_strcpy(newMessage, "");
	strcpy(newMessage2, "");
	(strcmp(newMessage, newMessage2) == 0) ? printf("OK\n") : printf("KO\n");
	
	printf("Test Simple: ");
	ft_strcpy(newMessage, "Je suis une chips");
	strcpy(newMessage2, "Je suis une chips");
	(strcmp(newMessage, newMessage2) == 0) ? printf("OK\n") : printf("KO\n");
	
	printf("Test Diff: ");
	ft_strcpy(newMessage, "");
	strcpy(newMessage2, "Assembleur");
	(strcmp(newMessage, newMessage2) != 0) ? printf("OK\n") : printf("KO\n");

	endTest("ft_strcpy");




		/*
	 ! FT_STRCMP
	*/
	headerTest("ft_strcpy");

	printf("Test Empty: ");
	(ft_strcmp("", "") == 0) ? printf("OK\n") : printf("KO\n");

	printf("Test Simple: ");
	(ft_strcmp("Hello fucking World!", "Hello fucking World!") == 0) ? printf("OK\n") : printf("KO\n");

	printf("Test Long: ");
	(ft_strcmp("Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!", "Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!") == 0) ? printf("OK\n") : printf("KO\n");


	printf("Test Diff 1: ");
	(ft_strcmp("Hello beautifull World!", "Hello fucking World!") > 0) ? printf("OK\n") : printf("KO\n");

	printf("Test Diff 2: ");
	(ft_strcmp("Hello beautifull World!", "Hello awesome World!") < 0) ? printf("OK\n") : printf("KO\n");
	
	endTest("ft_strcmp");

			/*
	 ! FT_WRITE
	*/
	headerTest("ft_write");
	
		printf("Test empty");
	(write(1, "", 0) == ft_write(1, "", 0)) ? printf("OK\n") : printf("KO\n");

	printf("Test simple");
	(write(1, "coucou", 6) == ft_write(1, "coucou", 6)) ? printf("OK\n") : printf("KO\n");

	printf("Test long");
	(write(1, "SqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualala", 1832) == ft_write(1, "SqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualala", 1832)) ? printf("OK\n") : printf("KO\n");

	int fd = open("testWrite.txt", O_RDWR);
	if(fd == -1) {
		printf("Issue when opening TestSimple.txt");
		return -1;
	}
	
	printf("Test with simple file: ");
	(write(fd, "J'ecris un message dans ce fichier", 34) == ft_write(fd, "J'ecris un message dans ce fichier", 34)) ? printf("OK\n") : printf("KO\n");

	endTest("ft_write");
	


	/*
	 ! FT_READ
	*/

	fd = open("TestWrite.txt", O_RDWR);
	if(fd == -1) {
		printf("Issue when opening TestSimple.txt");
		return -1;
	}
}


