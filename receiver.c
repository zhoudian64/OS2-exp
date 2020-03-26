#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main() {
	char buf[20];
	close(0);
	open("./mypipe.txt", O_RDWR);
	while(1) {
		scanf("%s",buf);
		printf("recive %s\n", buf);
	}
	return 0;
}
