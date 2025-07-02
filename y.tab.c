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




/* First part of user prologue.  */
#line 1 "sintatica.y"

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <array>
#include <iterator>
#include <algorithm>

#define YYSTYPE atributos

using namespace std;

int mainStatus = 0;
int var_temp_qnt;
int var_lace_qnt;
int var_cond_qnt;
int var_linha_qnt = 1;
int var_lace_name_qnt = 0;
int controleLoop = 0;
int controleFunction = 0;

string error = "";
string warning = "";
string contLinha = "1";

struct atributos
{
	string label;
	string traducao;
	string tipo;
	string valor;
	string index;
};

typedef struct
{
	string nomeVariavel;
	string tipoVariavel; 
	string labelVariavel;
	string valorVariavel;
}	TIPO_SIMBOLO;

typedef struct
{
	string tipoVariavel; 
	string labelVariavel;
	string valor;
}	TIPO_TEMP;

typedef struct
{
	string nomeLaco;
	string tipoLaco;
	string fimLaco;
	string inicioLaco;
	int contexto;
}	TIPO_LOOP;

typedef struct
{
	string nomeFunction;
	string tipoReturn;
	string inicioFunction;
	string fimFunction;
	vector<TIPO_SIMBOLO> parameters;
	string retornoTipo = "";
	string retornoLabel = "";
}	TIPO_FUNCTION;

vector<TIPO_LOOP> tabelaLoop;
vector<TIPO_FUNCTION> tabelaFunction;
vector<TIPO_SIMBOLO> parametersChamada;
vector<vector<TIPO_SIMBOLO>> mapa;
int contextoGlobal;
vector<TIPO_TEMP> tabelaTemp;
string atribuicaoVariavel;
string atribuicaoVariavelGlobais;
string traducaoFunction;

int yylex(void);
void yyerror(string);
int getContexto();
string gentempcode();
string genLacecode();
string genCondcode();
string genLaceNameCode();
void verificarVariavelRepetida(string variavel);
TIPO_SIMBOLO getSimbolo(string variavel);
void addSimbolo(string variavel, string tipo, string label);
void addString(string variavel, string tipo, string label);
int addTempString(string label, string tipo);
int getSize(string str);
void addTemp(string label, string tipo);
void verificarOperacaoRelacional(atributos tipo_1, atributos tipo_2);
void atualizarContexto(int num);
void contadorDeLinha();
void pushContexto();
void popContexto();
void pushLoop(string tipo);
void pushFunction();
TIPO_FUNCTION getFunction();
TIPO_LOOP getLace(string nome);
TIPO_LOOP getLaceBreak();
TIPO_FUNCTION getFunctionChamada(string nome);
void verificarAtributoRelacional(atributos tipo_1);

