#include <stdio.h>
#include <string.h>
unsigned long hashcode = 0x21DD09EC; //568134124 -> 1091790853 bytes
char str[5];
unsigned long check_password(const char* p){
	int* ip = (int*)p;
	int i;
	int res=0;
	for(i=0; i<5; i++){
		res += ip[i];
        printf("ip: %d\n", ip[i]);
        // printf("res: %d\n", res);
	}
    printf("res: %d\n", res);
	return res;
}

int main(int argc, char* argv[]){
	if(argc<2){
		printf("usage : %s [passcode]\n", argv[0]);
		return 0;
	}

    printf("Hashcode: %lu\n", hashcode);
	if(hashcode == check_password( argv[1] )){
		// setregid(getegid(), getegid());
		// system("/bin/cat flag");
        printf("RIGHT!");
		return 0;
	}
	else
		printf("wrong passcode.\n");
	return 0;
}