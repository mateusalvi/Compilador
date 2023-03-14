/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TK_PR_INT = 3,                  /* TK_PR_INT  */
  YYSYMBOL_TK_PR_FLOAT = 4,                /* TK_PR_FLOAT  */
  YYSYMBOL_TK_PR_BOOL = 5,                 /* TK_PR_BOOL  */
  YYSYMBOL_TK_PR_CHAR = 6,                 /* TK_PR_CHAR  */
  YYSYMBOL_TK_PR_IF = 7,                   /* TK_PR_IF  */
  YYSYMBOL_TK_PR_THEN = 8,                 /* TK_PR_THEN  */
  YYSYMBOL_TK_PR_ELSE = 9,                 /* TK_PR_ELSE  */
  YYSYMBOL_TK_PR_WHILE = 10,               /* TK_PR_WHILE  */
  YYSYMBOL_TK_PR_INPUT = 11,               /* TK_PR_INPUT  */
  YYSYMBOL_TK_PR_OUTPUT = 12,              /* TK_PR_OUTPUT  */
  YYSYMBOL_TK_PR_RETURN = 13,              /* TK_PR_RETURN  */
  YYSYMBOL_TK_PR_FOR = 14,                 /* TK_PR_FOR  */
  YYSYMBOL_TK_OC_LE = 15,                  /* TK_OC_LE  */
  YYSYMBOL_TK_OC_GE = 16,                  /* TK_OC_GE  */
  YYSYMBOL_TK_OC_EQ = 17,                  /* TK_OC_EQ  */
  YYSYMBOL_TK_OC_NE = 18,                  /* TK_OC_NE  */
  YYSYMBOL_TK_OC_AND = 19,                 /* TK_OC_AND  */
  YYSYMBOL_TK_OC_OR = 20,                  /* TK_OC_OR  */
  YYSYMBOL_TK_LIT_INT = 21,                /* TK_LIT_INT  */
  YYSYMBOL_TK_LIT_FLOAT = 22,              /* TK_LIT_FLOAT  */
  YYSYMBOL_TK_LIT_FALSE = 23,              /* TK_LIT_FALSE  */
  YYSYMBOL_TK_LIT_TRUE = 24,               /* TK_LIT_TRUE  */
  YYSYMBOL_TK_LIT_CHAR = 25,               /* TK_LIT_CHAR  */
  YYSYMBOL_TK_IDENTIFICADOR = 26,          /* TK_IDENTIFICADOR  */
  YYSYMBOL_TK_ERRO = 27,                   /* TK_ERRO  */
  YYSYMBOL_28_ = 28,                       /* ';'  */
  YYSYMBOL_29_ = 29,                       /* ','  */
  YYSYMBOL_30_ = 30,                       /* '['  */
  YYSYMBOL_31_ = 31,                       /* ']'  */
  YYSYMBOL_32_ = 32,                       /* '^'  */
  YYSYMBOL_33_ = 33,                       /* '('  */
  YYSYMBOL_34_ = 34,                       /* ')'  */
  YYSYMBOL_35_ = 35,                       /* '{'  */
  YYSYMBOL_36_ = 36,                       /* '}'  */
  YYSYMBOL_37_ = 37,                       /* '='  */
  YYSYMBOL_38_ = 38,                       /* '>'  */
  YYSYMBOL_39_ = 39,                       /* '<'  */
  YYSYMBOL_40_ = 40,                       /* '+'  */
  YYSYMBOL_41_ = 41,                       /* '-'  */
  YYSYMBOL_42_ = 42,                       /* '*'  */
  YYSYMBOL_43_ = 43,                       /* '/'  */
  YYSYMBOL_44_ = 44,                       /* '%'  */
  YYSYMBOL_45_ = 45,                       /* '!'  */
  YYSYMBOL_YYACCEPT = 46,                  /* $accept  */
  YYSYMBOL_Program = 47,                   /* Program  */
  YYSYMBOL_DecList = 48,                   /* DecList  */
  YYSYMBOL_Dec = 49,                       /* Dec  */
  YYSYMBOL_VarList = 50,                   /* VarList  */
  YYSYMBOL_Type = 51,                      /* Type  */
  YYSYMBOL_ArrayDim = 52,                  /* ArrayDim  */
  YYSYMBOL_Lit = 53,                       /* Lit  */
  YYSYMBOL_Func = 54,                      /* Func  */
  YYSYMBOL_PushTable = 55,                 /* PushTable  */
  YYSYMBOL_PopTable = 56,                  /* PopTable  */
  YYSYMBOL_ParamList = 57,                 /* ParamList  */
  YYSYMBOL_Param = 58,                     /* Param  */
  YYSYMBOL_Block = 59,                     /* Block  */
  YYSYMBOL_CommandList = 60,               /* CommandList  */
  YYSYMBOL_Command = 61,                   /* Command  */
  YYSYMBOL_DecLocal = 62,                  /* DecLocal  */
  YYSYMBOL_VarListLocal = 63,              /* VarListLocal  */
  YYSYMBOL_Atrib = 64,                     /* Atrib  */
  YYSYMBOL_Flow = 65,                      /* Flow  */
  YYSYMBOL_Ret = 66,                       /* Ret  */
  YYSYMBOL_FuncCall = 67,                  /* FuncCall  */
  YYSYMBOL_ID = 68,                        /* ID  */
  YYSYMBOL_FuncCallID = 69,                /* FuncCallID  */
  YYSYMBOL_Expr = 70,                      /* Expr  */
  YYSYMBOL_T = 71,                         /* T  */
  YYSYMBOL_F = 72,                         /* F  */
  YYSYMBOL_G = 73,                         /* G  */
  YYSYMBOL_I = 74,                         /* I  */
  YYSYMBOL_J = 75,                         /* J  */
  YYSYMBOL_K = 76,                         /* K  */
  YYSYMBOL_L = 77,                         /* L  */
  YYSYMBOL_ExprList = 78                   /* ExprList  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   170

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  46
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  82
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  147

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   282


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

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
       0,   118,   118,   121,   122,   125,   126,   129,   130,   131,
     132,   137,   138,   139,   140,   145,   146,   149,   150,   151,
     152,   153,   156,   157,   160,   162,   164,   165,   168,   171,
     172,   175,   176,   178,   179,   180,   181,   182,   183,   186,
     188,   189,   190,   191,   196,   197,   200,   201,   202,   205,
     208,   209,   212,   215,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   228,   229,   230,   231,   232,   233,
     234,   235,   236,   237,   238,   239,   240,   241,   242,   243,
     244,   246,   247
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TK_PR_INT",
  "TK_PR_FLOAT", "TK_PR_BOOL", "TK_PR_CHAR", "TK_PR_IF", "TK_PR_THEN",
  "TK_PR_ELSE", "TK_PR_WHILE", "TK_PR_INPUT", "TK_PR_OUTPUT",
  "TK_PR_RETURN", "TK_PR_FOR", "TK_OC_LE", "TK_OC_GE", "TK_OC_EQ",
  "TK_OC_NE", "TK_OC_AND", "TK_OC_OR", "TK_LIT_INT", "TK_LIT_FLOAT",
  "TK_LIT_FALSE", "TK_LIT_TRUE", "TK_LIT_CHAR", "TK_IDENTIFICADOR",
  "TK_ERRO", "';'", "','", "'['", "']'", "'^'", "'('", "')'", "'{'", "'}'",
  "'='", "'>'", "'<'", "'+'", "'-'", "'*'", "'/'", "'%'", "'!'", "$accept",
  "Program", "DecList", "Dec", "VarList", "Type", "ArrayDim", "Lit",
  "Func", "PushTable", "PopTable", "ParamList", "Param", "Block",
  "CommandList", "Command", "DecLocal", "VarListLocal", "Atrib", "Flow",
  "Ret", "FuncCall", "ID", "FuncCallID", "Expr", "T", "F", "G", "I", "J",
  "K", "L", "ExprList", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-102)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-54)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -102,    47,   128,  -102,  -102,  -102,  -102,  -102,  -102,   128,
       8,  -102,  -102,    23,  -102,    75,  -102,     8,   102,    28,
    -102,    11,  -102,  -102,  -102,  -102,  -102,    37,   102,    41,
      41,    52,  -102,  -102,    38,    39,    -1,    74,    36,     6,
      18,    34,  -102,  -102,    21,    -4,  -102,  -102,    80,   102,
      77,   102,   102,   102,   102,   102,   102,   102,   102,   102,
     102,   102,   102,   102,   102,    71,     8,    79,    86,  -102,
       8,    98,  -102,    17,    83,    74,  -102,    36,     6,     6,
      18,    18,    18,    18,    34,    34,  -102,  -102,  -102,     7,
    -102,  -102,    71,   128,  -102,  -102,   102,  -102,   119,   120,
     102,  -102,     8,  -102,   118,   127,  -102,  -102,  -102,  -102,
    -102,   -22,  -102,  -102,  -102,  -102,   102,   102,   136,  -102,
       3,  -102,    81,   102,   102,  -102,    15,    16,   115,     8,
    -102,   126,   136,   150,    71,   130,  -102,   123,    71,  -102,
       8,   102,   152,  -102,   136,    71,  -102
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      24,     0,     0,     1,    11,    12,    13,    14,     2,     4,
       0,     3,    52,     0,     6,     8,     5,     0,     0,     0,
       7,     8,    17,    18,    19,    20,    21,    52,     0,     0,
       0,     0,    80,    77,    79,     0,    16,    55,    57,    60,
      65,    68,    72,    75,     0,     0,    73,    74,    10,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    27,    76,
       0,     0,    51,    82,     0,    54,    15,    56,    58,    59,
      61,    62,    63,    64,    66,    67,    69,    70,    71,     0,
      25,    28,     0,     0,     9,    78,     0,    50,     0,     0,
       0,    30,     0,    38,     0,     0,    34,    35,    33,    36,
      37,     0,    22,    25,    26,    81,     0,     0,    49,    39,
      43,    29,    32,     0,     0,    23,     0,     0,     0,     0,
      31,     0,    44,     0,     0,    42,    40,     0,     0,    46,
       0,     0,    47,    41,    45,     0,    48
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -102,  -102,   153,  -102,   -13,   -41,   -43,    40,  -102,   148,
      51,    72,  -102,   -63,    44,  -102,  -102,  -101,  -102,  -102,
    -102,   -84,   -10,  -102,   -27,   116,   117,    66,    92,    35,
      82,   112,    73
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     8,     9,    13,    10,    31,    32,    14,     2,
     112,    67,    68,   103,   104,   105,   106,   119,   107,   108,
     109,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,    74
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      15,    45,    90,    66,    20,   110,    71,    21,   123,    76,
       4,     5,     6,     7,    98,   124,    51,    99,   128,    51,
     100,    56,    57,    73,     4,     5,     6,     7,   136,   113,
      69,    52,   129,    27,    12,    51,    51,    51,   110,   143,
      17,    18,    89,   101,    58,    59,    96,     3,   102,   133,
     134,    16,    66,    54,    55,    65,    91,    94,    60,    61,
      21,    44,    22,    23,    24,    25,    26,    27,    49,    73,
     -53,   139,    50,   118,    28,   142,    62,    63,    64,   111,
     131,   102,   146,    48,     4,     5,     6,     7,    98,   126,
     127,    99,   120,    53,   100,    84,    85,   132,    22,    23,
      24,    25,    26,    27,    17,    18,    89,    27,   -24,    70,
      28,    72,   111,    92,   144,    93,    89,    97,    29,   120,
      78,    79,    30,    22,    23,    24,    25,    26,    27,    95,
     120,     4,     5,     6,     7,    28,    22,    23,    24,    25,
      26,    46,    47,    29,    86,    87,    88,    30,    80,    81,
      82,    83,   116,   117,   121,   122,    51,   137,   138,   140,
     141,   145,    11,    19,   125,   114,   130,    75,   135,   115,
      77
};

static const yytype_uint8 yycheck[] =
{
      10,    28,    65,    44,    17,    89,    49,    17,    30,    52,
       3,     4,     5,     6,     7,    37,    20,    10,    15,    20,
      13,    15,    16,    50,     3,     4,     5,     6,   129,    92,
      34,    32,    29,    26,    26,    20,    20,    20,   122,   140,
      29,    30,    35,    36,    38,    39,    29,     0,    89,    34,
      34,    28,    93,    17,    18,    34,    66,    70,    40,    41,
      70,    33,    21,    22,    23,    24,    25,    26,    30,    96,
      33,   134,    33,   100,    33,   138,    42,    43,    44,    89,
     123,   122,   145,    31,     3,     4,     5,     6,     7,   116,
     117,    10,   102,    19,    13,    60,    61,   124,    21,    22,
      23,    24,    25,    26,    29,    30,    35,    26,    33,    29,
      33,    34,   122,    34,   141,    29,    35,    34,    41,   129,
      54,    55,    45,    21,    22,    23,    24,    25,    26,    31,
     140,     3,     4,     5,     6,    33,    21,    22,    23,    24,
      25,    29,    30,    41,    62,    63,    64,    45,    56,    57,
      58,    59,    33,    33,    36,    28,    20,    31,     8,    29,
      37,     9,     9,    15,   113,    93,   122,    51,   128,    96,
      53
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    47,    55,     0,     3,     4,     5,     6,    48,    49,
      51,    48,    26,    50,    54,    68,    28,    29,    30,    55,
      50,    68,    21,    22,    23,    24,    25,    26,    33,    41,
      45,    52,    53,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    33,    70,    77,    77,    31,    30,
      33,    20,    32,    19,    17,    18,    15,    16,    38,    39,
      40,    41,    42,    43,    44,    34,    51,    57,    58,    34,
      29,    52,    34,    70,    78,    71,    52,    72,    73,    73,
      74,    74,    74,    74,    75,    75,    76,    76,    76,    35,
      59,    68,    34,    29,    50,    31,    29,    34,     7,    10,
      13,    36,    51,    59,    60,    61,    62,    64,    65,    66,
      67,    68,    56,    59,    57,    78,    33,    33,    70,    63,
      68,    36,    28,    30,    37,    56,    70,    70,    15,    29,
      60,    52,    70,    34,    34,    53,    63,    31,     8,    59,
      29,    37,    59,    63,    70,     9,    59
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    46,    47,    48,    48,    49,    49,    50,    50,    50,
      50,    51,    51,    51,    51,    52,    52,    53,    53,    53,
      53,    53,    54,    54,    55,    56,    57,    57,    58,    59,
      59,    60,    60,    61,    61,    61,    61,    61,    61,    62,
      63,    63,    63,    63,    64,    64,    65,    65,    65,    66,
      67,    67,    68,    69,    70,    70,    71,    71,    72,    72,
      72,    73,    73,    73,    73,    73,    74,    74,    74,    75,
      75,    75,    75,    76,    76,    76,    77,    77,    77,    77,
      77,    78,    78
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     1,     3,     2,     3,     1,     6,
       4,     1,     1,     1,     1,     3,     1,     1,     1,     1,
       1,     1,     6,     7,     0,     0,     3,     1,     2,     3,
       2,     3,     2,     1,     1,     1,     1,     1,     1,     2,
       3,     5,     3,     1,     3,     6,     5,     6,     8,     2,
       4,     3,     1,     1,     3,     1,     3,     1,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     3,
       3,     3,     1,     2,     2,     1,     3,     1,     4,     1,
       1,     3,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 2: /* Program: PushTable DecList  */