#line 179 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    TK_NUM = 258,                  /* TK_NUM  */
    TK_REAL = 259,                 /* TK_REAL  */
    TK_CHAR = 260,                 /* TK_CHAR  */
    TK_TRUE = 261,                 /* TK_TRUE  */
    TK_FALSE = 262,                /* TK_FALSE  */
    TK_STRING = 263,               /* TK_STRING  */
    TK_VOID = 264,                 /* TK_VOID  */
    TK_FUNCTION = 265,             /* TK_FUNCTION  */
    TK_MAIN = 266,                 /* TK_MAIN  */
    TK_ID = 267,                   /* TK_ID  */
    TK_TIPO_INT = 268,             /* TK_TIPO_INT  */
    TK_TIPO_FLOAT = 269,           /* TK_TIPO_FLOAT  */
    TK_TIPO_CHAR = 270,            /* TK_TIPO_CHAR  */
    TK_TIPO_BOOL = 271,            /* TK_TIPO_BOOL  */
    TK_TIPO_STRING = 272,          /* TK_TIPO_STRING  */
    TK_CAST_FLOAT = 273,           /* TK_CAST_FLOAT  */
    TK_CAST_INT = 274,             /* TK_CAST_INT  */
    TK_CAST_BOOL = 275,            /* TK_CAST_BOOL  */
    TK_MAIOR_IGUAL = 276,          /* TK_MAIOR_IGUAL  */
    TK_MENOR_IGUAL = 277,          /* TK_MENOR_IGUAL  */
    TK_IGUAL_IGUAL = 278,          /* TK_IGUAL_IGUAL  */
    TK_DIFERENTE = 279,            /* TK_DIFERENTE  */
    TK_MAIS_MAIS = 280,            /* TK_MAIS_MAIS  */
    TK_MENOS_MENOS = 281,          /* TK_MENOS_MENOS  */
    TK_OU = 282,                   /* TK_OU  */
    TK_E = 283,                    /* TK_E  */
    TK_MAIS_IGUAL = 284,           /* TK_MAIS_IGUAL  */
    TK_MENOS_IGUAL = 285,          /* TK_MENOS_IGUAL  */
    TK_IF = 286,                   /* TK_IF  */
    TK_ELSE = 287,                 /* TK_ELSE  */
    TK_WHILE = 288,                /* TK_WHILE  */
    TK_FOR = 289,                  /* TK_FOR  */
    TK_DO = 290,                   /* TK_DO  */
    TK_SWITCH = 291,               /* TK_SWITCH  */
    TK_CASE = 292,                 /* TK_CASE  */
    TK_BREAK = 293,                /* TK_BREAK  */
    TK_CONTINUE = 294,             /* TK_CONTINUE  */
    TK_PRINT = 295,                /* TK_PRINT  */
    TK_SCAN = 296,                 /* TK_SCAN  */
    TK_RETURN = 297,               /* TK_RETURN  */
    TK_ERROR = 298,                /* TK_ERROR  */
    TK_CAST_CHAR = 299             /* TK_CAST_CHAR  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define TK_NUM 258
#define TK_REAL 259
#define TK_CHAR 260
#define TK_TRUE 261
#define TK_FALSE 262
#define TK_STRING 263
#define TK_VOID 264
#define TK_FUNCTION 265
#define TK_MAIN 266
#define TK_ID 267
#define TK_TIPO_INT 268
#define TK_TIPO_FLOAT 269
#define TK_TIPO_CHAR 270
#define TK_TIPO_BOOL 271
#define TK_TIPO_STRING 272
#define TK_CAST_FLOAT 273
#define TK_CAST_INT 274
#define TK_CAST_BOOL 275
#define TK_MAIOR_IGUAL 276
#define TK_MENOR_IGUAL 277
#define TK_IGUAL_IGUAL 278
#define TK_DIFERENTE 279
#define TK_MAIS_MAIS 280
#define TK_MENOS_MENOS 281
#define TK_OU 282
#define TK_E 283
#define TK_MAIS_IGUAL 284
#define TK_MENOS_IGUAL 285
#define TK_IF 286
#define TK_ELSE 287
#define TK_WHILE 288
#define TK_FOR 289
#define TK_DO 290
#define TK_SWITCH 291
#define TK_CASE 292
#define TK_BREAK 293
#define TK_CONTINUE 294
#define TK_PRINT 295
#define TK_SCAN 296
#define TK_RETURN 297
#define TK_ERROR 298
#define TK_CAST_CHAR 299

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_TK_NUM = 3,                     /* TK_NUM  */
  YYSYMBOL_TK_REAL = 4,                    /* TK_REAL  */
  YYSYMBOL_TK_CHAR = 5,                    /* TK_CHAR  */
  YYSYMBOL_TK_TRUE = 6,                    /* TK_TRUE  */
  YYSYMBOL_TK_FALSE = 7,                   /* TK_FALSE  */
  YYSYMBOL_TK_STRING = 8,                  /* TK_STRING  */
  YYSYMBOL_TK_VOID = 9,                    /* TK_VOID  */
  YYSYMBOL_TK_FUNCTION = 10,               /* TK_FUNCTION  */
  YYSYMBOL_TK_MAIN = 11,                   /* TK_MAIN  */
  YYSYMBOL_TK_ID = 12,                     /* TK_ID  */
  YYSYMBOL_TK_TIPO_INT = 13,               /* TK_TIPO_INT  */
  YYSYMBOL_TK_TIPO_FLOAT = 14,             /* TK_TIPO_FLOAT  */
  YYSYMBOL_TK_TIPO_CHAR = 15,              /* TK_TIPO_CHAR  */
  YYSYMBOL_TK_TIPO_BOOL = 16,              /* TK_TIPO_BOOL  */
  YYSYMBOL_TK_TIPO_STRING = 17,            /* TK_TIPO_STRING  */
  YYSYMBOL_TK_CAST_FLOAT = 18,             /* TK_CAST_FLOAT  */
  YYSYMBOL_TK_CAST_INT = 19,               /* TK_CAST_INT  */
  YYSYMBOL_TK_CAST_BOOL = 20,              /* TK_CAST_BOOL  */
  YYSYMBOL_TK_MAIOR_IGUAL = 21,            /* TK_MAIOR_IGUAL  */
  YYSYMBOL_TK_MENOR_IGUAL = 22,            /* TK_MENOR_IGUAL  */
  YYSYMBOL_TK_IGUAL_IGUAL = 23,            /* TK_IGUAL_IGUAL  */
  YYSYMBOL_TK_DIFERENTE = 24,              /* TK_DIFERENTE  */
  YYSYMBOL_TK_MAIS_MAIS = 25,              /* TK_MAIS_MAIS  */
  YYSYMBOL_TK_MENOS_MENOS = 26,            /* TK_MENOS_MENOS  */
  YYSYMBOL_TK_OU = 27,                     /* TK_OU  */
  YYSYMBOL_TK_E = 28,                      /* TK_E  */
  YYSYMBOL_TK_MAIS_IGUAL = 29,             /* TK_MAIS_IGUAL  */
  YYSYMBOL_TK_MENOS_IGUAL = 30,            /* TK_MENOS_IGUAL  */
  YYSYMBOL_TK_IF = 31,                     /* TK_IF  */
  YYSYMBOL_TK_ELSE = 32,                   /* TK_ELSE  */
  YYSYMBOL_TK_WHILE = 33,                  /* TK_WHILE  */
  YYSYMBOL_TK_FOR = 34,                    /* TK_FOR  */
  YYSYMBOL_TK_DO = 35,                     /* TK_DO  */
  YYSYMBOL_TK_SWITCH = 36,                 /* TK_SWITCH  */
  YYSYMBOL_TK_CASE = 37,                   /* TK_CASE  */
  YYSYMBOL_TK_BREAK = 38,                  /* TK_BREAK  */
  YYSYMBOL_TK_CONTINUE = 39,               /* TK_CONTINUE  */
  YYSYMBOL_TK_PRINT = 40,                  /* TK_PRINT  */
  YYSYMBOL_TK_SCAN = 41,                   /* TK_SCAN  */
  YYSYMBOL_TK_RETURN = 42,                 /* TK_RETURN  */
  YYSYMBOL_TK_ERROR = 43,                  /* TK_ERROR  */
  YYSYMBOL_44_ = 44,                       /* '+'  */
  YYSYMBOL_TK_CAST_CHAR = 45,              /* TK_CAST_CHAR  */
  YYSYMBOL_46_ = 46,                       /* '('  */
  YYSYMBOL_47_ = 47,                       /* ')'  */
  YYSYMBOL_48_ = 48,                       /* ';'  */
  YYSYMBOL_49_ = 49,                       /* ','  */
  YYSYMBOL_50_ = 50,                       /* '{'  */
  YYSYMBOL_51_ = 51,                       /* '}'  */
  YYSYMBOL_52_ = 52,                       /* ':'  */
  YYSYMBOL_53_ = 53,                       /* '-'  */
  YYSYMBOL_54_ = 54,                       /* '>'  */
  YYSYMBOL_55_ = 55,                       /* '<'  */
  YYSYMBOL_56_ = 56,                       /* '!'  */
  YYSYMBOL_57_ = 57,                       /* '='  */
  YYSYMBOL_58_ = 58,                       /* '*'  */
  YYSYMBOL_59_ = 59,                       /* '/'  */
  YYSYMBOL_60_ = 60,                       /* '%'  */
  YYSYMBOL_YYACCEPT = 61,                  /* $accept  */
  YYSYMBOL_S = 62,                         /* S  */
  YYSYMBOL_FUNCAO = 63,                    /* FUNCAO  */
  YYSYMBOL_DECLAFUNC = 64,                 /* DECLAFUNC  */
  YYSYMBOL_PARAMETERS = 65,                /* PARAMETERS  */
  YYSYMBOL_PARAMETER = 66,                 /* PARAMETER  */
  YYSYMBOL_BLOCO = 67,                     /* BLOCO  */
  YYSYMBOL_COMANDOS = 68,                  /* COMANDOS  */
  YYSYMBOL_CASES = 69,                     /* CASES  */
  YYSYMBOL_CASE = 70,                      /* CASE  */
  YYSYMBOL_COMANDO = 71,                   /* COMANDO  */
  YYSYMBOL_DECLARACAO = 72,                /* DECLARACAO  */
  YYSYMBOL_TIPOS = 73,                     /* TIPOS  */
  YYSYMBOL_E = 74,                         /* E  */
  YYSYMBOL_CHAMADAS = 75,                  /* CHAMADAS  */
  YYSYMBOL_CHAMADA = 76,                   /* CHAMADA  */
  YYSYMBOL_RELACIONAL = 77,                /* RELACIONAL  */
  YYSYMBOL_ATRIBUICAO = 78,                /* ATRIBUICAO  */
  YYSYMBOL_M = 79,                         /* M  */
  YYSYMBOL_P = 80                          /* P  */
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
#define YYFINAL  19
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   561

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  61
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  82
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  198

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   299


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
       2,     2,     2,    56,     2,     2,     2,    60,     2,     2,
      46,    47,    58,    44,    49,    53,     2,    59,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    52,    48,
      55,    57,    54,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    50,     2,    51,     2,     2,     2,     2,
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    45
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   125,   125,   134,   137,   141,   146,   164,   181,   185,
     189,   192,   197,   203,   207,   211,   229,   246,   263,   281,
     294,   306,   317,   328,   336,   347,   352,   357,   362,   367,
     372,   375,   378,   388,   397,   410,   503,   507,   511,   515,
     519,   523,   529,   575,   615,   624,   633,   655,   677,   699,
     721,   739,   742,   745,   784,   790,   795,   799,   808,   819,
     827,   835,   843,   851,   859,   867,   875,   883,   892,   951,
     991,  1051,  1067,  1073,  1079,  1087,  1095,  1102,  1109,  1116,
    1123,  1130,  1134
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
  "\"end of file\"", "error", "\"invalid token\"", "TK_NUM", "TK_REAL",
  "TK_CHAR", "TK_TRUE", "TK_FALSE", "TK_STRING", "TK_VOID", "TK_FUNCTION",
  "TK_MAIN", "TK_ID", "TK_TIPO_INT", "TK_TIPO_FLOAT", "TK_TIPO_CHAR",
  "TK_TIPO_BOOL", "TK_TIPO_STRING", "TK_CAST_FLOAT", "TK_CAST_INT",
  "TK_CAST_BOOL", "TK_MAIOR_IGUAL", "TK_MENOR_IGUAL", "TK_IGUAL_IGUAL",
  "TK_DIFERENTE", "TK_MAIS_MAIS", "TK_MENOS_MENOS", "TK_OU", "TK_E",
  "TK_MAIS_IGUAL", "TK_MENOS_IGUAL", "TK_IF", "TK_ELSE", "TK_WHILE",
  "TK_FOR", "TK_DO", "TK_SWITCH", "TK_CASE", "TK_BREAK", "TK_CONTINUE",
  "TK_PRINT", "TK_SCAN", "TK_RETURN", "TK_ERROR", "'+'", "TK_CAST_CHAR",
  "'('", "')'", "';'", "','", "'{'", "'}'", "':'", "'-'", "'>'", "'<'",
  "'!'", "'='", "'*'", "'/'", "'%'", "$accept", "S", "FUNCAO", "DECLAFUNC",
  "PARAMETERS", "PARAMETER", "BLOCO", "COMANDOS", "CASES", "CASE",
  "COMANDO", "DECLARACAO", "TIPOS", "E", "CHAMADAS", "CHAMADA",
  "RELACIONAL", "ATRIBUICAO", "M", "P", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-91)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     526,   -91,   114,   -48,    -1,   -91,   -91,   -91,   -91,    11,
     526,   -34,   -27,     2,   -22,   -91,    18,   335,    -9,   -91,
     -91,   114,   526,   -91,   526,   -91,   -91,   -91,   -91,   -91,
     -91,   -91,   -10,     0,    12,   335,   335,    13,    14,   335,
     335,   335,   506,   -91,   -91,    48,   -91,    -5,    -2,   -91,
      15,   -91,   -91,   -91,   -91,   335,   335,   335,   506,   506,
     335,    49,   506,    98,   506,   335,   335,   335,   335,   335,
     335,   335,   335,   335,   335,   136,   136,   136,    16,    16,
     114,   209,    21,   -91,   361,   371,   382,    22,   -91,   506,
     506,   506,   506,   506,   506,   506,   506,   506,   506,   -91,
     -91,   -91,   -91,   264,   -91,   -91,   -91,   335,   -91,   -91,
     -91,   -91,   -91,     0,    12,    17,    24,    25,    16,    28,
      30,    31,   335,   264,    29,   264,    34,   263,   -91,   335,
     335,    -4,    43,   136,   -91,   -91,   400,   -91,   -91,   -91,
     -91,   -91,   411,   422,    36,    37,    42,    46,   -91,   318,
      16,    50,   335,   335,    52,   156,   440,   264,    16,   506,
      61,   451,    59,   318,   -91,   210,   -91,   264,   335,    63,
      97,    64,    59,   264,   459,   318,   -91,   -91,   469,   264,
      62,   264,   -91,   -91,   264,   264,   498,    16,   -91,   264,
     -91,   -91,   -91,   264,   264,   -91,   -91,   -91
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    41,     0,     0,    36,    37,    38,    40,    39,     0,
       0,     0,     0,     0,     0,    36,     0,     0,     0,     1,
       5,     9,     0,    35,     0,     7,    74,    75,    76,    78,
      79,    77,    80,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    68,    51,    52,    54,    72,     0,     0,     8,
      10,     3,     4,    44,    45,    56,     0,     0,    47,    48,
       0,     0,    49,     0,    67,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    57,     0,    55,     0,     0,     0,     0,    73,    61,
      62,    63,    64,    65,    66,    59,    60,    42,    43,    80,
      69,    70,    71,    26,     2,     6,    11,     0,    53,    50,
      46,    81,    82,    36,    37,     0,     0,     0,     0,     0,
       0,     0,     0,    26,     0,    26,     0,     0,    58,     0,
       0,     0,     0,     0,    32,    33,     0,    14,    12,    13,
      31,    30,     0,     0,     0,     0,     0,     0,    34,     0,
       0,     0,     0,     0,     0,    26,     0,    26,     0,     0,
      51,     0,    28,     0,    18,    26,    21,    26,     0,     0,
       0,     0,    28,    26,     0,     0,    15,    23,     0,    26,
       0,    26,    27,    20,    26,    26,     0,     0,    22,    26,
      25,    19,    17,    26,    26,    29,    16,    24
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -91,    10,   -91,   -91,   -91,    38,   -77,   -90,   -56,   -91,
     -91,     7,   115,   -17,   -91,    26,   -28,     3,   -91,   -71
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     9,    10,    11,    48,    49,   123,   124,   171,   172,
     125,   126,    13,   127,    82,    83,    43,    44,    45,    46
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      42,   104,   105,    14,   100,   101,   102,    12,     3,    17,
      18,    19,    21,    14,    23,    53,    54,    12,    58,    59,
      20,    22,    62,    63,    64,    14,    24,    14,    50,    12,
      25,    12,    51,   137,    52,   139,    55,    47,    81,    84,
      85,   132,    78,    86,   144,    79,    56,    17,    89,    90,
      91,    92,    93,    94,    95,    96,    97,    98,    57,    60,
      61,    87,   147,   129,    80,   164,   103,   166,   108,   112,
     130,   131,   155,   157,   133,   176,   146,   177,   134,   135,
     138,   167,   140,   183,   151,   152,   173,    50,   153,   188,
      81,   190,    73,   154,   191,   192,   170,   158,   185,   195,
     180,    74,   162,   196,   197,   136,    75,    76,    77,   168,
     194,   179,   142,   143,   189,   181,   182,    16,   106,    65,
      66,    67,    68,     1,   160,    69,    70,    15,     5,     6,
       7,     8,   156,   128,   145,   159,   161,     0,     0,    26,
      27,    28,    29,    30,    31,    88,   174,     0,    99,     0,
       0,   178,    71,    72,     0,     0,     0,     0,   186,    26,
      27,    28,    29,    30,    31,     1,     0,     0,    32,   113,
     114,     6,     7,     8,    35,    36,    37,    38,     0,     0,
       0,     0,    40,     0,     0,     0,     0,   115,   163,   116,
     117,   118,   119,     0,   120,   121,    37,    38,   122,     0,
       0,    39,    40,     0,     0,     0,   103,     0,     0,     0,
       0,     0,    41,    26,    27,    28,    29,    30,    31,     1,
       0,     0,    32,   113,   114,     6,     7,     8,    35,    36,
      65,    66,    67,    68,     0,     0,    69,    70,     0,     0,
       0,   115,   175,   116,   117,   118,   119,     0,   120,   121,
      37,    38,   122,     0,     0,    39,    40,     0,   107,     0,
     103,     0,     0,    71,    72,     0,    41,    26,    27,    28,
      29,    30,    31,     1,     0,     0,    32,   113,   114,     6,
       7,     8,    35,    36,    65,    66,    67,    68,     0,     0,
      69,    70,     0,     0,     0,   115,     0,   116,   117,   118,
     119,     0,   120,   121,    37,    38,   122,     0,     0,    39,
      40,   141,     0,     0,   103,     0,     0,    71,    72,     0,
      41,    26,    27,    28,    29,    30,    31,     0,     0,     0,
      32,    33,    34,     0,     0,     0,    35,    36,    26,    27,
      28,    29,    30,    31,     0,     0,     0,    32,    33,    34,
       0,     0,     0,    35,    36,     0,     0,     0,    37,    38,
       0,     0,     0,    39,    40,     0,     0,     0,   103,     0,
       0,     0,     0,     0,    41,    37,    38,     0,     0,     0,
      39,    40,    65,    66,    67,    68,     0,     0,    69,    70,
       0,    41,    65,    66,    67,    68,     0,     0,    69,    70,
       0,     0,     0,    65,    66,    67,    68,     0,   109,    69,
      70,     0,     0,     0,     0,    71,    72,     0,   110,     0,
       0,    65,    66,    67,    68,    71,    72,    69,    70,   111,
       0,     0,    65,    66,    67,    68,    71,    72,    69,    70,
       0,     0,     0,    65,    66,    67,    68,     0,   148,    69,
      70,     0,     0,     0,    71,    72,     0,     0,   149,     0,
       0,    65,    66,    67,    68,    71,    72,    69,    70,   150,
       0,     0,    65,    66,    67,    68,    71,    72,    69,    70,
      65,    66,    67,    68,     0,     0,    69,    70,   165,     0,
      65,    66,    67,    68,    71,    72,    69,    70,   169,     0,
       0,     0,     0,     0,     0,    71,    72,   184,     0,     0,
       0,     0,     0,    71,    72,     0,   187,     0,     0,    65,
      66,    67,    68,    71,    72,    69,    70,    65,    66,    67,
      68,     0,     0,    69,    70,     1,     2,     0,     3,     4,
       5,     6,     7,     8,     0,     0,   193,     0,     0,     0,
       0,     0,    71,    72,     0,     0,     0,     0,     0,     0,
      71,    72
};

