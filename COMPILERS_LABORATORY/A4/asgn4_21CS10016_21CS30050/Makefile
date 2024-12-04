# Compile and run the parser on the input file and redirect the output to a text file

asgn4_21CS10016_21CS30050_output.txt: parser asgn4_21CS10016_21CS30050_test.c
	./parser < asgn4_21CS10016_21CS30050_test.c > asgn4_21CS10016_21CS30050_output.txt
	cat asgn4_21CS10016_21CS30050_output.txt

# Link the parser program from object files

parser: lex.yy.o y.tab.o asgn4_21CS10016_21CS30050.o
	gcc lex.yy.o y.tab.o asgn4_21CS10016_21CS30050.o -lfl -o parser

# Compile the main C program file to an object file

asgn4_21CS10016_21CS30050.o: asgn4_21CS10016_21CS30050.c
	gcc -c asgn4_21CS10016_21CS30050.c

# Compile the lex.yy.c file to an object file

lex.yy.o: lex.yy.c
	gcc -c lex.yy.c

# Compile the y.tab.c file to an object file

y.tab.o: y.tab.c
	gcc -c y.tab.c

# Generate lex.yy.c from the lex file and y.tab.c and y.tab.h from the yacc file

lex.yy.c: asgn4_21CS10016_21CS30050.l y.tab.h
	flex asgn4_21CS10016_21CS30050.l

# Generate y.tab.c and y.tab.h from the yacc file

y.tab.c y.tab.h: asgn4_21CS10016_21CS30050.y
	bison -dty --report=all asgn4_21CS10016_21CS30050.y

# Clean up object files, executable, and generated files

clean:
	rm -f parser *.o *.txt lex.yy.* y.tab.* y.output