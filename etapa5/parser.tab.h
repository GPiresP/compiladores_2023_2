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
#line 31 "parser.y"

        #include "ast.h"
        #include "valorlexico.h"
        #include "scopetable.h"
        #include "iloc.h"

#line 56 "parser.tab.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    TK_PR_INT = 258,               /* TK_PR_INT  */
    TK_PR_FLOAT = 259,             /* TK_PR_FLOAT  */
    TK_PR_BOOL = 260,              /* TK_PR_BOOL  */
    TK_PR_IF = 261,                /* TK_PR_IF  */
    TK_PR_ELSE = 262,              /* TK_PR_ELSE  */
    TK_PR_WHILE = 263,             /* TK_PR_WHILE  */
    TK_PR_RETURN = 264,            /* TK_PR_RETURN  */
    TK_OC_LE = 265,                /* TK_OC_LE  */
    TK_OC_GE = 266,                /* TK_OC_GE  */
    TK_OC_EQ = 267,                /* TK_OC_EQ  */
    TK_OC_NE = 268,                /* TK_OC_NE  */
    TK_OC_AND = 269,               /* TK_OC_AND  */
    TK_OC_OR = 270,                /* TK_OC_OR  */
    TK_IDENTIFICADOR = 271,        /* TK_IDENTIFICADOR  */
    TK_LIT_INT = 272,              /* TK_LIT_INT  */
    TK_LIT_FLOAT = 273,            /* TK_LIT_FLOAT  */
    TK_LIT_FALSE = 274,            /* TK_LIT_FALSE  */
    TK_LIT_TRUE = 275,             /* TK_LIT_TRUE  */
    TK_ERRO = 276                  /* TK_ERRO  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 38 "parser.y"

        VL *valor_lexico;
        AST *ast;
        T_STRING_LIST *string_list;

#line 100 "parser.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