#line 118 "parser.y"
                            { if((yyvsp[0].tree)){arvore = (void*)(yyval.tree); (yyval.tree) = (yyvsp[0].tree); }}
#line 1240 "parser.tab.c"
    break;

  case 3: /* DecList: Dec DecList  */
#line 121 "parser.y"
                      { (yyval.tree) = (yyvsp[-1].tree); if((yyvsp[0].tree)){asd_add_child((yyval.tree),(yyvsp[0].tree));} }
#line 1246 "parser.tab.c"
    break;

  case 4: /* DecList: Dec  */
#line 122 "parser.y"
              { if((yyvsp[0].tree)){(yyval.tree) = (yyvsp[0].tree);} else{(yyval.tree) = NULL;} }
#line 1252 "parser.tab.c"
    break;

  case 5: /* Dec: Type VarList ';'  */
#line 125 "parser.y"
                       { if((yyvsp[-1].tree)){ (yyval.tree) = (yyvsp[-1].tree); } else{(yyval.tree) = NULL; } }
#line 1258 "parser.tab.c"
    break;

  case 6: /* Dec: Type Func  */
#line 126 "parser.y"
                { (yyval.tree) = (yyvsp[0].tree); }
#line 1264 "parser.tab.c"
    break;

  case 7: /* VarList: ID ',' VarList  */
