#include <stdlib.h>
#include <stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main(){

printf("UID: %d\n", getuid());
printf("EUID: %d\n", geteuid());
printf("__________________\n");
// Temporary privilege drop
seteuid(33);
printf("UID: %d\n", getuid());
printf("EUID: %d\n", geteuid());
printf("__________________\n");
seteuid(0);
printf("UID: %d\n", getuid());
printf("EUID: %d\n", geteuid());
printf("__________________\n");
// Permanent  privilege drop
setuid(33);
printf("UID: %d\n", getuid());
printf("EUID: %d\n", geteuid());
printf("__________________\n");
setuid(0);
printf("UID: %d\n", getuid());
printf("EUID: %d\n", geteuid());
return 0;
}