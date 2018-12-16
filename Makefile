all:
	gmake -C src
	gmake -C tests

clean:
	gmake -C src clean
	gmake -C tests clean