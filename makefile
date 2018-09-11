CXX=gcc
CFLAGS = -std=gnu11 -g -Wall -Wextra -Wmissing-declarations -Wmissing-prototypes -Werror-implicit-function-declaration -Wreturn-type -Wparentheses -Wunused -Wold-style-definition -Wundef -Wshadow -Wstrict-prototypes -Wswitch-default -Wunreachable-code

mpasswdsort: mpasswdsort.c  list.o
	${CXX} ${CFLAGS} mpasswdsort.c list.o -o mpasswdsort

list.o: list.c list.h
	 ${CXX} -c list.c

clean:
	rm -rf *o mpasswdsort.o
