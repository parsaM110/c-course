# Running 
compile 
```
gcc test.c -o test
```
run
```
./test
```
show previous Status code
```
echo $?
```
see the status Code of others by :
```
man ls
```
environment variable

- %PATH%

- $PATH

show paths 
```
>echo $PATH
/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin:/snap/bin
```
show path of a command
```
which ls
where ls
whereis ls
```
bash code to make one core occupied
```
while true; do :; done
```
show cpu info:
```
lscpu
```
show the cpu current speed
```
sudo dmidecode -t processor | grep -i 'current speed'
	Current Speed: 2700 MHz
```
show maximum cpu freq (my ubuntu 2204 doesn't show it though maybe it is because I am running on VM)
```
lscpu | grep Mhz
```
show cpu info (/proc doesn't exist it is vfs (virtual file system ))[user space can talk with kernel space through vfs]:
```
cat /proc/cpuinfo
```
get cpu live freq Mhz by
```
cat /proc/cpuinfo| grep MHz
```
there is also this folder which shows each cpu as filesystem:
```
 ls /sys/devices/system/cpu/
cpu0  cpu1  cpufreq  cpuidle  hotplug  isolated  kernel_max  modalias  offline  online  possible  power  present  smt  uevent  vulnerabilities
```
not cpu intensive anymore:
```
while true; do sleep 0.1; done  
```
create delay in constant freq cpus:
```
while(1);
```
all syscalls are IO intensive(every job except cpu computation is IO intensive)
- read from RAM
- read from HARD DRIVE
- read 1024 byte from network Card

all time sharing machines are not reliable (SDS 940 first one| Charlieplex Trick) you should use RTOS.

RTOS guarantee that each tasks is done in exact time.

you can do `cpu pinning`.

Async - Non Blocking programming vs try and catch ??? :

send the data don't stop
go to next job there if it was okay it is okay if not abort

give a specified time to a task
abort later come back to it
if it is important don't give it just 20ns give it 50ns

Timeout programming

in RTOS give your tasks specified time not automatic anymore, you manage it yourself

do the time sharing software is like async/await


not fist this and then that 
do the jobs in between of each other

so we can't check the button each time
event-oriented-programming (interrupt):
cpu must support it though
it is hardware approach you connect to hardware 


in software you can do it with `iNotify` whenever changes 
`tail` command works like this

polling is also another way instead of occupying cpu with a infinite loop

every cpu have for example in x86 it only have 3 interrupt(hardware)

in assembly by int 
int 03 means debug = stop and give me the control


gdb uses exactly this for debugging 
so the code is changed
some malware know this
you should debugging by hardware not software like softICE

atomic means the statement got executed in one step
and there would be no race condition

general and static variables are in BSS and Data segment shared in whole program and not thread software
and each thread want to use or edit it 
so it is bad practice to use it

if I save password or license and dump the memory into hard
password is saved on hard

if you write firmware and have mmu the whole memory is used and no dynamic static part 
the whole memory is yours no os no paging
and sectioning it is by compiler

in firmware the whole memory is yours for compiler
in os virtual memory is used

.exe file on hard is binary image file

stack overflow + payload = shell code
cause the app unintentionally be executed

stack overflow is now detected by some methods
for example there is a signature between heap and stack, if overflow happens the signature is changed, os detect kill the app
overflow and segmentation fault is made by os
firmware's are more prone to these attacks

create assembly of c code:
```
gcc -S test.c -o test.s
```
embed src file with excusable and no optimization just my code:
```
gcc -g test.c -o test
```
so for instance"
```
~/test$ gcc -g test.c
~/test$ ls
a.out  README.md  test  test.c  test.s
~/test$ ll a.out
-rwxrwxr-x 1 ubuntu ubuntu 17192 Dec  5 06:06 a.out*
```
```
gdb -tui a.out
ni (next assembly)
step 
next (step over function)
layout split
b 4
```
or 
```
gcc -g test.c test
gdb -tui ./test
```
RAM (memory) paging
doesn't get the reason of need to virtual memory
swap -> ram is full the less used app is moved to hard to free up some space


stack is memory which automatic and compiler create 
all local variables in functions are in stack and when function ends they are freed


heap is memory which is free and is for programmers

stack is like lost in wikipedia 
you go more and more like the code I have give for functions that are having inside calls

in heap you may not free memory
and it stays in memory (memory leaks)

some design patters says using heap is prohibited like NASA

memory profiler :
valgrind shows memory leak

java and python use garbage collector for memory leak

rust uses ownership for memory leak


## Storage Class
- Auto
	- Local (Stack)
	- Global (BSS, DS)
- Manual
	- Heap
auto, static, global, extern, const, ...

300 :
- [000000001][001011100] -> Big Endian (still File format, Protocol)
- [001011100][000000001] -> Little Endian (intel)

	IP is Big Endian -> cisco, microtik
	microtik : mips be (big endian) [old]
	sdn (software defined network) and now run linux [new]

C Data Types :

- Numbers
	- char, int, float, double, pointer, void
- Aggregator 
	- struct, union, enum, array

Modifiers :
```
short 
long 
long long
signed: 2's compliment
unsigned
```

64 bit system default :
```
int a; == signed long int a;
```
SMP means symmetric multi processing
```
uname -a
Linux ubuntu-2204 6.8.0-49-generic #49~22.04.1-Ubuntu SMP PREEMPT_DYNAMIC Wed Nov  6 17:42:15 UTC 2 x86_64 x86_64 x86_64 GNU/Linux
```

short char : 1 Byte

300 -> 100101100

1[00101100] -> 44

```
./test
100
44
*** stack smashing detected ***: terminated
Aborted (core dumped)
```

linux root id is 0
```
 id root
uid=0(root) gid=0(root) groups=0(root)
```

linux first user start from 1000
```
id ubuntu
uid=1000(ubuntu) gid=1000(ubuntu) groups=1000(ubuntu),4(adm),24(cdrom),27(sudo),30(dip),46(plugdev),122(lpadmin),134(lxd),135(sambashare)
```
for compiling the code only with declaration:
```
gcc  -g -c test.c -o test
```
without -c you will get error for test function
but the binary output can't be executed 
because it only make object file not linking stage
in linking stage compiler check the body and gives you error for not defining the function

C is Forward Declarative lang

default initialization (declaration and definition):
```c
int data;
int a,b,c;
```
declaration and definition and initialization:
```c
int data = 10;
int a=1,b=2,c;
int data;  // is also define (memory allocation is done)
```

variables can become garbage if stored in heap or stack | not in global or BSS

Storage class says where & when something in class is going to live:
- Storage
- Initial : initial value
- Scope : where we can see the variable (.eg we can see it only in main function)
- Lifetime : when did it wake up and we it dies


Storage Class:
- Auto ->  Stack, everything stored in Stack is initialed as Garbage(everything was there become initial value, C doesn't make it 0), Block, Block(auto in cpp means auto detect variable type)
- Extern -> Data Segment/BSS(are part of binary image of program) , your initial value or 0, Global, Start2End
- Static -> DS/BSS , 0 , Global->G/L->Block, Start2End
- Register -> CPU, Garbage, Block, Block
- Dynamic memory initialization (Heap) -> no storage class | no lifetime | no visibility -> everything is manual(c doing nothing)
> Static for global is used for sharing data in multi thread(it makes race condition | you should use Mutex or Semaphore)

-  External used in library and module development
- best to avoid static and external variables  because data is stored is DS(data segment) binary size become big and causes race condition and cause security issues | but good in speed 

- Auto var when {} closed data is removed and we got no memory leaks
- Register used for speed concerns
- don't communicate using data, use data in communication (don't allocate a part of RAM to a memory and tell all to go and work with here, instead we take a part of RAM and passes to those who needs it)(don't memory share use communication (message queue, ipc, socket) and if you need to share in 2 thread, use partitioning )
- for example in matrix multiplication (use half part for one and the other for the next and then sum it up| it is hard? yes! implementation is effing hard)
- `volatile` a variable : don't let compiler optimize the variable and change it(used in embedded system | graphic memory is a memory mapper, it is volatile, hardware is managing it, don't touch it, software is only using it)
- we don't have function signature in c, we have in cpp for methods in class
## main factions

- microsoft have no return value so many write `void main(){}`
- in writing firmware we don't have return value we have a `while(1){}` if it ends the cpu is halted and nothing happen and you have to restart.

### some registry
- eax, ebx, ecx, edx, edi, esi general purpose registers
- we have copying for all values
- in cpp we have `passbyrefrence`, in c we don't
- in c we have `passbyvalue` and `passbypointer`

### math operation in c 
- \+
- \-
- \*
- /
- % 
- &
- | 
- ^
- ~
- \>>
- <<

### add = to operation
- `a \= 2` means make a in half
- `a &= 2` make a bitwise and with 2 
- `=` has answers so `a=b=11` is valid c but it doesn't have answer in python
- we have no boolean in c so 0-> false, everything else -> true in if or while

### expressions  
- function call , if are expressions not statement -> by ; we  make statement
- you can convert couple of statement into one expression by {} block
- in gcc4 this doesn't work `if(a==20){}` and you should write `if(a=20){}`

### while & for
- `while(1);` is used to put micro on working (used in firmware)
- `do{}while(...)` is useful for  reading input 
- `for(init;cond;update)` in `for` first expression is executed ones and then never and last also executed after successful cond
- for(;;); //-> while(1);

in C99+ you can do this : `for(int i=0; i<0; i=i+1){}` it is better than 
```c
int b=0;
for(;b<10;b=b+1){}
``` 
because i in first case is destroyed but in first case loop var is leaked(this is the reason of cpp update in linux kernel)
- continue: in for says go to next iteration
- break: cancel whole thing
- switch case only works for digits and proper number and is faster than if because of asm implementation(it create map of real number)
```c
switch(a){
	case 1:
		...
	case 2:
		...
	case 3:
		...
	default:
		...
}
```
and if a was equal 2 it  jumps to `case 2` then it goes to `case 3` and until end, so if you should use break after each case if you want each scope code be for each case