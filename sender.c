#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
// 实时上close()在unistd.h中
#include<unistd.h>
#include<stdio.h>

int main() {
	printf("\n");
	int i;
	close(1);
	open("./mypipe.txt", O_WRONLY | O_CREAT, 0666);
	for( i=0; ; i++) {
	// 由于pipe1 被关闭了所以都往下一个fd(open的文件)里写了
		printf("%d\n", i);
		sleep(1);
	}
	return 0;
}

