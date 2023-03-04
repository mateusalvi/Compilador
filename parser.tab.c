/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1





# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "parser.y"

	
#define YYDEBUG 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "asd.h"
int yylex();
int yyerror (char *s);
extern int yydebug;
extern int get_line_number();
extern void *arvore;

#line 126 "parser.tab.c"

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    TK_PR_INT = 258,
    TK_PR_FLOAT = 259,
    TK_PR_BOOL = 260,
    TK_PR_CHAR = 261,
    TK_PR_IF = 262,
    TK_PR_THEN = 263,
    TK_PR_ELSE = 264,
    TK_PR_WHILE = 265,
    TK_PR_INPUT = 266,
    TK_PR_OUTPUT = 267,
    TK_PR_RETURN = 268,
    TK_PR_FOR = 269,
    TK_OC_LE = 270,
    TK_OC_GE = 271,
    TK_OC_EQ = 272,
    TK_OC_NE = 273,
    TK_OC_AND = 274,
    TK_OC_OR = 275,
    TK_LIT_INT = 276,
    TK_LIT_FLOAT = 277,
    TK_LIT_FALSE = 278,
    TK_LIT_TRUE = 279,
    TK_LIT_CHAR = 280,
    TK_IDENTIFICADOR = 281,
    TK_ERRO = 282
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 17 "parser.y"

	value_t valor_lexico;
	asd_tree_t *tree;

#line 170 "parser.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   177

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  32
/* YYNRULES -- Number of rules.  */
#define YYNRULES  83
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  150

#define YYUNDEFTOK  2
#define YYMAXUTOK   282


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    45,     2,     2,     2,    44,     2,     2,
      33,    34,    42,    40,    29,    41,     2,    43,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    28,
      39,    37,    38,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    30,     2,    31,    32,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    35,     2,    36,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   114,   114,   117,   118,   121,   122,   125,   127,   128,
     129,   130,   133,   134,   135,   136,   139,   140,   141,   142,
     145,   146,   149,   150,   153,   154,   155,   156,   157,   160,
     161,   164,   165,   168,   171,   172,   175,   176,   178,   179,
     180,   181,   182,   183,   186,   187,   188,   191,   192,   193,
     196,   199,   200,   203,   206,   209,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   237,   238
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "TK_PR_INT", "TK_PR_FLOAT", "TK_PR_BOOL",
  "TK_PR_CHAR", "TK_PR_IF", "TK_PR_THEN", "TK_PR_ELSE", "TK_PR_WHILE",
  "TK_PR_INPUT", "TK_PR_OUTPUT", "TK_PR_RETURN", "TK_PR_FOR", "TK_OC_LE",
  "TK_OC_GE", "TK_OC_EQ", "TK_OC_NE", "TK_OC_AND", "TK_OC_OR",
  "TK_LIT_INT", "TK_LIT_FLOAT", "TK_LIT_FALSE", "TK_LIT_TRUE",
  "TK_LIT_CHAR", "TK_IDENTIFICADOR", "TK_ERRO", "';'", "','", "'['", "']'",
  "'^'", "'('", "')'", "'{'", "'}'", "'='", "'>'", "'<'", "'+'", "'-'",
  "'*'", "'/'", "'%'", "'!'", "$accept", "Program", "DecList", "Dec",
  "DecLocal", "VarListLocal", "Type", "VarList", "ArrayDim", "ArrayDimEnd",
  "Lit", "Func", "ParamList", "Param", "Block", "CommandList", "Command",
  "Atrib", "Flow", "Ret", "FuncCall", "ID", "FuncCallID", "Expr", "T", "F",
  "G", "I", "J", "K", "L", "ExprList", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,    59,    44,
      91,    93,    94,    40,    41,   123,   125,    61,    62,    60,
      43,    45,    42,    47,    37,    33
};
# endif