#line 129 "parser.y"
                         {  (yyval.tree) = (yyvsp[-2].tree); asd_add_child((yyval.tree),(yyvsp[0].tree)); if(search_stack((yyvsp[-2].tree)->label)){return ERR_DECLARED;} else {ht_insert((yyvsp[-2].tree)->label, (yyvsp[-2].tree)->value);} }
#line 1270 "parser.tab.c"
    break;

  case 8: /* VarList: ID  */
#line 130 "parser.y"
                     { (yyval.tree) = (yyvsp[0].tree); if(search_stack((yyvsp[0].tree)->label)){return ERR_DECLARED;} else {ht_insert((yyvsp[0].tree)->label, (yyvsp[0].tree)->value);} }
#line 1276 "parser.tab.c"
    break;

  case 9: /* VarList: ID '[' ArrayDim ']' ',' VarList  */
#line 131 "parser.y"
                                                  { (yyval.tree) = asd_new("[]"), asd_add_child((yyval.tree), (yyvsp[-5].tree)); asd_add_child((yyval.tree), (yyvsp[-3].tree)); asd_add_child((yyval.tree), (yyvsp[0].tree)); if(search_stack((yyvsp[-5].tree)->label)){return ERR_DECLARED;} else {ht_insert((yyvsp[-5].tree)->label, (yyvsp[-5].tree)->value);} }
