#include <stdio.h>
#include <fcntl.h>
extern ssize_t ft_read(int fd, void *buf, size_t count);

int main(void) {
	int fd = open("file.txt", O_RDWR);
	char buff[1024];
	int byteRead = ft_read(fd, buff, sizeof(buff));
	printf("Read from file -> %s", buff);
}