/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <vector>
#include <string>
#include <limits>
#include <sstream>
#include "SymTable.h"
//#include "SymbolInfo.h"

//#define YYSTYPE SymbolInfo*

using namespace std;

extern int yylex();
void yyerror(const char *s);
extern FILE *yyin;
extern int lCount;
extern int errCount;


int labelCount=0;
int tempCount=0;
int pTempCount = 0;
int maxTemp = 0;


string variable_type;
SymbolTable table(13);
int IDargs = 0;
vector<string> args; 
extern int lCount;
int semErrors;
vector<SymbolInfo> params;
string return_label;

vector<string> variables;
vector<string> arrays;
vector<int> arraySizes;

ofstream logFile, errorFile, asmCode;

char *newLabel()
{
	char *lb= new char[4];
	strcpy(lb,"L");
	char b[3];
	sprintf(b,"%d", labelCount);
	labelCount++;
	strcat(lb,b);
	return lb;
}

char *newTemp()
{
	char *t= new char[4];
	strcpy(t,"t");
	char b[3];
	sprintf(b,"%d", tempCount);
	tempCount++;
	if(maxTemp < tempCount) maxTemp = tempCount;
	strcat(t,b);
	return t;
}

char *newPTemp()
{
	char *pt= new char[4];
	strcpy(pt,"p");
	char b[3];
	sprintf(b,"%d", pTempCount);
	pTempCount++;
	strcat(pt,b);
	return pt;
}

//SymbolTable *table= new SymbolTable(31);


#line 148 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    COMMENT = 258,
    IF = 259,
    ELSE = 260,
    FOR = 261,
    WHILE = 262,
    DO = 263,
    BREAK = 264,
    CONTINUE = 265,
    INT = 266,
    FLOAT = 267,
    CHAR = 268,
    DOUBLE = 269,
    VOID = 270,
    RETURN = 271,
    SWITCH = 272,
    CASE = 273,
    DEFAULT = 274,
    INCOP = 275,
    DECOP = 276,
    ASSIGNOP = 277,
    LPAREN = 278,
    RPAREN = 279,
    LCURL = 280,
    RCURL = 281,
    LTHIRD = 282,
    RTHIRD = 283,
    SEMICOLON = 284,
    COMMA = 285,
    STRING = 286,
    NOT = 287,
    PRINTLN = 288,
    ID = 289,
    CONST_INT = 290,
    CONST_FLOAT = 291,
    CONST_CHAR = 292,
    ADDOP = 293,
    MULOP = 294,
    LOGICOP = 295,
    RELOP = 296,
    THEN = 297
  };
#endif
/* Tokens.  */
#define COMMENT 258
#define IF 259
#define ELSE 260
#define FOR 261
#define WHILE 262
#define DO 263
#define BREAK 264
#define CONTINUE 265
#define INT 266
#define FLOAT 267
#define CHAR 268
#define DOUBLE 269
#define VOID 270
#define RETURN 271
#define SWITCH 272
#define CASE 273
#define DEFAULT 274
#define INCOP 275
#define DECOP 276
#define ASSIGNOP 277
#define LPAREN 278
#define RPAREN 279
#define LCURL 280
#define RCURL 281
#define LTHIRD 282
#define RTHIRD 283
#define SEMICOLON 284
#define COMMA 285
#define STRING 286
#define NOT 287
#define PRINTLN 288
#define ID 289
#define CONST_INT 290
#define CONST_FLOAT 291
#define CONST_CHAR 292
#define ADDOP 293
#define MULOP 294
#define LOGICOP 295
#define RELOP 296
#define THEN 297

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 85 "parser.y" /* yacc.c:355  */

SymbolInfo* symVal;

#line 276 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 293 "y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
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
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   146

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  26
/* YYNRULES -- Number of rules.  */
#define YYNRULES  70
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  122

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   297

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      35,    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   113,   113,   136,   143,   150,   156,   162,   169,   187,
     195,   194,   286,   300,   305,   317,   322,   326,   325,   336,
     343,   347,   354,   361,   368,   377,   404,   448,   473,   504,
     508,   517,   521,   525,   529,   555,   568,   583,   598,   605,
     610,   618,   625,   631,   636,   643,   660,   684,   688,   704,
     708,   753,   757,   795,   799,   825,   830,   861,   877,   886,
     893,   908,   918,   923,   929,   935,   945,   956,   960,   963,
     967
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "COMMENT", "IF", "ELSE", "FOR", "WHILE",
  "DO", "BREAK", "CONTINUE", "INT", "FLOAT", "CHAR", "DOUBLE", "VOID",
  "RETURN", "SWITCH", "CASE", "DEFAULT", "INCOP", "DECOP", "ASSIGNOP",
  "LPAREN", "RPAREN", "LCURL", "RCURL", "LTHIRD", "RTHIRD", "SEMICOLON",
  "COMMA", "STRING", "NOT", "PRINTLN", "ID", "CONST_INT", "CONST_FLOAT",
  "CONST_CHAR", "ADDOP", "MULOP", "LOGICOP", "RELOP", "THEN", "$accept",
  "start", "program", "unit", "func_declaration", "func_definition", "$@1",
  "parameter_list", "compound_statement", "$@2", "var_declaration",
  "type_specifier", "declaration_list", "statements", "statement",
  "expression_statement", "variable", "expression", "logic_expression",
  "rel_expression", "simple_expression", "term", "unary_expression",
  "factor", "argument_list", "arguments", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297
};
# endif

#define YYPACT_NINF -74

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-74)))

