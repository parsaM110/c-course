.PHONY:all clean install

# default
all: libarea.o main.o
	@gcc objs/*.o -o program
#put @ to echo instructs too

libarea.o:
	@mkdir -p objs
	@gcc -c libarea.c -o objs/libarea.o
	cd -

main.o:
	@mkdir -p objs
	@gcc -c main.c -o objs/main.o

clean:
	@rm -r objs

install:
	@echo "I am Installing"
	@cp program /usr/bin/program
