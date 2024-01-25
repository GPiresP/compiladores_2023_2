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
#line 7 "parser.y"

        #include <stddef.h>
        #include <string.h>
        #include <stdio.h>
        #include <stdlib.h>
        #include "ast.h"
        #include "valorlexico.h"
        #include "scopetable.h"
        #include "iloc.h"

        #define ERR_UNDECLARED 10 //2.2
        #define ERR_DECLARED 11 //2.2
        #define ERR_VARIABLE 20 //2.3
        #define ERR_FUNCTION 21 //2.3

        int yylex(void);
        void yyerror (char const *mensagem);
        extern int yylineast;
        extern void *arvore;
        T_SCOPE_TABLE_STACK *table_stack = NULL;

        

#line 95 "parser.tab.c"

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
  YYSYMBOL_TK_PR_IF = 6,                   /* TK_PR_IF  */
  YYSYMBOL_TK_PR_ELSE = 7,                 /* TK_PR_ELSE  */
  YYSYMBOL_TK_PR_WHILE = 8,                /* TK_PR_WHILE  */
  YYSYMBOL_TK_PR_RETURN = 9,               /* TK_PR_RETURN  */
  YYSYMBOL_TK_OC_LE = 10,                  /* TK_OC_LE  */
  YYSYMBOL_TK_OC_GE = 11,                  /* TK_OC_GE  */
  YYSYMBOL_TK_OC_EQ = 12,                  /* TK_OC_EQ  */
  YYSYMBOL_TK_OC_NE = 13,                  /* TK_OC_NE  */
  YYSYMBOL_TK_OC_AND = 14,                 /* TK_OC_AND  */
  YYSYMBOL_TK_OC_OR = 15,                  /* TK_OC_OR  */
  YYSYMBOL_TK_IDENTIFICADOR = 16,          /* TK_IDENTIFICADOR  */
  YYSYMBOL_TK_LIT_INT = 17,                /* TK_LIT_INT  */
  YYSYMBOL_TK_LIT_FLOAT = 18,              /* TK_LIT_FLOAT  */
  YYSYMBOL_TK_LIT_FALSE = 19,              /* TK_LIT_FALSE  */
  YYSYMBOL_TK_LIT_TRUE = 20,               /* TK_LIT_TRUE  */
  YYSYMBOL_21_ = 21,                       /* '!'  */
  YYSYMBOL_22_ = 22,                       /* '-'  */
  YYSYMBOL_23_ = 23,                       /* '*'  */
  YYSYMBOL_24_ = 24,                       /* '/'  */
  YYSYMBOL_25_ = 25,                       /* '%'  */
  YYSYMBOL_26_ = 26,                       /* '+'  */
  YYSYMBOL_27_ = 27,                       /* '<'  */
  YYSYMBOL_28_ = 28,                       /* '>'  */
  YYSYMBOL_29_ = 29,                       /* '{'  */
  YYSYMBOL_30_ = 30,                       /* '}'  */
  YYSYMBOL_31_ = 31,                       /* '('  */
  YYSYMBOL_32_ = 32,                       /* ')'  */
  YYSYMBOL_33_ = 33,                       /* '='  */
  YYSYMBOL_34_ = 34,                       /* ','  */
  YYSYMBOL_35_ = 35,                       /* ';'  */
  YYSYMBOL_TK_ERRO = 36,                   /* TK_ERRO  */
  YYSYMBOL_YYACCEPT = 37,                  /* $accept  */
  YYSYMBOL_programa = 38,                  /* programa  */
  YYSYMBOL_declaracoes = 39,               /* declaracoes  */
  YYSYMBOL_declaracao = 40,                /* declaracao  */
  YYSYMBOL_variaveis_globais = 41,         /* variaveis_globais  */
  YYSYMBOL_identificadores = 42,           /* identificadores  */
  YYSYMBOL_tipo = 43,                      /* tipo  */
  YYSYMBOL_funcao = 44,                    /* funcao  */
  YYSYMBOL_cabecalho = 45,                 /* cabecalho  */
  YYSYMBOL_lista_parametros = 46,          /* lista_parametros  */
  YYSYMBOL_parametros = 47,                /* parametros  */
  YYSYMBOL_parametro = 48,                 /* parametro  */
  YYSYMBOL_corpo = 49,                     /* corpo  */
  YYSYMBOL_bloco_comandos = 50,            /* bloco_comandos  */
  YYSYMBOL_comandos = 51,                  /* comandos  */
  YYSYMBOL_comando = 52,                   /* comando  */
  YYSYMBOL_variaveis_locais = 53,          /* variaveis_locais  */
  YYSYMBOL_atribuicao = 54,                /* atribuicao  */
  YYSYMBOL_chamada_funcao = 55,            /* chamada_funcao  */
  YYSYMBOL_lista_argumentos = 56,          /* lista_argumentos  */
  YYSYMBOL_argumentos = 57,                /* argumentos  */
  YYSYMBOL_argumento = 58,                 /* argumento  */
  YYSYMBOL_retorno = 59,                   /* retorno  */
  YYSYMBOL_controle_fluxo = 60,            /* controle_fluxo  */
  YYSYMBOL_bloco_if_else = 61,             /* bloco_if_else  */
  YYSYMBOL_bloco_if = 62,                  /* bloco_if  */
  YYSYMBOL_bloco_else = 63,                /* bloco_else  */
  YYSYMBOL_bloco_while = 64,               /* bloco_while  */
  YYSYMBOL_expressao = 65,                 /* expressao  */
  YYSYMBOL_term0 = 66,                     /* term0  */
  YYSYMBOL_term1 = 67,                     /* term1  */
  YYSYMBOL_term2 = 68,                     /* term2  */
  YYSYMBOL_term4 = 69,                     /* term4  */
  YYSYMBOL_term8 = 70,                     /* term8  */
  YYSYMBOL_term10 = 71,                    /* term10  */
  YYSYMBOL_term13 = 72,                    /* term13  */
  YYSYMBOL_term14 = 73,                    /* term14  */
  YYSYMBOL_operando = 74,                  /* operando  */
  YYSYMBOL_abrir_escopo = 75,              /* abrir_escopo  */
  YYSYMBOL_fechar_escopo = 76              /* fechar_escopo  */
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

