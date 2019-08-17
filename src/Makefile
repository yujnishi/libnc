OS=${shell uname -o}
SRCS=${wildcard *.c}

ifeq ($(OS),Cygwin)
target=nc.dll
else
target=libnc.so
endif

all:
	gcc -I../include -shared -fPIC -o $(target) $(SRCS)

clean:
	rm -f $(target)

