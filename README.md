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
some malwares know this
you should debugging by hardware not software like softICE

atomic means the statement got executed in one step
and there would be no race condition

general and static variables are in BSS and Data segment shared in whole program and not thread software
and each thread want to use or edit it 
so it is bad practice to use it

if I save password or license and dump the memory into hard
password is saved on hard

if you write firmware and have mmu the whole memory is used and no dyanmic static part 
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



