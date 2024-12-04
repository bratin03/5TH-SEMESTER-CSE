#   - To compile and build the shared library and the main program:
#	> make

#   - To run the compiled program:
#   > make run

#   - To clean up generated files:
#   > make clean

# Compiler
CC = gcc

# Compiler flags
CFLAGS = -fPIC -c -I.   # Flags for compiling source files
LDFLAGS = -shared       # Flags for linking to create a shared library

# Default target: build the library and the main program
all: library a.out

# Target to build the shared library
library: libass2_21CS10016.so

# Linking to create the shared library
libass2_21CS10016.so: ass2_21CS10016.o
	$(CC) $(LDFLAGS) -o $@ $^  

# Compiling source files to object files
ass2_21CS10016.o: ass2_21CS10016.c myl.h
	$(CC) $(CFLAGS) -o $@ $<  


# Target to build the main program
# Linking the main program
a.out: library
	$(CC) -I. -L. -Wl,-rpath=. main.c -o a.out -lass2_21CS10016  

# Target to run the compiled program
run: a.out
	./a.out

# Target to clean up generated files
clean:
	rm -f *.o libass2_21CS10016.so a.out
