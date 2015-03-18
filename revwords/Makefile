all: revwords

revwords:revwords.c libhelpers.so
	gcc revwords.c -o revwords -L../lib/ -I../lib/ -lhelpers
libhelpers.so:
	make -C ../lib
clean:
	rm -rf revwords ../lib/libhelpers.so
