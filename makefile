etapa2: scanner.l parser.y
	bison -d parser.y
	flex scanner.l
	gcc -c lex.yy.c main.c parser.tab.c
	gcc -o etapa2 lex.yy.o main.o parser.tab.o -lfl