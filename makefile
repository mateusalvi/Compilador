etapa4: scanner.l parser.y hash.h hash.c semantic.h semantic.c asd.h asd.c main.c
	bison -d parser.y
	flex scanner.l
	gcc -c -g lex.yy.c main.c hash.c semantic.c asd.c parser.tab.c
	gcc -o etapa4 lex.yy.o main.o hash.o semantic.o asd.o parser.tab.o -lfl