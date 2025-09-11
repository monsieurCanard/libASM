#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>

extern size_t ft_strlen(const char *str);
extern char *ft_strcpy(char *dest, const char *src);
extern int ft_strcmp(const char *s1, const char *s2);
extern ssize_t ft_write(int fd, const void *buf, size_t count);
extern ssize_t ft_read(int fd, void *buf, size_t count);
extern char *ft_strdup(const char *s);

int counter = 0;


void test_ft_read_errno();
void test_ft_write_errno();

void headerTest(char* nameFunction) {
	printf("\n----------------------------------------------------------\n");
	printf("FUNCTION --------- [%s]", nameFunction);
	printf("\n----------------------------------------------------------\n");
}

void endTest(int nb_test) {
	printf("\n----------------------------------------------------------\n");
	printf("TEST PASSED %d/%d",counter, nb_test);
	printf("\n----------------------------------------------------------\n");
	counter = 0;
}

void testOK() {
	printf("\e[1;32m[OK]\e[0m\n");
	counter++;
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
	
	endTest(4);



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

	endTest(3);


		/*
	 ! FT_STRCMP
	*/
	headerTest("ft_strcmp");

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
	
	endTest(5);

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
	printf("Test file: ");
	(write(fd, "SqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualala", 1832) == ft_write(fd, "SqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualalaSqualala", 1832)) ? testOK() : testKO();


	
	(write(fd, "J'ecris un message dans ce fichier", 34) == ft_write(fd, "J'ecris un message dans ce fichier", 34)) ? testOK() : testKO();

	endTest(4);
	test_ft_write_errno();
	


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
	// printf("ft_read: %ld, read: %ld ", ft_result, std_result);
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
	// printf("ft_read: %ld, read: %ld ", ft_result, std_result);
	(ft_result == std_result) ? testOK() : testKO();
	
	
	printf("Test testRead.txt with buffer size = 1 : ");
	char shortBuffer[1];
	ft_result = ft_read(fd, shortBuffer, sizeof(shortBuffer));
	lseek(fd, 0, SEEK_SET);
	std_result = read(fd, shortBuffer, sizeof(shortBuffer));
	// printf("ft_read: %ld, read: %ld ", ft_result, std_result);
	(ft_result == std_result) ? testOK() : testKO();

	printf("Test testRead.txt with buffer size = 0 : ");
	char emptyBuffer[0];
	ft_result = ft_read(fd, emptyBuffer, sizeof(emptyBuffer));
	lseek(fd, 0, SEEK_SET);
	std_result = read(fd, emptyBuffer, sizeof(emptyBuffer));
	// printf("ft_read: %ld, read: %ld ", ft_result, std_result);
	(ft_result == std_result) ? testOK() : testKO();

	printf("Test testRead.txt with buffer size = 1400000 : ");
	char bigBuffer[1400000];
	ft_result = ft_read(fd, bigBuffer, sizeof(bigBuffer));
	lseek(fd, 0, SEEK_SET);
	std_result = read(fd, bigBuffer, sizeof(bigBuffer));
	// printf("ft_read: %ld, read: %ld ", ft_result, std_result);
	(ft_result == std_result) ? testOK() : testKO();
	
	endTest(5);
	test_ft_read_errno();

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

	endTest(3);
}



