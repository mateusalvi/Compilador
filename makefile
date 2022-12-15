etapa1: scanner.l
	flex scanner.l
	gcc -c lex.yy.c main.c
	gcc -o etapa1 lex.yy.o main.o -lfl
clean:
	rm -rf etapa1
