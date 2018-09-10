CXX=gcc
CFLAGS = -std=gnu11 -Wall -Wextra -Wmissing-declarations -Wmissing-prototypes -Werror-implicit-function-declaration -Wreturn-type -Wparentheses -Wunused -Wold-style-definition -Wundef -Wshadow -Wstrict-prototypes -Wswitch-default -Wunreachable-code
all:
	${CXX} ${CFLAGS} mpasswordsort.c list.c -o mpasswdsort.o



clean:
	rm -rf *o mpasswdsort.o
