#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>

int main() {
	char buf[20];
	int fd = open("./mypipe.txt", O_RDWR | O_CREAT, 0666);
	printf("fd = %d\n", fd);
	
	close(0);
	dup(fd);
	close(fd);

	while(1) {
		scanf("%s",buf);
		printf("receive %s\n", buf);
	}
	return 0;
}

