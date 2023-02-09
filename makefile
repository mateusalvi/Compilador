etapa2: scanner.l parser.y asd.c
	bison -v parser.y
	flex scanner.l
	gcc -c lex.yy.c main.c asd.c parser.tab.c
	gcc -o etapa2 lex.yy.o main.o asd.c parser.tab.o -lfl