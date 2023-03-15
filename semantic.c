
//  #include <stdio.h>
// #include <stdlib.h>
//  #include <string.h>
//  #include "asd.h"
//  #include "semantic.h"

<<<<<<< HEAD
// enum tk_types{
// 	IDENTIFICADOR = 0,
// 	INT = 1,
// 	FLOAT = 2,
// 	BOOL = 3,
// 	CHAR = 4,
// 	PR_INT = 5,
// 	PR_FLOAT = 6,
// 	PR_BOOL = 7,
// 	PR_CHAR = 8,
// 	PR_IF = 9,
// 	PR_THEN = 10,
// 	PR_ELSE = 11,
// 	PR_WHILE = 12,
// 	PR_INPUT = 13,
// 	PR_OUTPUT = 14,
// 	PR_RETURN = 15,
// 	PR_FOR = 16,
// 	OC_LE = 17,
// 	OC_GE = 18,
// 	OC_EQ = 19,
// 	OC_NE = 20,
// 	OC_AND = 21,
// 	OC_OR = 22,
// 	SPECIAL_CHARACTER = 23,
// 	FUNCTION = 24,
// 	VARIABLE = 25,
// 	ARRAY = 26
// };

// void compare_type(value_t valor1, value_t valor2)
// {
// 	if(valor1.type == CHAR && valor2.type == INT)
// 		print_error(valor1.atLine, "Char", "Int", ERR_CHAR_TO_INT);
// 	if(valor1.type == CHAR && valor2.type == FLOAT)
// 		print_error(valor1.atLine, "Char", "Float", ERR_CHAR_TO_FLOAT);
// 	if(valor1.type == CHAR && valor2.type == BOOL)
// 		print_error(valor1.atLine, "Char", "Bool", ERR_CHAR_TO_BOOL);
// 	else
// 		return;
// }

// void check_vector_type()
// {
// 	return;
// }

// void check_function_variable(value_t value1, value_t value2)
// {
// 	if (value1.type == FUNCTION && (value2.type == VARIABLE || value2.type == ARRAY))
// 		return;
// }

// void print_error(int linhaDoErro, char* tipo1, char* tipo2, int error)
// {
// 	printf("Erro na linha %d, não é possível atribuir %s a uma variavel do tipo %s\n", linhaDoErro, tipo2, tipo1);
// 	exit(error);
// }
=======
>>>>>>> parent of 0475934 (Merge branch 'main' of https://github.com/mateusalvi/Compilador)

// /*
// int undeclared_err (value_t value1)
//  {
//  	while(i != -1 or ht_search == NULL;)
//  		ht_search(value1);
	
//  	return ERR_UNDECLARED;
//  }

//  int declared_err (value_t value1)
//  {
//  	while(i != -1 or ht_search == NULL;)
//  		ht_search(value1);
	
//  	return ERR_DECLARED;
//  }

//  int variable_err (value_t value1)
//  {
//  	return ERR_VARIABLE
//  }

//  int array_err (value_t value1)
//  {}

//  int function_err (value_t value1)
//  {}

//  int char_to_int_err (value_t value1, value_t value2)
//  {
//  	if(Ht_item1.type != Ht_item2.type)
// 		return ERR_CHAR_TO_INT;
	
//  }

// int char_to_float (value_t value1, value_t value2)
//  {
// 	if(Ht_item1.type != Ht_item2.type)
//  		return ERR_CHAR_TO_FLOAT;
//  }

//  int char_to_bool (value_t value1, value_t value2)
//  {
//  	if(Ht_item1.type != Ht_item2.type)
//  		return ERR_CHAR_TO_BOOL;
//  }

//  int char_vector (value_t value1, value_t value2)
//  {
//  	if(Ht_item1.type != Ht_item2.type)
//  		return ERR_CHAR_VECTOR;
//  }

//  int x_to_char (value_t value1, value_t value2)
//  {
//  	if(Ht_item1.type != Ht_item2.type)
//  		return ERR_X_TO_CHAR;
//  }
// */ 