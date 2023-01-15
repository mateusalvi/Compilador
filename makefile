etapa1: scanner.l
	flex scanner.l
	gcc -c lex.yy.c main.c
	gcc -o etapa2 y.tab.o lex.yy.o hash.o main.o
clean:
	rm -rf etapa1