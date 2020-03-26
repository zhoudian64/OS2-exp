#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/file.h>
#include<fcntl.h>
#include<stdio.h>

int main() {
	int fd = open("./lock", O_RDONLY);
	for (int i = 0; ; ++i) {
		printf("Trying to lock file.\n");
		flock(fd, LOCK_EX);
		printf("file locked.\n");
		printf("i = %d\n", i);
		sleep(1);
		printf("Trying to unlock file.\n");
		flock(fd, LOCK_UN);
		printf("file unlocked.\n");
	}
	return 0;
}
