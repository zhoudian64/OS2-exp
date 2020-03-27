#include<sys/types.h>
#include<dirent.h>
#include<stdio.h>
#include<unistd.h>

int main() {
	DIR *dir;
	struct dirent *entry;
	if ((dir = opendir("/")) == NULL)
		return 1;
	else {
		puts("files in / :");
		while((entry = readdir(dir)) != NULL)
			printf("	%s\n", entry->d_name);
		closedir(dir);
	}
	return 0;
}