#line 1282 "parser.tab.c"
    break;

  case 10: /* VarList: ID '[' ArrayDim ']'  */
#line 132 "parser.y"
                                      { (yyval.tree) = asd_new("[]"), asd_add_child((yyval.tree), (yyvsp[-3].tree)); asd_add_child((yyval.tree), (yyvsp[-1].tree)); if(search_stack((yyvsp[-3].tree)->label)){return ERR_DECLARED;} else {ht_insert((yyvsp[-3].tree)->label, (yyvsp[-3].tree)->value);}}
#line 1288 "parser.tab.c"
    break;

  case 11: /* Type: TK_PR_INT  */
#line 137 "parser.y"
                 { (yyval.tree) = asd_new(create_leaf((yyvsp[0].valor_lexico))); asd_free_node((yyval.tree)); }
#line 1294 "parser.tab.c"
    break;

  case 12: /* Type: TK_PR_FLOAT  */
#line 138 "parser.y"
                      { (yyval.tree) = NULL; }
#line 1300 "parser.tab.c"
    break;

  case 13: /* Type: TK_PR_BOOL  */
#line 139 "parser.y"
                     { (yyval.tree) = NULL; }
#line 1306 "parser.tab.c"
    break;

  case 14: /* Type: TK_PR_CHAR  */
