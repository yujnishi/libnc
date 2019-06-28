all:
	ctags -x --declarations -r '/^test_/' locale.c
	bash main.sh
	bash main.sh | gcc -x c -I../include -L../src -Wl,-rpath=../src - -lcunit -lnc
	./a.out