#if 1

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
#endif /* 1 */

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
#define YYLAST   112

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  80
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  131

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   276


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
       2,     2,     2,    21,     2,     2,     2,    25,     2,     2,
      31,    32,    23,    26,    34,    22,     2,    24,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    35,
      27,    33,    28,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    29,     2,    30,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    36
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   125,   125,   129,   133,   134,   138,   139,   143,   170,
     182,   198,   202,   206,   213,   224,   251,   252,   256,   257,
     261,   287,   291,   292,   296,   308,   312,   313,   314,   315,
     316,   317,   321,   349,   378,   407,   408,   412,   413,   417,
     421,   429,   430,   434,   438,   450,   451,   455,   464,   468,
     476,   480,   488,   492,   500,   508,   512,   520,   528,   536,
     544,   548,   556,   564,   569,   577,   585,   593,   597,   598,
     599,   603,   604,   605,   609,   633,   678,   724,   770,   819,
     830
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "TK_PR_INT",
  "TK_PR_FLOAT", "TK_PR_BOOL", "TK_PR_IF", "TK_PR_ELSE", "TK_PR_WHILE",
  "TK_PR_RETURN", "TK_OC_LE", "TK_OC_GE", "TK_OC_EQ", "TK_OC_NE",
  "TK_OC_AND", "TK_OC_OR", "TK_IDENTIFICADOR", "TK_LIT_INT",
  "TK_LIT_FLOAT", "TK_LIT_FALSE", "TK_LIT_TRUE", "'!'", "'-'", "'*'",
  "'/'", "'%'", "'+'", "'<'", "'>'", "'{'", "'}'", "'('", "')'", "'='",
  "','", "';'", "TK_ERRO", "$accept", "programa", "declaracoes",
  "declaracao", "variaveis_globais", "identificadores", "tipo", "funcao",
  "cabecalho", "lista_parametros", "parametros", "parametro", "corpo",
  "bloco_comandos", "comandos", "comando", "variaveis_locais",
  "atribuicao", "chamada_funcao", "lista_argumentos", "argumentos",
  "argumento", "retorno", "controle_fluxo", "bloco_if_else", "bloco_if",
  "bloco_else", "bloco_while", "expressao", "term0", "term1", "term2",
  "term4", "term8", "term10", "term13", "term14", "operando",
  "abrir_escopo", "fechar_escopo", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-73)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-80)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
       7,    43,    23,   -73,   -73,   -73,   -73,   -73,    10,   -73,
      38,   -73,   -20,   -73,   -73,   -73,    -5,    23,    24,    41,
     -73,    42,    27,    26,   -73,    62,   -73,   -73,   -73,   -73,
      50,    23,    44,    45,    78,    11,   -73,    38,    39,    49,
     -73,   -73,   -73,   -73,   -73,   -73,    65,   -73,    24,   -73,
      23,   -73,    78,    78,    48,   -73,   -73,   -73,   -73,    78,
      78,    78,   -73,   -73,    58,    60,    37,     6,   -16,    15,
     -73,   -73,   -73,    78,    78,    53,   -73,    77,    24,   -73,
     -73,    67,    57,    59,   -73,   -73,    69,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      70,   -73,    56,   -73,   -73,   -73,   -73,   -73,    87,    24,
      24,   -73,    60,    37,     6,     6,   -16,   -16,   -16,   -16,
      15,    15,   -73,   -73,   -73,   -73,    78,   -73,   -73,   -73,
     -73
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      79,     0,    79,     1,    11,    12,    13,    80,     5,     7,
       0,     6,     0,     2,     4,    10,     0,    17,     0,     0,
       8,     0,     0,    16,    19,    79,    80,    21,     9,    20,
       0,     0,     0,     0,     0,     0,    23,     0,     0,     0,
      26,    27,    28,    29,    30,    41,    46,    42,     0,    14,
       0,    18,     0,     0,    74,    77,    78,    75,    76,     0,
       0,     0,    72,    40,    48,    50,    52,    55,    60,    63,
      67,    70,    73,    36,     0,    32,    22,    25,     0,    43,
      80,     0,     0,     0,    69,    68,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    35,    37,    39,    33,    24,    45,    31,     0,     0,
       0,    71,    49,    51,    53,    54,    58,    59,    56,    57,
      62,    61,    64,    65,    66,    34,     0,    15,    44,    47,
      38
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -73,   -73,    96,   -73,   -73,    68,   -13,   -73,   -73,   -73,
     -73,    76,   -73,   -47,    31,   -73,   -73,   -73,   -22,   -73,
     -15,   -73,   -73,   -73,   -73,   -73,   -73,   -73,   -29,   -73,
      25,    22,   -54,   -72,   -44,   -51,   -73,   -73,     0,   -24
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     1,     7,     8,     9,    16,    10,    11,    18,    22,
      23,    24,    26,    27,    38,    39,    40,    41,    62,   100,
     101,   102,    43,    44,    45,    46,    79,    47,   103,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    12,    13
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       2,    80,    49,    42,    21,    63,    95,    -3,    84,    85,
      96,    17,    37,     4,     5,     6,    91,    92,    21,   116,
     117,   118,   119,    82,    83,    48,     4,     5,     6,    19,
      20,   106,    86,    93,    94,   114,   115,    81,    97,    98,
      99,   -79,    73,     3,    74,   104,   122,   123,   124,    89,
      90,   120,   121,    25,    15,    42,   107,    28,    29,    30,
      31,    50,   128,   129,    37,     4,     5,     6,    32,    76,
      33,    34,    78,    87,    88,    52,    53,    48,    35,    73,
       4,     5,     6,    32,    77,    33,    34,    19,   108,   109,
     126,   110,    36,    35,    54,    55,    56,    57,    58,    59,
      60,   111,   125,   127,    14,    75,   -79,    51,   105,    61,
     113,   130,   112
};

