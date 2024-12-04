a.out: lex.yy.o y.tab.o
	gcc lex.yy.o y.tab.o
	./a.out < input.txt > output.txt

lex.yy.o: lex.yy.c y.tab.h
	gcc -c lex.yy.c
y.tab.o: y.tab.c
	gcc -c y.tab.c
lex.yy.c: calc_lex.l
	flex calc_lex.l
y.tab.c y.tab.h : calc_parse.y
	yacc -dtv calc_parse.y

clean :
	rm -f *.yy.* *.tab.* *.o *.out output.* *.output