static const yytype_int16 yycheck[] =
{
      17,    78,    79,     0,    75,    76,    77,     0,    12,    57,
      11,     0,    46,    10,    12,    25,    26,    10,    35,    36,
      10,    48,    39,    40,    41,    22,    48,    24,    21,    22,
      12,    24,    22,   123,    24,   125,    46,    46,    55,    56,
      57,   118,    47,    60,    48,    47,    46,    57,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    46,    46,
      46,    12,   133,    46,    49,   155,    50,   157,    47,    47,
      46,    46,   149,   150,    46,   165,    33,   167,    48,    48,
      51,   158,    48,   173,    48,    48,   163,    80,    46,   179,
     107,   181,    44,    47,   184,   185,    37,    47,   175,   189,
       3,    53,    50,   193,   194,   122,    58,    59,    60,    48,
     187,    48,   129,   130,    52,    51,   172,     2,    80,    21,
      22,    23,    24,     9,   152,    27,    28,    13,    14,    15,
      16,    17,   149,   107,   131,   152,   153,    -1,    -1,     3,
       4,     5,     6,     7,     8,    47,   163,    -1,    12,    -1,
      -1,   168,    54,    55,    -1,    -1,    -1,    -1,   175,     3,
       4,     5,     6,     7,     8,     9,    -1,    -1,    12,    13,
      14,    15,    16,    17,    18,    19,    40,    41,    -1,    -1,
      -1,    -1,    46,    -1,    -1,    -1,    -1,    31,    32,    33,
      34,    35,    36,    -1,    38,    39,    40,    41,    42,    -1,
      -1,    45,    46,    -1,    -1,    -1,    50,    -1,    -1,    -1,
      -1,    -1,    56,     3,     4,     5,     6,     7,     8,     9,
      -1,    -1,    12,    13,    14,    15,    16,    17,    18,    19,
      21,    22,    23,    24,    -1,    -1,    27,    28,    -1,    -1,
      -1,    31,    32,    33,    34,    35,    36,    -1,    38,    39,
      40,    41,    42,    -1,    -1,    45,    46,    -1,    49,    -1,
      50,    -1,    -1,    54,    55,    -1,    56,     3,     4,     5,
       6,     7,     8,     9,    -1,    -1,    12,    13,    14,    15,
      16,    17,    18,    19,    21,    22,    23,    24,    -1,    -1,
      27,    28,    -1,    -1,    -1,    31,    -1,    33,    34,    35,
      36,    -1,    38,    39,    40,    41,    42,    -1,    -1,    45,
      46,    48,    -1,    -1,    50,    -1,    -1,    54,    55,    -1,
      56,     3,     4,     5,     6,     7,     8,    -1,    -1,    -1,
      12,    13,    14,    -1,    -1,    -1,    18,    19,     3,     4,
       5,     6,     7,     8,    -1,    -1,    -1,    12,    13,    14,
      -1,    -1,    -1,    18,    19,    -1,    -1,    -1,    40,    41,
      -1,    -1,    -1,    45,    46,    -1,    -1,    -1,    50,    -1,
      -1,    -1,    -1,    -1,    56,    40,    41,    -1,    -1,    -1,
      45,    46,    21,    22,    23,    24,    -1,    -1,    27,    28,
      -1,    56,    21,    22,    23,    24,    -1,    -1,    27,    28,
      -1,    -1,    -1,    21,    22,    23,    24,    -1,    47,    27,
      28,    -1,    -1,    -1,    -1,    54,    55,    -1,    47,    -1,
      -1,    21,    22,    23,    24,    54,    55,    27,    28,    47,
      -1,    -1,    21,    22,    23,    24,    54,    55,    27,    28,
      -1,    -1,    -1,    21,    22,    23,    24,    -1,    48,    27,
      28,    -1,    -1,    -1,    54,    55,    -1,    -1,    47,    -1,
      -1,    21,    22,    23,    24,    54,    55,    27,    28,    47,
      -1,    -1,    21,    22,    23,    24,    54,    55,    27,    28,
      21,    22,    23,    24,    -1,    -1,    27,    28,    48,    -1,
      21,    22,    23,    24,    54,    55,    27,    28,    47,    -1,
      -1,    -1,    -1,    -1,    -1,    54,    55,    48,    -1,    -1,
      -1,    -1,    -1,    54,    55,    -1,    47,    -1,    -1,    21,
      22,    23,    24,    54,    55,    27,    28,    21,    22,    23,
      24,    -1,    -1,    27,    28,     9,    10,    -1,    12,    13,
      14,    15,    16,    17,    -1,    -1,    48,    -1,    -1,    -1,
      -1,    -1,    54,    55,    -1,    -1,    -1,    -1,    -1,    -1,
      54,    55
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     9,    10,    12,    13,    14,    15,    16,    17,    62,
      63,    64,    72,    73,    78,    13,    73,    57,    11,     0,
      62,    46,    48,    12,    48,    12,     3,     4,     5,     6,
       7,     8,    12,    13,    14,    18,    19,    40,    41,    45,
      46,    56,    74,    77,    78,    79,    80,    46,    65,    66,
      72,    62,    62,    25,    26,    46,    46,    46,    74,    74,
      46,    46,    74,    74,    74,    21,    22,    23,    24,    27,
      28,    54,    55,    44,    53,    58,    59,    60,    47,    47,
      49,    74,    75,    76,    74,    74,    74,    12,    47,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    12,
      80,    80,    80,    50,    67,    67,    66,    49,    47,    47,
      47,    47,    47,    13,    14,    31,    33,    34,    35,    36,
      38,    39,    42,    67,    68,    71,    72,    74,    76,    46,
      46,    46,    67,    46,    48,    48,    74,    68,    51,    68,
      48,    48,    74,    74,    48,    78,    33,    80,    48,    47,
      47,    48,    48,    46,    47,    67,    74,    67,    47,    74,
      77,    74,    50,    32,    68,    48,    68,    67,    48,    47,
      37,    69,    70,    67,    74,    32,    68,    68,    74,    48,
       3,    51,    69,    68,    48,    67,    74,    47,    68,    52,
      68,    68,    68,    48,    67,    68,    68,    68
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    61,    62,    62,    62,    62,    63,    64,    65,    65,
      66,    66,    67,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    69,    69,    70,
      71,    71,    71,    71,    71,    72,    73,    73,    73,    73,
      73,    73,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    75,    75,    76,    76,    77,
      77,    77,    77,    77,    77,    77,    77,    77,    78,    79,
      79,    79,    79,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     3,     3,     2,     5,     3,     1,     0,
       1,     3,     3,     2,     2,     7,    10,     9,     6,     9,
       8,     6,     8,     7,    10,     8,     0,     2,     0,     4,
       2,     2,     2,     2,     3,     2,     1,     1,     1,     1,
       1,     1,     3,     3,     2,     2,     4,     2,     2,     2,
       4,     1,     1,     4,     1,     1,     0,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     3,     3,
       3,     3,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     4,     4
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
  case 2: /* S: TK_TIPO_INT TK_MAIN '(' ')' BLOCO  */
#line 126 "sintatica.y"
                        {
				if(error == "")
					cout << "/*Compilador Neolingo*/\n" + warning + "\n"<< "#include <iostream>\n#include <string.h>\n#include <stdio.h>" + atribuicaoVariavelGlobais + "\n" + traducaoFunction  + "\nint main(void)\n{\n" <<  atribuicaoVariavel + "\n" + yyvsp[0].traducao << "\treturn 0;\n}" << endl;
				else{
					cout << "\n" + warning + "\n";
					yyerror(error);
				} 
			}
#line 1578 "y.tab.c"
    break;

  case 3: /* S: DECLARACAO ';' S  */
#line 135 "sintatica.y"
                        {
			}
#line 1585 "y.tab.c"
    break;

  case 4: /* S: ATRIBUICAO ';' S  */
#line 138 "sintatica.y"
                        {
				traducaoFunction += yyvsp[-2].traducao;
			}
#line 1593 "y.tab.c"
    break;

  case 5: /* S: FUNCAO S  */
#line 142 "sintatica.y"
                        {
			}
#line 1600 "y.tab.c"
    break;

  case 6: /* FUNCAO: DECLAFUNC '(' PARAMETERS ')' BLOCO  */
#line 147 "sintatica.y"
                        {
				TIPO_FUNCTION function = getFunction();

				int size = tabelaFunction.size() - 1;
				tabelaFunction[size].nomeFunction = yyvsp[-4].label;

				if((function.retornoLabel == "") && (yyvsp[-4].tipo != "void"))
					error += "\033[1;31merror\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Função não apresenta um retorno.\n";
				else if((function.retornoLabel != "") && (yyvsp[-4].tipo == "void"))
					error += "\033[1;31merror\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Função void não poder conter um retorno.\n";
				else if(yyvsp[-4].tipo != function.retornoTipo && (yyvsp[-4].tipo != "void"))
					error += "\033[1;31merror\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Tipo de return não condiz com o tipo da função.\n";

				traducaoFunction += yyvsp[0].traducao + "\tEndFunc" + ";\n\n";
			}
#line 1620 "y.tab.c"
    break;

  case 7: /* DECLAFUNC: TK_FUNCTION TIPOS TK_ID  */
#line 165 "sintatica.y"
                   {
			   int size = tabelaFunction.size() - 1;
			   for(int i = size; i >= 0; i--)
			   {
				   if(yyvsp[0].label == tabelaFunction[i].nomeFunction)
				   {
						error += "\033[1;31merror\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Nome de função já existe.\n";
				   }
			   }

			   traducaoFunction += "    _" + yyvsp[0].label + ":\n";
			   yyval.label = yyvsp[0].label;
			   yyval.tipo = yyvsp[-1].tipo;
		   }
#line 1639 "y.tab.c"
    break;

  case 8: /* PARAMETERS: PARAMETER  */
#line 182 "sintatica.y"
                   {
		   }
#line 1646 "y.tab.c"
    break;

  case 9: /* PARAMETERS: %empty  */
#line 185 "sintatica.y"
                   {
		   }
#line 1653 "y.tab.c"
    break;

  case 10: /* PARAMETER: DECLARACAO  */
#line 190 "sintatica.y"
                    {
		    }
#line 1660 "y.tab.c"
    break;

  case 11: /* PARAMETER: DECLARACAO ',' PARAMETER  */
#line 193 "sintatica.y"
                    {
		    }
#line 1667 "y.tab.c"
    break;

  case 12: /* BLOCO: '{' COMANDOS '}'  */
#line 198 "sintatica.y"
                        {
				yyval.traducao = yyvsp[-1].traducao;
			}
#line 1675 "y.tab.c"
    break;

  case 13: /* COMANDOS: COMANDO COMANDOS  */
#line 204 "sintatica.y"
                        {
				yyval.traducao = yyvsp[-1].traducao + yyvsp[0].traducao;
			}
#line 1683 "y.tab.c"
    break;

  case 14: /* COMANDOS: BLOCO COMANDOS  */
#line 208 "sintatica.y"
                        {
				yyval.traducao = yyvsp[-1].traducao + yyvsp[0].traducao;
			}
#line 1691 "y.tab.c"
    break;

  case 15: /* COMANDOS: TK_IF '(' E ')' E ';' COMANDOS  */
#line 212 "sintatica.y"
                        {
				verificarAtributoRelacional(yyvsp[-4]);
				yyval.label = gentempcode();

				if(controleFunction > 0){
					traducaoFunction = traducaoFunction + "\t" + "int" + " " + yyval.label +";\n";
				} else {
					atribuicaoVariavel = atribuicaoVariavel + "\t" + "int" + " " + yyval.label +";\n";
				}

				string cond = genCondcode();

				yyval.traducao = yyvsp[-4].traducao + "\t" 
				+ yyval.label + " = !" + yyvsp[-4].label + ";\n" + "\t"
				"if(" + yyval.label + ") goto "+ cond + "\n" + 
				yyvsp[-2].traducao + "\t" + cond + "\n" + yyvsp[0].traducao;
			}
#line 1713 "y.tab.c"
    break;

  case 16: /* COMANDOS: TK_IF '(' E ')' E ';' TK_ELSE E ';' COMANDOS  */
#line 230 "sintatica.y"
                        {
				verificarAtributoRelacional(yyvsp[-7]);
				yyval.label = gentempcode();
				if(controleFunction > 0){
					traducaoFunction = traducaoFunction + "\t" + "int" + " " + yyval.label +";\n";
				} else {
					atribuicaoVariavel = atribuicaoVariavel + "\t" + "int" + " " + yyval.label +";\n";
				}
				string cond = genCondcode();

				yyval.traducao = yyvsp[-7].traducao + "\t" 
				+ yyval.label + " = !" + yyvsp[-7].label + ";\n" + "\t"
				"if(" + yyval.label + ") goto ELSE;" + "\n" + 
				yyvsp[-5].traducao + "\tgoto " + cond + "\n" + "\tELSE:\n" + yyvsp[-2].traducao
				+ "\t" + cond +"\n" + yyvsp[0].traducao;
			}
#line 1734 "y.tab.c"
    break;

  case 17: /* COMANDOS: TK_IF '(' E ')' E ';' TK_ELSE BLOCO COMANDOS  */
#line 247 "sintatica.y"
                        {
				verificarAtributoRelacional(yyvsp[-6]);
				yyval.label = gentempcode();
				if(controleFunction > 0){
					traducaoFunction = traducaoFunction + "\t" + "int" + " " + yyval.label +";\n";
				} else {
					atribuicaoVariavel = atribuicaoVariavel + "\t" + "int" + " " + yyval.label +";\n";
				}
				string cond = genCondcode();

				yyval.traducao = yyvsp[-6].traducao + "\t" 
				+ yyval.label + " = !" + yyvsp[-6].label + ";\n" + "\t"
				"if(" + yyval.label + ") goto ELSE;\n" + yyvsp[-4].traducao
				+ "\tgoto "+cond+"\n" + "\tELSE:\n" + yyvsp[-1].traducao + "\t"+cond+"\n" +
				yyvsp[0].traducao;
			}
#line 1755 "y.tab.c"
    break;

  case 18: /* COMANDOS: TK_IF '(' E ')' BLOCO COMANDOS  */
#line 264 "sintatica.y"
                        {
				verificarAtributoRelacional(yyvsp[-3]);
				yyval.label = gentempcode();

				if(!mainStatus){
					traducaoFunction = traducaoFunction + "\t" + "int" + " " + yyval.label +";\n";
				} else {
					atribuicaoVariavel = atribuicaoVariavel + "\t" + "int" + " " + yyval.label +";\n";
				}

				string cond = genCondcode();

				yyval.traducao = yyvsp[-3].traducao + "\t" 
				+ yyval.label + " = !" + yyvsp[-3].label + ";\n" + "\t"
				"if(" + yyval.label + ") goto " + cond + "\n"
				+ yyvsp[-1].traducao + "\t" + cond + "\n" + yyvsp[0].traducao;
			}
#line 1777 "y.tab.c"
    break;

  case 19: /* COMANDOS: TK_IF '(' E ')' BLOCO TK_ELSE E ';' COMANDOS  */
#line 282 "sintatica.y"
                        {
				verificarAtributoRelacional(yyvsp[-6]);
				yyval.label = gentempcode();
				atribuicaoVariavel = atribuicaoVariavel + "\t" + "int" + " " + yyval.label +";\n";
				string cond = genCondcode();

				yyval.traducao = yyvsp[-6].traducao + "\t" 
				+ yyval.label + " = !" + yyvsp[-6].label + ";\n" + "\t"
				"if(" + yyval.label + ") goto ELSE;\n" + yyvsp[-4].traducao +
				"\tgoto " + cond + "\n" + "\tELSE:\n" + yyvsp[-2].traducao
				+ "\t" + cond +"\n" + yyvsp[0].traducao ;
			}
#line 1794 "y.tab.c"
    break;

  case 20: /* COMANDOS: TK_IF '(' E ')' BLOCO TK_ELSE BLOCO COMANDOS  */
#line 295 "sintatica.y"
                        {
				verificarAtributoRelacional(yyvsp[-5]);
				yyval.label = gentempcode();
				atribuicaoVariavel = atribuicaoVariavel + "\t" + "int" + " " + yyval.label +";\n";
				string cond = genCondcode();

				yyval.traducao = yyvsp[-5].traducao + "\t" 
				+ yyval.label + " = !" + yyvsp[-5].label + ";\n" + "\t"
				"if(" + yyval.label + ") goto ELSE;\n" + yyvsp[-3].traducao +
				"\tgoto " + cond + "\n" + "\tELSE:\n" + yyvsp[-1].traducao + "\t"+cond+"\n" + yyvsp[0].traducao;
			}
#line 1810 "y.tab.c"
    break;

  case 21: /* COMANDOS: TK_WHILE '(' E ')' BLOCO COMANDOS  */
#line 307 "sintatica.y"
                        {
				verificarAtributoRelacional(yyvsp[-3]);
				yyval.label = gentempcode();
				atribuicaoVariavel = atribuicaoVariavel + "\t" + "int" + " " + yyval.label +";\n";
				TIPO_LOOP loop = getLace(yyvsp[-5].label);

				yyval.traducao = loop.inicioLaco + yyvsp[-3].traducao + "\t" + yyval.label + " = !" +
				yyvsp[-3].label + ";\n" + "\tIF(" + yyval.label + ") goto " + loop.fimLaco + "\n" +
				yyvsp[-1].traducao + "\tgoto " + loop.inicioLaco + "\n\t" + loop.fimLaco + "\n" + yyvsp[0].traducao;
			}
#line 1825 "y.tab.c"
    break;

  case 22: /* COMANDOS: TK_DO BLOCO TK_WHILE '(' E ')' ';' COMANDOS  */
#line 318 "sintatica.y"
                        {
				verificarAtributoRelacional(yyvsp[-3]);
				yyval.label = gentempcode();
				atribuicaoVariavel = atribuicaoVariavel + "\t" + "int" + " " + yyval.label +";\n";
				TIPO_LOOP loop = getLace(yyvsp[-7].label);

				yyval.traducao = loop.inicioLaco + yyvsp[-6].traducao + yyvsp[-3].traducao + "\t" 
				+ yyval.label + " = !" + yyvsp[-3].label + ";\n" + "\tIF(" + yyval.label +") goto " 
				+ loop.fimLaco  + "\n" + "\tgoto " + loop.inicioLaco + "\n\t" + loop.fimLaco +" \n"+ yyvsp[0].traducao;
			}
#line 1840 "y.tab.c"
    break;

  case 23: /* COMANDOS: TK_FOR '(' ';' ';' ')' BLOCO COMANDOS  */
#line 329 "sintatica.y"
                        {
				yyval.label = gentempcode();
				atribuicaoVariavel = atribuicaoVariavel + "\t" + "int" + " " + yyval.label +";\n";
				TIPO_LOOP loop = getLace(yyvsp[-6].label); 

				yyval.traducao = loop.inicioLaco + yyvsp[-1].traducao + "\t" + "goto " + loop.inicioLaco + "\n\t" + loop.fimLaco +"\n" + yyvsp[0].traducao;
			}
#line 1852 "y.tab.c"
    break;

  case 24: /* COMANDOS: TK_FOR '(' ATRIBUICAO ';' RELACIONAL ';' E ')' BLOCO COMANDOS  */
#line 337 "sintatica.y"
                        {
				yyval.label = gentempcode();
				atribuicaoVariavel = atribuicaoVariavel + "\t" + "int" + " " + yyval.label +";\n";
				string lace = genLacecode();
				string cond = genCondcode();

				yyval.traducao = yyvsp[-7].traducao + lace + yyvsp[-5].traducao + "\t" + yyval.label + 
				" = !" + yyvsp[-5].label + ";\n\t" + "if(" + yyval.label + ") goto "+ cond + "\n" + 
				yyvsp[-1].traducao + yyvsp[-3].traducao + "\tgoto " + lace + "\n\t"+ cond +"\n" + yyvsp[0].traducao;
			}
#line 1867 "y.tab.c"
    break;

  case 25: /* COMANDOS: TK_SWITCH '(' P ')' '{' CASES '}' COMANDOS  */
#line 348 "sintatica.y"
                        {
				yyval.traducao = yyvsp[-5].traducao + yyvsp[-2].traducao + yyvsp[0].traducao;
			}
#line 1875 "y.tab.c"
    break;

  case 26: /* COMANDOS: %empty  */
#line 352 "sintatica.y"
                        {
				yyval.traducao = "";
			}
#line 1883 "y.tab.c"
    break;

  case 27: /* CASES: CASE CASES  */
#line 358 "sintatica.y"
                        {
				yyval.traducao = yyvsp[-1].traducao + yyvsp[0].traducao;
			}
#line 1891 "y.tab.c"
    break;

  case 28: /* CASES: %empty  */
#line 362 "sintatica.y"
                        {
				yyval.traducao = "";
			}
#line 1899 "y.tab.c"
    break;

  case 29: /* CASE: TK_CASE TK_NUM ':' COMANDOS  */
#line 368 "sintatica.y"
                        {
			}
#line 1906 "y.tab.c"
    break;

  case 30: /* COMANDO: E ';'  */
#line 373 "sintatica.y"
                        {
			}
#line 1913 "y.tab.c"
    break;

  case 31: /* COMANDO: DECLARACAO ';'  */
#line 376 "sintatica.y"
                        {
			}
#line 1920 "y.tab.c"
    break;

  case 32: /* COMANDO: TK_BREAK ';'  */
#line 379 "sintatica.y"
                        {
				if(controleLoop == 0)
				{
					error += "\033[1;31merror\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Break não existente em um loop.\n";
				} else {
					TIPO_LOOP loop = getLaceBreak();
					yyval.traducao = "\tgoto " + loop.fimLaco + "\n";
				}
			}
#line 1934 "y.tab.c"
    break;

  case 33: /* COMANDO: TK_CONTINUE ';'  */
#line 389 "sintatica.y"
                        {
				if(controleLoop == 0){
					error += "\033[1;31merror\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Continue não existente em um loop.\n";
				} else {
					TIPO_LOOP loop = getLaceBreak();
					yyval.traducao = "\tgoto " + loop.inicioLaco + "\n";
				}
			}
#line 1947 "y.tab.c"
    break;

  case 34: /* COMANDO: TK_RETURN E ';'  */
#line 398 "sintatica.y"
                        {
				if(controleFunction == 0){
					error += "\033[1;31merror\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Return não está dentro de uma função.\n";
				}
				
				int size = tabelaFunction.size() - 1;
				tabelaFunction[size].retornoLabel = yyvsp[-1].label;
				tabelaFunction[size].retornoTipo = yyvsp[-1].tipo;
				yyval.traducao += yyvsp[-1].traducao + "\tReturn " + yyvsp[-1].label + ";\n";
			}
#line 1962 "y.tab.c"
    break;

  case 35: /* DECLARACAO: TIPOS TK_ID  */
#line 411 "sintatica.y"
                        {
				if(yyvsp[-1].tipo == "void")
					error += "\033[1;31mError\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Void não é um tipo declarável.\n";

				if(yyvsp[-1].tipo != "string"){
					int indiceTopo = tabelaFunction.size() - 1;
					if(controleFunction > 0 && getContexto() == 0){

						TIPO_SIMBOLO simb;
						simb.nomeVariavel = yyvsp[0].label;
						simb.tipoVariavel = yyvsp[-1].tipo;
						simb.labelVariavel = gentempcode();

						if(tabelaFunction[indiceTopo].parameters.size() == 0)
						{
							tabelaFunction[indiceTopo].parameters.push_back(simb);

						} else {
							for (int i = tabelaFunction[indiceTopo].parameters.size(); i >= 0; i--)
							{
								if(tabelaFunction[indiceTopo].parameters[i].nomeVariavel == yyvsp[0].label)
								{
									error += "\033[1;31mError\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Nome do parâmetro '" + yyvsp[0].label + "' ja utilizado na função.\n";
								}	
							}
							tabelaFunction[indiceTopo].parameters.push_back(simb);
						}
						traducaoFunction = traducaoFunction + "\t" + simb.tipoVariavel + " " + simb.labelVariavel +";\n";
						
					} else {

						if(controleFunction > 0 && getContexto() > 0){
							int indiceTopoParameters = tabelaFunction[indiceTopo].parameters.size();
							for (int i = indiceTopoParameters; i >= 0; i--)
							{ 
								if(tabelaFunction[indiceTopo].parameters[i].nomeVariavel == yyvsp[0].label)
								{
									error += "\033[1;31mError\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Váriavel '" + yyvsp[0].label + "' não poderá ser de declarada nesta função.\n";
								}	
							}
						}

						verificarVariavelRepetida(yyvsp[0].label);
						addSimbolo(yyvsp[0].label, yyvsp[-1].tipo, gentempcode());
						yyval.traducao = "";
						yyval.label = "";
					}
				} else {
					int indiceTopo = tabelaFunction.size() - 1;
					if(controleFunction > 0 && getContexto() == 0){
						TIPO_SIMBOLO simb;
						simb.nomeVariavel = yyvsp[0].label;
						simb.tipoVariavel = yyvsp[-1].tipo;
						simb.labelVariavel = gentempcode();

						if(tabelaFunction[indiceTopo].parameters.size() == 0)
						{
							tabelaFunction[indiceTopo].parameters.push_back(simb);
						} else {
							for (int i = tabelaFunction[indiceTopo].parameters.size(); i >= 0; i--)
							{ 
								if(tabelaFunction[indiceTopo].parameters[i].nomeVariavel == yyvsp[0].label)
								{
									error += "\033[1;31mError\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Nome do parâmetro '" + yyvsp[0].label + "' ja utilizado na função.\n";
								}	
							}
							tabelaFunction[indiceTopo].parameters.push_back(simb);
						}
						traducaoFunction = traducaoFunction + "\t" + "char" + " *" + simb.labelVariavel + ";\n";
					} else {
						if(controleFunction > 0 && getContexto() > 0){
							int indiceTopoParameters = tabelaFunction[indiceTopo].parameters.size();
							for (int i = indiceTopoParameters; i >= 0; i--)
							{ 
								if(tabelaFunction[indiceTopo].parameters[i].nomeVariavel == yyvsp[0].label)
								{
									error += "\033[1;31mError\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Váriavel '" + yyvsp[0].label + "' não poderá ser de declarada nesta função.\n";
								}	
							}
						}

						string label = gentempcode();
						verificarVariavelRepetida(yyvsp[0].label);
						addString(yyvsp[0].label, "string", label);
						yyval.traducao = "";
						yyval.tipo = "string";
						yyval.label = "\tstrcpy(" + label + ", " + "\0" + ");\n";
					}
				}
			}
#line 2057 "y.tab.c"
    break;

  case 36: /* TIPOS: TK_TIPO_INT  */
#line 504 "sintatica.y"
                        {
				yyval.tipo = "int";
			}
#line 2065 "y.tab.c"
    break;

  case 37: /* TIPOS: TK_TIPO_FLOAT  */
#line 508 "sintatica.y"
                        {
				yyval.tipo = "float";
			}
#line 2073 "y.tab.c"
    break;

  case 38: /* TIPOS: TK_TIPO_CHAR  */
#line 512 "sintatica.y"
                        {
				yyval.tipo = "char";
			}
#line 2081 "y.tab.c"
    break;

  case 39: /* TIPOS: TK_TIPO_STRING  */
#line 516 "sintatica.y"
                        {
				yyval.tipo = "string";
			}
#line 2089 "y.tab.c"
    break;

  case 40: /* TIPOS: TK_TIPO_BOOL  */
#line 520 "sintatica.y"
                        {
				yyval.tipo = "bool";
			}
#line 2097 "y.tab.c"
    break;

  case 41: /* TIPOS: TK_VOID  */
#line 524 "sintatica.y"
                        {
				yyval.tipo = "void";
			}
#line 2105 "y.tab.c"
    break;

  case 42: /* E: M '+' E  */
#line 530 "sintatica.y"
                        {
				yyval.label = gentempcode();
				string tipoAux;
				string labelAux;
				
				//cout << $1.tipo;

				if(yyvsp[-2].tipo == "string" && yyvsp[0].tipo == "string"){
					error += "\033[1;31mError\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Concatenação de string em breve.\n";
				}

				if(yyvsp[-2].tipo == yyvsp[0].tipo){
					yyval.tipo = yyvsp[-2].tipo;
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
					yyval.label + " = " + yyvsp[-2].label + " + " + yyvsp[0].label + ";\n";
					addTemp(yyval.label, yyval.tipo);
				}
				else if(yyvsp[-2].tipo == "int" & yyvsp[0].tipo == "float"){
					yyval.tipo = yyvsp[0].tipo;
					addTemp(yyval.label, yyval.tipo);
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
					yyval.label + " = (float) " + yyvsp[-2].label + ";\n";

					labelAux = yyval.label;
					yyval.label = gentempcode();
					addTemp(yyval.label, yyval.tipo);
					yyval.traducao = yyval.traducao + "\t"+
					yyval.label + " = " + labelAux + " + " + yyvsp[0].label + ";\n";
				}
				else if(yyvsp[-2].tipo == "float" & yyvsp[0].tipo == "int"){
					yyval.tipo = yyvsp[-2].tipo;
					addTemp(yyval.label, yyval.tipo);
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
					yyval.label + " = (float) " + yyvsp[0].label + ";\n";

					labelAux = yyval.label;
					yyval.label = gentempcode();
					addTemp(yyval.label, yyval.tipo);
					yyval.traducao = yyval.traducao + "\t"+
					yyval.label + " = " + yyvsp[-2].label + " + " + labelAux + ";\n";
				}
				else{
					error += "\033[1;31mError\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Operandos com tipos inválidos.\n";
				}
			}
#line 2155 "y.tab.c"
    break;

  case 43: /* E: M '-' E  */
#line 576 "sintatica.y"
                        {
				yyval.label = gentempcode();
				string tipoAux;
				string labelAux;

				if(yyvsp[-2].tipo == yyvsp[0].tipo){
					yyval.tipo = yyvsp[-2].tipo;
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
					yyval.label + " = " + yyvsp[-2].label + " - " + yyvsp[0].label + ";\n";
					addTemp(yyval.label, yyval.tipo);
				}
				else if(yyvsp[-2].tipo == "int" & yyvsp[0].tipo == "float"){
					yyval.tipo = yyvsp[0].tipo;
					addTemp(yyval.label, yyval.tipo);
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
					yyval.label + " = (float) " + yyvsp[-2].label + ";\n";

					labelAux = yyval.label;
					yyval.label = gentempcode();
					addTemp(yyval.label, yyval.tipo);
					yyval.traducao = yyval.traducao + "\t"+
					yyval.label + " = " + labelAux + " - " + yyvsp[0].label + ";\n";
				}
				else if(yyvsp[-2].tipo == "float" & yyvsp[0].tipo == "int"){
					yyval.tipo = yyvsp[-2].tipo;
					addTemp(yyval.label, yyval.tipo);
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
					yyval.label + " = (float) " + yyvsp[0].label + ";\n";

					labelAux = yyval.label;
					yyval.label = gentempcode();
					addTemp(yyval.label, yyval.tipo);
					yyval.traducao = yyval.traducao + "\t"+
					yyval.label + " = " + yyvsp[-2].label + " - " + labelAux + ";\n";
				}
				else{
					error += "\033[1;31mError\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Operandos com tipos inválidos.\n";
				}
			}
#line 2199 "y.tab.c"
    break;

  case 44: /* E: TK_ID TK_MAIS_MAIS  */
#line 616 "sintatica.y"
                        {
				TIPO_SIMBOLO variavel_1 = getSimbolo(yyvsp[-1].label);
				if(variavel_1.tipoVariavel == "char" || variavel_1.tipoVariavel == "string" || variavel_1.tipoVariavel == "bool" || variavel_1.tipoVariavel == "float"){
					error += "\033[1;31merror\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Tipo inválido para operação unária.\n";
				}
				yyval.traducao = yyvsp[-1].traducao + yyvsp[0].traducao + "\t" + 
				variavel_1.labelVariavel + " = " + variavel_1.labelVariavel + " + 1" + ";\n";
			}
#line 2212 "y.tab.c"
    break;

  case 45: /* E: TK_ID TK_MENOS_MENOS  */
#line 625 "sintatica.y"
                        {
				TIPO_SIMBOLO variavel_1 = getSimbolo(yyvsp[-1].label);
				if(variavel_1.tipoVariavel == "char" || variavel_1.tipoVariavel == "string" || variavel_1.tipoVariavel == "bool" || variavel_1.tipoVariavel == "float"){
					error += "\033[1;31merror\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Tipo inválido para operação unária.\n";
				}
				yyval.traducao = yyvsp[-1].traducao + yyvsp[0].traducao + "\t" + 
				variavel_1.labelVariavel + " = " + variavel_1.labelVariavel + " - 1" + ";\n";
			}
#line 2225 "y.tab.c"
    break;

  case 46: /* E: TK_TIPO_FLOAT '(' E ')'  */
#line 634 "sintatica.y"
                        {		
				yyval.label = gentempcode();
				yyval.tipo  = "float";

				addTemp(yyval.label, yyval.tipo);
				
				if(yyvsp[-1].tipo == "int")
				{	
					yyval.traducao = yyvsp[-1].traducao + "\t" + 
					yyval.label + " = " + "(float) " + yyvsp[-1].label + ";\n";  
				} else if (yyvsp[-1].tipo == "float")
				{
					yyval.traducao = yyvsp[-1].traducao + "\t" + 
					yyval.label + " = " + "(float) " + yyvsp[-1].label + ";\n";
					warning += "\033[1;33mWarning\033[0m - Linha " + contLinha +  ": as variáveis já apresentam o mesmo tipo.\n";
				}
				else
				{
					error += "\n\033[1;31mError\033[0m - Linha " + contLinha +  ": Casting inválido";
				}
			}
#line 2251 "y.tab.c"
    break;

  case 47: /* E: TK_CAST_FLOAT E  */
#line 656 "sintatica.y"
                        {
				yyval.label = gentempcode();
				yyval.tipo  = "float";
				addTemp(yyval.label, yyval.tipo);

				if(yyvsp[0].tipo == "int")
				{
					yyval.traducao = yyvsp[0].traducao + "\t" + 
					yyval.label + " = (float) " + yyvsp[0].label + ";\n";
				}
				else if (yyvsp[0].tipo == "float")
				{
					yyval.traducao = yyvsp[0].traducao + "\t" + 
					yyval.label + " = (float) " + yyvsp[0].label + ";\n";
					warning += "\033[1;33mWarning\033[0m - Linha " + contLinha + ": as variáveis já apresentam o mesmo tipo.\n";
				}
				else
				{
					error += "\033[1;31mError\033[0m - Linha " + contLinha + ": Casting inválido para float.\n";
				}
			}
#line 2277 "y.tab.c"
    break;

  case 48: /* E: TK_CAST_INT E  */
#line 678 "sintatica.y"
                        {
				yyval.label = gentempcode();
				yyval.tipo  = "int";
				addTemp(yyval.label, yyval.tipo);

				if(yyvsp[0].tipo == "float")
				{
					yyval.traducao = yyvsp[0].traducao + "\t" + 
					yyval.label + " = (int) " + yyvsp[0].label + ";\n";
				}
				else if (yyvsp[0].tipo == "int")
				{
					yyval.traducao = yyvsp[0].traducao + "\t" + 
					yyval.label + " = (int) " + yyvsp[0].label + ";\n";
					warning += "\033[1;33mWarning\033[0m - Linha " + contLinha + ": as variáveis já apresentam o mesmo tipo.\n";
				}
				else
				{
					error += "\033[1;31mError\033[0m - Linha " + contLinha + ": Casting inválido para int.\n";
				}
			}
#line 2303 "y.tab.c"
    break;

  case 49: /* E: TK_CAST_CHAR E  */
#line 700 "sintatica.y"
                        {
				yyval.label = gentempcode();
				yyval.tipo  = "char";
				addTemp(yyval.label, yyval.tipo);

				if(yyvsp[0].tipo == "int")
				{
					yyval.traducao = yyvsp[0].traducao + "\t" + 
					yyval.label + " = (char) " + yyvsp[0].label + ";\n";
				}
				else if(yyvsp[0].tipo == "char")
				{
					yyval.traducao = yyvsp[0].traducao + "\t" + 
					yyval.label + " = (char) " + yyvsp[0].label + ";\n";
					warning += "\033[1;33mWarning\033[0m - Linha " + contLinha + ": as variáveis já apresentam o mesmo tipo.\n";
				}
				else
				{
					error += "\033[1;31mError\033[0m - Linha " + contLinha + ": Casting inválido para char.\n";
				}
			}
#line 2329 "y.tab.c"
    break;

  case 50: /* E: TK_TIPO_INT '(' E ')'  */
#line 722 "sintatica.y"
                        {	
				yyval.label = gentempcode();
				yyval.tipo  = "int";
				addTemp(yyval.label, yyval.tipo);

				if(yyvsp[-1].tipo == "float")
				{
					yyval.traducao = yyvsp[-1].traducao + "\t" + 
					yyval.label + " = " + "(int) " + yyvsp[-1].label + ";\n";
				} else if (yyvsp[-1].tipo == "int"){
					yyval.traducao = yyvsp[-1].traducao + "\t" + 
					yyval.label + " = " + "(int) " + yyvsp[-1].label + ";\n";
					warning += "\033[1;33mWarning\033[0m - Linha " + contLinha +  ": as variáveis já apresentam o mesmo tipo.\n";
				}else{
					error += "\033[1;31mError\033[0m - Linha " + contLinha +  ": Casting inválido\n";
				}
			}
#line 2351 "y.tab.c"
    break;

  case 51: /* E: RELACIONAL  */
#line 740 "sintatica.y"
                        {
			}
#line 2358 "y.tab.c"
    break;

  case 52: /* E: ATRIBUICAO  */
#line 743 "sintatica.y"
                        {
			}
#line 2365 "y.tab.c"
    break;

  case 53: /* E: TK_ID '(' CHAMADAS ')'  */
#line 746 "sintatica.y"
                        {
				TIPO_FUNCTION aux = getFunctionChamada(yyvsp[-3].label);
				int index;
				int j = parametersChamada.size() - 1;
				string params;

				for(int k = tabelaFunction.size() - 1; k >= 0; k--)
				{
					if(tabelaFunction[k].nomeFunction == yyvsp[-3].label){
						index = k;
						break;
					}
				}

				if(aux.parameters.size() != parametersChamada.size())
					error += "\033[1;31mError\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Quantidade de parâmetros inválida.\n";
				else{
					for(int i = 0; i < aux.parameters.size(); i++)
					{
						if(aux.parameters[i].tipoVariavel != parametersChamada[j].tipoVariavel)
						{
							error += "\033[1;31mError\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m O parâmetro da função '" + aux.parameters[i].nomeVariavel + "' recebe tipo diferente.\n";
						} else {
							tabelaFunction[index].parameters[i].valorVariavel = parametersChamada[j].labelVariavel;
							params += "\tparam " + parametersChamada[j].labelVariavel + ";\n";
						}
						j--;
					}
				}
				
				yyval.traducao += yyvsp[-1].traducao + params;
				yyval.tipo = aux.retornoTipo; 
			    yyval.label = "call " + aux.nomeFunction + ", " + std::to_string(parametersChamada.size());

				while( parametersChamada.size() != 0){
					parametersChamada.pop_back();
				}
			}
#line 2408 "y.tab.c"
    break;

  case 54: /* E: M  */
#line 785 "sintatica.y"
                        {
				yyval.traducao = yyvsp[0].traducao;
			}
#line 2416 "y.tab.c"
    break;

  case 55: /* CHAMADAS: CHAMADA  */
#line 791 "sintatica.y"
                   {
			   yyval.traducao = yyvsp[0].traducao;
		   }
#line 2424 "y.tab.c"
    break;

  case 56: /* CHAMADAS: %empty  */
#line 795 "sintatica.y"
                   {
		   }
#line 2431 "y.tab.c"
    break;

  case 57: /* CHAMADA: E  */
#line 800 "sintatica.y"
                   {
			   TIPO_SIMBOLO aux;
			   aux.tipoVariavel = yyvsp[0].tipo;
			   aux.labelVariavel = yyvsp[0].label;
			   parametersChamada.push_back(aux);

			   yyval.traducao = yyvsp[0].traducao;
		   }
#line 2444 "y.tab.c"
    break;

  case 58: /* CHAMADA: E ',' CHAMADA  */
#line 809 "sintatica.y"
                   {
			   TIPO_SIMBOLO aux;
			   aux.tipoVariavel = yyvsp[-2].tipo;
			   aux.labelVariavel = yyvsp[-2].label;
			   parametersChamada.push_back(aux);

			   yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao; 
		   }
#line 2457 "y.tab.c"
    break;

  case 59: /* RELACIONAL: E '>' E  */
#line 820 "sintatica.y"
                        {
				verificarOperacaoRelacional(yyvsp[-2], yyvsp[0]);
				yyval.label = gentempcode();
				addTemp(yyval.label, "int");
				yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
				yyval.label + " = " + yyvsp[-2].label + " > " + yyvsp[0].label + ";\n";
			}
#line 2469 "y.tab.c"
    break;

  case 60: /* RELACIONAL: E '<' E  */
#line 828 "sintatica.y"
                        {
				verificarOperacaoRelacional(yyvsp[-2], yyvsp[0]);
				yyval.label = gentempcode();
				addTemp(yyval.label, "int");
				yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
				yyval.label + " = " + yyvsp[-2].label + " < " + yyvsp[0].label + ";\n";
			}
#line 2481 "y.tab.c"
    break;

  case 61: /* RELACIONAL: E TK_MAIOR_IGUAL E  */
#line 836 "sintatica.y"
                        {
				verificarOperacaoRelacional(yyvsp[-2], yyvsp[0]);
				yyval.label = gentempcode();
				addTemp(yyval.label, "int");
				yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
				yyval.label + " = " + yyvsp[-2].label + " >= " + yyvsp[0].label + ";\n";
			}
#line 2493 "y.tab.c"
    break;

  case 62: /* RELACIONAL: E TK_MENOR_IGUAL E  */
#line 844 "sintatica.y"
                        {
				verificarOperacaoRelacional(yyvsp[-2], yyvsp[0]);
				yyval.label = gentempcode();
				addTemp(yyval.label, "int");
				yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
				yyval.label + " = " + yyvsp[-2].label + " <= " + yyvsp[0].label + ";\n";
			}
#line 2505 "y.tab.c"
    break;

  case 63: /* RELACIONAL: E TK_IGUAL_IGUAL E  */
#line 852 "sintatica.y"
                        {
				verificarOperacaoRelacional(yyvsp[-2], yyvsp[0]);
				yyval.label = gentempcode();
				addTemp(yyval.label, "int");
				yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
				yyval.label + " = " + yyvsp[-2].label + " == " + yyvsp[0].label + ";\n";
			}
#line 2517 "y.tab.c"
    break;

  case 64: /* RELACIONAL: E TK_DIFERENTE E  */
#line 860 "sintatica.y"
                        {
				verificarOperacaoRelacional(yyvsp[-2], yyvsp[0]);
				yyval.label = gentempcode();
				addTemp(yyval.label, "int");
				yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
				yyval.label + " = " + yyvsp[-2].label + " != " + yyvsp[0].label + ";\n";
			}
#line 2529 "y.tab.c"
    break;

  case 65: /* RELACIONAL: E TK_OU E  */
#line 868 "sintatica.y"
                        {
				verificarOperacaoRelacional(yyvsp[-2], yyvsp[0]);
				yyval.label = gentempcode();
				addTemp(yyval.label, "int");
				yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
				yyval.label + " = " + yyvsp[-2].label + " || " + yyvsp[0].label + ";\n";
			}
#line 2541 "y.tab.c"
    break;

  case 66: /* RELACIONAL: E TK_E E  */
#line 876 "sintatica.y"
                        {
				verificarOperacaoRelacional(yyvsp[-2], yyvsp[0]);
				yyval.label = gentempcode();
				addTemp(yyval.label, "int");
				yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
				yyval.label + " = " + yyvsp[-2].label + " && " + yyvsp[0].label + ";\n";
			}
#line 2553 "y.tab.c"
    break;

  case 67: /* RELACIONAL: '!' E  */
#line 884 "sintatica.y"
                        {
				yyval.label = gentempcode();
				addTemp(yyval.label, "int");
				yyval.traducao = yyvsp[0].traducao + "\t" + 
				yyval.label + " = " + "!" + yyvsp[0].label + ";\n";
			}
#line 2564 "y.tab.c"
    break;

  case 68: /* ATRIBUICAO: TK_ID '=' E  */
#line 893 "sintatica.y"
                        {
				TIPO_SIMBOLO variavel = getSimbolo(yyvsp[-2].label);

				string traduzir;
				if(variavel.tipoVariavel == yyvsp[0].tipo){
					if(yyvsp[0].tipo == "string"){

						traduzir = yyvsp[-2].traducao
						+ "\tstrcpy(" + yyvsp[0].label +", " + yyvsp[0].valor +");\n\t" + 
						variavel.labelVariavel + " = " + "(char*) malloc(" + yyvsp[0].index +");" +
						"\n\tstrcpy(" + variavel.labelVariavel +", " + yyvsp[0].label +");\n";

						if(getContexto() != 0)
							yyval.traducao = traduzir;
						else
							traducaoFunction += traduzir + '\n';
							
					} else {
						traduzir = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
				    	variavel.labelVariavel + " = " + yyvsp[0].label + ";\n";
						if(getContexto() != 0)
							yyval.traducao = traduzir;
						else
							traducaoFunction += traduzir + '\n';
					}
				}
				else if (variavel.tipoVariavel == "int" & yyvsp[0].tipo == "float")
				{
					yyval.label = gentempcode();
					addTemp(yyval.label, "int");
					traduzir = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
					yyval.label + " = (int) " + yyvsp[0].label + ";\n" + "\t" + 
					variavel.labelVariavel + " = " + yyval.label + ";\n";

					if(getContexto() != 0)
							yyval.traducao = traduzir;
						else
							traducaoFunction += traduzir + '\n';
				}
				else if (variavel.tipoVariavel == "float" & yyvsp[0].tipo == "int")
				{
					yyval.label = gentempcode();
					addTemp(yyval.label, "float");
					traduzir = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
					yyval.label + " = (float) " + yyvsp[0].label + ";\n" + "\t" + 
					variavel.labelVariavel + " = " + yyval.label + ";\n";

					if(getContexto() != 0)
							yyval.traducao = traduzir;
						else
							traducaoFunction += traduzir + '\n';
				}
				else{
					error += "\033[1;31mError\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Atribuição inválida, tipos diferentes.\n";
				}
			}
#line 2625 "y.tab.c"
    break;

  case 69: /* M: M '*' P  */
#line 952 "sintatica.y"
                        {
				yyval.label = gentempcode();
				string tipoAux;
				string labelAux;

				if(yyvsp[-2].tipo == yyvsp[0].tipo){
					yyval.tipo = yyvsp[-2].tipo;
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
					yyval.label + " = " + yyvsp[-2].label + " * " + yyvsp[0].label + ";\n";
					addTemp(yyval.label, yyval.tipo);
				}
				else if(yyvsp[-2].tipo == "int" & yyvsp[0].tipo == "float"){
					yyval.tipo = yyvsp[0].tipo;
					addTemp(yyval.label, yyval.tipo);
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
					yyval.label + " = (float) " + yyvsp[-2].label + ";\n";

					labelAux = yyval.label;
					yyval.label = gentempcode();
					addTemp(yyval.label, yyval.tipo);
					yyval.traducao = yyval.traducao + "\t"+
					yyval.label + " = " + labelAux + " * " + yyvsp[0].label + ";\n";
				}
				else if(yyvsp[-2].tipo == "float" & yyvsp[0].tipo == "int"){
					yyval.tipo = yyvsp[-2].tipo;
					addTemp(yyval.label, yyval.tipo);
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
					yyval.label + " = (float) " + yyvsp[0].label + ";\n";

					labelAux = yyval.label;
					yyval.label = gentempcode();
					addTemp(yyval.label, yyval.tipo);
					yyval.traducao = yyval.traducao + "\t"+
					yyval.label + " = " + yyvsp[-2].label + " * " + labelAux + ";\n";
				}
				else{
					error += "\033[1;31mError\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Operandos com tipos inválidos.\n";
				}
			}
#line 2669 "y.tab.c"
    break;

  case 70: /* M: M '/' P  */
#line 992 "sintatica.y"
                        {
				yyval.label = gentempcode();
				string tipoAux;
				string labelAux;

				if(yyvsp[-2].tipo == yyvsp[0].tipo){
					yyval.tipo = yyvsp[-2].tipo;
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
					yyval.label + " = " + yyvsp[-2].label + " / " + yyvsp[0].label + ";\n";
					addTemp(yyval.label, yyval.tipo);
				}
				else if(yyvsp[-2].tipo == "int" & yyvsp[0].tipo == "float"){
					yyval.tipo = yyvsp[0].tipo;
					addTemp(yyval.label, yyval.tipo);
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
					yyval.label + " = (float) " + yyvsp[-2].label + ";\n";

					labelAux = yyval.label;
					yyval.label = gentempcode();
					addTemp(yyval.label, yyval.tipo);
					yyval.traducao = yyval.traducao + "\t"+
					yyval.label + " = " + labelAux + " / " + yyvsp[0].label + ";\n";
				}
				else if(yyvsp[-2].tipo == "float" & yyvsp[0].tipo == "int"){
					yyval.tipo = yyvsp[-2].tipo;
					addTemp(yyval.label, yyval.tipo);
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
					yyval.label + " = (float) " + yyvsp[0].label + ";\n";

					labelAux = yyval.label;
					yyval.label = gentempcode();
					addTemp(yyval.label, yyval.tipo);
					yyval.traducao = yyval.traducao + "\t"+
					yyval.label + " = " + yyvsp[-2].label + " / " + labelAux + ";\n";
				}
				else{
					error += "\033[1;31mError\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Operandos com tipos inválidos.\n";
				}

				string aux = yyvsp[0].valor;
				int cont = 0;
				int ponto = 0;

				for(int i = 0; i < aux.size(); i++)
				{
					if(aux[i] == '.')
					{
						ponto = 1;
					}
					if(aux[i] == '0')
					{
						cont++;
					}
				}

				if(cont == aux.size() || (cont + ponto) == aux.size()){
					error += "\033[1;31mError\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Operação inválida, divisão por 0.\n";
				}
			}
#line 2733 "y.tab.c"
    break;

  case 71: /* M: M '%' P  */
#line 1052 "sintatica.y"
                        {
				yyval.label = gentempcode();
				string tipoAux;
				string labelAux;

				if(yyvsp[-2].tipo == "int" & yyvsp[0].tipo == "int"){
					tipoAux = yyvsp[-2].tipo;
					yyval.traducao = yyvsp[-2].traducao + yyvsp[0].traducao + "\t" + 
					yyval.label + " = " + yyvsp[-2].label + " % " + yyvsp[0].label + ";\n";
					addTemp(yyval.label, tipoAux);
				}
				else{
					error += "\033[1;31mError\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Operandos inválidos para %, (ou presença de float).\n";
				}
			}
#line 2753 "y.tab.c"
    break;

  case 72: /* M: P  */
#line 1068 "sintatica.y"
                        {
				yyval.traducao = yyvsp[0].traducao;
			}
#line 2761 "y.tab.c"
    break;

  case 73: /* P: '(' E ')'  */
#line 1074 "sintatica.y"
                        {
				yyval.traducao = yyvsp[-1].traducao;
				yyval.tipo = yyvsp[-1].tipo;
				yyval.label = yyvsp[-1].label;
			}
#line 2771 "y.tab.c"
    break;

  case 74: /* P: TK_NUM  */
#line 1080 "sintatica.y"
                        {
				yyval.tipo = "int";
				yyval.label = gentempcode();
				addTemp(yyval.label, yyval.tipo);
				yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].label + ";\n";
				yyval.valor = yyvsp[0].label;
			}
