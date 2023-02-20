etapa3: scanner.l parser.y asd.h
	bison -d parser.y
	flex scanner.l
	gcc -c lex.yy.c main.c asd.c parser.tab.c
	gcc -o etapa3 lex.yy.o main.o asd.c parser.tab.o -lfl