static const yytype_int8 yycheck[] =
{
       0,    48,    26,    25,    17,    34,    22,     0,    59,    60,
      26,    31,    25,     3,     4,     5,    10,    11,    31,    91,
      92,    93,    94,    52,    53,    25,     3,     4,     5,    34,
      35,    78,    61,    27,    28,    89,    90,    50,    23,    24,
      25,    31,    31,     0,    33,    74,    97,    98,    99,    12,
      13,    95,    96,    29,    16,    77,    80,    16,    16,    32,
      34,    11,   109,   110,    77,     3,     4,     5,     6,    30,
       8,     9,     7,    15,    14,    31,    31,    77,    16,    31,
       3,     4,     5,     6,    35,     8,     9,    34,    21,    32,
      34,    32,    30,    16,    16,    17,    18,    19,    20,    21,
      22,    32,    32,    16,     8,    37,    29,    31,    77,    31,
      88,   126,    87
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    38,    75,     0,     3,     4,     5,    39,    40,    41,
      43,    44,    75,    76,    39,    16,    42,    31,    45,    34,
      35,    43,    46,    47,    48,    29,    49,    50,    16,    16,
      32,    34,     6,     8,     9,    16,    30,    43,    51,    52,
      53,    54,    55,    59,    60,    61,    62,    64,    75,    76,
      11,    48,    31,    31,    16,    17,    18,    19,    20,    21,
      22,    31,    55,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    31,    33,    42,    30,    35,     7,    63,
      50,    43,    65,    65,    72,    72,    65,    15,    14,    12,
      13,    10,    11,    27,    28,    22,    26,    23,    24,    25,
      56,    57,    58,    65,    65,    51,    50,    76,    21,    32,
      32,    32,    67,    68,    69,    69,    70,    70,    70,    70,
      71,    71,    72,    72,    72,    32,    34,    16,    50,    50,
      57
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    38,    38,    39,    39,    40,    40,    41,    42,
      42,    43,    43,    43,    44,    45,    46,    46,    47,    47,
      48,    49,    50,    50,    51,    51,    52,    52,    52,    52,
      52,    52,    53,    54,    55,    56,    56,    57,    57,    58,
      59,    60,    60,    61,    62,    63,    63,    64,    65,    66,
      66,    67,    67,    68,    68,    68,    69,    69,    69,    69,
      69,    70,    70,    70,    71,    71,    71,    71,    72,    72,
      72,    73,    73,    73,    74,    74,    74,    74,    74,    75,
      76
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     3,     0,     2,     1,     1,     1,     3,     3,
       1,     1,     1,     1,     4,     7,     1,     0,     3,     1,
       2,     1,     3,     2,     3,     2,     1,     1,     1,     1,
       1,     3,     2,     3,     4,     1,     0,     1,     3,     1,
       2,     1,     1,     2,     5,     2,     0,     5,     1,     3,
       1,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     3,     3,     1,     2,     2,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     0,
       0
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


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
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
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
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
# endif
#endif

#ifndef yytnamerr
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
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
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
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
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
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
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
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
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

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

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
  case 2: /* programa: abrir_escopo declaracoes fechar_escopo  */
#line 126 "parser.y"
        { 
                (yyval.ast) = (yyvsp[-1].ast); arvore = (void*) (yyval.ast);
        }
#line 1522 "parser.tab.c"
    break;

  case 3: /* programa: %empty  */
#line 129 "parser.y"
                 { (yyval.ast) = NULL; }
#line 1528 "parser.tab.c"
    break;

  case 4: /* declaracoes: declaracao declaracoes  */
#line 133 "parser.y"
                               { if ((yyvsp[-1].ast) == NULL) (yyval.ast) = (yyvsp[0].ast); else { (yyval.ast) = (yyvsp[-1].ast); ast_add_child((yyvsp[-1].ast), (yyvsp[0].ast)); } }
#line 1534 "parser.tab.c"
    break;

  case 5: /* declaracoes: declaracao  */
#line 134 "parser.y"
                     { (yyval.ast) = (yyvsp[0].ast); }
#line 1540 "parser.tab.c"
    break;

  case 6: /* declaracao: funcao  */
#line 138 "parser.y"
               { (yyval.ast) = (yyvsp[0].ast); }
#line 1546 "parser.tab.c"
    break;

  case 7: /* declaracao: variaveis_globais  */
#line 139 "parser.y"
                            { (yyval.ast) = NULL; }
#line 1552 "parser.tab.c"
    break;

  case 8: /* variaveis_globais: tipo identificadores ';'  */
#line 144 "parser.y"
        { 
                (yyval.ast) = NULL; 
                int line_num = (yyvsp[-2].valor_lexico)->line_number;
                char *nature = "identificador";
                int stack_idx = (table_stack->tables_number) - 1;
                T_SCOPE_TABLE* stack_top = table_stack->tables[stack_idx];
                for(int i = 0; i < (yyvsp[-1].string_list)->strings_number; i++)
                {
                        char *string = (yyvsp[-1].string_list)->strings[i];

                        T_SCOPE_TABLE_ROW *existing_row = find_symbol_stack(table_stack, string);

                        if(existing_row != NULL)
                        {
                                printf("ERROR AT LINE %d. EXITING WITH CODE: %d (VARIABLE ALREADY DECLARED!). VARIABLE NAME: %s.\n", (yyvsp[-2].valor_lexico)->line_number, ERR_DECLARED, string);
                                exit(ERR_DECLARED); 
                        }

                        T_SCOPE_TABLE_ROW *row = create_row(line_num, string, nature, (yyvsp[-2].valor_lexico)->token_value, string);
                        stack_top = add_row(stack_top, row);
                        table_stack->tables[stack_idx] = stack_top;
                }
        }
#line 1580 "parser.tab.c"
    break;

  case 9: /* identificadores: identificadores ',' TK_IDENTIFICADOR  */
#line 171 "parser.y"
        { 
                T_SCOPE_TABLE_ROW *existing_row = find_symbol_stack(table_stack, (yyvsp[0].valor_lexico)->token_value);

                if(existing_row != NULL)
                {
                        printf("ERROR AT LINE %d. EXITING WITH CODE: %d (VARIABLE ALREADY DECLARED!). VARIABLE NAME: %s.\n", (yyvsp[0].valor_lexico)->line_number, ERR_DECLARED, (yyvsp[0].valor_lexico)->token_value);
                        exit(ERR_DECLARED); 
                }

                (yyval.string_list) = add_string((yyvsp[-2].string_list), (yyvsp[0].valor_lexico)->token_value); 
        }
#line 1596 "parser.tab.c"
    break;

  case 10: /* identificadores: TK_IDENTIFICADOR  */
#line 183 "parser.y"
        { 
                T_SCOPE_TABLE_ROW *existing_row = find_symbol_stack(table_stack, (yyvsp[0].valor_lexico)->token_value);

                if(existing_row != NULL)
                {
                        printf("ERROR AT LINE %d. EXITING WITH CODE: %d (VARIABLE ALREADY DECLARED!). VARIABLE NAME: %s.\n", (yyvsp[0].valor_lexico)->line_number, ERR_DECLARED, (yyvsp[0].valor_lexico)->token_value);
                        exit(ERR_DECLARED); 
                }

                (yyval.string_list) = create_string_list(); 
                (yyval.string_list) = add_string((yyval.string_list), (yyvsp[0].valor_lexico)->token_value);
        }
#line 1613 "parser.tab.c"
    break;

  case 11: /* tipo: TK_PR_INT  */
#line 199 "parser.y"
        { 
                (yyval.valor_lexico) = (yyvsp[0].valor_lexico);
        }
#line 1621 "parser.tab.c"
    break;

  case 12: /* tipo: TK_PR_FLOAT  */
#line 203 "parser.y"
        { 
                (yyval.valor_lexico) = (yyvsp[0].valor_lexico);
        }
#line 1629 "parser.tab.c"
    break;

  case 13: /* tipo: TK_PR_BOOL  */
#line 207 "parser.y"
        { 
                (yyval.valor_lexico) = (yyvsp[0].valor_lexico);
        }
#line 1637 "parser.tab.c"
    break;

  case 14: /* funcao: abrir_escopo cabecalho corpo fechar_escopo  */
#line 214 "parser.y"
        { 
                (yyval.ast) = (yyvsp[-2].ast); 
                if((yyvsp[-1].ast) != NULL) 
                { 
                        ast_add_child((yyval.ast), (yyvsp[-1].ast)); 
                }
        }
#line 1649 "parser.tab.c"
    break;

  case 15: /* cabecalho: '(' lista_parametros ')' TK_OC_GE tipo '!' TK_IDENTIFICADOR  */
#line 225 "parser.y"
        { 
                (yyval.ast) = ast_new((yyvsp[0].valor_lexico)->token_value, (yyvsp[-2].valor_lexico)->token_value);

                int line_num = (yyvsp[-6].valor_lexico)->line_number;
                char *nature = "função";
                int stack_idx = (table_stack->tables_number) - 2;
                T_SCOPE_TABLE* stack_top = table_stack->tables[stack_idx];

                char *string = (yyvsp[0].valor_lexico)->token_value;

                T_SCOPE_TABLE_ROW *existing_row = find_symbol_stack(table_stack, string);

                if(existing_row != NULL)
                {
                        printf("ERROR AT LINE %d. EXITING WITH CODE: %d (FUNCTION ALREADY DECLARED!). FUNCTION NAME: %s.\n", (yyvsp[-6].valor_lexico)->line_number, ERR_DECLARED, string);
                        exit(ERR_DECLARED); 
                }

                T_SCOPE_TABLE_ROW *row = create_row(line_num, string, nature, (yyvsp[-2].valor_lexico)->token_value, string);
                stack_top = add_row(stack_top, row);
                
                table_stack->tables[stack_idx] = stack_top;
        }
#line 1677 "parser.tab.c"
    break;

  case 16: /* lista_parametros: parametros  */
#line 251 "parser.y"
                   { (yyval.ast) = NULL; }
#line 1683 "parser.tab.c"
    break;

  case 17: /* lista_parametros: %empty  */
#line 252 "parser.y"
                 { (yyval.ast) = NULL; }
#line 1689 "parser.tab.c"
    break;

  case 18: /* parametros: parametros ',' parametro  */
#line 256 "parser.y"
                                 { (yyval.ast) = NULL; }
#line 1695 "parser.tab.c"
    break;

  case 19: /* parametros: parametro  */
#line 257 "parser.y"
                    { (yyval.ast) = NULL; }
#line 1701 "parser.tab.c"
    break;

  case 20: /* parametro: tipo TK_IDENTIFICADOR  */
#line 262 "parser.y"
        { 
                (yyval.ast) = NULL;
                int line_num = (yyvsp[-1].valor_lexico)->line_number;
                char *nature = "identificador";
                int stack_idx = (table_stack->tables_number) - 1;
                T_SCOPE_TABLE* stack_top = table_stack->tables[stack_idx];

                char *string = (yyvsp[0].valor_lexico)->token_value;

                T_SCOPE_TABLE_ROW *existing_row = find_symbol_stack(table_stack, string);

                if(existing_row != NULL)
                {
                        printf("ERROR AT LINE %d. EXITING WITH CODE: %d (VARIABLE ALREADY DECLARED!). VARIABLE NAME: %s.\n", (yyvsp[-1].valor_lexico)->line_number, ERR_DECLARED, string);
                        exit(ERR_DECLARED); 
                }

                T_SCOPE_TABLE_ROW *row = create_row(line_num, string, nature, (yyvsp[-1].valor_lexico)->token_value, string);
                stack_top = add_row(stack_top, row);
                
                table_stack->tables[stack_idx] = stack_top;
        }
#line 1728 "parser.tab.c"
    break;

  case 21: /* corpo: bloco_comandos  */
#line 287 "parser.y"
                       { (yyval.ast) = (yyvsp[0].ast); }
#line 1734 "parser.tab.c"
    break;

  case 22: /* bloco_comandos: '{' comandos '}'  */
#line 291 "parser.y"
                         { (yyval.ast) = (yyvsp[-1].ast); }
#line 1740 "parser.tab.c"
    break;

  case 23: /* bloco_comandos: '{' '}'  */
#line 292 "parser.y"
                  { (yyval.ast) = NULL; }
#line 1746 "parser.tab.c"
    break;

  case 24: /* comandos: comando ';' comandos  */
#line 296 "parser.y"
                             { 
                                if((yyvsp[-2].ast) != NULL) {
                                    (yyval.ast) = (yyvsp[-2].ast);
                                    if ((yyvsp[0].ast) != NULL) {
                                        ast_add_child((yyvsp[-2].ast), (yyvsp[0].ast));
                                    }
                                } else if((yyvsp[0].ast) != NULL) {
                                    (yyval.ast) = (yyvsp[0].ast);
                                } else {
                                    (yyval.ast) = NULL;
                                }
                            }
#line 1763 "parser.tab.c"
    break;

  case 25: /* comandos: comando ';'  */
#line 308 "parser.y"
                      { (yyval.ast) = (yyvsp[-1].ast); }
#line 1769 "parser.tab.c"
    break;

  case 26: /* comando: variaveis_locais  */
#line 312 "parser.y"
                         { (yyval.ast) = (yyvsp[0].ast); }
#line 1775 "parser.tab.c"
    break;

  case 27: /* comando: atribuicao  */
#line 313 "parser.y"
                     { (yyval.ast) = (yyvsp[0].ast); }
#line 1781 "parser.tab.c"
    break;

  case 28: /* comando: chamada_funcao  */
#line 314 "parser.y"
                         { (yyval.ast) = (yyvsp[0].ast); }
#line 1787 "parser.tab.c"
    break;

  case 29: /* comando: retorno  */
#line 315 "parser.y"
                  { (yyval.ast) = (yyvsp[0].ast); }
#line 1793 "parser.tab.c"
    break;

  case 30: /* comando: controle_fluxo  */
#line 316 "parser.y"
                         { (yyval.ast) = (yyvsp[0].ast); }
#line 1799 "parser.tab.c"
    break;

  case 31: /* comando: abrir_escopo bloco_comandos fechar_escopo  */
#line 317 "parser.y"
                                                    { (yyval.ast) = (yyvsp[-1].ast); }
#line 1805 "parser.tab.c"
    break;

  case 32: /* variaveis_locais: tipo identificadores  */
#line 322 "parser.y"
        { 
                (yyval.ast) = NULL; 
                int line_num = (yyvsp[-1].valor_lexico)->line_number;
                char *nature = "identificador";
                int stack_idx = (table_stack->tables_number) - 1;
                T_SCOPE_TABLE* stack_top = table_stack->tables[stack_idx];
                for(int i = 0; i < (yyvsp[0].string_list)->strings_number; i++)
                {
                        char *string = (yyvsp[0].string_list)->strings[i];

                        T_SCOPE_TABLE_ROW *existing_row = find_symbol_stack(table_stack, string);

                        if(existing_row != NULL)
                        {
                                printf("ERROR AT LINE %d. EXITING WITH CODE: %d (VARIABLE ALREADY DECLARED!). VARIABLE NAME: %s.\n", (yyvsp[-1].valor_lexico)->line_number, ERR_DECLARED, string);
                                exit(ERR_DECLARED); 
                        }

                        T_SCOPE_TABLE_ROW *row = create_row(line_num, string, nature, (yyvsp[-1].valor_lexico)->token_value, string);
                        stack_top = add_row(stack_top, row);
                        table_stack->tables[stack_idx] = stack_top;
                }
        
        }
#line 1834 "parser.tab.c"
    break;

  case 33: /* atribuicao: TK_IDENTIFICADOR '=' expressao  */
#line 350 "parser.y"
        { 
                char *symbol = (yyvsp[-2].valor_lexico)->token_value;

                T_SCOPE_TABLE_ROW *row = find_symbol_stack(table_stack, symbol);

                if(row == NULL)
                {
                        printf("ERROR AT LINE %d. EXITING WITH CODE: %d (VARIABLE NOT YET DECLARED!). VARIABLE NAME: %s.\n", (yyvsp[-2].valor_lexico)->line_number, ERR_UNDECLARED, symbol);
                        exit(ERR_UNDECLARED);
                }
                else
                {
                        char *nature = "identificador";
                        int is_equal = strcmp(row->nature, nature);
                        if(is_equal != 0)
                        {
                                printf("ERROR AT LINE %d. EXITING WITH CODE: %d (FUNCTION BEING USED AS VARIABLE!). FUNCTION NAME: %s.\n", (yyvsp[-2].valor_lexico)->line_number, ERR_FUNCTION, symbol);
                                exit(ERR_UNDECLARED);
                        } 
                }

                (yyval.ast) = ast_new("=", (yyvsp[0].ast)->type); 
                ast_add_child((yyval.ast), ast_new((yyvsp[-2].valor_lexico)->token_value, row->data_type)); 
                ast_add_child((yyval.ast), (yyvsp[0].ast)); 
        }
#line 1864 "parser.tab.c"
    break;

  case 34: /* chamada_funcao: TK_IDENTIFICADOR '(' lista_argumentos ')'  */
#line 379 "parser.y"
        { 
                char *symbol = (yyvsp[-3].valor_lexico)->token_value;

                T_SCOPE_TABLE_ROW *row = find_symbol_stack(table_stack, symbol);

                if(row == NULL)
                {
                        printf("ERROR AT LINE %d. EXITING WITH CODE: %d  (FUNCTION NOT YET DECLARED!). FUNCTION NAME: %s.\n", (yyvsp[-3].valor_lexico)->line_number, ERR_UNDECLARED, symbol);
                        exit(ERR_UNDECLARED);
                }
                else
                {
                        char *nature = "função";
                        int is_equal = strcmp(row->nature, nature);
                        if(is_equal != 0)
                        {
                                printf("ERROR AT LINE %d. EXITING WITH CODE: %d (VARIABLE BEING CALLED AS FUNCTION!). VARIABLE NAME: %s.\n", (yyvsp[-3].valor_lexico)->line_number, ERR_VARIABLE, symbol);
                                exit(ERR_UNDECLARED);
                        }
                }

                char call[] = "call ";
                (yyval.ast) = ast_new(strcat(call, (yyvsp[-3].valor_lexico)->token_value), row->data_type); 
                ast_add_child((yyval.ast), (yyvsp[-1].ast)); 
        }
#line 1894 "parser.tab.c"
    break;

  case 35: /* lista_argumentos: argumentos  */
#line 407 "parser.y"
                   { (yyval.ast) = (yyvsp[0].ast); }
#line 1900 "parser.tab.c"
    break;

  case 36: /* lista_argumentos: %empty  */
#line 408 "parser.y"
                 { (yyval.ast) = NULL; }
#line 1906 "parser.tab.c"
    break;

  case 37: /* argumentos: argumento  */
#line 412 "parser.y"
                  { (yyval.ast) = (yyvsp[0].ast); }
#line 1912 "parser.tab.c"
    break;

  case 38: /* argumentos: argumento ',' argumentos  */
#line 413 "parser.y"
                                   { (yyval.ast) = (yyvsp[-2].ast); ast_add_child((yyvsp[-2].ast), (yyvsp[0].ast)); }
#line 1918 "parser.tab.c"
    break;

  case 39: /* argumento: expressao  */
#line 417 "parser.y"
                  { (yyval.ast) = (yyvsp[0].ast); }
#line 1924 "parser.tab.c"
    break;

  case 40: /* retorno: TK_PR_RETURN expressao  */
#line 422 "parser.y"
        { 
                (yyval.ast) = ast_new((yyvsp[-1].valor_lexico)->token_value, (yyvsp[0].ast)->type); 
                ast_add_child((yyval.ast), (yyvsp[0].ast)); 
        }
#line 1933 "parser.tab.c"
    break;

  case 41: /* controle_fluxo: bloco_if_else  */
#line 429 "parser.y"
                      { (yyval.ast) = (yyvsp[0].ast); }
#line 1939 "parser.tab.c"
    break;

  case 42: /* controle_fluxo: bloco_while  */
#line 430 "parser.y"
                      { (yyval.ast) = (yyvsp[0].ast); }
#line 1945 "parser.tab.c"
    break;

  case 43: /* bloco_if_else: bloco_if bloco_else  */
#line 434 "parser.y"
                            {  (yyval.ast) = (yyvsp[-1].ast); if((yyvsp[0].ast) != NULL){ ast_add_child((yyval.ast), (yyvsp[0].ast)); } }
#line 1951 "parser.tab.c"
    break;

  case 44: /* bloco_if: TK_PR_IF '(' expressao ')' bloco_comandos  */
#line 439 "parser.y"
        { 
                (yyval.ast) = ast_new((yyvsp[-4].valor_lexico)->token_value, (yyvsp[-2].ast)->type); 
                ast_add_child((yyval.ast), (yyvsp[-2].ast)); 
                if((yyvsp[0].ast) != NULL)
                { 
                        ast_add_child((yyval.ast), (yyvsp[0].ast)); 
                } 
        }
#line 1964 "parser.tab.c"
    break;

  case 45: /* bloco_else: TK_PR_ELSE bloco_comandos  */
#line 450 "parser.y"
                                  { (yyval.ast) = (yyvsp[0].ast); }
#line 1970 "parser.tab.c"
    break;

  case 46: /* bloco_else: %empty  */
#line 451 "parser.y"
                 { (yyval.ast) = NULL; }
#line 1976 "parser.tab.c"
    break;

  case 47: /* bloco_while: TK_PR_WHILE '(' expressao ')' bloco_comandos  */
#line 456 "parser.y"
        { 
                (yyval.ast) = ast_new((yyvsp[-4].valor_lexico)->token_value, (yyvsp[-2].ast)->type); 
                ast_add_child((yyval.ast), (yyvsp[-2].ast)); 
                ast_add_child((yyval.ast), (yyvsp[0].ast)); 
        }
#line 1986 "parser.tab.c"
    break;

  case 48: /* expressao: term0  */
#line 464 "parser.y"
              { (yyval.ast) = (yyvsp[0].ast); }
#line 1992 "parser.tab.c"
    break;

  case 49: /* term0: term0 TK_OC_OR term1  */
#line 469 "parser.y"
        { 
                char *type = malloc(sizeof (char*));
                type = calc_type((yyvsp[-2].ast)->type, (yyvsp[0].ast)->type);
                (yyval.ast) = ast_new((yyvsp[-1].valor_lexico)->token_value, type);  
                ast_add_child((yyval.ast), (yyvsp[-2].ast)); 
                ast_add_child((yyval.ast), (yyvsp[0].ast)); 
        }
#line 2004 "parser.tab.c"
    break;

  case 50: /* term0: term1  */
#line 476 "parser.y"
                { (yyval.ast) = (yyvsp[0].ast); }
#line 2010 "parser.tab.c"
    break;

  case 51: /* term1: term1 TK_OC_AND term2  */
#line 481 "parser.y"
        {
                char *type = malloc(sizeof (char*));
                type = calc_type((yyvsp[-2].ast)->type, (yyvsp[0].ast)->type);
                (yyval.ast) = ast_new((yyvsp[-1].valor_lexico)->token_value, type);  
                ast_add_child((yyval.ast), (yyvsp[-2].ast)); 
                ast_add_child((yyval.ast), (yyvsp[0].ast)); 
        }
#line 2022 "parser.tab.c"
    break;

  case 52: /* term1: term2  */
#line 488 "parser.y"
                { (yyval.ast) = (yyvsp[0].ast); }
#line 2028 "parser.tab.c"
    break;

  case 53: /* term2: term2 TK_OC_EQ term4  */
#line 493 "parser.y"
        { 
                char *type = malloc(sizeof (char*));
                type = calc_type((yyvsp[-2].ast)->type, (yyvsp[0].ast)->type);
                (yyval.ast) = ast_new((yyvsp[-1].valor_lexico)->token_value, type);  
                ast_add_child((yyval.ast), (yyvsp[-2].ast)); 
                ast_add_child((yyval.ast), (yyvsp[0].ast)); 
        }
#line 2040 "parser.tab.c"
    break;

  case 54: /* term2: term2 TK_OC_NE term4  */
#line 501 "parser.y"
        { 
                char *type = malloc(sizeof (char*));
                type = calc_type((yyvsp[-2].ast)->type, (yyvsp[0].ast)->type);
                (yyval.ast) = ast_new((yyvsp[-1].valor_lexico)->token_value, type);  
                ast_add_child((yyval.ast), (yyvsp[-2].ast)); 
                ast_add_child((yyval.ast), (yyvsp[0].ast)); 
        }
#line 2052 "parser.tab.c"
    break;

  case 55: /* term2: term4  */
#line 508 "parser.y"
                { (yyval.ast) = (yyvsp[0].ast); }
#line 2058 "parser.tab.c"
    break;

  case 56: /* term4: term4 '<' term8  */
#line 513 "parser.y"
        { 
                char *type = malloc(sizeof (char*));
                type = calc_type((yyvsp[-2].ast)->type, (yyvsp[0].ast)->type);
                (yyval.ast) = ast_new((yyvsp[-1].valor_lexico)->token_value, type);  
                ast_add_child((yyval.ast), (yyvsp[-2].ast)); 
                ast_add_child((yyval.ast), (yyvsp[0].ast)); 
        }
#line 2070 "parser.tab.c"
    break;

  case 57: /* term4: term4 '>' term8  */
#line 521 "parser.y"
        { 
                char *type = malloc(sizeof (char*));
                type = calc_type((yyvsp[-2].ast)->type, (yyvsp[0].ast)->type);
                (yyval.ast) = ast_new((yyvsp[-1].valor_lexico)->token_value, type);  
                ast_add_child((yyval.ast), (yyvsp[-2].ast)); 
                ast_add_child((yyval.ast), (yyvsp[0].ast)); 
        }
#line 2082 "parser.tab.c"
    break;

  case 58: /* term4: term4 TK_OC_LE term8  */
#line 529 "parser.y"
        { 
                char *type = malloc(sizeof (char*));
                type = calc_type((yyvsp[-2].ast)->type, (yyvsp[0].ast)->type);
                (yyval.ast) = ast_new((yyvsp[-1].valor_lexico)->token_value, type);  
                ast_add_child((yyval.ast), (yyvsp[-2].ast)); 
                ast_add_child((yyval.ast), (yyvsp[0].ast)); 
        }
#line 2094 "parser.tab.c"
    break;

  case 59: /* term4: term4 TK_OC_GE term8  */
#line 537 "parser.y"
        { 
                char *type = malloc(sizeof (char*));
                type = calc_type((yyvsp[-2].ast)->type, (yyvsp[0].ast)->type);
                (yyval.ast) = ast_new((yyvsp[-1].valor_lexico)->token_value, type);  
                ast_add_child((yyval.ast), (yyvsp[-2].ast)); 
                ast_add_child((yyval.ast), (yyvsp[0].ast)); 
        }
#line 2106 "parser.tab.c"
    break;

  case 60: /* term4: term8  */
#line 544 "parser.y"
                { (yyval.ast) = (yyvsp[0].ast); }
#line 2112 "parser.tab.c"
    break;

  case 61: /* term8: term8 '+' term10  */
#line 549 "parser.y"
        { 
                char *type = malloc(sizeof (char*));
                type = calc_type((yyvsp[-2].ast)->type, (yyvsp[0].ast)->type);
                (yyval.ast) = ast_new((yyvsp[-1].valor_lexico)->token_value, type); 
                ast_add_child((yyval.ast), (yyvsp[-2].ast)); 
                ast_add_child((yyval.ast), (yyvsp[0].ast)); 
        }
#line 2124 "parser.tab.c"
    break;

  case 62: /* term8: term8 '-' term10  */
#line 557 "parser.y"
        { 
                char *type = malloc(sizeof (char*));
                type = calc_type((yyvsp[-2].ast)->type, (yyvsp[0].ast)->type);
                (yyval.ast) = ast_new((yyvsp[-1].valor_lexico)->token_value, type); 
                ast_add_child((yyval.ast), (yyvsp[-2].ast)); 
                ast_add_child((yyval.ast), (yyvsp[0].ast)); 
        }
#line 2136 "parser.tab.c"
    break;

  case 63: /* term8: term10  */
#line 564 "parser.y"
                 { (yyval.ast) = (yyvsp[0].ast); }
#line 2142 "parser.tab.c"
    break;

  case 64: /* term10: term10 '*' term13  */
#line 570 "parser.y"
        { 
                char *type = malloc(sizeof (char*));
                type = calc_type((yyvsp[-2].ast)->type, (yyvsp[0].ast)->type);
                (yyval.ast) = ast_new((yyvsp[-1].valor_lexico)->token_value, type); 
                ast_add_child((yyval.ast), (yyvsp[-2].ast)); 
                ast_add_child((yyval.ast), (yyvsp[0].ast)); 
        }
#line 2154 "parser.tab.c"
    break;

  case 65: /* term10: term10 '/' term13  */
#line 578 "parser.y"
        { 
                char *type = malloc(sizeof (char*));
                type = calc_type((yyvsp[-2].ast)->type, (yyvsp[0].ast)->type);
                (yyval.ast) = ast_new((yyvsp[-1].valor_lexico)->token_value, type); 
                ast_add_child((yyval.ast), (yyvsp[-2].ast)); 
                ast_add_child((yyval.ast), (yyvsp[0].ast)); 
        }
#line 2166 "parser.tab.c"
    break;

  case 66: /* term10: term10 '%' term13  */
#line 586 "parser.y"
        { 
                char *type = malloc(sizeof (char*));
                type = calc_type((yyvsp[-2].ast)->type, (yyvsp[0].ast)->type);
                (yyval.ast) = ast_new((yyvsp[-1].valor_lexico)->token_value, type); 
                ast_add_child((yyval.ast), (yyvsp[-2].ast)); 
                ast_add_child((yyval.ast), (yyvsp[0].ast)); 
        }
#line 2178 "parser.tab.c"
    break;

  case 67: /* term10: term13  */
#line 593 "parser.y"
                 { (yyval.ast) = (yyvsp[0].ast); }
#line 2184 "parser.tab.c"
    break;

  case 68: /* term13: '-' term13  */
#line 597 "parser.y"
                   { (yyval.ast) = ast_new((yyvsp[-1].valor_lexico)->token_value, (yyvsp[0].ast)->type); ast_add_child((yyval.ast), (yyvsp[0].ast)); }
#line 2190 "parser.tab.c"
    break;

  case 69: /* term13: '!' term13  */
#line 598 "parser.y"
                     { (yyval.ast) = ast_new((yyvsp[-1].valor_lexico)->token_value, (yyvsp[0].ast)->type); ast_add_child((yyval.ast), (yyvsp[0].ast)); }
#line 2196 "parser.tab.c"
    break;

  case 70: /* term13: term14  */
#line 599 "parser.y"
                 { (yyval.ast) = (yyvsp[0].ast); }
#line 2202 "parser.tab.c"
    break;

  case 71: /* term14: '(' expressao ')'  */
#line 603 "parser.y"
                          { (yyval.ast) = (yyvsp[-1].ast); }
#line 2208 "parser.tab.c"
    break;

  case 72: /* term14: chamada_funcao  */
#line 604 "parser.y"
                         { (yyval.ast) = (yyvsp[0].ast); }
#line 2214 "parser.tab.c"
    break;

  case 73: /* term14: operando  */
#line 605 "parser.y"
                   { (yyval.ast) = (yyvsp[0].ast); }
#line 2220 "parser.tab.c"
    break;

  case 74: /* operando: TK_IDENTIFICADOR  */
#line 610 "parser.y"
        { 
                char *symbol = (yyvsp[0].valor_lexico)->token_value;

                T_SCOPE_TABLE_ROW *row = find_symbol_stack(table_stack, symbol);

                if(row == NULL)
                {
                        printf("ERROR AT LINE %d. EXITING WITH CODE: %d (VARIABLE NOT YET DECLARED!). VARIABLE NAME: %s.\n", (yyvsp[0].valor_lexico)->line_number, ERR_UNDECLARED, symbol);
                        exit(ERR_UNDECLARED);
                }
                else
                {
                        char *nature = "identificador";
                        int is_equal = strcmp(row->nature, nature);
                        if(is_equal != 0)
                        {
                                printf("ERROR AT LINE %d. EXITING WITH CODE: %d (FUNCTION BEING USED AS VARIABLE!). FUNCTION NAME: %s.\n", (yyvsp[0].valor_lexico)->line_number, ERR_FUNCTION, symbol);
                                exit(ERR_UNDECLARED);
                        }
                }

                (yyval.ast) = ast_new((yyvsp[0].valor_lexico)->token_value, row->data_type); 
        }
#line 2248 "parser.tab.c"
    break;

  case 75: /* operando: TK_LIT_FALSE  */
#line 634 "parser.y"
        { 
                char *type = "bool";
                (yyval.ast) = ast_new((yyvsp[0].valor_lexico)->token_value, type);
                int line_num = (yyvsp[0].valor_lexico)->line_number;
                char *nature = "literal";
                int stack_idx = (table_stack->tables_number) - 1;
                T_SCOPE_TABLE* stack_top = table_stack->tables[stack_idx];

                char *string = (yyvsp[0].valor_lexico)->token_value;

                T_SCOPE_TABLE_ROW *prev_row = find_value_stack(table_stack, string);

                char *key = (char*) calloc(1, sizeof (char*));
                strcpy(key, string);

                if(prev_row == NULL)
                {
                        char *key_val = "#0";

                        strcat(key, key_val);
                }
                else
                {
                        char *key_val;
                        char del[2] = "#";
                        char *row_val = prev_row->symbol;
                        char *val_cpy = (char*) calloc(1, sizeof (char*));
                        strcpy(val_cpy, row_val);
                        key_val = strtok(val_cpy, del);
                        key_val = strtok(NULL, del);

                        int next_val = atoi(key_val) + 1;
                        sprintf(key_val, "%d", next_val);

                        char new_key[3] = {'#'};
                        strcat(new_key, key_val);
                        strcat(key, new_key);
                }

                T_SCOPE_TABLE_ROW *row = create_row(line_num, key, nature, type, string);
                stack_top = add_row(stack_top, row);
                
                table_stack->tables[stack_idx] = stack_top;
        }
#line 2297 "parser.tab.c"
    break;

  case 76: /* operando: TK_LIT_TRUE  */
#line 679 "parser.y"
        { 
                char *type = "bool";
                (yyval.ast) = ast_new((yyvsp[0].valor_lexico)->token_value, type); 

                int line_num = (yyvsp[0].valor_lexico)->line_number;
                char *nature = "literal";
                int stack_idx = (table_stack->tables_number) - 1;
                T_SCOPE_TABLE* stack_top = table_stack->tables[stack_idx];

                char *string = (yyvsp[0].valor_lexico)->token_value;

                T_SCOPE_TABLE_ROW *prev_row = find_value_stack(table_stack, string);

                char *key = (char*) calloc(1, sizeof (char*));
                strcpy(key, string);

                if(prev_row == NULL)
                {
                        char *key_val = "#0";

                        strcat(key, key_val);
                }
                else
                {
                        char *key_val;
                        char del[2] = "#";
                        char *row_val = prev_row->symbol;
                        char *val_cpy = (char*) calloc(1, sizeof (char*));
                        strcpy(val_cpy, row_val);
                        key_val = strtok(val_cpy, del);
                        key_val = strtok(NULL, del);

                        int next_val = atoi(key_val) + 1;
                        sprintf(key_val, "%d", next_val);

                        char new_key[3] = {'#'};
                        strcat(new_key, key_val);
                        strcat(key, new_key);
                }

                T_SCOPE_TABLE_ROW *row = create_row(line_num, key, nature, type, string);
                stack_top = add_row(stack_top, row);
                
                table_stack->tables[stack_idx] = stack_top;
        }
#line 2347 "parser.tab.c"
    break;

  case 77: /* operando: TK_LIT_INT  */
#line 725 "parser.y"
        { 
                char *type = "int";
                (yyval.ast) = ast_new((yyvsp[0].valor_lexico)->token_value, type); 

                int line_num = (yyvsp[0].valor_lexico)->line_number;
                char *nature = "literal";
                int stack_idx = (table_stack->tables_number) - 1;
                T_SCOPE_TABLE* stack_top = table_stack->tables[stack_idx];

                char *string = (yyvsp[0].valor_lexico)->token_value;

                T_SCOPE_TABLE_ROW *prev_row = find_value_stack(table_stack, string);

                char *key = (char*) calloc(1, sizeof (char*));
                strcpy(key, string);

                if(prev_row == NULL)
                {
                        char *key_val = "#0";

                        strcat(key, key_val);
                }
                else
                {
                        char *key_val;
                        char del[2] = "#";
                        char *row_val = prev_row->symbol;
                        char *val_cpy = (char*) calloc(1, sizeof (char*));
                        strcpy(val_cpy, row_val);
                        key_val = strtok(val_cpy, del);
                        key_val = strtok(NULL, del);

                        int next_val = atoi(key_val) + 1;
                        sprintf(key_val, "%d", next_val);

                        char new_key[3] = {'#'};
                        strcat(new_key, key_val);
                        strcat(key, new_key);
                }

                T_SCOPE_TABLE_ROW *row = create_row(line_num, key, nature, type, string);
                stack_top = add_row(stack_top, row);
                
                table_stack->tables[stack_idx] = stack_top;
        }
#line 2397 "parser.tab.c"
    break;

  case 78: /* operando: TK_LIT_FLOAT  */
#line 771 "parser.y"
        { 
                char *type = "float";
                (yyval.ast) = ast_new((yyvsp[0].valor_lexico)->token_value, type); 

                int line_num = (yyvsp[0].valor_lexico)->line_number;
                char *nature = "literal";
                int stack_idx = (table_stack->tables_number) - 1;
                T_SCOPE_TABLE* stack_top = table_stack->tables[stack_idx];

                char *string = (yyvsp[0].valor_lexico)->token_value;

                T_SCOPE_TABLE_ROW *prev_row = find_value_stack(table_stack, string);

                char *key = (char*) calloc(1, sizeof (char*));
                strcpy(key, string);

                if(prev_row == NULL)
                {
                        char *key_val = "#0";

                        strcat(key, key_val);
                }
                else
                {
                        char *key_val;
                        char del[2] = "#";
                        char *row_val = prev_row->symbol;
                        char *val_cpy = (char*) calloc(1, sizeof (char*));
                        strcpy(val_cpy, row_val);
                        key_val = strtok(val_cpy, del);
                        key_val = strtok(NULL, del);

                        int next_val = atoi(key_val) + 1;
                        sprintf(key_val, "%d", next_val);

                        char new_key[3] = {'#'};
                        strcat(new_key, key_val);
                        strcat(key, new_key);
                }

                T_SCOPE_TABLE_ROW *row = create_row(line_num, key, nature, type, string);
                stack_top = add_row(stack_top, row);
                
                table_stack->tables[stack_idx] = stack_top;
        }
#line 2447 "parser.tab.c"
    break;

  case 79: /* abrir_escopo: %empty  */
#line 820 "parser.y"
        {
                table_stack = add_table(table_stack);
                // printf("***--***--***\n");
                // printf("ESCOPO CRIADO\n");
                // printf("NÚMERO DE TABELAS NA PILHA: %d\n", table_stack->tables_number);
                // printf("***--***--***\n");
        }
#line 2459 "parser.tab.c"
    break;

  case 80: /* fechar_escopo: %empty  */
#line 831 "parser.y"
        {
                print_stack(table_stack);
                // printf("***--***--***\n");
                // printf("ESCOPO FECHADO\n");
                // printf("NÚMERO DE TABELAS NA PILHA: %d\n", table_stack->tables_number - 1);
                // printf("***--***--***\n");
                table_stack = pop_table(table_stack);
        }
#line 2472 "parser.tab.c"
    break;


#line 2476 "parser.tab.c"

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
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
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
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 841 "parser.y"

