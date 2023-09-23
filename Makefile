include:
	# Compile library and program using it together by using #include
	gcc exampleprog.c numformat.c -o exampleprog -lm
standalone:
	# Compile the all-in-one single-file program implementing and wrapping the library functions
	gcc standalone.c -o standalone -lm
lib:
	# Compile into a shared object (.so) library file to be linked to later
	gcc -c -o numformat.o numformat.c
	gcc -shared -l m -o libnumformat.so numformat.o
link:
	# Compile the program using numformat by linking to the existing library (run make lib first)
	gcc -B . -l numformat -o linkedexampleprog exampleprog.c
	# NOTE: Make sure library is in a directory in LD_LIBRARY_PATH before running!
clean:
	# Delete all build files and binaries
	rm -f *.o *.so standalone exampleprog linkedexampleprog