#define YYTABLE_NINF -11

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      38,   -74,   -74,   -74,    22,    38,   -74,   -74,   -74,   -74,
      -4,   -74,   -74,    28,     3,    38,    23,   -74,   -74,    25,
      -7,    36,    47,    29,    18,    38,   -74,   -74,    41,   -74,
     -74,    52,    44,    55,    54,   -74,   -74,   -74,   -74,    89,
      61,    63,    64,    75,    75,   -74,    75,    74,    34,   -74,
     -74,    75,   -74,   -74,    65,    56,   -74,   -74,    -8,    15,
     -74,    62,   -14,    67,   -74,   -74,    75,    97,    75,    17,
      79,    53,   -74,    81,    75,    75,   -74,    90,   -74,   -74,
     -74,   -74,    75,   -74,   -74,    75,    75,    75,    75,    84,
      97,    92,   -74,   -74,   -74,    95,   -74,   104,   100,   106,
     -74,   -74,    67,    98,   -74,    89,    75,    89,    19,   -74,
      75,   -74,   132,   114,   -74,   -74,   -74,   -74,    89,    89,
     -74,   -74
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    22,    23,    24,     0,     2,     4,     6,     7,     5,
       0,     1,     3,    27,     0,    16,     0,    21,    20,     0,
       0,    15,     0,    25,     0,     0,    14,    28,     0,     9,
       8,     0,    13,     0,    17,    11,    12,    26,    19,     0,
       0,     0,     0,     0,     0,    42,     0,     0,    45,    63,
      64,     0,    33,    31,     0,     0,    29,    32,    60,     0,
      47,    49,    51,    53,    55,    59,     0,     0,     0,     0,
       0,    60,    58,     0,    68,     0,    57,    27,    18,    30,
      65,    66,     0,    44,    43,     0,     0,     0,     0,     0,
       0,     0,    41,    40,    62,     0,    70,     0,    67,     0,
      48,    50,    54,    52,    56,     0,     0,     0,     0,    61,
       0,    46,    35,     0,    37,    39,    38,    69,     0,     0,
      36,    34
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -74,   -74,   -74,   134,   -74,   -74,   -74,   -74,   109,   -74,
      21,    10,   -74,   -74,   -53,   -56,   -46,   -37,   -73,    57,
      58,    60,   -43,   -74,   -74,   -74
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,     7,     8,    31,    20,    52,    39,
      53,    54,    14,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    97,    98
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      71,    96,    79,    72,    17,    71,    69,    70,    76,   100,
      10,    90,    80,    81,    82,    10,    83,    24,    92,    29,
     115,     9,    11,    25,    86,    21,     9,    87,    71,    89,
      13,    91,    18,    19,   106,    32,    71,   117,    99,    71,
      71,    71,    71,   -10,    84,   104,    93,    30,   116,     1,
       2,    15,   112,     3,   114,    16,    28,    74,    22,    23,
      40,    75,    41,    42,    71,   120,   121,     1,     2,   113,
      26,     3,    43,    80,    81,    27,    33,    34,    36,    44,
      38,    34,    78,    37,    66,    45,    67,    68,    46,    47,
      48,    49,    50,    40,    51,    41,    42,    73,    44,    77,
       1,     2,    85,    94,     3,    43,    88,    46,   105,    48,
      49,    50,    44,    51,    34,    95,   107,    16,    45,   108,
      44,    46,    47,    48,    49,    50,    45,    51,   109,    46,
     110,    48,    49,    50,   111,    51,    86,   118,   119,    12,
      35,     0,   101,     0,     0,   103,   102
};