#line 140 "parser.y"
                     { (yyval.tree) = NULL; }
#line 1312 "parser.tab.c"
    break;

  case 15: /* ArrayDim: Expr '^' ArrayDim  */
#line 145 "parser.y"
                              { (yyval.tree) = asd_new("^"); asd_add_child((yyval.tree),(yyvsp[-2].tree)); asd_add_child((yyval.tree),(yyvsp[0].tree)); }
#line 1318 "parser.tab.c"
    break;

  case 16: /* ArrayDim: Expr  */
#line 146 "parser.y"
               { (yyval.tree) = (yyvsp[0].tree); }
#line 1324 "parser.tab.c"
    break;

  case 17: /* Lit: TK_LIT_INT  */
#line 149 "parser.y"
                 { (yyval.tree) = asd_new(create_leaf((yyvsp[0].valor_lexico)));  printf("Contents of structure are %d, %d\n", (yyvsp[0].valor_lexico).atLine, (yyvsp[0].valor_lexico).type); }
#line 1330 "parser.tab.c"
    break;

  case 18: /* Lit: TK_LIT_FLOAT  */
#line 150 "parser.y"
                   { (yyval.tree) = asd_new(create_leaf((yyvsp[0].valor_lexico))); ht_insert((yyvsp[0].valor_lexico).value.valueChar, (yyvsp[0].valor_lexico)); }
#line 1336 "parser.tab.c"
    break;

  case 19: /* Lit: TK_LIT_FALSE  */
#line 151 "parser.y"
                   { (yyval.tree) = asd_new(create_leaf((yyvsp[0].valor_lexico))); ht_insert((yyvsp[0].valor_lexico).value.valueChar, (yyvsp[0].valor_lexico)); }
#line 1342 "parser.tab.c"
    break;

  case 20: /* Lit: TK_LIT_TRUE  */
#line 152 "parser.y"
                  { (yyval.tree) = asd_new(create_leaf((yyvsp[0].valor_lexico)));  ht_insert((yyvsp[0].valor_lexico).value.valueChar, (yyvsp[0].valor_lexico));}
#line 1348 "parser.tab.c"
    break;

  case 21: /* Lit: TK_LIT_CHAR  */
#line 153 "parser.y"
                  { (yyval.tree) = asd_new(create_leaf((yyvsp[0].valor_lexico))); ht_insert((yyvsp[0].valor_lexico).value.valueChar, (yyvsp[0].valor_lexico));  }
#line 1354 "parser.tab.c"
    break;

  case 22: /* Func: ID PushTable '(' ')' Block PopTable  */
#line 156 "parser.y"
                                           { (yyval.tree) = (yyvsp[-5].tree); if((yyvsp[-1].tree)){ asd_add_child((yyval.tree),(yyvsp[-1].tree)); }; }
#line 1360 "parser.tab.c"
    break;

  case 23: /* Func: ID PushTable '(' ParamList ')' Block PopTable  */
#line 157 "parser.y"
                                                        { (yyval.tree) = (yyvsp[-6].tree); if((yyvsp[-3].tree)){ asd_add_child((yyval.tree),(yyvsp[-3].tree)); }; if((yyvsp[-1].tree)){ asd_add_child((yyval.tree),(yyvsp[-1].tree)); }; }
#line 1366 "parser.tab.c"
    break;

  case 24: /* PushTable: %empty  */
#line 160 "parser.y"
                   { printf("aloquei memória"); push(create_table(999)); }
#line 1372 "parser.tab.c"
    break;

  case 25: /* PopTable: %empty  */
#line 162 "parser.y"
                  { print_stack(); pop(); }
#line 1378 "parser.tab.c"
    break;

  case 26: /* ParamList: Param ',' ParamList  */
#line 164 "parser.y"
                                { (yyval.tree) = (yyvsp[-2].tree); asd_add_child((yyval.tree),(yyvsp[0].tree)); }
#line 1384 "parser.tab.c"
    break;

  case 27: /* ParamList: Param  */
#line 165 "parser.y"
                { (yyval.tree) = (yyvsp[0].tree); }
#line 1390 "parser.tab.c"
    break;

  case 28: /* Param: Type ID  */
#line 168 "parser.y"
                { (yyval.tree) = (yyvsp[0].tree); }
#line 1396 "parser.tab.c"
    break;

  case 29: /* Block: '{' CommandList '}'  */
#line 171 "parser.y"
                             { if((yyvsp[-1].tree)){ (yyval.tree) = (yyvsp[-1].tree); } }
#line 1402 "parser.tab.c"
    break;

  case 30: /* Block: '{' '}'  */
#line 172 "parser.y"
                  { (yyval.tree) = NULL; }
#line 1408 "parser.tab.c"
    break;

  case 31: /* CommandList: Command ';' CommandList  */
#line 175 "parser.y"
                                      { if((yyvsp[-2].tree)){ (yyval.tree) = (yyvsp[-2].tree); }; if((yyvsp[0].tree)){ asd_add_child((yyval.tree),(yyvsp[0].tree)); }; }
