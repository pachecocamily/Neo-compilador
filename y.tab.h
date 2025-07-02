/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

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
    TK_VEZES_IGUAL = 286,          /* TK_VEZES_IGUAL  */
    TK_DIVISAO_IGUAL = 287,        /* TK_DIVISAO_IGUAL  */
    TK_IF = 288,                   /* TK_IF  */
    TK_ELSE = 289,                 /* TK_ELSE  */
    TK_WHILE = 290,                /* TK_WHILE  */
    TK_FOR = 291,                  /* TK_FOR  */
    TK_DO = 292,                   /* TK_DO  */
    TK_SWITCH = 293,               /* TK_SWITCH  */
    TK_CASE = 294,                 /* TK_CASE  */
    TK_BREAK = 295,                /* TK_BREAK  */
    TK_CONTINUE = 296,             /* TK_CONTINUE  */
    TK_PRINT = 297,                /* TK_PRINT  */
    TK_SCAN = 298,                 /* TK_SCAN  */
    TK_RETURN = 299,               /* TK_RETURN  */
    TK_ERROR = 300,                /* TK_ERROR  */
    TK_CAST_CHAR = 301             /* TK_CAST_CHAR  */
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
#define TK_VEZES_IGUAL 286
#define TK_DIVISAO_IGUAL 287
#define TK_IF 288
#define TK_ELSE 289
#define TK_WHILE 290
#define TK_FOR 291
#define TK_DO 292
#define TK_SWITCH 293
#define TK_CASE 294
#define TK_BREAK 295
#define TK_CONTINUE 296
#define TK_PRINT 297
#define TK_SCAN 298
#define TK_RETURN 299
#define TK_ERROR 300
#define TK_CAST_CHAR 301

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
