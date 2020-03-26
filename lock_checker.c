#include<sys/types.h>
#include<sys/stat.h>
#include<sys/file.h>
#include<fcntl.h>
#include<stdio.h>

int main() {
	int fd = open("./lock", O_RDONLY);
	for (int i = 0; ; ++i) {
		flock(fd, LOCK_EX);
		printf("i = %d\n", i);
		flock(fd, LOCK_UN);
	}
	return 0;
}
