auto:
	gcc -c main.c -o bin/main.o -I./inc
	gcc -c -fPIC src/english.c -o bin/shared/english.o -I./inc 
	gcc -c -fPIC src/vietnam.c -o bin/shared/vietnam.o -I./inc 
shared:
	gcc -shared bin/shared/english.o bin/shared/vietnam.o -o bin/shared/libsum.so
link:
	gcc  bin/main.o -Lbin/shared -lsum -o bin/use-shared-lib