#line 2783 "y.tab.c"
    break;

  case 75: /* P: TK_REAL  */
#line 1088 "sintatica.y"
                        {
				yyval.tipo = "float";
				yyval.label = gentempcode();
				addTemp(yyval.label, yyval.tipo);
				yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].label + ";\n";
				yyval.valor = yyvsp[0].label;
			}
#line 2795 "y.tab.c"
    break;

  case 76: /* P: TK_CHAR  */
#line 1096 "sintatica.y"
                        {
				yyval.tipo = "char";
				yyval.label = gentempcode();
				addTemp(yyval.label, yyval.tipo);
				yyval.traducao = "\t" + yyval.label + " = " + yyvsp[0].label + ";\n";
			}
#line 2806 "y.tab.c"
    break;

  case 77: /* P: TK_STRING  */
#line 1103 "sintatica.y"
                        {
				yyval.tipo = "string";
				yyval.label = gentempcode();
				yyval.traducao = "\tstrcpy(" + yyval.label +", " + yyvsp[0].valor + ");\n";
				yyval.index = std::to_string(addTempString(yyval.label, yyval.valor));
			}
#line 2817 "y.tab.c"
    break;

  case 78: /* P: TK_TRUE  */
#line 1110 "sintatica.y"
                        {
				yyval.tipo = "bool";
				yyval.label = gentempcode();
				addTemp(yyval.label, "int");
				yyval.traducao = "\t" + yyval.label + " = " + "1" + ";\n";	
			}
