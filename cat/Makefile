all: cat

cat:cat.c libhelpers.so
	gcc cat.c -o cat -L../lib/ -I../lib/ -lhelpers
libhelpers.so:
	make -C ../lib
clean:
	rm -rf cat 
