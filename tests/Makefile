all:
	bash main.sh
	bash main.sh | gcc -x c -I../include -L../src - -lcunit -lnc
	./a.out