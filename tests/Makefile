all:
	bash main.sh | gcc -x c -I../include -L../src -Wl,-rpath=../src - -lcunit -lnc
	./a.out