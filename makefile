etapa5: scanner.l parser.y hash.h hash.c asd.h asd.c main.c
	bison -d parser.y
	flex scanner.l
	gcc -c -g lex.yy.c main.c hash.c asd.c iloc.c stack.c parser.tab.c
	gcc -o etapa5 lex.yy.o main.o hash.o  asd.o iloc.o stack.o parser.tab.o -lfl