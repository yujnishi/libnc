all:
	bash main.sh
	bash main.sh | gcc -g -o a.out -x c -I../include -L../src -Wl,-rpath=../src - -lcunit -lnc
	rm -rf locale
	mkdir -p locale
	export PATH=$$PATH:../src ; LC_PATH=locale ./a.out

clean:
	rm -rf locale a.out CUnitAutomated-Results.xml
