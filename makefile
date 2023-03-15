etapa4: scanner.l parser.y hash.h hash.c s asd.h asd.c main.c
	bison -d parser.y
	flex scanner.l
	gcc -c -g lex.yy.c main.c hash.c asd.c parser.tab.c
	gcc -o etapa4 lex.yy.o main.o hash.o  asd.o parser.tab.o -lfl