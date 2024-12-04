all: a.out
	./a.out < test.txt > output.txt
a.out: lex.yy.o y.tab.o
	g++ lex.yy.o y.tab.o -o a.out

y.tab.o: y.tab.c
	g++ -c y.tab.c

lex.yy.o: lex.yy.c y.tab.h
	g++ -c lex.yy.c

y.tab.c y.tab.h : parser.y
	yacc -r all -dtv parser.y

lex.yy.c: lexer.l parser.h
	flex  lexer.l

clean:
	rm -f *.yy.* *.out *.tab.* *.output ouptut.*