#line 2828 "y.tab.c"
    break;

  case 79: /* P: TK_FALSE  */
#line 1117 "sintatica.y"
                        {
				yyval.tipo = "bool";
				yyval.label = gentempcode();
				addTemp(yyval.label, "int");
				yyval.traducao = "\t" + yyval.label + " = " + "0" + ";\n";		
			}
#line 2839 "y.tab.c"
    break;

  case 80: /* P: TK_ID  */
#line 1124 "sintatica.y"
                        {
				TIPO_SIMBOLO variavel = getSimbolo(yyvsp[0].label);
				yyval.tipo = variavel.tipoVariavel;
				yyval.label = variavel.labelVariavel;
				yyval.traducao = "";
			}
#line 2850 "y.tab.c"
    break;

  case 81: /* P: TK_PRINT '(' E ')'  */
#line 1131 "sintatica.y"
                        {
				yyval.traducao = yyvsp[-1].traducao + "\t" + "cout << " + yyvsp[-1].label + ";\n";
			}
#line 2858 "y.tab.c"
    break;

  case 82: /* P: TK_SCAN '(' TK_ID ')'  */
#line 1135 "sintatica.y"
                        {
				TIPO_SIMBOLO variavel = getSimbolo(yyvsp[-1].label);
				yyval.traducao = yyvsp[-1].traducao + "\t" "STD::CIN >> " + variavel.labelVariavel + ";\n";
			}