#define YYPACT_NINF (-102)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-55)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      67,  -102,  -102,  -102,  -102,    30,  -102,    67,    42,  -102,
    -102,  -102,    56,  -102,    53,  -102,    42,   115,    17,  -102,
      28,  -102,  -102,  -102,  -102,  -102,    48,   115,    78,    78,
      75,  -102,  -102,    62,    64,   -14,    94,    46,    -1,    54,
      66,  -102,  -102,    80,    42,    85,    92,    -3,  -102,  -102,
     103,   115,   101,   115,   115,   115,   115,   115,   115,   115,
     115,   115,   115,   115,   115,   115,   115,     6,  -102,  -102,
      80,    67,  -102,    42,   116,  -102,     4,   119,    94,  -102,
      35,    46,    -1,    -1,    54,    54,    54,    54,    66,    66,
    -102,  -102,  -102,   121,   122,   115,  -102,  -102,    42,  -102,
     125,   129,  -102,  -102,  -102,  -102,    24,  -102,  -102,  -102,
    -102,   115,  -102,   115,   115,   115,   138,  -102,    10,  -102,
      40,   115,   115,  -102,  -102,    14,    15,    55,    42,  -102,
     128,   132,   138,   155,    80,   135,  -102,   130,   115,    80,
    -102,    42,   115,   134,   157,  -102,   138,   140,    80,  -102
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    12,    13,    14,    15,     0,     2,     4,     0,     1,
       3,    53,     0,     6,    17,     5,     0,     0,     0,    16,
      17,    24,    25,    26,    27,    28,    53,     0,     0,     0,
       0,    81,    78,    80,     0,    21,    56,    58,    61,    66,
      69,    73,    76,     0,     0,     0,    32,     0,    74,    75,
      19,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    29,    33,
       0,     0,    77,     0,     0,    52,    83,     0,    55,    20,
      23,    57,    59,    60,    62,    63,    64,    65,    67,    68,
      70,    71,    72,     0,     0,     0,    35,    39,     0,    43,
       0,     0,    40,    38,    41,    42,     0,    30,    31,    18,
      79,     0,    51,     0,     0,     0,    50,     7,    11,    34,
      37,     0,     0,    82,    22,     0,     0,     0,     0,    36,
       0,    80,    44,     0,     0,    10,     8,     0,     0,     0,
      47,     0,     0,     0,    48,     9,    45,    79,     0,    49
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -102,  -102,   162,  -102,  -102,  -101,   -15,   -11,   -47,    57,
      44,  -102,   102,  -102,   -41,    52,  -102,  -102,  -102,  -102,
     -60,    -8,  -102,   -26,   124,   120,    61,    70,    87,    79,
     123,    63
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     5,     6,     7,    97,   117,     8,    12,    30,    79,
      31,    13,    45,    46,    99,   100,   101,   102,   103,   104,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    77
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      14,    47,    68,    44,    74,    19,    53,   105,    20,     1,
       2,     3,     4,    93,    58,    59,    94,    53,    54,    95,
       1,     2,     3,     4,    53,   127,    76,   136,    80,   107,
       9,    72,    26,   111,    53,    53,    69,    60,    61,   128,
     145,    67,    96,     1,     2,     3,     4,    93,   133,   134,
      94,    43,    98,    95,   121,    53,    44,    16,    17,   106,
     105,   122,   109,    56,    57,    20,    26,   113,    11,   116,
       1,     2,     3,     4,   130,    67,    21,    22,    23,    24,
      25,   -54,    16,    17,    15,    76,    18,    80,   125,   126,
     118,   143,    51,   140,    62,    63,   132,    52,   144,    21,
      22,    23,    24,    25,    26,    98,    50,   149,    64,    65,
      66,    27,   106,    55,   131,    67,   146,    82,    83,    70,
     118,    71,    21,    22,    23,    24,    25,    26,    84,    85,
      86,    87,    73,   118,    27,    75,    21,    22,    23,    24,
      25,    26,    28,    90,    91,    92,    29,   110,    27,    88,
      89,    48,    49,   112,   114,   115,    28,   120,    53,   137,
      29,   119,   138,   139,   141,   147,   148,   142,   -46,    10,
     124,   135,   129,   108,   123,    81,     0,    78
};

