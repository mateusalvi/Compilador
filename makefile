etapa4: scanner.l parser.y asd.h asd.c main.c hash.h hash.c stack.h stack.c semantic.h semantic.c
	bison -d parser.y
	flex scanner.l
	gcc -c -g lex.yy.c main.c stack.c hash.c  semantic.c asd.c parser.tab.c
	gcc -o etapa4 lex.yy.o main.o asd.c hash.c stack.c semantic.c parser.tab.o -lfl