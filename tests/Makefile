all:
	bash main.sh | gcc -x c -I../include -L../src -Wl,-rpath=../src - -lcunit -lnc -E
	./a.out