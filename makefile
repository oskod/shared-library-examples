COMP = gcc
CFLAGS = 
LDFLAGS = -ldl

default: release

lib/:
	mkdir lib

lib: lib.c lib/
	$(COMP) lib.c \
	$(CFLAGS) $(LDFLAGS) \
	-O3 -s \
	-fPIC -shared \
	-o lib/libmylib.so

dist/:
	mkdir dist

release: lib dist/
	$(COMP) main.c \
	$(CFLAGS) $(LDFLAGS) \
	-O3 -s \
	-o dist/release