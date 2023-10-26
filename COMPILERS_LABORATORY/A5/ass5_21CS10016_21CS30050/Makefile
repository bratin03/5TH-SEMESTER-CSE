# Assignment Number 5
# 
# Student Information:
# - Bratin Mondal (Roll Number - 21CS10016)
# - Somya Kumar (Roll Number - 21CS30050)


# This Makefile is used to compile and test the 'a.out' program.

# Compile and run the program for all test cases
test: a.out
	@echo "Starting TestCases"
	@echo "Testcase 1"
	./a.out < Input/ass5_21CS10016_21CS30050_test_1.c > Output/ass5_21CS10016_21CS30050_quads1.out
	@echo "Testcase 2"
	./a.out < Input/ass5_21CS10016_21CS30050_test_2.c > Output/ass5_21CS10016_21CS30050_quads2.out
	@echo "Testcase 3"
	./a.out < Input/ass5_21CS10016_21CS30050_test_3.c > Output/ass5_21CS10016_21CS30050_quads3.out
	@echo "Testcase 4"
	./a.out < Input/ass5_21CS10016_21CS30050_test_4.c > Output/ass5_21CS10016_21CS30050_quads4.out
	@echo "Testcase 5"
	./a.out < Input/ass5_21CS10016_21CS30050_test_5.c > Output/ass5_21CS10016_21CS30050_quads5.out
	@echo "Testcase 6"
	./a.out < Input/ass5_21CS10016_21CS30050_test_6.c > Output/ass5_21CS10016_21CS30050_quads6.out
	@echo "Testcase 7"
	./a.out < Input/ass5_21CS10016_21CS30050_test_7.c > Output/ass5_21CS10016_21CS30050_quads7.out
	@echo "Testcase 8"
	./a.out < Input/ass5_21CS10016_21CS30050_test_8.c > Output/ass5_21CS10016_21CS30050_quads8.out
	@echo "Testcase 9"
	./a.out < Input/ass5_21CS10016_21CS30050_test_9.c > Output/ass5_21CS10016_21CS30050_quads9.out
	@echo "Testcase 10"
	./a.out < Input/ass5_21CS10016_21CS30050_test_10.c > Output/ass5_21CS10016_21CS30050_quads10.out
	@echo "Testing Completed"

# Target to test individual test cases
testcase1: test
	cat Output/ass5_21CS10016_21CS30050_quads1.out
testcase2: test
	cat Output/ass5_21CS10016_21CS30050_quads2.out
testcase3: test
	cat Output/ass5_21CS10016_21CS30050_quads3.out
testcase4: test
	cat Output/ass5_21CS10016_21CS30050_quads4.out
testcase5: test
	cat Output/ass5_21CS10016_21CS30050_quads5.out
testcase6: test
	cat Output/ass5_21CS10016_21CS30050_quads6.out
testcase7: test
	cat Output/ass5_21CS10016_21CS30050_quads7.out
testcase8: test
	cat Output/ass5_21CS10016_21CS30050_quads8.out
testcase9: test
	cat Output/ass5_21CS10016_21CS30050_quads9.out
testcase10: test
	cat Output/ass5_21CS10016_21CS30050_quads10.out

# Compile the main program 'a.out' using lex and bison
a.out: lex.yy.o ass5_21CS10016_21CS30050.tab.o ass5_21CS10016_21CS30050_translator.o
	g++ lex.yy.o ass5_21CS10016_21CS30050.tab.o ass5_21CS10016_21CS30050_translator.o -lfl

# Compile the translator
ass5_21CS10016_21CS30050_translator.o: ass5_21CS10016_21CS30050_translator.cxx ass5_21CS10016_21CS30050_translator.h
	g++ -c ass5_21CS10016_21CS30050_translator.cxx

# Compile the lexer
lex.yy.o: lex.yy.c
	g++ -c lex.yy.c

# Compile the parser
ass5_21CS10016_21CS30050.tab.o: ass5_21CS10016_21CS30050.tab.c
	g++ -c ass5_21CS10016_21CS30050.tab.c

# Generate lexer code
lex.yy.c: ass5_21CS10016_21CS30050.l ass5_21CS10016_21CS30050.tab.h ass5_21CS10016_21CS30050_translator.h
	flex ass5_21CS10016_21CS30050.l

# Generate parser code and header file
ass5_21CS10016_21CS30050.tab.c ass5_21CS10016_21CS30050.tab.h: ass5_21CS10016_21CS30050.y
	bison -dv ass5_21CS10016_21CS30050.y -W

# Clean the generated files
clean:
	rm -f *.yy.* *.o *.tab.* *.out *.output