static const yytype_int16 yycheck[] =
{
       8,    27,    43,    18,    51,    16,    20,    67,    16,     3,
       4,     5,     6,     7,    15,    16,    10,    20,    32,    13,
       3,     4,     5,     6,    20,    15,    52,   128,    54,    70,
       0,    34,    26,    29,    20,    20,    44,    38,    39,    29,
     141,    35,    36,     3,     4,     5,     6,     7,    34,    34,
      10,    34,    67,    13,    30,    20,    71,    29,    30,    67,
     120,    37,    73,    17,    18,    73,    26,    32,    26,    95,
       3,     4,     5,     6,   121,    35,    21,    22,    23,    24,
      25,    33,    29,    30,    28,   111,    33,   113,   114,   115,
      98,   138,    30,   134,    40,    41,   122,    33,   139,    21,
      22,    23,    24,    25,    26,   120,    31,   148,    42,    43,
      44,    33,   120,    19,   122,    35,   142,    56,    57,    34,
     128,    29,    21,    22,    23,    24,    25,    26,    58,    59,
      60,    61,    29,   141,    33,    34,    21,    22,    23,    24,
      25,    26,    41,    64,    65,    66,    45,    31,    33,    62,
      63,    28,    29,    34,    33,    33,    41,    28,    20,    31,
      45,    36,    30,     8,    29,    31,     9,    37,    28,     7,
     113,   127,   120,    71,   111,    55,    -1,    53
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,    47,    48,    49,    52,     0,
      48,    26,    53,    57,    67,    28,    29,    30,    33,    53,
      67,    21,    22,    23,    24,    25,    26,    33,    41,    45,
      54,    56,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    34,    52,    58,    59,    69,    76,    76,
      31,    30,    33,    20,    32,    19,    17,    18,    15,    16,
      38,    39,    40,    41,    42,    43,    44,    35,    60,    67,
      34,    29,    34,    29,    54,    34,    69,    77,    70,    55,
      69,    71,    72,    72,    73,    73,    73,    73,    74,    74,
      75,    75,    75,     7,    10,    13,    36,    50,    52,    60,
      61,    62,    63,    64,    65,    66,    67,    60,    58,    53,
      31,    29,    34,    32,    33,    33,    69,    51,    67,    36,
      28,    30,    37,    77,    55,    69,    69,    15,    29,    61,
      54,    67,    69,    34,    34,    56,    51,    31,    30,     8,
      60,    29,    37,    54,    60,    51,    69,    31,     9,    60
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    48,    48,    49,    49,    50,    51,    51,
      51,    51,    52,    52,    52,    52,    53,    53,    53,    53,
      54,    54,    55,    55,    56,    56,    56,    56,    56,    57,
      57,    58,    58,    59,    60,    60,    61,    61,    62,    62,
      62,    62,    62,    62,    63,    63,    63,    64,    64,    64,
      65,    66,    66,    67,    68,    69,    69,    70,    70,    71,
      71,    71,    72,    72,    72,    72,    72,    73,    73,    73,
      74,    74,    74,    74,    75,    75,    75,    76,    76,    76,
      76,    76,    77,    77
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     3,     2,     2,     3,     5,
       3,     1,     1,     1,     1,     1,     3,     1,     6,     4,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     4,
       5,     3,     1,     2,     3,     2,     3,     2,     1,     1,
       1,     1,     1,     1,     3,     6,     6,     5,     6,     8,
       2,     4,     3,     1,     1,     3,     1,     3,     1,     3,
       3,     1,     3,     3,     3,     3,     1,     3,     3,     1,
       3,     3,     3,     1,     2,     2,     1,     3,     1,     4,
       1,     1,     3,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 114 "parser.y"
                  { arvore = (void*)(yyval.tree); (yyval.tree) = (yyvsp[0].tree); }
#line 1455 "parser.tab.c"
    break;

  case 3:
#line 117 "parser.y"
                      {  (yyval.tree) = (yyvsp[-1].tree); asd_add_child((yyval.tree),(yyvsp[0].tree)); }
#line 1461 "parser.tab.c"
    break;

  case 4:
#line 118 "parser.y"
              { (yyval.tree) = (yyvsp[0].tree); }
#line 1467 "parser.tab.c"
    break;

  case 5:
#line 121 "parser.y"
                       { if((yyvsp[-1].tree)){ (yyval.tree) = (yyvsp[-1].tree); } }
#line 1473 "parser.tab.c"
    break;

  case 6:
#line 122 "parser.y"
                { (yyval.tree) = (yyvsp[0].tree); }
#line 1479 "parser.tab.c"
    break;

  case 7:
#line 125 "parser.y"
                            { if((yyvsp[0].tree)){ (yyval.tree) = (yyvsp[0].tree); } }
#line 1485 "parser.tab.c"
    break;

  case 8:
#line 127 "parser.y"
                                   { (yyval.tree) = (yyvsp[0].tree); }
#line 1491 "parser.tab.c"
    break;

  case 9:
#line 128 "parser.y"
                                           { (yyval.tree) = asd_new("<="); asd_add_child((yyval.tree), (yyvsp[-4].tree)); asd_add_child((yyval.tree), (yyvsp[-2].tree)); asd_add_child((yyval.tree), (yyvsp[0].tree)); }
#line 1497 "parser.tab.c"
    break;

  case 10:
#line 129 "parser.y"
                                  { (yyval.tree) = asd_new("<="); asd_add_child((yyval.tree), (yyvsp[-2].tree)); asd_add_child((yyval.tree), (yyvsp[0].tree)); }
#line 1503 "parser.tab.c"
    break;

  case 11:
#line 130 "parser.y"
                     { (yyval.tree) = NULL; }
#line 1509 "parser.tab.c"
    break;

  case 12:
#line 133 "parser.y"
                 { (yyval.tree) = asd_new(create_leaf((yyvsp[0].valor_lexico))); asd_free_node((yyval.tree)); }
#line 1515 "parser.tab.c"
    break;

  case 13:
#line 134 "parser.y"
                      { (yyval.tree) = asd_new(create_leaf((yyvsp[0].valor_lexico))); asd_free_node((yyval.tree)); }
#line 1521 "parser.tab.c"
    break;

  case 14:
#line 135 "parser.y"
                     { (yyval.tree) = asd_new(create_leaf((yyvsp[0].valor_lexico))); asd_free_node((yyval.tree)); }
#line 1527 "parser.tab.c"
    break;

  case 15:
#line 136 "parser.y"
                     { (yyval.tree) = asd_new(create_leaf((yyvsp[0].valor_lexico))); asd_free_node((yyval.tree)); }
#line 1533 "parser.tab.c"
    break;

  case 16:
#line 139 "parser.y"
                         { (yyval.tree) = (yyvsp[-2].tree); asd_add_child((yyval.tree),(yyvsp[0].tree)); }
#line 1539 "parser.tab.c"
    break;

  case 17:
#line 140 "parser.y"
                     { (yyval.tree) = (yyvsp[0].tree); }
#line 1545 "parser.tab.c"
    break;

  case 18:
#line 141 "parser.y"
                                                  { (yyval.tree) = asd_new("[]"), asd_add_child((yyval.tree), (yyvsp[-5].tree)); asd_add_child((yyval.tree), (yyvsp[-3].tree)); asd_add_child((yyval.tree), (yyvsp[0].tree)); }
#line 1551 "parser.tab.c"
    break;

  case 19:
#line 142 "parser.y"
                                      { (yyval.tree) = asd_new("[]"), asd_add_child((yyval.tree), (yyvsp[-3].tree)); asd_add_child((yyval.tree), (yyvsp[-1].tree)); }
#line 1557 "parser.tab.c"
    break;

  case 20:
#line 145 "parser.y"
                                 { (yyval.tree) = asd_new("^"); asd_add_child((yyval.tree),(yyvsp[-2].tree)); asd_add_child((yyval.tree),(yyvsp[0].tree)); }
#line 1563 "parser.tab.c"
    break;

  case 21:
#line 146 "parser.y"
               { (yyval.tree) = (yyvsp[0].tree); }
#line 1569 "parser.tab.c"
    break;

  case 22:
#line 149 "parser.y"
                                   { (yyval.tree) = asd_new("^"); asd_add_child((yyval.tree),(yyvsp[-2].tree)); asd_add_child((yyval.tree),(yyvsp[0].tree)); }
#line 1575 "parser.tab.c"
    break;

  case 23:
#line 150 "parser.y"
           { (yyval.tree) = (yyvsp[0].tree); }
#line 1581 "parser.tab.c"
    break;

  case 24:
#line 153 "parser.y"
                 { (yyval.tree) = asd_new(create_leaf((yyvsp[0].valor_lexico))); }
#line 1587 "parser.tab.c"
    break;

  case 25:
#line 154 "parser.y"
                   { (yyval.tree) = asd_new(create_leaf((yyvsp[0].valor_lexico))); }
#line 1593 "parser.tab.c"
    break;

  case 26:
#line 155 "parser.y"
                   { (yyval.tree) = asd_new(create_leaf((yyvsp[0].valor_lexico))); }
#line 1599 "parser.tab.c"
    break;

  case 27:
#line 156 "parser.y"
                  { (yyval.tree) = asd_new(create_leaf((yyvsp[0].valor_lexico))); }
#line 1605 "parser.tab.c"
    break;

  case 28:
#line 157 "parser.y"
                  { (yyval.tree) = asd_new(create_leaf((yyvsp[0].valor_lexico))); }
#line 1611 "parser.tab.c"
    break;

  case 29:
#line 160 "parser.y"
                        { (yyval.tree) = (yyvsp[-3].tree); if((yyvsp[0].tree)){ asd_add_child((yyval.tree),(yyvsp[0].tree)); }; }
#line 1617 "parser.tab.c"
    break;

  case 30:
#line 161 "parser.y"
                                     { (yyval.tree) = (yyvsp[-4].tree); asd_add_child((yyval.tree),(yyvsp[-2].tree)); if((yyvsp[0].tree)){ asd_add_child((yyval.tree),(yyvsp[0].tree)); }; }
#line 1623 "parser.tab.c"
    break;

  case 31:
#line 164 "parser.y"
                                { (yyval.tree) = (yyvsp[-2].tree); asd_add_child((yyval.tree),(yyvsp[0].tree)); }
#line 1629 "parser.tab.c"
    break;

  case 32:
#line 165 "parser.y"
                { (yyval.tree) = (yyvsp[0].tree); }
#line 1635 "parser.tab.c"
    break;

  case 33:
#line 168 "parser.y"
                { (yyval.tree) = (yyvsp[0].tree); }
#line 1641 "parser.tab.c"
    break;

  case 34:
#line 171 "parser.y"
                             { if((yyvsp[-1].tree)){ (yyval.tree) = (yyvsp[-1].tree); } }
#line 1647 "parser.tab.c"
    break;

  case 35:
#line 172 "parser.y"
                  { (yyval.tree) = NULL; }
#line 1653 "parser.tab.c"
    break;

  case 36:
#line 175 "parser.y"
                                      { if((yyvsp[-2].tree)){ (yyval.tree) = (yyvsp[-2].tree); }; if((yyvsp[0].tree)){ asd_add_child((yyval.tree),(yyvsp[0].tree)); }; }
#line 1659 "parser.tab.c"
    break;

  case 37:
#line 176 "parser.y"
                      { if((yyvsp[-1].tree)){ (yyval.tree) = (yyvsp[-1].tree); }; }
#line 1665 "parser.tab.c"
    break;

  case 38:
#line 178 "parser.y"
               { (yyval.tree) = (yyvsp[0].tree); }
#line 1671 "parser.tab.c"
    break;

  case 39:
#line 179 "parser.y"
                   { (yyval.tree) = (yyvsp[0].tree); }
#line 1677 "parser.tab.c"
    break;

  case 40:
#line 180 "parser.y"
                { (yyval.tree) = (yyvsp[0].tree); }
#line 1683 "parser.tab.c"
    break;

  case 41:
#line 181 "parser.y"
              { (yyval.tree) = (yyvsp[0].tree); }
#line 1689 "parser.tab.c"
    break;

  case 42:
#line 182 "parser.y"
                   { (yyval.tree) = (yyvsp[0].tree); }
#line 1695 "parser.tab.c"
    break;

  case 43:
#line 183 "parser.y"
                { (yyval.tree) = (yyvsp[0].tree); }
#line 1701 "parser.tab.c"
    break;

  case 44:
#line 186 "parser.y"
                    { (yyval.tree) = asd_new("="); asd_add_child((yyval.tree),(yyvsp[-2].tree)); asd_add_child((yyval.tree),(yyvsp[0].tree)); }
#line 1707 "parser.tab.c"
    break;

  case 45:
#line 187 "parser.y"
                                       { (yyval.tree) = asd_new("="); asd_tree_t *col = asd_new("[]"); asd_add_child((yyval.tree), col); asd_add_child((yyval.tree), (yyvsp[0].tree)); asd_add_child(col, (yyvsp[-5].tree)); asd_add_child(col,(yyvsp[-3].tree)); }
#line 1713 "parser.tab.c"
    break;

  case 46:
#line 188 "parser.y"
                                     { (yyval.tree) = asd_new("="); asd_tree_t *col = asd_new("[]"); asd_add_child((yyval.tree), col); asd_add_child(col, (yyvsp[-3].tree)); asd_add_child((yyval.tree), (yyvsp[-1].tree)); }
#line 1719 "parser.tab.c"
    break;

  case 47:
#line 191 "parser.y"
                                      { (yyval.tree) = asd_new("while"); asd_add_child((yyval.tree), (yyvsp[-2].tree)); if((yyvsp[0].tree)){ asd_add_child((yyval.tree), (yyvsp[0].tree)); }; }
#line 1725 "parser.tab.c"
    break;

  case 48:
#line 192 "parser.y"
                                                  { (yyval.tree) = asd_new("if"); asd_add_child((yyval.tree), (yyvsp[-3].tree)); if((yyvsp[0].tree)){ asd_add_child((yyval.tree), (yyvsp[0].tree)); }; }
#line 1731 "parser.tab.c"
    break;

  case 49:
#line 193 "parser.y"
                                                                  { (yyval.tree) = asd_new("if"); asd_add_child((yyval.tree), (yyvsp[-5].tree)); if((yyvsp[-2].tree)){ asd_add_child((yyval.tree), (yyvsp[-2].tree)); }; if((yyvsp[0].tree)){ asd_add_child((yyval.tree), (yyvsp[0].tree)); }; }
#line 1737 "parser.tab.c"
    break;

  case 50:
#line 196 "parser.y"
                        { (yyval.tree) = asd_new("return"); asd_add_child((yyval.tree), (yyvsp[0].tree)); }
#line 1743 "parser.tab.c"
    break;

  case 51:
#line 199 "parser.y"
                                       { (yyval.tree) = (yyvsp[-3].tree); asd_add_child((yyval.tree), (yyvsp[-1].tree)); }
#line 1749 "parser.tab.c"
    break;

  case 52:
#line 200 "parser.y"
                             { (yyval.tree) = (yyvsp[-2].tree); }
#line 1755 "parser.tab.c"
    break;

  case 53:
#line 203 "parser.y"
                     { (yyval.tree) = asd_new(create_leaf((yyvsp[0].valor_lexico))); }
#line 1761 "parser.tab.c"
    break;

  case 54:
#line 206 "parser.y"
                              { char newLabel[100] = "call "; strcat(newLabel, create_leaf((yyvsp[0].valor_lexico))); (yyval.tree) = asd_new(newLabel); }
#line 1767 "parser.tab.c"
    break;

  case 55:
#line 209 "parser.y"
                        { (yyval.tree) = asd_new("||"); asd_add_child((yyval.tree), (yyvsp[-2].tree)); asd_add_child((yyval.tree), (yyvsp[0].tree)); }
#line 1773 "parser.tab.c"
    break;

  case 56:
#line 210 "parser.y"
            { (yyval.tree) = (yyvsp[0].tree); }
#line 1779 "parser.tab.c"
    break;

  case 57:
#line 211 "parser.y"
                  { (yyval.tree) = asd_new("&&"); asd_add_child((yyval.tree), (yyvsp[-2].tree)); asd_add_child((yyval.tree), (yyvsp[0].tree)); }
#line 1785 "parser.tab.c"
    break;

  case 58:
#line 212 "parser.y"
            { (yyval.tree) = (yyvsp[0].tree); }
#line 1791 "parser.tab.c"
    break;

  case 59:
#line 213 "parser.y"
                 { (yyval.tree) = asd_new("=="); asd_add_child((yyval.tree), (yyvsp[-2].tree)); asd_add_child((yyval.tree), (yyvsp[0].tree)); }
#line 1797 "parser.tab.c"
    break;

  case 60:
#line 214 "parser.y"
                       { (yyval.tree) = asd_new("!="); asd_add_child((yyval.tree), (yyvsp[-2].tree)); asd_add_child((yyval.tree), (yyvsp[0].tree)); }
#line 1803 "parser.tab.c"
    break;

  case 61:
#line 215 "parser.y"
            { (yyval.tree) = (yyvsp[0].tree); }
#line 1809 "parser.tab.c"
    break;

  case 62:
#line 216 "parser.y"
                 { (yyval.tree) = asd_new("<="); asd_add_child((yyval.tree), (yyvsp[-2].tree)); asd_add_child((yyval.tree), (yyvsp[0].tree)); }
#line 1815 "parser.tab.c"
    break;

  case 63:
#line 217 "parser.y"
                       { (yyval.tree) = asd_new(">="); asd_add_child((yyval.tree), (yyvsp[-2].tree)); asd_add_child((yyval.tree), (yyvsp[0].tree)); }
#line 1821 "parser.tab.c"
    break;

  case 64:
#line 218 "parser.y"
                  { (yyval.tree) = asd_new(">"); asd_add_child((yyval.tree), (yyvsp[-2].tree)); asd_add_child((yyval.tree), (yyvsp[0].tree)); }
#line 1827 "parser.tab.c"
    break;

  case 65:
#line 219 "parser.y"
                  { (yyval.tree) = asd_new("<"); asd_add_child((yyval.tree), (yyvsp[-2].tree)); asd_add_child((yyval.tree), (yyvsp[0].tree)); }
#line 1833 "parser.tab.c"
    break;

  case 66:
#line 220 "parser.y"
            { (yyval.tree) = (yyvsp[0].tree); }
#line 1839 "parser.tab.c"
    break;

  case 67:
#line 221 "parser.y"
            { (yyval.tree) = asd_new("+"); asd_add_child((yyval.tree), (yyvsp[-2].tree)); asd_add_child((yyval.tree), (yyvsp[0].tree)); }
#line 1845 "parser.tab.c"
    break;

  case 68:
#line 222 "parser.y"
                  { (yyval.tree) = asd_new("-"); asd_add_child((yyval.tree), (yyvsp[-2].tree)); asd_add_child((yyval.tree), (yyvsp[0].tree)); }
#line 1851 "parser.tab.c"
    break;

  case 69:
#line 223 "parser.y"
            { (yyval.tree) = (yyvsp[0].tree); }
#line 1857 "parser.tab.c"
    break;

  case 70:
#line 224 "parser.y"
            { (yyval.tree) = asd_new("*"); asd_add_child((yyval.tree), (yyvsp[-2].tree)); asd_add_child((yyval.tree), (yyvsp[0].tree)); }
#line 1863 "parser.tab.c"
    break;

  case 71:
#line 225 "parser.y"
                  { (yyval.tree) = asd_new("/"); asd_add_child((yyval.tree), (yyvsp[-2].tree)); asd_add_child((yyval.tree), (yyvsp[0].tree)); }
#line 1869 "parser.tab.c"
    break;

  case 72:
#line 226 "parser.y"
                  { (yyval.tree) = asd_new("%"); asd_add_child((yyval.tree), (yyvsp[-2].tree)); asd_add_child((yyval.tree), (yyvsp[0].tree)); }
#line 1875 "parser.tab.c"
    break;

  case 73:
#line 227 "parser.y"
            { (yyval.tree) = (yyvsp[0].tree); }
#line 1881 "parser.tab.c"
    break;

  case 74:
#line 228 "parser.y"
          { (yyval.tree) = asd_new("-"); asd_add_child((yyval.tree), (yyvsp[0].tree)); }
#line 1887 "parser.tab.c"
    break;

  case 75:
#line 229 "parser.y"
                { (yyval.tree) = asd_new("!"); asd_add_child((yyval.tree), (yyvsp[0].tree)); }
#line 1893 "parser.tab.c"
    break;

  case 76:
#line 230 "parser.y"
            { (yyval.tree) = (yyvsp[0].tree); }
#line 1899 "parser.tab.c"
    break;

  case 77:
#line 231 "parser.y"
                 { (yyval.tree) = (yyvsp[-1].tree); }
#line 1905 "parser.tab.c"
    break;

  case 78:
#line 232 "parser.y"
                    { (yyval.tree) = (yyvsp[0].tree); }
#line 1911 "parser.tab.c"
    break;

  case 80:
#line 234 "parser.y"
             { (yyval.tree) = (yyvsp[0].tree); }
#line 1917 "parser.tab.c"
    break;

  case 81:
#line 235 "parser.y"
              { (yyval.tree) = (yyvsp[0].tree); }
#line 1923 "parser.tab.c"
    break;

  case 82:
#line 237 "parser.y"
                             {(yyval.tree) = (yyvsp[-2].tree); asd_add_child((yyval.tree),(yyvsp[0].tree));}
#line 1929 "parser.tab.c"
    break;

  case 83:
#line 238 "parser.y"
               { (yyval.tree) = (yyvsp[0].tree); }
#line 1935 "parser.tab.c"
    break;


#line 1939 "parser.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[+*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 241 "parser.y"


int yyerror(char *err){
	fprintf(stderr, "ERROR in line = %d\n", get_line_number());
	return 0;
}
