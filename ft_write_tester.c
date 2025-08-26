#include <stdio.h>
#include <errno.h>

extern ssize_t ft_write(int fd, const void *buf, size_t count);


int main(void) {
	int count = ft_write(1, "coucouawawdawdawdawdawdawdadw", 29);
	printf(" counter = %d", count);
}