#line 2867 "y.tab.c"
    break;


#line 2871 "y.tab.c"

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

#line 1140 "sintatica.y"


#include "lex.yy.c"

int yyparse();
int getContexto(){
	return mapa.size() - 1;
}

string gentempcode(){
	var_temp_qnt++;
	return "t" + std::to_string(var_temp_qnt);	
}

string genLacecode(){
	var_lace_qnt++;
	return "_L" + std::to_string(var_lace_qnt) + ":";	
}

string genCondcode(){
	var_cond_qnt++;
	return "FIM_IF_" + std::to_string(var_cond_qnt) + ":";
}

string genLaceNameCode(){
	var_lace_name_qnt++;
	return "loop_" + std::to_string(var_lace_name_qnt);
}

void verificarVariavelRepetida(string variavel){

	int contexto = mapa.size() - 1;
	vector<TIPO_SIMBOLO> tabelaSimbolos;
	tabelaSimbolos = mapa[contexto];

	for(int i = 0; i < tabelaSimbolos.size(); i++)
	{
		if(tabelaSimbolos[i].nomeVariavel == variavel)
		{
			error += "\033[1;31mError\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m A variável '" + variavel + "' já existe.\n";
		}
	}
}

TIPO_SIMBOLO getSimbolo(string variavel){

	int contexto = mapa.size() - 1;
	vector<TIPO_SIMBOLO> tabelaSimbolos;
	tabelaSimbolos = mapa[contexto];

	while(contexto >= 0)
	{
		for (int i = tabelaSimbolos.size() - 1; i >= 0; i--)
		{
			if(tabelaSimbolos[i].nomeVariavel == variavel)
			{
				return tabelaSimbolos[i];
			}				
		}
		
		contexto -= 1;
		if(contexto >= 0){
			tabelaSimbolos = mapa[contexto];
		}
	}

	if(controleFunction > 0){

		int sizeFunctions = tabelaFunction.size() - 1;
		int sizeFunctionsParameters = tabelaFunction[sizeFunctions].parameters.size();

		for (int i = sizeFunctionsParameters; i >= 0; i--)
		{
			if(tabelaFunction[sizeFunctions].parameters[i].nomeVariavel == variavel)
			{
				return tabelaFunction[sizeFunctions].parameters[i];
			}				
		}
		
	}

	error += "\033[1;31mError\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m A variável '" + variavel + "' não foi instanciada.\n";
}