#line 1414 "parser.tab.c"
    break;

  case 32: /* CommandList: Command ';'  */
#line 176 "parser.y"
                      { if((yyvsp[-1].tree)){ (yyval.tree) = (yyvsp[-1].tree); }; }
#line 1420 "parser.tab.c"
    break;

  case 33: /* Command: Flow  */
#line 178 "parser.y"
               { (yyval.tree) = (yyvsp[0].tree); }
#line 1426 "parser.tab.c"
    break;

  case 34: /* Command: DecLocal  */
#line 179 "parser.y"
                   { (yyval.tree) = (yyvsp[0].tree); }
#line 1432 "parser.tab.c"
    break;

  case 35: /* Command: Atrib  */
#line 180 "parser.y"
                { (yyval.tree) = (yyvsp[0].tree); }
#line 1438 "parser.tab.c"
    break;

  case 36: /* Command: Ret  */
#line 181 "parser.y"
              { (yyval.tree) = (yyvsp[0].tree); }
#line 1444 "parser.tab.c"
    break;

  case 37: /* Command: FuncCall  */
#line 182 "parser.y"
                   { (yyval.tree) = (yyvsp[0].tree); }
#line 1450 "parser.tab.c"
    break;

  case 38: /* Command: Block  */
#line 183 "parser.y"
                { (yyval.tree) = (yyvsp[0].tree); }
#line 1456 "parser.tab.c"
    break;

  case 39: /* DecLocal: Type VarListLocal  */
#line 186 "parser.y"
                            { if((yyvsp[0].tree)){ (yyval.tree) = (yyvsp[0].tree); } }
#line 1462 "parser.tab.c"
    break;

  case 40: /* VarListLocal: ID ',' VarListLocal  */
#line 188 "parser.y"
                                   { (yyval.tree) = (yyvsp[0].tree); if((search_stack((yyvsp[-2].tree)->label))){return ERR_DECLARED;} else {ht_insert((yyvsp[-2].tree)->label, (yyvsp[-2].tree)->value);}}
#line 1468 "parser.tab.c"
    break;

  case 41: /* VarListLocal: ID TK_OC_LE Lit ',' VarListLocal  */
#line 189 "parser.y"
                                           { (yyval.tree) = asd_new("<="); asd_add_child((yyval.tree), (yyvsp[-4].tree)); asd_add_child((yyval.tree), (yyvsp[-2].tree)); asd_add_child((yyval.tree), (yyvsp[0].tree)); if(search_stack((yyvsp[-4].tree)->label)){return ERR_DECLARED;} else {ht_insert((yyvsp[-4].tree)->label, (yyvsp[-4].tree)->value);} }
#line 1474 "parser.tab.c"
    break;

  case 42: /* VarListLocal: ID TK_OC_LE Lit  */
#line 190 "parser.y"
                                  { (yyval.tree) = asd_new("<="); asd_add_child((yyval.tree), (yyvsp[-2].tree)); asd_add_child((yyval.tree), (yyvsp[0].tree)); if(search_stack((yyvsp[-2].tree)->label)){return ERR_DECLARED;} else {ht_insert((yyvsp[-2].tree)->label, (yyvsp[-2].tree)->value);} }
#line 1480 "parser.tab.c"
    break;

  case 43: /* VarListLocal: ID  */
#line 191 "parser.y"
                     { (yyval.tree) = NULL; if(search_stack((yyvsp[0].tree)->label)){return ERR_DECLARED;} else {ht_insert((yyvsp[0].tree)->label, (yyvsp[0].tree)->value);} }
#line 1486 "parser.tab.c"
    break;

  case 44: /* Atrib: ID '=' Expr  */
#line 196 "parser.y"
                    { (yyval.tree) = asd_new("="); asd_add_child((yyval.tree),(yyvsp[-2].tree)); asd_add_child((yyval.tree),(yyvsp[0].tree)); }
#line 1492 "parser.tab.c"
    break;

  case 45: /* Atrib: ID '[' ArrayDim ']' '=' Expr  */
#line 197 "parser.y"
                                       { (yyval.tree) = asd_new("="); asd_tree_t *col = asd_new("[]"); asd_add_child((yyval.tree), col); asd_add_child((yyval.tree), (yyvsp[0].tree)); asd_add_child(col, (yyvsp[-5].tree)); asd_add_child(col,(yyvsp[-3].tree)); }
#line 1498 "parser.tab.c"
    break;

  case 46: /* Flow: TK_PR_WHILE '(' Expr ')' Block  */
#line 200 "parser.y"
                                      { (yyval.tree) = asd_new("while"); asd_add_child((yyval.tree), (yyvsp[-2].tree)); if((yyvsp[0].tree)){ asd_add_child((yyval.tree), (yyvsp[0].tree)); }; }
