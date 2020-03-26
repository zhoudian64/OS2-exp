#include<sys/mman.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdio.h>

int main() {
	// U may use dprintf instead of trying to oreooreo fds.
	int fd = open("./data.bin", O_RDWR | O_CREAT, 0666);
	dprintf(fd, "%d\n",8);

	char *p = mmap(NULL, sizeof(char), PROT_READ, MAP_SHARED, fd, 0);
	while (1) {
		printf("%c\n", *p);
		sleep(1);
	}
	munmap(p, sizeof(int));
	close(fd);
	return 0;
}