void addSimbolo(string variavel, string tipo, string label){
	
	TIPO_SIMBOLO valor;

	valor.nomeVariavel = variavel;
	valor.tipoVariavel = tipo;
	valor.labelVariavel = label;

	int contexto = mapa.size() - 1;
	mapa[contexto].push_back(valor);

	if(valor.tipoVariavel == "bool"){
		valor.tipoVariavel = "int";
	}


	if(controleFunction > 0)
	{
		traducaoFunction = traducaoFunction + "\t" + valor.tipoVariavel + " " + valor.labelVariavel +";\n";

	}else if(contexto == 0 && controleFunction == 0)
	{
		atribuicaoVariavelGlobais = atribuicaoVariavelGlobais  + "\t" + valor.tipoVariavel + " " + valor.labelVariavel +";\n";

	} else 
	{
		atribuicaoVariavel = atribuicaoVariavel + "\t" + valor.tipoVariavel + " " + valor.labelVariavel +";\n";
	}
}

void addString(string variavel, string tipo, string label){
	TIPO_SIMBOLO valor;
	
	valor.nomeVariavel = variavel;
	valor.tipoVariavel = tipo;
	valor.labelVariavel = label;

	int contexto = mapa.size() - 1;
	mapa[contexto].push_back(valor);

	valor.tipoVariavel = "char";
	if(controleFunction > 0){
		traducaoFunction = traducaoFunction + "\t" + valor.tipoVariavel + " *" 
		+ valor.labelVariavel + ";\n";
	} else if(contexto == 0 && controleFunction == 0){
		atribuicaoVariavelGlobais = atribuicaoVariavelGlobais + "\t" + valor.tipoVariavel + " *" 
		+ valor.labelVariavel + ";\n";
	} else {
		atribuicaoVariavel = atribuicaoVariavel + "\t" + valor.tipoVariavel + " *" 
		+ valor.labelVariavel + ";\n";
	}
}