#line 1504 "parser.tab.c"
    break;

  case 47: /* Flow: TK_PR_IF '(' Expr ')' TK_PR_THEN Block  */
#line 201 "parser.y"
                                                  { (yyval.tree) = asd_new("if"); asd_add_child((yyval.tree), (yyvsp[-3].tree)); if((yyvsp[0].tree)){ asd_add_child((yyval.tree), (yyvsp[0].tree)); }; }
#line 1510 "parser.tab.c"
    break;

  case 48: /* Flow: TK_PR_IF '(' Expr ')' TK_PR_THEN Block TK_PR_ELSE Block  */
#line 202 "parser.y"
                                                                  { (yyval.tree) = asd_new("if"); asd_add_child((yyval.tree), (yyvsp[-5].tree)); if((yyvsp[-2].tree)){ asd_add_child((yyval.tree), (yyvsp[-2].tree)); }; if((yyvsp[0].tree)){ asd_add_child((yyval.tree), (yyvsp[0].tree)); }; }
#line 1516 "parser.tab.c"
    break;

  case 49: /* Ret: TK_PR_RETURN Expr  */
#line 205 "parser.y"
                        { (yyval.tree) = asd_new("return"); asd_add_child((yyval.tree), (yyvsp[0].tree)); }
#line 1522 "parser.tab.c"
    break;

  case 50: /* FuncCall: FuncCallID '(' ExprList ')'  */
#line 208 "parser.y"
                                       { (yyval.tree) = (yyvsp[-3].tree); asd_add_child((yyval.tree), (yyvsp[-1].tree)); if((search_stack((yyvsp[-3].tree)->label))){return ERR_DECLARED;} }
#line 1528 "parser.tab.c"
    break;

  case 51: /* FuncCall: FuncCallID '(' ')'  */
#line 209 "parser.y"
                             { (yyval.tree) = (yyvsp[-2].tree); if((search_stack((yyvsp[-2].tree)->label))){return ERR_DECLARED;} }
#line 1534 "parser.tab.c"
    break;

  case 52: /* ID: TK_IDENTIFICADOR  */
#line 212 "parser.y"
                     { (yyval.tree) = asd_new(create_leaf((yyvsp[0].valor_lexico))); }
#line 1540 "parser.tab.c"
    break;

  case 53: /* FuncCallID: TK_IDENTIFICADOR  */
#line 215 "parser.y"
                              { char newLabel[100] = "call "; strcat(newLabel, create_leaf((yyvsp[0].valor_lexico))); (yyval.tree) = asd_new(newLabel); }
#line 1546 "parser.tab.c"
    break;

  case 54: /* Expr: Expr TK_OC_OR T  */
#line 218 "parser.y"
                        { (yyval.tree) = asd_new("||"); asd_add_child((yyval.tree), (yyvsp[-2].tree)); asd_add_child((yyval.tree), (yyvsp[0].tree)); }
#line 1552 "parser.tab.c"
    break;

  case 55: /* Expr: T  */
#line 219 "parser.y"
            { (yyval.tree) = (yyvsp[0].tree); }
#line 1558 "parser.tab.c"
    break;

  case 56: /* T: T TK_OC_AND F  */
#line 220 "parser.y"
                  { (yyval.tree) = asd_new("&&"); asd_add_child((yyval.tree), (yyvsp[-2].tree)); asd_add_child((yyval.tree), (yyvsp[0].tree)); }
#line 1564 "parser.tab.c"
    break;

  case 57: /* T: F  */
#line 221 "parser.y"
            { (yyval.tree) = (yyvsp[0].tree); }
#line 1570 "parser.tab.c"
    break;

  case 58: /* F: F TK_OC_EQ G  */
#line 222 "parser.y"
                 { (yyval.tree) = asd_new("=="); asd_add_child((yyval.tree), (yyvsp[-2].tree)); asd_add_child((yyval.tree), (yyvsp[0].tree)); }
#line 1576 "parser.tab.c"
    break;

  case 59: /* F: F TK_OC_NE G  */
#line 223 "parser.y"
                       { (yyval.tree) = asd_new("!="); asd_add_child((yyval.tree), (yyvsp[-2].tree)); asd_add_child((yyval.tree), (yyvsp[0].tree)); }
#line 1582 "parser.tab.c"
    break;

  case 60: /* F: G  */
#line 224 "parser.y"
            { (yyval.tree) = (yyvsp[0].tree); }
#line 1588 "parser.tab.c"
    break;

  case 61: /* G: G TK_OC_LE I  */
#line 225 "parser.y"
                 { (yyval.tree) = asd_new("<="); asd_add_child((yyval.tree), (yyvsp[-2].tree)); asd_add_child((yyval.tree), (yyvsp[0].tree)); }
#line 1594 "parser.tab.c"
    break;

  case 62: /* G: G TK_OC_GE I  */
#line 226 "parser.y"
                       { (yyval.tree) = asd_new(">="); asd_add_child((yyval.tree), (yyvsp[-2].tree)); asd_add_child((yyval.tree), (yyvsp[0].tree)); }
