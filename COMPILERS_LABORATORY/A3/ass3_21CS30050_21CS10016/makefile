ass3_21CS30050_21CS10016_output.txt: analyzer ass3_21CS30050_21CS10016_test.c
	./analyzer < ass3_21CS30050_21CS10016_test.c > ass3_21CS30050_21CS10016_output.txt
	cat ass3_21CS30050_21CS10016_output.txt
	
analyzer: lex.yy.c
	gcc lex.yy.c -lfl -o analyzer

lex.yy.c: ass3_21CS30050_21CS10016.l
	flex ass3_21CS30050_21CS10016.l ass3_21CS30050_21CS10016.c

clean:
	rm -f analyzer lex.yy.c ass3_21CS30050_21CS10016_output.txt