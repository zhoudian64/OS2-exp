#include<unistd.h>
#include<fcntl.h>

int main() {
	link("./link_example.c","./link_example2.c");
	return 0;
}