static const yytype_int8 yycheck[] =
{
      46,    74,    55,    46,     1,    51,    43,    44,    51,    82,
       0,    67,    20,    21,    22,     5,     1,    24,     1,     1,
       1,     0,     0,    30,    38,    15,     5,    41,    74,    66,
      34,    68,    29,    30,    90,    25,    82,   110,    75,    85,
      86,    87,    88,    25,    29,    88,    29,    29,    29,    11,
      12,    23,   105,    15,   107,    27,    27,    23,    35,    34,
       4,    27,     6,     7,   110,   118,   119,    11,    12,   106,
      34,    15,    16,    20,    21,    28,    35,    25,    34,    23,
      26,    25,    26,    28,    23,    29,    23,    23,    32,    33,
      34,    35,    36,     4,    38,     6,     7,    23,    23,    34,
      11,    12,    40,    24,    15,    16,    39,    32,    24,    34,
      35,    36,    23,    38,    25,    34,    24,    27,    29,    24,
      23,    32,    33,    34,    35,    36,    29,    38,    24,    32,
      30,    34,    35,    36,    28,    38,    38,     5,    24,     5,
      31,    -1,    85,    -1,    -1,    87,    86
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    11,    12,    15,    44,    45,    46,    47,    48,    53,
      54,     0,    46,    34,    55,    23,    27,     1,    29,    30,
      50,    54,    35,    34,    24,    30,    34,    28,    27,     1,
      29,    49,    54,    35,    25,    51,    34,    28,    26,    52,
       4,     6,     7,    16,    23,    29,    32,    33,    34,    35,
      36,    38,    51,    53,    54,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    23,    23,    23,    60,
      60,    59,    65,    23,    23,    27,    65,    34,    26,    57,
      20,    21,    22,     1,    29,    40,    38,    41,    39,    60,
      58,    60,     1,    29,    24,    34,    61,    67,    68,    60,
      61,    62,    64,    63,    65,    24,    58,    24,    24,    24,
      30,    28,    57,    60,    57,     1,    29,    61,     5,    24,
      57,    57
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    43,    44,    45,    45,    46,    46,    46,    47,    47,
      49,    48,    50,    50,    50,    50,    50,    52,    51,    51,
      53,    53,    54,    54,    54,    55,    55,    55,    55,    56,
      56,    57,    57,    57,    57,    57,    57,    57,    57,    57,
      57,    57,    58,    58,    58,    59,    59,    60,    60,    61,
      61,    62,    62,    63,    63,    64,    64,    65,    65,    65,
      66,    66,    66,    66,    66,    66,    66,    67,    67,    68,
      68
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     6,     6,
       0,     7,     4,     3,     2,     1,     0,     0,     4,     2,
       3,     3,     1,     1,     1,     3,     6,     1,     4,     1,
       2,     1,     1,     1,     7,     5,     7,     5,     5,     5,
       3,     3,     1,     2,     2,     1,     4,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     2,     2,     1,
       1,     4,     3,     1,     1,     2,     2,     1,     0,     3,
       1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
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
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
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
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
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
            /* Fall through.  */
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

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
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
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
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
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
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
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
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
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
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
          yyp++;
          yyformat++;
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
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

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
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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
#line 114 "parser.y" /* yacc.c:1646  */
    {
		//write your code in this block in all the similar blocks below
		if(!errCount && !semErrors){
			(yyvsp[0].symVal)->code+="\n\nDECIMAL_OUT PROC NEAR\n\n\tpush ax\n\tpush bx\n\tpush cx\n\tpush dx\n\tor ax,ax\n \tjge enddif\n\tpush ax\n\tmov dl,'-'\n\tmov ah,2\n\tint 21h\n\tpop ax\n\tneg ax\nenddif:\n\txor cx,cx\n\tmov bx,10d\nrepeat:\n\txor dx,dx\n\tdiv bx\n\t push dx\n\tinc cx\n\tor ax,ax\n\tjne repeat\n\tmov ah,2\nprint_loop:\n\tpop dx\n\tor dl,30h\n\tint 21h\n\tloop print_loop\n\tpop dx\n\tpop cx\n\tpop bx\n\tpop ax\n\tret\n\nDECIMAL_OUT ENDP\n";
			ofstream fout;
			fout.open("code.asm");
			fout << ".model small\n.stack 100h\n\n.data\n" ;
			for(int i = 0; i<variables.size() ; i++){
				fout << variables[i] << " dw ?\n";			
			}

			for(int i = 0 ; i< arrays.size() ; i++){
				fout << arrays[i] << " dw " << arraySizes[i] << " dup(?)\n";
			}

			fout << "\n.code \n"; 
			fout << (yyvsp[0].symVal)->code;
			logFile << "Line " << lCount << " : start : program\n"<< endl;
		}
	}
#line 1484 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 137 "parser.y" /* yacc.c:1646  */
    {
		logFile << "Line " << lCount << " : program : program unit\n"<< endl;
		(yyval.symVal) = (yyvsp[-1].symVal);
		(yyval.symVal)->code += (yyvsp[0].symVal)->code;
	}
#line 1494 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 144 "parser.y" /* yacc.c:1646  */
    {
		logFile << "Line " << lCount << " : program : unit\n"<< endl;
		(yyval.symVal) = (yyvsp[0].symVal);
	}
#line 1503 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 151 "parser.y" /* yacc.c:1646  */
    {
		logFile << "Line " << lCount << " : unit : var_declaration\n"<< endl;
		(yyval.symVal) = (yyvsp[0].symVal);
	}
#line 1512 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 157 "parser.y" /* yacc.c:1646  */
    {
			logFile << "Line " << lCount << " : unit : func_declaration\n"<< endl;
			(yyval.symVal) = (yyvsp[0].symVal);
     	}
#line 1521 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 163 "parser.y" /* yacc.c:1646  */
    {
			logFile << "Line " << lCount << " : unit : func_definition\n"<< endl;
			(yyval.symVal) = (yyvsp[0].symVal);
     	}
#line 1530 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 170 "parser.y" /* yacc.c:1646  */
    {
				logFile << "Line " << lCount << " : func_declaration : 	type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n" ;
				logFile << (yyvsp[-4].symVal)->getName() << endl << endl;
				SymbolInfo *temp = table.lookUp((yyvsp[-4].symVal)->getName(), "FUNC");
				if(temp != NULL){
					errorFile << "Error at line " << lCount << " Function "<< (yyvsp[-4].symVal)->getName() <<" already declared" << endl << endl;
					semErrors++;
				}else {
					SymbolInfo* temp2 = table.InsertandGet((yyvsp[-4].symVal)->getName(), "ID");
					temp2->setIDType("FUNC");
					temp2->setFuncRet((yyvsp[-5].symVal)->getVarType());
					for(int i = 0; i<args.size(); i++){
						temp2->ParamList.push_back(args[i]);					
					}
					args.clear();
				} 
			}
#line 1552 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 188 "parser.y" /* yacc.c:1646  */
    {
				errorFile << "Error at line " << lCount << " ; missing" << endl << endl;
				semErrors++;
			}
#line 1561 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 195 "parser.y" /* yacc.c:1646  */
    {
				
				SymbolInfo *temp = table.lookUp((yyvsp[-3].symVal)->getName(), "FUNC");
				if(args.size() != IDargs){
					errorFile << "Error at line " << lCount << " Parameter mismatch for Function "<< (yyvsp[-3].symVal)->getName() << endl << endl;
					args.clear(); IDargs = 0;
					semErrors++;
				}												
				if(temp != NULL){
					//logFile << "Function " << $2->getName() <<" already declared" << endl;
					if(temp->isFuncDefined()== true){
						errorFile << "Error at line " << lCount << "Function "<< (yyvsp[-3].symVal)->getName() <<" already defined" << endl << endl;
						semErrors++;
						args.clear();
						IDargs = 0;
					}
					else if(temp->getFuncRet() != (yyvsp[-4].symVal)->getVarType()){
						errorFile << "Error at line " << lCount << "Function "<< (yyvsp[-3].symVal)->getName() <<" :return type doesn't match declaration" << endl << endl;
						semErrors++;
						args.clear();IDargs = 0; 
					} 
					else if(temp->ParamList.size() != args.size()){
						errorFile << "Error at line " << lCount << "Function "<< (yyvsp[-3].symVal)->getName() <<" :Parameter list doesn not match declaration" << endl << endl;
						args.clear();IDargs = 0;
						semErrors++;					
					}
					else{
						for(int i = 0; i<temp->ParamList.size(); i++){
							if(temp->ParamList[i] != args[i]){
								errorFile << "Error at line " << lCount << "Function "<< (yyvsp[-3].symVal)->getName()<< " :argument mismatch" << endl << endl;
								args.clear();IDargs = 0;
								semErrors++;	
							}
						}				
					}
				}
				else{
					SymbolInfo* temp = new SymbolInfo();
					temp = table.InsertandGet((yyvsp[-3].symVal)->getName(), "ID");
					temp->setIDType("FUNC");
					temp->setFuncRet((yyvsp[-4].symVal)->getVarType());
					//
					for(int i = 0; i<args.size(); i++){
						temp->ParamList.push_back(args[i]);					
					}
					temp->setFuncDefined();
				}
				
				
	
				}
#line 1617 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 247 "parser.y" /* yacc.c:1646  */
    {
				logFile << "Line " << lCount << " : func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n" ;
				logFile << (yyvsp[-5].symVal)->getName() << endl << endl;
				SymbolInfo * func = new SymbolInfo();				
				(yyval.symVal) = func;
				(yyval.symVal)->code += (yyvsp[-5].symVal)->getName() + " PROC NEAR\n\n";
				(yyval.symVal)->code += (yyvsp[0].symVal)->code;
				if((yyvsp[-5].symVal)->getName()!="main"){
					(yyval.symVal)->code+=string(return_label)+":\n";
				}
				if(args.size()!=0){
					(yyval.symVal)->code+="\tpop bp\n";
				}
				if((yyvsp[-5].symVal)->getName()!="main"){
					(yyval.symVal)->code+="\tret ";
				}
		
				int p=args.size()*2;
				if(p){
					string Result;       

					ostringstream convert;  
	
					convert << p;    

					Result = convert.str(); 
					(yyval.symVal)->code+=Result+"\n";
				}
				(yyval.symVal)->code+="\n";
				if((yyvsp[-5].symVal)->getName()=="main"){
					(yyval.symVal)->code+="\tmov ah,4ch\n\tint 21h\n";
				}
				(yyval.symVal)->code += "\n" + (yyvsp[-5].symVal)->getName() + " ENDP\n\n";
				args.clear();
				IDargs = 0;
				return_label = "";
			}
#line 1659 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 287 "parser.y" /* yacc.c:1646  */
    {
					logFile << "Line " << lCount << " : parameter_list  : parameter_list COMMA type_specifier ID\n" ;
					logFile << (yyvsp[0].symVal)->getName() << endl << endl;
					args.push_back(variable_type);//changed from $3->getVarType()
					IDargs++;
					(yyvsp[0].symVal)->setIDType("VAR");
					(yyvsp[0].symVal)->setVarType(variable_type);//changed from $3->getVarType()
					SymbolInfo* temp = new SymbolInfo((yyvsp[0].symVal)->getName(), (yyvsp[0].symVal)->getType());
					temp->setIDType("VAR");
					
					params.push_back(*temp);
				
				}
#line 1677 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 301 "parser.y" /* yacc.c:1646  */
    {
			logFile << "Line " << lCount << " : parameter_list  : parameter_list COMMA type_specifier\n"<< endl;
			args.push_back((yyvsp[0].symVal)->getVarType());
		}
#line 1686 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 306 "parser.y" /* yacc.c:1646  */
    {
			logFile << "Line " << lCount << " : parameter_list  : type_specifier ID\n" ;
			logFile << (yyvsp[0].symVal)->getName() << endl << endl;
			args.push_back(variable_type);//$1->getVarType()
			IDargs++;
			(yyvsp[0].symVal)->setIDType("VAR");
			(yyvsp[0].symVal)->setVarType(variable_type);//$1->getVarType()
			params.push_back(*(yyvsp[0].symVal));
				

		}
#line 1702 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 318 "parser.y" /* yacc.c:1646  */
    {
			logFile << "Line " << lCount << " : parameter_list  : type_specifier\n" ;
			args.push_back(variable_type);
		}
#line 1711 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 322 "parser.y" /* yacc.c:1646  */
    {}
#line 1717 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 326 "parser.y" /* yacc.c:1646  */
    {
						table.enterScope(); 
						for(int i = 0; i<params.size(); i++) table.Insert(params[i]);
						params.clear();					
					}
#line 1727 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 331 "parser.y" /* yacc.c:1646  */
    {	
						table.exitScope();
						(yyval.symVal)=(yyvsp[-1].symVal);
						logFile << "Line " << lCount << " : compound_statement : LCURL statements RCURL\n"<< endl;
					}
#line 1737 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 337 "parser.y" /* yacc.c:1646  */
    {
						(yyval.symVal)=new SymbolInfo("compound_statement","dummy");
						logFile << "Line " << lCount << " : compound_statement : LCURL RCURL\n"<< endl;
					}
#line 1746 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 344 "parser.y" /* yacc.c:1646  */
    {
					logFile << "Line " << lCount << " : var_declaration : type_specifier declaration_list SEMICOLON\n"<< endl;
				}
#line 1754 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 348 "parser.y" /* yacc.c:1646  */
    {
						errorFile << "Error at line " << lCount << " ; missing" << endl << endl;
						semErrors++;
				}
#line 1763 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 355 "parser.y" /* yacc.c:1646  */
    {
					logFile << "Line " << lCount << " : type_specifier	: INT\n"<< endl; 
					SymbolInfo* s= new SymbolInfo("INT");
					variable_type = "INT" ;
					(yyval.symVal) = s;
				}
#line 1774 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 362 "parser.y" /* yacc.c:1646  */
    {	
					logFile << "Line " << lCount << " : type_specifier	: FLOAT\n"<< endl;
					SymbolInfo* s= new SymbolInfo("FLOAT");
					variable_type = "FLOAT" ;
					(yyval.symVal) = s;
				}
#line 1785 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 369 "parser.y" /* yacc.c:1646  */
    {
					logFile << "Line " << lCount << " : type_specifier	: VOID\n"<< endl;
					SymbolInfo* s= new SymbolInfo("VOID");
					variable_type = "VOID" ;
					(yyval.symVal) = s;
				}
#line 1796 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 378 "parser.y" /* yacc.c:1646  */
    {
						logFile << "Line " << lCount << " : declaration_list : 	declaration_list COMMA ID\n" ;
						logFile << (yyvsp[0].symVal)->getName() << endl << endl;
						if(variable_type == "VOID"){
							errorFile << "Error at line " << lCount << " :variable type can't be void" << endl << endl;
							semErrors++;
						}
						else{
							SymbolInfo* temp = table.lookUp((yyvsp[0].symVal)->getName(), "VAR");
							if(temp != NULL){
							errorFile << "Error at line " << lCount << ": Variable "<< (yyvsp[0].symVal)->getName() <<" already declared" << endl << endl;	
								semErrors++;	
							}
							else{
								//SymbolInfo* temp2 = table.InsertandGet($3->getName(), $3->getType());
								//temp2->setVarType(variable_type);
								//temp2->setIDType("VAR");
								SymbolInfo* temp2 = new SymbolInfo((yyvsp[0].symVal)->getName(), (yyvsp[0].symVal)->getType());
								temp2->setVarType(variable_type);
								temp2->setIDType("VAR");
								table.Insert(*temp2);
								//data.push_back(*temp2);
								//table.printAll(logFile);
							}
						}
					}
#line 1827 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 405 "parser.y" /* yacc.c:1646  */
    {
						logFile << "Line " << lCount << " : declaration_list : 	declaration_list COMMA ID LTHIRD CONST_INT RTHIRD\n" ;
						logFile << (yyvsp[-3].symVal)->getName() << endl;
						logFile << (yyvsp[-1].symVal)->getName() << endl << endl;
						if(variable_type == "VOID"){
							errorFile << "Error at line " << lCount << " : array type can't be void" << endl << endl;
							semErrors++;
						}
						else{
							SymbolInfo* temp = table.lookUp((yyvsp[-3].symVal)->getName(), "ARA");
							if(temp!= NULL){
							errorFile << "Error at line " << lCount << " : Array "<< (yyvsp[-3].symVal)->getName()<< " already declared" << endl << endl;
								semErrors++;			
							}
							else{
								SymbolInfo* temp2 = new SymbolInfo((yyvsp[-3].symVal)->getName(), (yyvsp[-3].symVal)->getType());
								temp2->setVarType(variable_type);
								temp2->setIDType("ARA");
								int araSize = atoi(((yyvsp[-1].symVal)->getName()).c_str());
								temp2->setAraSize(araSize);
								if(variable_type == "INT"){								
									for(int i = temp2->ints.size(); i<araSize; i++){
										temp2->ints.push_back(0);
									}							
								}
								else if(variable_type == "FLOAT"){								
									for(int i = temp2->floats.size(); i<araSize; i++){
										temp2->floats.push_back(0);
									}							
								}
								else if(variable_type == "CHAR"){								
									for(int i = temp2->chars.size(); i<araSize; i++){
										temp2->chars.push_back('\0');
									}							
								}
								table.Insert(*temp2);	
								//data.push_back(*temp2);		
								//cout << temp2->getName() << endl;			
								//table.printAll(logFile);
							}
						}

					}
#line 1875 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 449 "parser.y" /* yacc.c:1646  */
    {
						logFile << "Line " << lCount << " : declaration_list :	ID\n" ;
						logFile << (yyvsp[0].symVal)->getName() << endl << endl;
						if(variable_type == "VOID"){
							errorFile << "Error at line " << lCount << " :variable type can't be void" << endl << endl;
							semErrors++;
						}
						else{
							SymbolInfo* temp = table.lookUp((yyvsp[0].symVal)->getName(), "ARA");
							if(temp!= NULL){
							errorFile << "Error at line " << lCount << ": Variable "<< (yyvsp[0].symVal)->getName() <<" already declared" << endl << endl;	
								semErrors++;		
							}
							else{
								SymbolInfo* temp2 = new SymbolInfo((yyvsp[0].symVal)->getName(), (yyvsp[0].symVal)->getType());
								temp2->setVarType(variable_type);
								temp2->setIDType("VAR");
								table.Insert(*temp2);
								//data.push_back(*temp2);
								//cout << temp2->getName() << endl;
								//table.printAll(logFile);		
							}
						}
					}
#line 1904 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 474 "parser.y" /* yacc.c:1646  */
    {
						logFile << "Line " << lCount << " : declaration_list :	ID LTHIRD CONST_INT RTHIRD\n" ;
						logFile << (yyvsp[-3].symVal)->getName() << endl;
						logFile << (yyvsp[-1].symVal)->getName() << endl << endl;
						if(variable_type == "VOID"){
							errorFile << "Error at line " << lCount << " :array type can't be void" << endl << endl;
							semErrors++;
						}
						else{
							SymbolInfo* temp = table.lookUp((yyvsp[-3].symVal)->getName(), "ARA");
							if(temp!= NULL){
								errorFile << "Error at line " << lCount << ": Array "<< (yyvsp[-3].symVal)->getName() <<" already declared" << endl << endl;	
								semErrors++;
							}
							else{
								SymbolInfo* temp2 = new SymbolInfo((yyvsp[-3].symVal)->getName(), (yyvsp[-3].symVal)->getType());
								temp2->setVarType(variable_type);
								temp2->setIDType("ARA");
								int araSize = atoi(((yyvsp[-1].symVal)->getName()).c_str());
								temp2->setAraSize(araSize);
								table.Insert(*temp2);
								//data.push_back(*temp2);
								//cout << temp2->getName() << endl;
								//table.printAll(logFile);			
							}
						}
					}
#line 1936 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 504 "parser.y" /* yacc.c:1646  */
    {
				(yyval.symVal)=(yyvsp[0].symVal);
				logFile << "Line " << lCount << " : statements : statement\n"<< endl;
			}
#line 1945 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 508 "parser.y" /* yacc.c:1646  */
    {
				(yyval.symVal)=(yyvsp[-1].symVal);
				(yyval.symVal)->code += (yyvsp[0].symVal)->code;
				delete (yyvsp[0].symVal);
				logFile << "Line " << lCount << " : statements : statements statement\n"<< endl;
			}
#line 1956 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 518 "parser.y" /* yacc.c:1646  */
    {
				logFile << "Line " << lCount << " : statement : var_declaration\n"<< endl;
			}
#line 1964 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 521 "parser.y" /* yacc.c:1646  */
    {
					logFile << "Line " << lCount << " : statement : expression_statement\n"<< endl;
					(yyval.symVal)=(yyvsp[0].symVal);
				}
#line 1973 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 525 "parser.y" /* yacc.c:1646  */
    {
					logFile << "Line " << lCount << " : statement : compound_statement\n"<< endl;
					(yyval.symVal)=(yyvsp[0].symVal);
				}
#line 1982 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 529 "parser.y" /* yacc.c:1646  */
    {			
				logFile << "Line " << lCount << " : statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n"<< endl;
					/*
						$3's code at first, which is already done by assigning $$=$3
						create two labels and append one of them in $$->code
						compare $4's symbol with 0
						if equal jump to 2nd label
						append $7's code
						append $5's code
						append the second label in the code
					*/

					(yyval.symVal) = (yyvsp[-4].symVal);
					char *label1 = newLabel();
					char *label2 = newLabel();
					(yyval.symVal)->code += string(label1) + ":\n";
					(yyval.symVal)->code+=(yyvsp[-3].symVal)->code;
					(yyval.symVal)->code+="\tmov ax , "+(yyvsp[-3].symVal)->getName()+"\n";
					(yyval.symVal)->code+="\tcmp ax , 0\n";
					(yyval.symVal)->code+="\tje "+string(label2)+"\n";
					(yyval.symVal)->code+=(yyvsp[0].symVal)->code;
					(yyval.symVal)->code+=(yyvsp[-2].symVal)->code;
					(yyval.symVal)->code+="\tjmp "+string(label1)+"\n";
					(yyval.symVal)->code+=string(label2)+":\n";
		
				}
#line 2013 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 555 "parser.y" /* yacc.c:1646  */
    {
					logFile << "Line " << lCount << " : statement : IF LPAREN expression RPAREN statement\n"<< endl;
					(yyval.symVal)=(yyvsp[-2].symVal);
					
					char *label=newLabel();
					(yyval.symVal)->code+="\tmov ax, "+(yyvsp[-2].symVal)->getName()+"\n";
					(yyval.symVal)->code+="\tcmp ax, 0\n";
					(yyval.symVal)->code+="\tje "+string(label)+"\n";
					(yyval.symVal)->code+=(yyvsp[0].symVal)->code;
					(yyval.symVal)->code+=string(label)+":\n";
					
					(yyval.symVal)->setName("if");//not necessary
				}
#line 2031 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 568 "parser.y" /* yacc.c:1646  */
    {
					logFile << "Line " << lCount << " : statement : IF LPAREN expression RPAREN statement ELSE statement\n"<< endl;
					(yyval.symVal)=(yyvsp[-4].symVal);
					//similar to if part
					char *elselabel=newLabel();
					char *exitlabel=newLabel();
					(yyval.symVal)->code+="\tmov ax,"+(yyvsp[-4].symVal)->getName()+"\n";
					(yyval.symVal)->code+="\tcmp ax,0\n";
					(yyval.symVal)->code+="\tje "+string(elselabel)+"\n";
					(yyval.symVal)->code+=(yyvsp[-2].symVal)->code;
					(yyval.symVal)->code+="\tjmp "+string(exitlabel)+"\n";
					(yyval.symVal)->code+=string(elselabel)+":\n";
					(yyval.symVal)->code+=(yyvsp[0].symVal)->code;
					(yyval.symVal)->code+=string(exitlabel)+":\n";
				}
#line 2051 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 583 "parser.y" /* yacc.c:1646  */
    {
					logFile << "Line " << lCount << " : statement : WHILE LPAREN expression RPAREN statement\n"<< endl;
					(yyval.symVal) = new SymbolInfo();
					char * label = newLabel();
					char * exit = newLabel();
					(yyval.symVal)->code = string(label) + ":\n"; 
					(yyval.symVal)->code+=(yyvsp[-2].symVal)->code;
					(yyval.symVal)->code+="\tmov ax , "+(yyvsp[-2].symVal)->getName()+"\n";
					(yyval.symVal)->code+="\tcmp ax , 0\n";
					(yyval.symVal)->code+="\tje "+string(exit)+"\n";
					(yyval.symVal)->code+=(yyvsp[0].symVal)->code;
					(yyval.symVal)->code+="\tjmp "+string(label)+"\n";
					(yyval.symVal)->code+=string(exit)+":\n";
			
				}
#line 2071 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 598 "parser.y" /* yacc.c:1646  */
    {
					// write code for printing an ID. You may assume that ID is an integer variable.
					(yyval.symVal)=new SymbolInfo("println","nonterminal");
					logFile << "Line " << lCount << " : statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n"<< endl;
					(yyval.symVal)->code += "\tmov ax, " + (yyvsp[-2].symVal)->getName() +"\n";
					(yyval.symVal)->code += "\tcall DECIMAL_OUT\n";
				}
#line 2083 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 606 "parser.y" /* yacc.c:1646  */
    {
				errorFile << "Error at line " << lCount << " ; missing" << endl << endl;
				semErrors++;
			}
#line 2092 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 610 "parser.y" /* yacc.c:1646  */
    {
					// write code for return.
					(yyval.symVal)=(yyvsp[-1].symVal);
					(yyval.symVal)->code+="\tmov dx,"+(yyvsp[-1].symVal)->getName()+"\n";
					(yyval.symVal)->code+="\tjmp   "+string(return_label)+"\n";
		
					logFile << "Line " << lCount << " : statement : RETURN expression SEMICOLON\n"<< endl;
				}
#line 2105 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 619 "parser.y" /* yacc.c:1646  */
    {
				errorFile << "Error at line " << lCount << " ; missing" << endl << endl;
				semErrors++;
			}
#line 2114 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 625 "parser.y" /* yacc.c:1646  */
    {
							logFile << "Line " << lCount << " : expression_statement : SEMICOLON\n"<< endl;
							(yyval.symVal)=new SymbolInfo(";","SEMICOLON");
							(yyval.symVal)->code="";
							tempCount = 0;
						}
#line 2125 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 631 "parser.y" /* yacc.c:1646  */
    {
							logFile << "Line " << lCount << " : expression_statement : expression SEMICOLON\n"<< endl;
							(yyval.symVal)=(yyvsp[-1].symVal);
							tempCount = 0;
						}
#line 2135 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 637 "parser.y" /* yacc.c:1646  */
    {
							errorFile << "Error at line " << lCount << " ; missing" << endl << endl;
							semErrors++;
						}
#line 2144 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 643 "parser.y" /* yacc.c:1646  */
    {
				logFile << "Line " << lCount << " : variable : ID\n" ;
				logFile << (yyvsp[0].symVal)->getName() << endl << endl;
				SymbolInfo* temp = table.lookUp((yyvsp[0].symVal)->getName(),"VAR");
				if(temp == NULL){
					//logFile << "Variable " << $1->getName() << " doesn't exist" << endl;
					errorFile << "Error at line " << lCount << " : " << (yyvsp[0].symVal)->getName() << " doesn't exist" <<  endl << endl;					
					semErrors++;
				}
				else{
					(yyval.symVal)= new SymbolInfo((yyvsp[0].symVal));
					(yyval.symVal)->code="";
					(yyval.symVal)->setName((yyval.symVal)->getName()+to_string(table.scopeNum));
					variables.push_back((yyval.symVal)->getName()+to_string(table.scopeNum));
					(yyval.symVal)->setType("notarray");
				}
		}
#line 2166 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 660 "parser.y" /* yacc.c:1646  */
    {
				logFile << "Line " << lCount << " : variable : ID LTHIRD expression RTHIRD\n" ;
				logFile << (yyvsp[-3].symVal)->getName() << endl << endl;
				SymbolInfo* temp = table.lookUp((yyvsp[-3].symVal)->getName(),"ARA");
				if(temp == NULL){
				errorFile << "Error at line " << lCount << " : " <<(yyvsp[-3].symVal)->getName() << " doesn't exist" <<  endl << endl;					
					semErrors++;				
				}
				else{
					
					(yyval.symVal)= new SymbolInfo((yyvsp[-3].symVal));
					(yyval.symVal)->setType("array");
					(yyval.symVal)->setName((yyval.symVal)->getName()+to_string(table.scopeNum));
					arrays.push_back((yyval.symVal)->getName()+to_string(table.scopeNum));
					arraySizes.push_back((yyvsp[-3].symVal)->getAraSize());
					(yyval.symVal)->code=(yyvsp[-1].symVal)->code ;
					(yyval.symVal)->code += "\tmov bx, " +(yyvsp[-1].symVal)->getName() +"\n";
					(yyval.symVal)->code += "\tadd bx, bx\n";
					
					delete (yyvsp[-1].symVal);
			}
		}
#line 2193 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 684 "parser.y" /* yacc.c:1646  */
    {
			(yyval.symVal)= (yyvsp[0].symVal);
			logFile << "Line " << lCount << " : expression : logic_expression\n"<< endl;
		}
#line 2202 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 688 "parser.y" /* yacc.c:1646  */
    {
				logFile << "Line " << lCount << " : expression : variable ASSIGNOP logic_expression\n"<< endl;
				(yyval.symVal)=(yyvsp[-2].symVal);
				(yyval.symVal)->code=(yyvsp[0].symVal)->code+(yyvsp[-2].symVal)->code;
				(yyval.symVal)->code+="\tmov ax, "+(yyvsp[0].symVal)->getName()+"\n";
				if((yyval.symVal)->getType()=="notarray"){ 
					(yyval.symVal)->code+= "\tmov "+(yyvsp[-2].symVal)->getName()+", ax\n";
				}
				
				else{
					(yyval.symVal)->code+= "\tmov  "+(yyvsp[-2].symVal)->getName()+"[bx], ax\n";
				}
				delete (yyvsp[0].symVal);
			}
#line 2221 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 704 "parser.y" /* yacc.c:1646  */
    {
					logFile << "Line " << lCount << " : logic_expression : rel_expression\n"<< endl;
					(yyval.symVal)= (yyvsp[0].symVal);		
				}
#line 2230 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 708 "parser.y" /* yacc.c:1646  */
    {
					logFile << "Line " << lCount << " : logic_expression : rel_expression LOGICOP rel_expression\n"<< endl;
					(yyval.symVal)=(yyvsp[-2].symVal);
					(yyval.symVal)->code+=(yyvsp[0].symVal)->code;
					char * label1 = newLabel();
					char * label2 = newLabel();
					char * temp = newPTemp();
					if((yyvsp[-1].symVal)->getName()=="&&"){
						/* 
						Check whether both operands value is 1. If both are one set value of a temporary variable to 1
						otherwise 0
						*/
						(yyval.symVal)->code += "\tmov ax , " + (yyvsp[-2].symVal)->getName() +"\n";
						(yyval.symVal)->code += "\tcmp ax , 0\n";
				 		(yyval.symVal)->code += "\tje " + string(label1) +"\n";
						(yyval.symVal)->code += "\tmov ax , " + (yyvsp[0].symVal)->getName() +"\n";
						(yyval.symVal)->code += "\tcmp ax , 0\n";
						(yyval.symVal)->code += "\tje " + string(label1) +"\n";
						(yyval.symVal)->code += "\tmov " + string(temp) + " , 1\n";
						(yyval.symVal)->code += "\tjmp " + string(label2) + "\n";
						(yyval.symVal)->code += string(label1) + ":\n" ;
						(yyval.symVal)->code += "\tmov " + string(temp) + ", 0\n";
						(yyval.symVal)->code += string(label2) + ":\n";
						(yyval.symVal)->setName(temp);
						
					}
					else if((yyvsp[-1].symVal)->getName()=="||"){
						(yyval.symVal)->code += "\tmov ax , " + (yyvsp[-2].symVal)->getName() +"\n";
						(yyval.symVal)->code += "\tcmp ax , 0\n";
				 		(yyval.symVal)->code += "\tjne " + string(label1) +"\n";
						(yyval.symVal)->code += "\tmov ax , " + (yyvsp[0].symVal)->getName() +"\n";
						(yyval.symVal)->code += "\tcmp ax , 0\n";
						(yyval.symVal)->code += "\tjne " + string(label1) +"\n";
						(yyval.symVal)->code += "\tmov " + string(temp) + " , 0\n";
						(yyval.symVal)->code += "\tjmp " + string(label2) + "\n";
						(yyval.symVal)->code += string(label1) + ":\n" ;
						(yyval.symVal)->code += "\tmov " + string(temp) + ", 1\n";
						(yyval.symVal)->code += string(label2) + ":\n";
						(yyval.symVal)->setName(temp);
						
					}
					delete (yyvsp[0].symVal);
				}
#line 2278 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 753 "parser.y" /* yacc.c:1646  */
    {
				logFile << "Line " << lCount << " : rel_expression : simple_expression\n"<< endl;
				(yyval.symVal)= (yyvsp[0].symVal);
			}
#line 2287 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 757 "parser.y" /* yacc.c:1646  */
    {
				logFile << "Line " << lCount << " : rel_expression : simple_expression RELOP simple_expression\n"<< endl;
				(yyval.symVal)=(yyvsp[-2].symVal);
				(yyval.symVal)->code+=(yyvsp[0].symVal)->code;
				(yyval.symVal)->code+="\tmov ax, " + (yyvsp[-2].symVal)->getName()+"\n";
				(yyval.symVal)->code+="\tcmp ax, " + (yyvsp[0].symVal)->getName()+"\n";
				char *temp=newPTemp();
				char *label1=newLabel();
				char *label2=newLabel();
				if((yyvsp[-1].symVal)->getName()=="<"){
					(yyval.symVal)->code+="\tjl " + string(label1)+"\n";
				}
				else if((yyvsp[-1].symVal)->getName()=="<="){
					(yyval.symVal)->code+="\tjle " + string(label1)+"\n";
				}
				else if((yyvsp[-1].symVal)->getName()==">"){
					(yyval.symVal)->code+="\tjg " + string(label1)+"\n";
				}
				else if((yyvsp[-1].symVal)->getName()==">="){
					(yyval.symVal)->code+="\tjge " + string(label1)+"\n";
				}
				else if((yyvsp[-1].symVal)->getName()=="=="){
					(yyval.symVal)->code+="\tje " + string(label1)+"\n";
				}
				else if((yyvsp[-1].symVal)->getName()=="!="){
					(yyval.symVal)->code+="\tjne " + string(label1)+"\n";
				}
				
				(yyval.symVal)->code+="\tmov "+string(temp) +", 0\n";
				(yyval.symVal)->code+="\tjmp "+string(label2) +"\n";
				(yyval.symVal)->code+=string(label1)+":\n";
				(yyval.symVal)->code+= "\tmov "+string(temp)+", 1\n";
				(yyval.symVal)->code+=string(label2)+":\n";
				(yyval.symVal)->setName(temp);
				delete (yyvsp[0].symVal);
			}
#line 2328 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 795 "parser.y" /* yacc.c:1646  */
    {
				logFile << "Line " << lCount << " : simple_expression : term\n"<< endl;
				(yyval.symVal)= (yyvsp[0].symVal);
			}
#line 2337 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 799 "parser.y" /* yacc.c:1646  */
    {
				logFile << "Line " << lCount << " : simple_expression : simple_expression ADDOP term\n"<< endl;
				(yyval.symVal)=(yyvsp[-2].symVal);
				(yyval.symVal)->code+=(yyvsp[0].symVal)->code;
				
				// move one of the operands to a register, perform addition or subtraction with the other operand and move the result in a temporary variable  
				
				if((yyvsp[-1].symVal)->getName()=="+"){
					char* temp = newTemp();
					(yyval.symVal)->code += "\tmov ax, " + (yyvsp[-2].symVal)->getName() + "\n";
					(yyval.symVal)->code += "\tadd ax, " + (yyvsp[0].symVal)->getName() + "\n";
					(yyval.symVal)->code += "\tmov " + string(temp) +" , ax\n";
					(yyval.symVal)->setName(string(temp));
				}
				else if((yyvsp[-1].symVal)->getName() == "-"){
					char* temp = newTemp();
					(yyval.symVal)->code += "\tmov ax, " + (yyvsp[-2].symVal)->getName() + "\n";
					(yyval.symVal)->code += "\tsub ax, " + (yyvsp[0].symVal)->getName() + "\n";
					(yyval.symVal)->code += "\tmov " + string(temp) +" , ax\n";
					(yyval.symVal)->setName(string(temp));
				}
				delete (yyvsp[0].symVal);
				cout << endl;
			}
#line 2366 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 826 "parser.y" /* yacc.c:1646  */
    {
			logFile << "Line " << lCount << " : term : unary_expression\n"<< endl;						
			(yyval.symVal)= (yyvsp[0].symVal);
		}
#line 2375 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 831 "parser.y" /* yacc.c:1646  */
    {
			logFile << "Line " << lCount << " : term : term MULOP unary_expression\n"<< endl;
			(yyval.symVal)=(yyvsp[-2].symVal);
			(yyval.symVal)->code += (yyvsp[0].symVal)->code;
			(yyval.symVal)->code += "\tmov ax, "+ (yyvsp[-2].symVal)->getName()+"\n";
			(yyval.symVal)->code += "\tmov bx, "+ (yyvsp[0].symVal)->getName() +"\n";
			char *temp=newTemp();
			if((yyvsp[-1].symVal)->getName()=="*"){
				(yyval.symVal)->code += "\tmul bx\n";
				(yyval.symVal)->code += "\tmov "+ string(temp) + ", ax\n";
			}
			else if((yyvsp[-1].symVal)->getName()=="/"){
				// clear dx, perform 'div bx' and mov ax to temp
				(yyval.symVal)->code += "\txor dx , dx\n";
				(yyval.symVal)->code += "\tdiv bx\n";
				(yyval.symVal)->code += "\tmov " + string(temp) + " , ax\n";
			}
			else{
			// clear dx, perform 'div bx' and mov dx to temp
				(yyval.symVal)->code += "\txor dx , dx\n";
				(yyval.symVal)->code += "\tdiv bx\n";
				(yyval.symVal)->code += "\tmov " + string(temp) + " , dx\n";
				
			}
			(yyval.symVal)->setName(temp);
			cout << endl << (yyval.symVal)->code << endl;
			delete (yyvsp[0].symVal);
		}
#line 2408 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 862 "parser.y" /* yacc.c:1646  */
    {
						logFile << "Line " << lCount << " : unary_expression : ADDOP unary_expression\n"<< endl;
						
						if((yyvsp[-1].symVal)->getName() == "+"){
							(yyval.symVal)=(yyvsp[0].symVal);
						}
						else if((yyvsp[-1].symVal)->getName() == "-")
						{
							(yyval.symVal) = (yyvsp[0].symVal);
							(yyval.symVal)->code += "\tmov ax, " + (yyvsp[0].symVal)->getName() + "\n";
							(yyval.symVal)->code += "\tneg ax\n";
							(yyval.symVal)->code += "\tmov " + (yyvsp[0].symVal)->getName() + " , ax\n";
						}
							// Perform NEG operation if the symbol of ADDOP is '-'
					}
#line 2428 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 878 "parser.y" /* yacc.c:1646  */
    {
						logFile << "Line " << lCount << " : unary_expression : NOT unary_expression\n"<< endl;
						(yyval.symVal)=(yyvsp[0].symVal);
						char *temp=newTemp();
						(yyval.symVal)->code="\tmov ax, " + (yyvsp[0].symVal)->getName() + "\n";
						(yyval.symVal)->code+="\tnot ax\n";
						(yyval.symVal)->code+="\tmov "+string(temp)+", ax";
					}
#line 2441 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 887 "parser.y" /* yacc.c:1646  */
    {
						logFile << "Line " << lCount << " : unary_expression : factor\n"<< endl;
						(yyval.symVal)=(yyvsp[0].symVal);
					}
#line 2450 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 893 "parser.y" /* yacc.c:1646  */
    {
			//SymbolInfo * newVar = new SymbolInfo(*$1);
			
			logFile << "Line " << lCount << " : factor : variable\n"<< endl;
			if((yyval.symVal)->getType()=="notarray"){
				
			}
			
			else{
				char *temp= newTemp();
				(yyval.symVal)->code+="\tmov ax, " + (yyvsp[0].symVal)->getName() + "[bx]\n";
				(yyval.symVal)->code+= "\tmov " + string(temp) + ", ax\n";
				(yyval.symVal)->setName(temp);
			}
			}
#line 2470 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 909 "parser.y" /* yacc.c:1646  */
    {
		logFile << "Line " << lCount << " : factor : ID LPAREN argument_list RPAREN\n" ;
		logFile << (yyvsp[-3].symVal)->getName() << endl << endl;
		SymbolInfo *temp=new SymbolInfo();
			temp = table.lookUp((yyvsp[-3].symVal)->getName(), "FUNC");
			if(temp == NULL){
				errorFile << "Error at line " << lCount <<" : Function " <<(yyvsp[-3].symVal)->getName() <<" doesn't exist"<<endl << endl;
			}
	}
#line 2484 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 919 "parser.y" /* yacc.c:1646  */
    {
		logFile << "Line " << lCount << " : factor : LPAREN expression RPAREN\n"<< endl;
		(yyval.symVal)= (yyvsp[-1].symVal);
	}
#line 2493 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 924 "parser.y" /* yacc.c:1646  */
    {
		logFile << "Line " << lCount << " : factor : CONST_INT\n" ;
		logFile << (yyvsp[0].symVal)->getName() << endl << endl;
		(yyval.symVal)= (yyvsp[0].symVal);
	}
#line 2503 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 930 "parser.y" /* yacc.c:1646  */
    {
		logFile << "Line " << lCount << " : factor : CONST_FLOAT\n" ;
		logFile << (yyvsp[0].symVal)->getName() << endl << endl;
		(yyval.symVal)= (yyvsp[0].symVal);
	}
#line 2513 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 936 "parser.y" /* yacc.c:1646  */
    {
		logFile << "Line " << lCount << " : factor : variable INCOP\n"<< endl;
		(yyval.symVal)=(yyvsp[-1].symVal);
		(yyval.symVal)->code += "\tmov ax , " + (yyval.symVal)->getName()+ "\n";
		(yyval.symVal)->code += "\tadd ax , 1\n";
		(yyval.symVal)->code += "\tmov " + (yyval.symVal)->getName() + " , ax\n";
		// perform incop depending on whether the varaible is an array or not
		
	}
#line 2527 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 946 "parser.y" /* yacc.c:1646  */
    {
		logFile << "Line " << lCount << " : factor : variable DECOP\n"<< endl;
		(yyval.symVal) = (yyvsp[-1].symVal);
		
		(yyval.symVal)->code += "\tmov ax , " + (yyval.symVal)->getName()+ "\n";
		(yyval.symVal)->code += "\tsub ax , 1\n";
		(yyval.symVal)->code += "\tmov " + (yyval.symVal)->getName() + " , ax\n";
	}
#line 2540 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 957 "parser.y" /* yacc.c:1646  */
    {
					logFile << "Line " << lCount << " : argument_list : arguments\n"<< endl;
				}
#line 2548 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 960 "parser.y" /* yacc.c:1646  */
    {}
#line 2554 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 964 "parser.y" /* yacc.c:1646  */
    {
				logFile << "Line " << lCount << " : arguments : arguments COMMA logic_expression\n"<< endl;
			}
#line 2562 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 968 "parser.y" /* yacc.c:1646  */
    {
				logFile << "Line " << lCount << " : arguments : logic_expression\n"<< endl;
			}
#line 2570 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2574 "y.tab.c" /* yacc.c:1646  */
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

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

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
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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
                  yystos[*yyssp], yyvsp);
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
#line 973 "parser.y" /* yacc.c:1906  */



void yyerror(const char *s){
	cout << "Error at line no " << lCount << " : " << s << endl;
}

int main(int argc, char * argv[]){
	if(argc!=2){
		printf("Please provide input file name and try again\n");
		return 0;
	}
	
	FILE *fin=fopen(argv[1],"r");
	if(fin==NULL){
		printf("Cannot open specified file\n");
		return 0;
	}
	
	logFile.open("1405045_log.txt");
	errorFile.open("1405045_errors.txt");

	yyin= fin;
	yyparse();
	
	printf("\nTotal Lines: %d\n",--lCount);
	printf("\nTotal Errors: %d\n",errCount);

	logFile.close();
	errorFile.close();
	
	printf("\n");
	return 0;
}
