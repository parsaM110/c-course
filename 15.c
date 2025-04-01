#include <stdlib.h>
#include <stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main(){

printf("UID: %d\n", getuid());
printf("EUID: %d\n", geteuid());
seteuid(33);
printf("UID: %d\n", getuid());
printf("EUID: %d\n", geteuid());
return 0;
}