#line 1600 "parser.tab.c"
    break;

  case 63: /* G: G '>' I  */
#line 227 "parser.y"
                  { (yyval.tree) = asd_new(">"); asd_add_child((yyval.tree), (yyvsp[-2].tree)); asd_add_child((yyval.tree), (yyvsp[0].tree)); }
#line 1606 "parser.tab.c"
    break;

  case 64: /* G: G '<' I  */
#line 228 "parser.y"
                  { (yyval.tree) = asd_new("<"); asd_add_child((yyval.tree), (yyvsp[-2].tree)); asd_add_child((yyval.tree), (yyvsp[0].tree)); }
#line 1612 "parser.tab.c"
    break;

  case 65: /* G: I  */
#line 229 "parser.y"
            { (yyval.tree) = (yyvsp[0].tree); }
#line 1618 "parser.tab.c"
    break;

  case 66: /* I: I '+' J  */
#line 230 "parser.y"
            { (yyval.tree) = asd_new("+"); asd_add_child((yyval.tree), (yyvsp[-2].tree)); asd_add_child((yyval.tree), (yyvsp[0].tree)); }
#line 1624 "parser.tab.c"
    break;

  case 67: /* I: I '-' J  */
#line 231 "parser.y"
                  { (yyval.tree) = asd_new("-"); asd_add_child((yyval.tree), (yyvsp[-2].tree)); asd_add_child((yyval.tree), (yyvsp[0].tree)); }
#line 1630 "parser.tab.c"
    break;

  case 68: /* I: J  */
#line 232 "parser.y"
            { (yyval.tree) = (yyvsp[0].tree); }
#line 1636 "parser.tab.c"
    break;

  case 69: /* J: J '*' K  */
#line 233 "parser.y"
            { (yyval.tree) = asd_new("*"); asd_add_child((yyval.tree), (yyvsp[-2].tree)); asd_add_child((yyval.tree), (yyvsp[0].tree)); }
#line 1642 "parser.tab.c"
    break;

  case 70: /* J: J '/' K  */
#line 234 "parser.y"
                  { (yyval.tree) = asd_new("/"); asd_add_child((yyval.tree), (yyvsp[-2].tree)); asd_add_child((yyval.tree), (yyvsp[0].tree)); }
#line 1648 "parser.tab.c"
    break;

  case 71: /* J: J '%' K  */
#line 235 "parser.y"
                  { (yyval.tree) = asd_new("%"); asd_add_child((yyval.tree), (yyvsp[-2].tree)); asd_add_child((yyval.tree), (yyvsp[0].tree)); }
#line 1654 "parser.tab.c"
    break;

  case 72: /* J: K  */
#line 236 "parser.y"
            { (yyval.tree) = (yyvsp[0].tree); }
#line 1660 "parser.tab.c"
    break;

  case 73: /* K: '-' L  */
#line 237 "parser.y"
          { (yyval.tree) = asd_new("-"); asd_add_child((yyval.tree), (yyvsp[0].tree)); }
#line 1666 "parser.tab.c"
    break;

  case 74: /* K: '!' L  */
#line 238 "parser.y"
                { (yyval.tree) = asd_new("!"); asd_add_child((yyval.tree), (yyvsp[0].tree)); }
#line 1672 "parser.tab.c"
    break;

  case 75: /* K: L  */
#line 239 "parser.y"
            { (yyval.tree) = (yyvsp[0].tree); }
#line 1678 "parser.tab.c"
    break;

  case 76: /* L: '(' Expr ')'  */
#line 240 "parser.y"
                 { (yyval.tree) = (yyvsp[-1].tree); }
#line 1684 "parser.tab.c"
    break;

  case 77: /* L: FuncCall  */
#line 241 "parser.y"
                    { (yyval.tree) = (yyvsp[0].tree); }
#line 1690 "parser.tab.c"
    break;

  case 79: /* L: ID  */
#line 243 "parser.y"
             { (yyval.tree) = (yyvsp[0].tree);}
#line 1696 "parser.tab.c"
    break;

  case 80: /* L: Lit  */
#line 244 "parser.y"
              { (yyval.tree) = (yyvsp[0].tree); }
#line 1702 "parser.tab.c"
    break;

  case 81: /* ExprList: Expr ',' ExprList  */
#line 246 "parser.y"
                             {(yyval.tree) = (yyvsp[-2].tree); asd_add_child((yyval.tree),(yyvsp[0].tree));}
#line 1708 "parser.tab.c"
    break;

  case 82: /* ExprList: Expr  */
#line 247 "parser.y"
               { (yyval.tree) = (yyvsp[0].tree); }
#line 1714 "parser.tab.c"
    break;


#line 1718 "parser.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 250 "parser.y"


int yyerror(char *err){
	fprintf(stderr, "ERROR in line = %d\n", get_line_number());
	return 0;
}
