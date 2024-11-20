test: test.c
	gcc test.c string.c
	./a.out
# TODO add the array functionality to the library: sort, copy, clear,chop,etc
lib: string.c
	gcc string.c -c -o string.o 
	ar rcs libtrain.a string.o 	
	