void addTemp(string label, string tipo){
	TIPO_TEMP valor;
	valor.labelVariavel = label;
	valor.tipoVariavel = tipo;
	tabelaTemp.push_back(valor);

	if(valor.tipoVariavel == "bool"){
		valor.tipoVariavel = "int";
	}

	int contexto = getContexto();

	if(controleFunction > 0)
		traducaoFunction = traducaoFunction + "\t" + valor.tipoVariavel + " " + valor.labelVariavel +";\n";
	else if(contexto == 0 && controleFunction == 0)
		atribuicaoVariavelGlobais = atribuicaoVariavelGlobais + "\t" + valor.tipoVariavel + " " + valor.labelVariavel +";\n";
	else
		atribuicaoVariavel = atribuicaoVariavel + "\t" + valor.tipoVariavel + " " + valor.labelVariavel +";\n";
}

int addTempString(string label, string conteudo){
	TIPO_TEMP valor;
	valor.labelVariavel = label;
	valor.tipoVariavel = "string";
	valor.valor = conteudo;
	tabelaTemp.push_back(valor);
	valor.tipoVariavel = "char";

	int size = getSize(conteudo) - 1;
	int contexto = mapa.size() - 1;

	if(controleFunction > 0){
		traducaoFunction = traducaoFunction + "\t" + valor.tipoVariavel + " " + 
		valor.labelVariavel + "[" + std::to_string(size) + "]" + ";\n";
	} else if(contexto == 0 && controleFunction == 0){
		atribuicaoVariavelGlobais = atribuicaoVariavelGlobais + "\t" + valor.tipoVariavel + " " + 
		valor.labelVariavel + "[" + std::to_string(size) + "]" + ";\n";
	} else {
		atribuicaoVariavel = atribuicaoVariavel + "\t" + valor.tipoVariavel + " " + 
		valor.labelVariavel + "[" + std::to_string(size) + "]" + ";\n";
	}
	return size;
}

int getSize(string str){
	int i = 0;
	while (str[i] != '\0')
		i++;

	return i;
}

void verificarOperacaoRelacional(atributos tipo_1, atributos tipo_2){
	if((tipo_1.tipo == "char" || tipo_2.tipo == "char") || (tipo_1.tipo == "string" || tipo_2.tipo == "string"))
	{
		error += "\033[1;31mError\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Operação relacional inválida.\n";
	}
}

void verificarAtributoRelacional(atributos tipo_1){
	if(tipo_1.tipo == "char" || tipo_1.tipo == "string" || tipo_1.tipo == "void")
	{
		error += "\033[1;31mError\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Operação relacional inválida.\n";
	}
}

int main(int argc, char* argv[]){
	var_temp_qnt = 0;
	contextoGlobal = 0;
	vector<TIPO_SIMBOLO> tabelaSimbolos;
	mapa.push_back(tabelaSimbolos);
	yyparse();
	return 0;
}

void pushContexto(){
	vector<TIPO_SIMBOLO> tabelaSimbolos;
	mapa.push_back(tabelaSimbolos);
}

void popContexto(){
	mapa.pop_back();

	if(controleLoop != 0)
		controleLoop--;

	if(controleFunction != 0)
		controleFunction--;
}

void pushLoop(string tipo){

	controleLoop++;
	int size = tabelaLoop.size();
	TIPO_LOOP aux;
	aux.nomeLaco = "loop_" + std::to_string(var_lace_name_qnt);
	aux.tipoLaco = tipo;

	if(tipo == "while" && size != 0)
	{
		if(!(tabelaLoop[size - 1].tipoLaco == "do"))
		{
			aux.fimLaco = genCondcode();
			aux.inicioLaco = genLacecode();
			aux.contexto = getContexto();
			tabelaLoop.push_back(aux);
		}

	} else {
		aux.fimLaco = genCondcode();
		aux.inicioLaco = genLacecode();
		aux.contexto = mapa.size();
		tabelaLoop.push_back(aux);
	}
}

TIPO_LOOP getLace(string nome){

	for (int i = tabelaLoop.size() - 1; i >= 0; i--)
	{ 
		if(tabelaLoop[i].nomeLaco == nome)
		{
			return tabelaLoop[i];
		}
	}
}

TIPO_LOOP getLaceBreak(){
	int size = tabelaLoop.size();
	return tabelaLoop[size - 1];
}

void pushFunction(){
	TIPO_FUNCTION aux;
	aux.inicioFunction = genLacecode();
	aux.fimFunction = genLacecode();
	tabelaFunction.push_back(aux);
	controleFunction++;
}

TIPO_FUNCTION getFunction(){
	int size = tabelaFunction.size() - 1;
	return tabelaFunction[size];
}

TIPO_FUNCTION getFunctionChamada(string nome){

	TIPO_FUNCTION aux;
	int achou = 0;

	for(int i = 0; i < tabelaFunction.size(); i++){
		if(tabelaFunction[i].nomeFunction == nome){
			aux = tabelaFunction[i];
			achou = 1;
		}
	}

	if(achou == 0)
		error += "\033[1;31mError\033[0m - \033[1;36mLinha " + contLinha +  ":\033[0m\033[1;39m Nome da função não existe.\n";
	return aux;
}

void contadorDeLinha(){
	var_linha_qnt++;
	contLinha = std::to_string(var_linha_qnt);
}

void yyerror(string MSG){
	cout << MSG << endl;
	exit (0);
}
