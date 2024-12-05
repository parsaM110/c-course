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