void test_ft_read_errno() {
    char buffer[100];
    ssize_t result;
    
		headerTest("Ft_read ERRNO");

    // Test 1: Lecture normale (devrait réussir)
    printf("\nTest 1: Lecture normale\n");
    errno = 0;
    result = ft_read(STDIN_FILENO, buffer, 0);
    printf("ft_read(STDIN, buffer, 0) = %ld, errno = %d (%s)\n", 
           result, errno, strerror(errno));
		(errno == 0) ? testOK() : testKO();
		
    
    // Test 2: File descriptor invalide (devrait échouer avec EBADF)
    printf("\nTest 2: FD invalide (-1)\n");
    errno = 0;
    result = ft_read(-1, buffer, 10);
    printf("ft_read(-1, buffer, 10) = %ld, errno = %d (%s)\n", 
           result, errno, strerror(errno));
    printf("Attendu: errno = %d (EBADF)\n", EBADF);
		(errno == EBADF) ? testOK() : testKO();

    
    // Test 3: FD fermé (devrait échouer avec EBADF)
    printf("\nTest 3: FD fermé\n");
    errno = 0;
    result = ft_read(999, buffer, 10);
    printf("ft_read(999, buffer, 10) = %ld, errno = %d (%s)\n", 
           result, errno, strerror(errno));
    printf("Attendu: errno = %d (EBADF)\n", EBADF);
		(errno == EBADF) ? testOK() : testKO();

    
    // Test 4: Buffer NULL (devrait échouer avec EFAULT)
    printf("\nTest 4: Buffer NULL\n");
    errno = 0;
    result = ft_read(STDIN_FILENO, NULL, 10);
    printf("ft_read(STDIN, NULL, 10) = %ld, errno = %d (%s)\n", 
           result, errno, strerror(errno));
    printf("Attendu: errno = %d (EFAULT)\n", EFAULT);
		(errno == EFAULT) ? testOK() : testKO();

    
    // Test 5: Comparaison avec la vraie fonction read
    printf("\n=== Comparaison avec read() ===\n");
    
    // Test avec read() système
    errno = 0;
    ssize_t sys_result = read(-1, buffer, 10);
    int sys_errno = errno;
    
    // Test avec votre ft_read
    errno = 0;
    ssize_t ft_result = ft_read(-1, buffer, 10);
    int ft_errno = errno;
    
    printf("read(-1) = %ld, errno = %d\n", sys_result, sys_errno);
    printf("ft_read(-1) = %ld, errno = %d\n", ft_result, ft_errno);
    (sys_errno == ft_errno) ? testOK() : testKO();
		endTest(5);
}

void test_ft_write_errno() {
    char buffer[100];
    ssize_t result;
    
		headerTest("Ft_write ERRNO");

    // Test 1: Lecture normale (devrait réussir)
    printf("\nTest 1: Lecture normale\n");
    errno = 0;
    result = ft_write(STDIN_FILENO, buffer, 0);
    printf("ft_write(STDIN, buffer, 0) = %ld, errno = %d (%s)\n", 
           result, errno, strerror(errno));
		(errno == 0) ? testOK() : testKO();
		
    
    // Test 2: File descriptor invalide (devrait échouer avec EBADF)
    printf("\nTest 2: FD invalide (-1)\n");
    errno = 0;
    result = ft_write(-1, buffer, 10);
    printf("ft_write(-1, buffer, 10) = %ld, errno = %d (%s)\n", 
           result, errno, strerror(errno));
    printf("Attendu: errno = %d (EBADF)\n", EBADF);
		(errno == EBADF) ? testOK() : testKO();

    
    // Test 3: FD fermé (devrait échouer avec EBADF)
    printf("\nTest 3: FD fermé\n");
    errno = 0;
    result = ft_write(999, buffer, 10);
    printf("ft_write(999, buffer, 10) = %ld, errno = %d (%s)\n", 
           result, errno, strerror(errno));
    printf("Attendu: errno = %d (EBADF)\n", EBADF);
		(errno == EBADF) ? testOK() : testKO();

    
    // Test 4: Buffer NULL (devrait échouer avec EFAULT)
    printf("\nTest 4: Buffer NULL\n");
    errno = 0;
    result = ft_write(STDIN_FILENO, NULL, 10);
    printf("ft_write(STDIN, NULL, 10) = %ld, errno = %d (%s)\n", 
           result, errno, strerror(errno));
    printf("Attendu: errno = %d (EFAULT)\n", EFAULT);
		(errno == EFAULT) ? testOK() : testKO();

    
    // Test 5: Comparaison avec la vraie fonction write
    printf("\n=== Comparaison avec write() ===\n");
    
    // Test avec write() système
    errno = 0;
    ssize_t sys_result = write(-1, buffer, 10);
    int sys_errno = errno;
    
    // Test avec votre ft_write
    errno = 0;
    ssize_t ft_result = ft_write(-1, buffer, 10);
    int ft_errno = errno;
    
    printf("write(-1) = %ld, errno = %d\n", sys_result, sys_errno);
    printf("ft_write(-1) = %ld, errno = %d\n", ft_result, ft_errno);
    (sys_errno == ft_errno) ? testOK() : testKO();
		endTest(5);
}