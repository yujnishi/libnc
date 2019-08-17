all:
	bash main.sh
	bash main.sh | gcc -o a.out -x c -I../include -L../src -Wl,-rpath=../src - -lcunit -lnc
	mkdir -p locale
	export PATH=$$PATH:../src ; LC_PATH=locale ./a.out

clean:
	rm -rf locale a.out CUnitAutomated-Results.xml
