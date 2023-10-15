all: a.out

a.out: lex.yy.c y.tab.c
	g++ lex.yy.c y.tab.c -o a.out

y.tab.c: parser.y
	yacc -d parser.y

lex.yy.c: lexer.l parser.h
	lex lexer.l

clean:
	rm -f lex.yy.c y.tab.c a.out y.tab.h

