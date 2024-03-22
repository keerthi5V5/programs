#include<stdio.h>
#include<unistd.h>
int main(){
	printf("ProcessID:%d\n",getpid());
	printf("ParentProcessID:%d\n",getpid());
	return 0;
}
