#include<sys/types.h>
#include<sys/stat.h>
#include<sys/file.h>
#include<fcntl.h>
#include<stdio.h>

int main() {
	int fd = open ("./lock", O_RDONLY | O_CREAT, 0666);
	while (1) {
		getchar();
	// 非共享🔒
		flock(fd, LOCK_EX);
		printf("Lock!\n");
		getchar();
		flock(fd, LOCK_UN);
		printf("UnLock!\n");
	}
	return 0;
}
