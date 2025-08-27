#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

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

void testOK() {
	printf("\e[1;32m[OK]\e[0m\n");
}

void testKO() {
		printf("\e[1;31m[KO]\e[0m\n");
}


int main(void) {

		/*
	 ! FT_STRCPY
	*/ 
	headerTest("ft_strlen");
	
	printf("Test Empty: ");
	(ft_strlen("") == strlen("")) ? testOK(): testKO();
	
	printf("Test Simple: ");
	(ft_strlen("Squalala") == strlen("Squalala")) ? testOK() : testKO();
	
	printf("Test Long: ");
	(ft_strlen("lakwjdlakjwdlakwjdlakwjdlakwjdlakwjdlakwjdlajwdlakjwdlakjwdlakjwdlakjwdlakwjdlakjwdlakwjdlakwjdlakwjdlakwjdlakwjdlajwdlakjwdlakjwdlakjwdlakjwdlakwjdlakjwdlakwjdlakwjdlakwjdlakwjdlakwjdlajwdlakjwdlakjwdlakjwdlakjwdlakwjdlakjwdlakwjdlakwjdlakwjdlakwjdlakwjdlajwdlakjwdlakjwdlakjwdlakjwdlakwjdlakjwdlakwjdlakwjdlakwjdlakwjdlakwjdlajwdlakjwdlakjwdlakjwdlakjwdlakwjdlakjwdlakwjdlakwjdlakwjdlakwjdlakwjdlajwdlakjwdlakjwdlakjwdlakjwdlakwjdlakjwdlakwjdlakwjdlakwjdlakwjdlakwjdlajwdlakjwdlakjwdlakjwdlakjwdlakwjdlakjwdlakwjdlakwjdlakwjdlakwjdlakwjdlajwdlakjwdlakjwdlakjwdlakjwdlakwjdlakjwdlakwjdlakwjdlakwjdlakwjdlakwjdlajwdlakjwdlakjwdlakjwdlakjwdlakwjdlakjwdlakwjdlakwjdlakwjdlakwjdlakwjdlajwdlakjwdlakjwdlakjwdlakjwdlakwjdlakjwdlakwjdlakwjdlakwjdlakwjdlakwjdlajwdlakjwdlakjwdlakjwdlakjwdlakwjdlakjwdlakwjdlakwjdlakwjdlakwjdlakwjdlajwdlakjwdlakjwdlakjwdlakjwd") == strlen("lakwjdlakjwdlakwjdlakwjdlakwjdlakwjdlakwjdlajwdlakjwdlakjwdlakjwdlakjwdlakwjdlakjwdlakwjdlakwjdlakwjdlakwjdlakwjdlajwdlakjwdlakjwdlakjwdlakjwdlakwjdlakjwdlakwjdlakwjdlakwjdlakwjdlakwjdlajwdlakjwdlakjwdlakjwdlakjwdlakwjdlakjwdlakwjdlakwjdlakwjdlakwjdlakwjdlajwdlakjwdlakjwdlakjwdlakjwdlakwjdlakjwdlakwjdlakwjdlakwjdlakwjdlakwjdlajwdlakjwdlakjwdlakjwdlakjwdlakwjdlakjwdlakwjdlakwjdlakwjdlakwjdlakwjdlajwdlakjwdlakjwdlakjwdlakjwdlakwjdlakjwdlakwjdlakwjdlakwjdlakwjdlakwjdlajwdlakjwdlakjwdlakjwdlakjwdlakwjdlakjwdlakwjdlakwjdlakwjdlakwjdlakwjdlajwdlakjwdlakjwdlakjwdlakjwdlakwjdlakjwdlakwjdlakwjdlakwjdlakwjdlakwjdlajwdlakjwdlakjwdlakjwdlakjwdlakwjdlakjwdlakwjdlakwjdlakwjdlakwjdlakwjdlajwdlakjwdlakjwdlakjwdlakjwdlakwjdlakjwdlakwjdlakwjdlakwjdlakwjdlakwjdlajwdlakjwdlakjwdlakjwdlakjwdlakwjdlakjwdlakwjdlakwjdlakwjdlakwjdlakwjdlajwdlakjwdlakjwdlakjwdlakjwd")) ? testOK() : testKO();

	printf("Test Diff: ");
	(ft_strlen("") != strlen("awkjdhakjdwhakjwdh")) ? testOK() : testKO();
	
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
	(strcmp(newMessage, newMessage2) == 0) ? testOK() : testKO();
	
	printf("Test Simple: ");
	ft_strcpy(newMessage, "Je suis une chips");
	strcpy(newMessage2, "Je suis une chips");
	(strcmp(newMessage, newMessage2) == 0) ? testOK() : testKO();
	
	printf("Test Diff: ");
	ft_strcpy(newMessage, "");
	strcpy(newMessage2, "Assembleur");
	(strcmp(newMessage, newMessage2) != 0) ? testOK() : testKO();

	endTest("ft_strcpy");


		/*
	 ! FT_STRCMP
	*/
	headerTest("ft_strcpy");

	printf("Test Empty: ");
	(ft_strcmp("", "") == 0) ? testOK() : testKO();

	printf("Test Simple: ");
	(ft_strcmp("Hello fucking World!", "Hello fucking World!") == 0) ? testOK() : testKO();

	printf("Test Long: ");
	(ft_strcmp("Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!", "Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!Hello fucking World!") == 0) ? testOK() : testKO();


	printf("Test Diff 1: ");
	(ft_strcmp("Hello beautifull World!", "Hello fucking World!") > 0) ? testOK() : testKO();

	printf("Test Diff 2: ");
	(ft_strcmp("Hello beautifull World!", "Hello awesome World!") < 0) ? testOK() : testKO();
	
	endTest("ft_strcmp");

			/*
	 ! FT_WRITE
	*/
	headerTest("ft_write");
	
		printf("Test empty: ");
	(write(1, "", 0) == ft_write(1, "", 0)) ? testOK() : testKO();

	printf("Test simple: ");
	(write(1, "coucou\n", 7) == ft_write(1, "coucou\n", 7)) ? testOK() : testKO();

		int fd = open("srcs/tester/testWrite.txt", O_RDWR);
	if(fd == -1) {
		printf("Issue when opening TestSimple.txt");
		return -1;
	}
	printf("Test long: ");
	(write(fd, "SqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualala", 1832) == ft_write(fd, "SqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualala", 1832)) ? testOK() : testKO();


	
	printf("Test with simple file: ");
	(write(fd, "J'ecris un message dans ce fichier", 34) == ft_write(fd, "J'ecris un message dans ce fichier", 34)) ? testOK() : testKO();

	endTest("ft_write");
	


	/*
	 ! FT_READ
	*/
	ssize_t ft_result = 0;
	ssize_t std_result = 0;

	headerTest("ft_read");

	char buffR[1024];
	
	fd = open("srcs/tester/emptyFile.txt", O_RDWR);
	if(fd == -1) {
		printf("Issue when opening testWrite.txt");
		return -1;
	}

	printf("Test with empty file: ");
	ft_result = ft_read(fd, buffR, sizeof(buffR));
	lseek(fd, 0, SEEK_SET);
	std_result = read(fd, buffR, sizeof(buffR));
	printf("ft_read: %ld, read: %ld ", ft_result, std_result);
	(ft_result == std_result) ? testOK() : testKO();
	
	fd = open("srcs/tester/testRead.txt", O_RDWR);
	if(fd == -1) {
		printf("Issue when opening testWrite.txt");
		return -1;
	}
	
	printf("Test Simple with testRead.txt: ");
	ft_result = ft_read(fd, buffR, sizeof(buffR));
	lseek(fd, 0, SEEK_SET);
	std_result = read(fd, buffR, sizeof(buffR));
	printf("ft_read: %ld, read: %ld ", ft_result, std_result);
	(ft_result == std_result) ? testOK() : testKO();
	
	
	printf("Test testRead.txt with buffer size = 1 : ");
	char shortBuffer[1];
	ft_result = ft_read(fd, shortBuffer, sizeof(shortBuffer));
	lseek(fd, 0, SEEK_SET);
	std_result = read(fd, shortBuffer, sizeof(shortBuffer));
	printf("ft_read: %ld, read: %ld ", ft_result, std_result);
	(ft_result == std_result) ? testOK() : testKO();

	printf("Test testRead.txt with buffer size = 0 : ");
	char emptyBuffer[0];
	ft_result = ft_read(fd, emptyBuffer, sizeof(emptyBuffer));
	lseek(fd, 0, SEEK_SET);
	std_result = read(fd, emptyBuffer, sizeof(emptyBuffer));
	printf("ft_read: %ld, read: %ld ", ft_result, std_result);
	(ft_result == std_result) ? testOK() : testKO();

	printf("Test testRead.txt with buffer size = 1400000 : ");
	char bigBuffer[3000];
	ft_result = ft_read(fd, bigBuffer, sizeof(bigBuffer));
	lseek(fd, 0, SEEK_SET);
	std_result = read(fd, bigBuffer, sizeof(bigBuffer));
	printf("ft_read: %ld, read: %ld ", ft_result, std_result);
	(ft_result == std_result) ? testOK() : testKO();
	
	endTest("ft_write");

		/*
	 ! FT_STRDUP
	*/
	headerTest("ft_strdup");
	char *msg;
	char *msg2;
	
	printf("Test Simple : ");
	msg = strdup("I gonna hit your buisness !");
	msg2 = ft_strdup("I gonna hit your buisness !");
	(strcmp(msg, msg2) == 0) ? testOK() : testKO();
	free(msg); free(msg2);

	printf("Test Empty: ");
	msg = strdup("");
	msg2 = ft_strdup("");
	(strcmp(msg, msg2) == 0) ? testOK() : testKO();
	free(msg); free(msg2);

	printf("Test Big: ");
	msg = strdup("IWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEY");
	msg2 = ft_strdup("IWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEYIWANTSOMEMONEY");
	(strcmp(msg, msg2) == 0) ? testOK() : testKO();
	free(msg); free(msg2);

	endTest("ft_strdup");
}


