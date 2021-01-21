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
#line 1 "71parser.y" /* yacc.c:339  */

#include<bits/stdc++.h>
#include "SymTable.h"

//#define YYSTYPE SymbolInfo*

using namespace std;

string variable_type;
int yyparse(void);
int yylex(void);
extern FILE *yyin;
int IDargs = 0;

SymbolTable *table=new SymbolTable(13);

bool funcDef = false;
extern int lCount;
int semErrors;
vector<SymbolInfo*> params; 
vector<string> args; 

ofstream logFile, errorFile;

void yyerror(const char *s)
{
	//write your code
}



#line 98 "y.tab.c" /* yacc.c:339  */

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
    second_precedence = 297
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
#define second_precedence 297

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 32 "71parser.y" /* yacc.c:355  */

SymbolInfo* symVal;

#line 226 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 243 "y.tab.c" /* yacc.c:358  */

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
#define YYLAST   131

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  43
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  72
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  124

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
       0,    54,    54,    61,    65,    70,    73,    76,    81,   100,
     108,   169,   186,   191,   206,   212,   216,   220,   220,   215,
     224,   227,   228,   235,   242,   249,   259,   285,   327,   350,
     378,   379,   382,   383,   384,   385,   387,   389,   391,   392,
     393,   398,   399,   407,   408,   409,   417,   432,   471,   479,
     543,   551,   628,   636,   736,   744,   981,   989,  1344,  1357,
    1377,  1387,  1391,  1413,  1418,  1427,  1436,  1442,  1463,  1486,
    1490,  1493,  1497
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
  "CONST_CHAR", "ADDOP", "MULOP", "LOGICOP", "RELOP", "second_precedence",
  "$accept", "start", "program", "unit", "func_declaration",
  "func_definition", "parameter_list", "compound_statement", "$@1", "$@2",
  "$@3", "var_declaration", "type_specifier", "declaration_list",
  "statements", "statement", "expression_statement", "variable",
  "expression", "logic_expression", "rel_expression", "simple_expression",
  "term", "unary_expression", "factor", "argument_list", "arguments", YY_NULLPTR
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

#define YYPACT_NINF -66

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-66)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      11,   -66,   -66,   -66,    25,    11,   -66,   -66,   -66,   -66,
     -24,   -66,   -66,     1,     2,    11,    17,   -66,   -66,    20,
     -16,    24,    31,    33,    10,    11,   -66,   -66,    26,   -66,
      37,   -66,   -66,    38,    43,   -66,    58,   -66,   -66,    52,
      53,    55,    85,    85,   -66,    85,    56,     7,   -66,   -66,
     -66,    85,   -66,   -66,    46,    58,   -66,   -66,    29,     4,
     -66,    42,   -23,    47,   -66,   -66,    85,    78,    85,    18,
      61,    36,   -66,    54,    85,    85,   -66,    70,    72,   -66,
     -66,   -66,    85,   -66,   -66,    85,    85,    85,    85,    76,
      78,    79,   -66,   -66,   -66,    80,   -66,    81,    88,    74,
     -66,   -66,   -66,    47,    68,   -66,    58,    85,    58,    19,
     -66,    85,   -66,   -66,   106,   100,   -66,   -66,   -66,   -66,
      58,    58,   -66,   -66
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    23,    24,    25,     0,     2,     4,     6,     7,     5,
       0,     1,     3,    28,     0,    15,     0,    22,    21,     0,
       0,    14,     0,    26,     0,     0,    13,    29,     0,     9,
      16,     8,    10,    12,     0,    20,     0,    11,    27,     0,
       0,     0,     0,     0,    43,     0,     0,    46,    64,    65,
      66,     0,    34,    32,     0,    17,    30,    33,    61,     0,
      48,    50,    52,    54,    56,    60,     0,     0,     0,     0,
       0,    61,    59,     0,    70,     0,    58,    28,     0,    31,
      67,    68,     0,    45,    44,     0,     0,     0,     0,     0,
       0,     0,    42,    41,    63,     0,    72,     0,    69,     0,
      18,    49,    51,    55,    53,    57,     0,     0,     0,     0,
      62,     0,    47,    19,    36,     0,    38,    40,    39,    71,
       0,     0,    37,    35
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -66,   -66,   -66,   120,   -66,   -66,   -66,   102,   -66,   -66,
     -66,    16,    84,   -66,   -66,   -53,   -63,   -45,   -30,   -65,
      44,    40,    45,   -44,   -66,   -66,   -66
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     4,     5,     6,     7,     8,    20,    52,    36,    78,
     113,    53,    54,    14,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    97,    98
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      71,    72,    79,    17,    90,    83,    71,    76,    24,    96,
      13,    29,    69,    70,    25,    86,     9,   101,    87,    92,
     117,     9,     1,     2,    15,    11,     3,   107,    16,    71,
      74,    18,    19,    84,    75,    30,    89,    71,    91,    31,
      71,    71,    71,    71,   105,    99,   119,    93,   118,    80,
      81,    82,    22,   114,    23,   116,    80,    81,    26,    27,
      28,    34,    39,    35,    40,    41,    71,   122,   123,     1,
       2,    38,    37,     3,    42,    66,    67,   115,    68,    73,
      77,    43,    85,    30,    10,    94,    88,    44,    95,    10,
      45,    46,    47,    48,    49,    50,    51,    16,   100,    21,
     106,    43,   112,   108,   109,   110,    86,    44,    43,    33,
      45,   120,    47,    48,    49,    50,    51,    45,   111,    47,
      48,    49,    50,    51,   121,    12,    32,   104,     0,   102,
       0,   103
};

static const yytype_int8 yycheck[] =
{
      45,    45,    55,     1,    67,     1,    51,    51,    24,    74,
      34,     1,    42,    43,    30,    38,     0,    82,    41,     1,
       1,     5,    11,    12,    23,     0,    15,    90,    27,    74,
      23,    29,    30,    29,    27,    25,    66,    82,    68,    29,
      85,    86,    87,    88,    88,    75,   111,    29,    29,    20,
      21,    22,    35,   106,    34,   108,    20,    21,    34,    28,
      27,    35,     4,    26,     6,     7,   111,   120,   121,    11,
      12,    28,    34,    15,    16,    23,    23,   107,    23,    23,
      34,    23,    40,    25,     0,    24,    39,    29,    34,     5,
      32,    33,    34,    35,    36,    37,    38,    27,    26,    15,
      24,    23,    28,    24,    24,    24,    38,    29,    23,    25,
      32,     5,    34,    35,    36,    37,    38,    32,    30,    34,
      35,    36,    37,    38,    24,     5,    24,    87,    -1,    85,
      -1,    86
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    11,    12,    15,    44,    45,    46,    47,    48,    54,
      55,     0,    46,    34,    56,    23,    27,     1,    29,    30,
      49,    55,    35,    34,    24,    30,    34,    28,    27,     1,
      25,    29,    50,    55,    35,    26,    51,    34,    28,     4,
       6,     7,    16,    23,    29,    32,    33,    34,    35,    36,
      37,    38,    50,    54,    55,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    23,    23,    23,    61,
      61,    60,    66,    23,    23,    27,    66,    34,    52,    58,
      20,    21,    22,     1,    29,    40,    38,    41,    39,    61,
      59,    61,     1,    29,    24,    34,    62,    68,    69,    61,
      26,    62,    63,    65,    64,    66,    24,    59,    24,    24,
      24,    30,    28,    53,    58,    61,    58,     1,    29,    62,
       5,    24,    58,    58
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    43,    44,    45,    45,    46,    46,    46,    47,    47,
      48,    49,    49,    49,    49,    49,    51,    52,    53,    50,
      50,    54,    54,    55,    55,    55,    56,    56,    56,    56,
      57,    57,    58,    58,    58,    58,    58,    58,    58,    58,
      58,    58,    58,    59,    59,    59,    60,    60,    61,    61,
      62,    62,    63,    63,    64,    64,    65,    65,    66,    66,
      66,    67,    67,    67,    67,    67,    67,    67,    67,    68,
      68,    69,    69
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     6,     6,
       6,     4,     3,     2,     1,     0,     0,     0,     0,     6,
       2,     3,     3,     1,     1,     1,     3,     6,     1,     4,
       1,     2,     1,     1,     1,     7,     5,     7,     5,     5,
       5,     3,     3,     1,     2,     2,     1,     4,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     3,     2,     2,
       1,     1,     4,     3,     1,     1,     1,     2,     2,     1,
       0,     3,     1
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
#line 54 "71parser.y" /* yacc.c:1646  */
    {
		//write your code in this block in all the similar blocks below
		    
			logFile << "Line " << lCount << " : start : program\n"<< endl;
		}
#line 1417 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 61 "71parser.y" /* yacc.c:1646  */
    {
			logFile << "Line " << lCount << " : program : program unit\n"<< endl;
		}
#line 1425 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 65 "71parser.y" /* yacc.c:1646  */
    {	
			logFile << "Line " << lCount << " : program : unit\n"<< endl;
		}
#line 1433 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 70 "71parser.y" /* yacc.c:1646  */
    {
			logFile << "Line " << lCount << " : unit : var_declaration\n"<< endl;
		}
#line 1441 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 73 "71parser.y" /* yacc.c:1646  */
    {
			logFile << "Line " << lCount << " : unit : func_declaration\n"<< endl;
     	}
#line 1449 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 76 "71parser.y" /* yacc.c:1646  */
    {
			logFile << "Line " << lCount << " : unit : func_definition\n"<< endl;
     	}
#line 1457 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 82 "71parser.y" /* yacc.c:1646  */
    {
						logFile << "Line " << lCount << " : func_declaration : 	type_specifier ID LPAREN parameter_list RPAREN SEMICOLON\n"; 
						logFile << (yyvsp[-4].symVal)->getName() << endl << endl;
						SymbolInfo *temp = table->lookUp((yyvsp[-4].symVal)->getName(), "FUNC");
						if(temp != NULL){
							errorFile << "Error at line " << lCount << " Function "<< (yyvsp[-4].symVal)->getName() <<" already declared" << endl << endl;
							semErrors++;
						}else {
							SymbolInfo* temp2 = table->InsertandGet((yyvsp[-4].symVal)->getName(), "ID");
							temp2->setIDType("FUNC");
							temp2->setFuncRet((yyvsp[-5].symVal)->getVarType());
							for(int i = 0; i<args.size(); i++){
								temp2->ParamList.push_back(args[i]);					
							}
							args.clear();
						}
						//funcParam.exitScope();
					}
#line 1480 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 101 "71parser.y" /* yacc.c:1646  */
    {
						errorFile << "Error at line " << lCount << "; missing" << endl << endl;
						semErrors++;
					}
#line 1489 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 109 "71parser.y" /* yacc.c:1646  */
    {
				logFile << "Line " << lCount << " : func_definition : type_specifier ID LPAREN parameter_list RPAREN compound_statement\n";
				logFile << (yyvsp[-4].symVal)->getName() << endl << endl;
				SymbolInfo *temp = table->lookUp((yyvsp[-4].symVal)->getName(), "FUNC");
				if(args.size() != IDargs){
					errorFile << "Error at line " << lCount << " Parameter mismatch for Function "<< (yyvsp[-4].symVal)->getName() << endl << endl;
					args.clear(); IDargs = 0;
					semErrors++;
				}												
				if(temp != NULL){
					//logFile << "Function " << $2->getName() <<" already declared" << endl;
					if(temp->isFuncDefined()== true){
						errorFile << "Error at line " << lCount << "Function "<< (yyvsp[-4].symVal)->getName() <<" already defined" << endl << endl;
						semErrors++;
						args.clear();
						IDargs = 0;
					}
					else if(temp->getFuncRet() != (yyvsp[-5].symVal)->getVarType()){
						errorFile << "Error at line " << lCount << "Function "<< (yyvsp[-4].symVal)->getName() <<" :return type doesn't match declaration" << endl << endl;
						semErrors++;
						args.clear();IDargs = 0; 
					} 
					else if(temp->ParamList.size() != args.size()){
						errorFile << "Error at line " << lCount << "Function "<< (yyvsp[-4].symVal)->getName() <<" :Parameter list doesn not match declaration" << endl << endl;
						args.clear();IDargs = 0;
						semErrors++;					
					}
					else{
						for(int i = 0; i<temp->ParamList.size(); i++){
							if(temp->ParamList[i] != args[i]){
								errorFile << "Error at line " << lCount << "Function "<< (yyvsp[-4].symVal)->getName()<< " :argument mismatch" << endl << endl;
								args.clear();IDargs = 0;
								semErrors++;	
							}
						}				
					}
				}
				else{
					SymbolInfo* temp = new SymbolInfo();
					temp = table->InsertandGet((yyvsp[-4].symVal)->getName(), "ID");
					//logFile << $2->getName() << " Function inserted" << endl;
					temp->setIDType("FUNC");
					temp->setFuncRet((yyvsp[-5].symVal)->getVarType());
					//
					for(int i = 0; i<args.size(); i++){
						temp->ParamList.push_back(args[i]);					
					}
					temp->setFuncDefined();
				}
				args.clear();
				IDargs = 0;
				
	
				//funcParam.exitScope();
				}
#line 1549 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 170 "71parser.y" /* yacc.c:1646  */
    {
					logFile << "Line " << lCount << " : parameter_list  : parameter_list COMMA type_specifier ID\n";
					logFile << (yyvsp[0].symVal)->getName() << endl << endl;
					args.push_back(variable_type);//changed from $3->getVarType()
					IDargs++;
					//SymbolInfo* temp = funcParam.InsertandGet($4->getName(), $4->getType());					
					//temp->setIDType("VAR");
					//temp->setVarType($3->getVarType());
					(yyvsp[0].symVal)->setIDType("VAR");
					(yyvsp[0].symVal)->setVarType(variable_type);//changed from $3->getVarType()
					SymbolInfo* temp = new SymbolInfo((yyvsp[0].symVal)->getName(), (yyvsp[0].symVal)->getType());
					temp->setIDType("VAR");
					
					params.push_back(temp);
				
				}
#line 1570 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 187 "71parser.y" /* yacc.c:1646  */
    {					
					logFile << "Line " << lCount << " : parameter_list  : parameter_list COMMA type_specifier\n"<< endl;
					args.push_back((yyvsp[0].symVal)->getVarType());
				}
#line 1579 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 192 "71parser.y" /* yacc.c:1646  */
    {
					logFile << "Line " << lCount << " : parameter_list  : type_specifier ID\n";
					logFile << (yyvsp[0].symVal)->getName() << endl << endl;
					//args.clear();
					args.push_back(variable_type);//$1->getVarType()
					IDargs++;
					//SymbolInfo* temp = funcParam.InsertandGet($2->getName(), $2->getType());
					//temp->setIDType("VAR");
					//temp->setVarType($1->getVarType());
					(yyvsp[0].symVal)->setIDType("VAR");
					(yyvsp[0].symVal)->setVarType(variable_type);//$1->getVarType()
					params.push_back((yyvsp[0].symVal));
				
				}
#line 1598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 207 "71parser.y" /* yacc.c:1646  */
    {
					logFile << "Line " << lCount << " : parameter_list  : type_specifier\n"<< endl;
					//args.clear();
					args.push_back(variable_type);
				}
#line 1608 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 212 "71parser.y" /* yacc.c:1646  */
    {//logFile << "Empty parameter " << lCount << endl;
				}
#line 1615 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 216 "71parser.y" /* yacc.c:1646  */
    {
							table->enterScope(); 
							for(int i = 0; i<params.size(); i++) table->Insert(params[i]);
							params.clear();
						}
#line 1625 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 220 "71parser.y" /* yacc.c:1646  */
    {table->printAll(logFile);}
#line 1631 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 220 "71parser.y" /* yacc.c:1646  */
    {table->exitScope();}
#line 1637 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 221 "71parser.y" /* yacc.c:1646  */
    {
							logFile << "Line " << lCount << " : compound_statement : LCURL statements RCURL\n"<< endl;
						}
#line 1645 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 224 "71parser.y" /* yacc.c:1646  */
    {logFile << "Line " << lCount << " : compound_statement : LCURL RCURL\n"<< endl;}
#line 1651 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 227 "71parser.y" /* yacc.c:1646  */
    {logFile << "Line " << lCount << " : var_declaration : type_specifier declaration_list SEMICOLON\n"<< endl;}
#line 1657 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 229 "71parser.y" /* yacc.c:1646  */
    {
						errorFile << "Error at line " << lCount << "; missing" << endl << endl;
						semErrors++;
				}
#line 1666 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 236 "71parser.y" /* yacc.c:1646  */
    {
					logFile << "Line " << lCount << " : type_specifier	: INT\n"<< endl; 
					SymbolInfo* s= new SymbolInfo("INT");
					variable_type = "INT";
					(yyval.symVal) = s;
				}
#line 1677 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 243 "71parser.y" /* yacc.c:1646  */
    {	
					logFile << "Line " << lCount << " : type_specifier	: FLOAT\n"<< endl;
					SymbolInfo* s= new SymbolInfo("FLOAT");
					variable_type = "FLOAT";
					(yyval.symVal) = s;
				}
#line 1688 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 250 "71parser.y" /* yacc.c:1646  */
    {
					logFile << "Line " << lCount << " : type_specifier	: VOID\n"<< endl;
					SymbolInfo* s= new SymbolInfo("VOID");
					variable_type = "VOID";
					(yyval.symVal) = s;
				}
#line 1699 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 260 "71parser.y" /* yacc.c:1646  */
    {
						logFile << "Line " << lCount << " : declaration_list : 	declaration_list COMMA ID\n";
						logFile << (yyvsp[0].symVal)->getName() << endl << endl;
						if(variable_type == "VOID"){
							errorFile << "Error at line " << lCount << " :variable type can't be void" << endl << endl;
							semErrors++;
						}
						else{
							SymbolInfo* temp = table->lookUp((yyvsp[0].symVal)->getName(), "VAR");
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
								table->Insert(temp2);
								//table.printAll(logFile);
							}
						}
					}
#line 1729 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 286 "71parser.y" /* yacc.c:1646  */
    {
						logFile << "Line " << lCount << " : declaration_list : 	declaration_list COMMA ID LTHIRD CONST_INT RTHIRD\n";
						logFile << (yyvsp[-3].symVal)->getName() << endl;
						logFile << (yyvsp[-1].symVal)->getName() << endl << endl;
						if(variable_type == "VOID"){
							errorFile << "Error at line " << lCount << " : array type can't be void" << endl << endl;
							semErrors++;
						}
						else{
							SymbolInfo* temp = table->lookUp((yyvsp[-3].symVal)->getName(), "ARA");
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
								table->Insert(temp2);						
								//table.printAll(logFile);
							}
						}

					}
#line 1775 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 328 "71parser.y" /* yacc.c:1646  */
    {
						logFile << "Line " << lCount << " : declaration_list :	ID\n";
						logFile << (yyvsp[0].symVal)->getName() << endl << endl;
						if(variable_type == "VOID"){
							errorFile << "Error at line " << lCount << " :variable type can't be void" << endl << endl;
							semErrors++;
						}
						else{
							SymbolInfo* temp = table->lookUp((yyvsp[0].symVal)->getName(), "ARA");
							if(temp!= NULL){
							errorFile << "Error at line " << lCount << ": Variable "<< (yyvsp[0].symVal)->getName() <<" already declared" << endl << endl;	
								semErrors++;		
							}
							else{
								SymbolInfo* temp2 = new SymbolInfo((yyvsp[0].symVal)->getName(), (yyvsp[0].symVal)->getType());
								temp2->setVarType(variable_type);
								temp2->setIDType("VAR");
								table->Insert(temp2);
								//table.printAll(logFile);		
							}
						}
					}
#line 1802 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 351 "71parser.y" /* yacc.c:1646  */
    {
						logFile << "Line " << lCount << " : declaration_list :	ID LTHIRD CONST_INT RTHIRD\n";
						logFile << (yyvsp[-3].symVal)->getName() << endl;
						logFile << (yyvsp[-1].symVal)->getName() << endl << endl;
						if(variable_type == "VOID"){
							errorFile << "Error at line " << lCount << " :array type can't be void" << endl << endl;
							semErrors++;
						}
						else{
							SymbolInfo* temp = table->lookUp((yyvsp[-3].symVal)->getName(), "ARA");
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
								table->Insert(temp2);
								//table.printAll(logFile);			
							}
						}
					}
#line 1832 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 378 "71parser.y" /* yacc.c:1646  */
    {logFile << "Line " << lCount << " : statements : statement\n"<< endl;}
#line 1838 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 379 "71parser.y" /* yacc.c:1646  */
    {logFile << "Line " << lCount << " : statements : statements statement\n"<< endl;}
#line 1844 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 382 "71parser.y" /* yacc.c:1646  */
    {logFile << "Line " << lCount << " : statement : var_declaration\n"<< endl;}
#line 1850 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 383 "71parser.y" /* yacc.c:1646  */
    {logFile << "Line " << lCount << " : statement : expression_statement\n"<< endl;}
#line 1856 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 384 "71parser.y" /* yacc.c:1646  */
    {logFile << "Line " << lCount << " : statement : compound_statement\n"<< endl;}
#line 1862 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 386 "71parser.y" /* yacc.c:1646  */
    {logFile << "Line " << lCount << " : statement : FOR LPAREN expression_statement expression_statement expression RPAREN statement\n"<< endl;}
#line 1868 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 388 "71parser.y" /* yacc.c:1646  */
    {logFile << "Line " << lCount << " : statement : IF LPAREN expression RPAREN statement\n"<< endl;}
#line 1874 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 390 "71parser.y" /* yacc.c:1646  */
    {logFile << "Line " << lCount << " : statement : IF LPAREN expression RPAREN statement ELSE statement\n"<< endl;}
#line 1880 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 391 "71parser.y" /* yacc.c:1646  */
    {logFile << "Line " << lCount << " : statement : WHILE LPAREN expression RPAREN statement\n"<< endl;}
#line 1886 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 392 "71parser.y" /* yacc.c:1646  */
    {logFile << "Line " << lCount << " : statement : PRINTLN LPAREN ID RPAREN SEMICOLON\n"<< endl;}
#line 1892 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 394 "71parser.y" /* yacc.c:1646  */
    {
		errorFile << "Error at line " << lCount << "; missing" << endl << endl;
		semErrors++;
	}
#line 1901 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 398 "71parser.y" /* yacc.c:1646  */
    {logFile << "Line " << lCount << " : statement : RETURN expression SEMICOLON\n"<< endl;}
#line 1907 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 400 "71parser.y" /* yacc.c:1646  */
    {
			errorFile << "Error at line " << lCount << "; missing" << endl << endl;
			semErrors++;
		}
#line 1916 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 407 "71parser.y" /* yacc.c:1646  */
    {logFile << "Line " << lCount << " : expression_statement : SEMICOLON\n"<< endl;}
#line 1922 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 408 "71parser.y" /* yacc.c:1646  */
    {logFile << "Line " << lCount << " : expression_statement : expression SEMICOLON\n"<< endl;}
#line 1928 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 410 "71parser.y" /* yacc.c:1646  */
    {
							errorFile << "Error at line " << lCount << "; missing" << endl << endl;
							semErrors++;
						}
#line 1937 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 418 "71parser.y" /* yacc.c:1646  */
    {
				logFile << "Line " << lCount << " : variable : ID\n";
				logFile << (yyvsp[0].symVal)->getName() << endl << endl;
				SymbolInfo* temp = table->lookUp((yyvsp[0].symVal)->getName(),"VAR");
				if(temp == NULL){
					//logFile << "Variable " << $1->getName() << " doesn't exist" << endl;
					errorFile << "Error at line " << lCount << " : " << (yyvsp[0].symVal)->getName() << " doesn't exist" <<  endl << endl;					
					semErrors++;
				}
				else{
					(yyval.symVal) = temp;
					//variable_type = temp->getVarType();
				}			
			}
#line 1956 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 433 "71parser.y" /* yacc.c:1646  */
    {
				logFile << "Line " << lCount << " : variable : ID LTHIRD expression RTHIRD\n";
				logFile << (yyvsp[-3].symVal)->getName() << endl << endl;
				SymbolInfo* temp = table->lookUp((yyvsp[-3].symVal)->getName(),"ARA");
				if(temp == NULL){
				errorFile << "Error at line " << lCount << " : " <<(yyvsp[-3].symVal)->getName() << " doesn't exist" <<  endl << endl;					
					semErrors++;				
				}
				else{
					//$$ = temp;
					if((yyvsp[-1].symVal)->ints[0] >= temp->getAraSize()){
				errorFile << "Error at line " << lCount << " : " <<(yyvsp[-3].symVal)->getName() << " array index out of bounds" <<  endl << endl;				
						semErrors++;
						//temp->setAraIndex(0);
					} 
					else temp->setAraIndex((yyvsp[-1].symVal)->ints[0]);
					if(temp->getVarType() == "INT"){
						while(temp->ints.size() <= temp->getAraIndex()){
							temp->ints.push_back(0);
						}
					}
					else if(temp->getVarType() == "FLOAT"){
						while(temp->floats.size() <= temp->getAraIndex()){
							temp->floats.push_back(0);
						}
					}
					else if(temp->getVarType() == "CHAR"){
						while(temp->chars.size() <= temp->getAraIndex()){
							temp->chars.push_back('\0');
						}
					}
					(yyval.symVal) = temp;
					//variable_type = temp->getVarType();
				}			
			}
#line 1996 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 472 "71parser.y" /* yacc.c:1646  */
    {
				logFile << "Line " << lCount << " : expression : logic_expression\n"<< endl;
				(yyval.symVal) = (yyvsp[0].symVal);
				(yyval.symVal)->ints.push_back(0);
				(yyval.symVal)->floats.push_back(0);
				//logFile << "At Logic, value " << $$->ints[0] << " Type = " << $$->getVarType()<< endl;
			}
#line 2008 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 480 "71parser.y" /* yacc.c:1646  */
    {
				logFile << "Line " << lCount << " : expression : variable ASSIGNOP logic_expression\n"<< endl;
				string vType = (yyvsp[-2].symVal)->getVarType();
				if(vType == "INT"){
					if((yyvsp[-2].symVal)->getIDType() == "VAR"){
						(yyvsp[-2].symVal)->ints.push_back(0);
						if((yyvsp[0].symVal)->getVarType() == "INT"){
							if((yyvsp[0].symVal)->getIDType() == "VAR")(yyvsp[-2].symVal)->ints[0] = (yyvsp[0].symVal)->ints[0];
							else (yyvsp[-2].symVal)->ints[0] = (yyvsp[0].symVal)->ints[(yyvsp[0].symVal)->getAraIndex()];
						}
						else{
							errorFile << "Warning at line " << lCount <<" : Assigning float value to integer"<<endl << endl;
							if((yyvsp[0].symVal)->getIDType() == "VAR")(yyvsp[-2].symVal)->ints[0] = (int)(yyvsp[0].symVal)->floats[0];
							else (yyvsp[-2].symVal)->ints[0] = (int)(yyvsp[0].symVal)->floats[(yyvsp[0].symVal)->getAraIndex()];
						}
					}
					else if((yyvsp[-2].symVal)->getIDType() == "ARA"){
						(yyvsp[-2].symVal)->ints.push_back(0);
						if((yyvsp[0].symVal)->getVarType() == "INT"){
							if((yyvsp[0].symVal)->getIDType() == "VAR")(yyvsp[-2].symVal)->ints[(yyvsp[-2].symVal)->getAraIndex()] = (yyvsp[0].symVal)->ints[0];
							else (yyvsp[-2].symVal)->ints[(yyvsp[-2].symVal)->getAraIndex()] = (yyvsp[0].symVal)->ints[(yyvsp[0].symVal)->getAraIndex()];
						}
						else{
							errorFile << "Warning at line " << lCount <<" : Assigning float value to integer"<<endl << endl;
							if((yyvsp[0].symVal)->getIDType() == "VAR")(yyvsp[-2].symVal)->ints[(yyvsp[-2].symVal)->getAraIndex()] = (int)(yyvsp[0].symVal)->floats[0];
							else (yyvsp[-2].symVal)->ints[(yyvsp[-2].symVal)->getAraIndex()] = (int)(yyvsp[0].symVal)->floats[(yyvsp[0].symVal)->getAraIndex()];
						}
					}
				}
				else if(vType == "FLOAT"){
					if((yyvsp[-2].symVal)->getIDType() == "VAR"){
						(yyvsp[-2].symVal)->floats.push_back(0);
						if((yyvsp[0].symVal)->getVarType() == "INT"){
							if((yyvsp[0].symVal)->getIDType() == "VAR")(yyvsp[-2].symVal)->floats[0] = (float)(yyvsp[0].symVal)->ints[0];
							else (yyvsp[-2].symVal)->floats[0] = (float)(yyvsp[0].symVal)->ints[(yyvsp[0].symVal)->getAraIndex()];
						}
						else{
							if((yyvsp[0].symVal)->getIDType() == "VAR")(yyvsp[-2].symVal)->floats[0] = (yyvsp[0].symVal)->floats[0];
							else (yyvsp[-2].symVal)->floats[0] = (yyvsp[0].symVal)->floats[(yyvsp[0].symVal)->getAraIndex()];
						}
					}
					else if((yyvsp[-2].symVal)->getIDType() == "ARA"){
						(yyvsp[-2].symVal)->floats.push_back(0);
						if((yyvsp[0].symVal)->getVarType() == "INT"){
							if((yyvsp[0].symVal)->getIDType() == "VAR")(yyvsp[-2].symVal)->floats[(yyvsp[-2].symVal)->getAraIndex()] = (float)(yyvsp[0].symVal)->ints[0];
							else (yyvsp[-2].symVal)->floats[(yyvsp[-2].symVal)->getAraIndex()] = (float)(yyvsp[0].symVal)->ints[(yyvsp[0].symVal)->getAraIndex()];
						}
						else{
							errorFile << "Warning at line " << lCount <<" : Assigning float value to integer"<<endl << endl;
							if((yyvsp[0].symVal)->getIDType() == "VAR")(yyvsp[-2].symVal)->floats[(yyvsp[-2].symVal)->getAraIndex()] = (yyvsp[0].symVal)->floats[0];
							else (yyvsp[-2].symVal)->floats[(yyvsp[-2].symVal)->getAraIndex()] = (yyvsp[0].symVal)->floats[(yyvsp[0].symVal)->getAraIndex()];
						}
					}
				}
				(yyval.symVal) = (yyvsp[-2].symVal);
				//$$->ints[0] = 0;
				//$$->floats[0] = 0 ;
				//logFile << $$->getName()<< " = " << $$->ints[0] << endl;
				//logFile << $$->getName()<< " = " << $$->floats[0] << endl;
				table->printAll(logFile);				
			}
#line 2074 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 544 "71parser.y" /* yacc.c:1646  */
    {
						logFile << "Line " << lCount << " : logic_expression : rel_expression\n"<< endl;
						(yyval.symVal) = (yyvsp[0].symVal); 
						(yyval.symVal)->ints.push_back(0);
						(yyval.symVal)->floats.push_back(0);
						//logFile << "At Rel, value " << $$->floats[0]<< " Type = " << $$->getVarType() << endl;
					}
#line 2086 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 552 "71parser.y" /* yacc.c:1646  */
    {
						logFile << "Line " << lCount << " : logic_expression : rel_expression LOGICOP rel_expression\n"<< endl;
						SymbolInfo* temp = new SymbolInfo("INT");
						if((yyvsp[-2].symVal)->getVarType() == "CHAR" || (yyvsp[0].symVal)->getVarType() == "CHAR"){
							//logFile << "Logical operation not allowed for char datatype" << endl;
							temp->ints.push_back(0);
						}
						string logicop = (yyvsp[-1].symVal)->getName();
						if(logicop == "&&"){
							if((yyvsp[-2].symVal)->getVarType() == "FLOAT"){
								(yyvsp[-2].symVal)->floats.push_back(0);
								if((yyvsp[-2].symVal)->floats[0] == 0){
									temp->ints[0] = 0;								
								}
								else if((yyvsp[0].symVal)->getVarType() == "FLOAT"){
									(yyvsp[0].symVal)->floats.push_back(0);
									if((yyvsp[0].symVal)->floats[0] == 0) temp->ints[0] = 0;
									else temp->ints[0] = 1;
								}
								else if((yyvsp[0].symVal)->getVarType() == "INT"){
									(yyvsp[0].symVal)->ints.push_back(0);
									if((yyvsp[0].symVal)->ints[0] == 0) temp->ints[0] = 0;
									else temp->ints[0] = 1;
								}
							}
							else if((yyvsp[-2].symVal)->getVarType() == "INT"){
								(yyvsp[-2].symVal)->ints.push_back(0);
								if((yyvsp[-2].symVal)->ints[0] == 0) temp->ints[0] = 0;
								else if((yyvsp[0].symVal)->getVarType() == "FLOAT"){
									if((yyvsp[0].symVal)->floats[0] == 0) temp->ints[0] = 0;
									else temp->ints[0] = 1;
								}
								else if((yyvsp[0].symVal)->getVarType() == "INT"){\
									(yyvsp[0].symVal)->ints.push_back(0);
									if((yyvsp[0].symVal)->ints[0] == 0) temp->ints[0] = 0;
									else temp->ints[0] = 1;
								}
							}
						}
						else if(logicop == "||"){
							if((yyvsp[-2].symVal)->getVarType() == "FLOAT"){
								(yyvsp[-2].symVal)->floats.push_back(0);
								if((yyvsp[-2].symVal)->floats[0] != 0){
									temp->ints[0] = 1;								
								}
								else if((yyvsp[0].symVal)->getVarType() == "FLOAT"){
									(yyvsp[0].symVal)->floats.push_back(0);
									if((yyvsp[0].symVal)->floats[0] != 0) temp->ints[0] = 1;
									else temp->ints[0] =0;
								}
								else if((yyvsp[0].symVal)->getVarType() == "INT"){
									if((yyvsp[0].symVal)->ints[0] != 0) temp->ints[0] = 1;
									else temp->ints[0] =0;
								}
							}
							else if((yyvsp[-2].symVal)->getVarType() == "INT"){
								(yyvsp[-2].symVal)->ints.push_back(0);
								if((yyvsp[-2].symVal)->ints[0] != 0) temp->ints[0] = 1;
								else if((yyvsp[0].symVal)->getVarType() == "FLOAT"){
									(yyvsp[0].symVal)->floats.push_back(0);									
									if((yyvsp[0].symVal)->floats[0] != 0) temp->ints[0] = 1;
									else temp->ints[0] =0;
								}
								else if((yyvsp[0].symVal)->getVarType() == "INT"){
									(yyvsp[0].symVal)->ints.push_back(0);
									if((yyvsp[0].symVal)->ints[0] != 0) temp->ints[0] = 1;
									else temp->ints[0] =0;
								}
							}
						}
						(yyval.symVal) = temp;	
						//logFile << "At rel LOGICOP rel, value " << $$->ints[0] << " Type = " << $$->getVarType() << endl;
					}
#line 2164 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 629 "71parser.y" /* yacc.c:1646  */
    {
					logFile << "Line " << lCount << " : rel_expression : simple_expression\n"<< endl;
					(yyval.symVal) = (yyvsp[0].symVal);
					(yyval.symVal)->ints.push_back(0);
					(yyval.symVal)->floats.push_back(0);
					//logFile << "At Simple, value " << $$->floats[0]<< " Type = " << $$->getVarType() << endl;
				}
#line 2176 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 637 "71parser.y" /* yacc.c:1646  */
    {
					logFile << "Line " << lCount << " : rel_expression : simple_expression RELOP simple_expression\n"<< endl;
					SymbolInfo* temp = new SymbolInfo("INT");
					string relop = (yyvsp[-1].symVal)->getName();
					string type1 = (yyvsp[-2].symVal)->getVarType();
					string type2 = (yyvsp[0].symVal)->getVarType();
					if(relop == "=="){
						if(type1 != type2){
							//logFile << "Type mismatch for == operand" << endl;						
						}
						else if(type1 == "INT"){
							if((yyvsp[-2].symVal)->ints[0] == (yyvsp[0].symVal)->ints[0]) temp->ints[0] =1;
							else temp->ints[0] =0;
						}
						else if(type1 == "FLOAT"){
							if((yyvsp[-2].symVal)->floats[0] == (yyvsp[0].symVal)->floats[0]) temp->ints[0] =1;
							else temp->ints[0] =0;		
						}
						else if(type1 == "CHAR"){
							if((yyvsp[-2].symVal)->chars[0] == (yyvsp[0].symVal)->chars[0]) temp->ints[0] =1;
							else temp->ints[0] =0;		
						}
					}
					else if(relop == "!="){
						if(type1 != type2){
							//logFile << "Type mismatch for != operand" << endl;						
						}
						else if(type1 == "INT"){
							if((yyvsp[-2].symVal)->ints[0] != (yyvsp[0].symVal)->ints[0]) temp->ints[0] =1;
							else temp->ints[0] =0;
						}
						else if(type1 == "FLOAT"){
							if((yyvsp[-2].symVal)->floats[0] != (yyvsp[0].symVal)->floats[0]) temp->ints[0] =1;
							else temp->ints[0] =0;	
						}
						else if(type1 == "CHAR"){
							if((yyvsp[-2].symVal)->chars[0] != (yyvsp[0].symVal)->chars[0]) temp->ints[0] =1;
							else temp->ints[0] =0;	
						}
					}
					else if(relop == "<=" || relop == "<"){
						if(type1 == "INT"){
							if(type2 == "INT"){
								if((yyvsp[-2].symVal)->ints[0] < (yyvsp[0].symVal)->ints[0]) temp->ints[0] =1;
								else if((yyvsp[-2].symVal)->ints[0] == (yyvsp[0].symVal)->ints[0]) temp->ints[0] =1;
								else temp->ints[0] =0;
							}
							else if(type2 == "FLOAT"){
								if((yyvsp[-2].symVal)->ints[0] < (yyvsp[0].symVal)->floats[0]) temp->ints[0] =1;
								else if((yyvsp[-2].symVal)->ints[0] == (yyvsp[0].symVal)->floats[0]) temp->ints[0] =1;
								else temp->ints[0] =0;
							}
						}
						else if(type1 == "FLOAT"){
							if(type2 == "INT"){
								if((yyvsp[-2].symVal)->floats[0] < (yyvsp[0].symVal)->ints[0]) temp->ints[0] =1;
								else if((yyvsp[-2].symVal)->floats[0] == (yyvsp[0].symVal)->ints[0])temp->ints[0] =1;
								else temp->ints[0] =0;
							}
							else if(type2 == "FLOAT"){
								if((yyvsp[-2].symVal)->floats[0] < (yyvsp[0].symVal)->floats[0]) temp->ints[0] =1;
								else if((yyvsp[-2].symVal)->floats[0] == (yyvsp[0].symVal)->floats[0]) temp->ints[0] =1;
								else temp->ints[0] =0;
							}
						}

					}
					else if(relop == ">=" || relop == ">"){
						if(type1 == "INT"){
							if(type2 == "INT"){
								if((yyvsp[-2].symVal)->ints[0] > (yyvsp[0].symVal)->ints[0]) temp->ints[0] =1;
								else if((yyvsp[-2].symVal)->ints[0] == (yyvsp[0].symVal)->ints[0])temp->ints[0] =1;
								else temp->ints[0] =0;
							}
							else if(type2 == "FLOAT"){
								if((yyvsp[-2].symVal)->ints[0] > (yyvsp[0].symVal)->floats[0]) temp->ints[0] =1;
								else if((yyvsp[-2].symVal)->ints[0] == (yyvsp[0].symVal)->floats[0]) temp->ints[0] =1;
								else temp->ints[0] =0;
							}
						}
						else if(type1 == "FLOAT"){
							if(type2 == "INT"){
								if((yyvsp[-2].symVal)->floats[0] > (yyvsp[0].symVal)->ints[0]) temp->ints[0] =1;
								else if((yyvsp[-2].symVal)->floats[0] == (yyvsp[0].symVal)->ints[0]) temp->ints[0] =1;
								else temp->ints[0] =0;
							}
							else if(type2 == "FLOAT"){
								if((yyvsp[-2].symVal)->floats[0] > (yyvsp[0].symVal)->floats[0]) temp->ints[0] =1;
								else if((yyvsp[-2].symVal)->floats[0] == (yyvsp[0].symVal)->floats[0]) temp->ints[0] =1;
								else temp->ints[0] =0;
							}
						}

					}
					(yyval.symVal) = temp;	
				}
#line 2277 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 737 "71parser.y" /* yacc.c:1646  */
    {
						logFile << "Line " << lCount << " : simple_expression : term\n"<< endl;
						(yyval.symVal) = (yyvsp[0].symVal);
						(yyval.symVal)->ints.push_back(0);
						(yyval.symVal)->floats.push_back(0);
						//logFile << "At Term,value " << $$->floats[0]<< " Type = " << $$->getVarType() << endl;
					}
#line 2289 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 745 "71parser.y" /* yacc.c:1646  */
    {
						logFile << "Line " << lCount << " : simple_expression : simple_expression ADDOP term\n"<< endl;
						string addop = (yyvsp[-1].symVal)->getName();
						//logFile << $1->ints[0] << "+" << $3->ints[0] << endl;
						if(addop == "+"){
							if((yyvsp[-2].symVal)->getIDType() == "VAR"){
								if((yyvsp[0].symVal)->getIDType() == "VAR"){						
									if((yyvsp[-2].symVal)->getVarType() == "FLOAT"){
										SymbolInfo* temp = new SymbolInfo("FLOAT");
										if((yyvsp[0].symVal)->getVarType() == "INT"){
											temp->floats[0] =(yyvsp[-2].symVal)->floats[0] + (yyvsp[0].symVal)->ints[0];							
										}
										else{
											temp->floats[0]=(yyvsp[-2].symVal)->floats[0] + (yyvsp[0].symVal)->floats[0];
										}
										(yyval.symVal) = temp;
									}
									else if((yyvsp[0].symVal)->getVarType() == "FLOAT"){
										SymbolInfo* temp = new SymbolInfo("FLOAT");
										if((yyvsp[-2].symVal)->getVarType() == "INT"){
											temp->floats[0]=(yyvsp[-2].symVal)->ints[0] + (yyvsp[0].symVal)->floats[0];							
										}
										else{
											temp->floats[0]= (yyvsp[-2].symVal)->floats[0] + (yyvsp[0].symVal)->floats[0];
										}
										(yyval.symVal) = temp;
									}
									else if((yyvsp[0].symVal)->getVarType() == "INT" && (yyvsp[-2].symVal)->getVarType() == "INT"){
										SymbolInfo* temp = new SymbolInfo("INT");
										temp->ints[0] = (yyvsp[-2].symVal)->ints[0] + (yyvsp[0].symVal)->ints[0];
										(yyval.symVal) = temp;
									}
								}
								else if((yyvsp[0].symVal)->getIDType() == "ARA"){						
									if((yyvsp[-2].symVal)->getVarType() == "FLOAT"){
										SymbolInfo* temp = new SymbolInfo("FLOAT");
										if((yyvsp[0].symVal)->getVarType() == "INT"){
											temp->floats[0] = (yyvsp[-2].symVal)->floats[0] + (yyvsp[0].symVal)->ints[(yyvsp[0].symVal)->getAraIndex()];							
										}
										else{
											temp->floats[0]= (yyvsp[-2].symVal)->floats[0] + (yyvsp[0].symVal)->floats[(yyvsp[0].symVal)->getAraIndex()];
										}
										(yyval.symVal) = temp;
									}
									else if((yyvsp[0].symVal)->getVarType() == "FLOAT"){
										SymbolInfo* temp = new SymbolInfo("FLOAT");
										if((yyvsp[-2].symVal)->getVarType() == "INT"){
											temp->floats[0]=(yyvsp[-2].symVal)->ints[0] + (yyvsp[0].symVal)->floats[(yyvsp[0].symVal)->getAraIndex()];							
										}
										else{
											temp->floats[0] = (yyvsp[-2].symVal)->floats[0] + (yyvsp[0].symVal)->floats[(yyvsp[0].symVal)->getAraIndex()];
										}
										(yyval.symVal) = temp;
									}
									else if((yyvsp[0].symVal)->getVarType() == "INT" && (yyvsp[-2].symVal)->getVarType() == "INT"){
										SymbolInfo* temp = new SymbolInfo("INT");
										temp->ints[0] =(yyvsp[-2].symVal)->ints[0] + (yyvsp[0].symVal)->ints[(yyvsp[0].symVal)->getAraIndex()];
										(yyval.symVal) = temp;
									}
								}
							}
							else if((yyvsp[-2].symVal)->getIDType() == "ARA"){
								if((yyvsp[0].symVal)->getIDType() == "VAR"){						
									if((yyvsp[-2].symVal)->getVarType() == "FLOAT"){
										SymbolInfo* temp = new SymbolInfo("FLOAT");
										if((yyvsp[0].symVal)->getVarType() == "INT"){
											temp->floats[0] =(yyvsp[-2].symVal)->floats[(yyvsp[-2].symVal)->getAraIndex()] + (yyvsp[0].symVal)->ints[0];							
										}
										else{
											temp->floats[0]=(yyvsp[-2].symVal)->floats[(yyvsp[-2].symVal)->getAraIndex()] + (yyvsp[0].symVal)->floats[0];
										}
										(yyval.symVal) = temp;
									}
									else if((yyvsp[0].symVal)->getVarType() == "FLOAT"){
										SymbolInfo* temp = new SymbolInfo("FLOAT");
										if((yyvsp[-2].symVal)->getVarType() == "INT"){
											temp->floats[0]=(yyvsp[-2].symVal)->ints[(yyvsp[-2].symVal)->getAraIndex()] + (yyvsp[0].symVal)->floats[0];							
										}
										else{
											temp->floats[0]=(yyvsp[-2].symVal)->floats[(yyvsp[-2].symVal)->getAraIndex()] + (yyvsp[0].symVal)->floats[0];
										}
										(yyval.symVal) = temp;
									}
									else if((yyvsp[0].symVal)->getVarType() == "INT" && (yyvsp[-2].symVal)->getVarType() == "INT"){
										SymbolInfo* temp = new SymbolInfo("INT");
										temp->ints[0]=(yyvsp[-2].symVal)->ints[(yyvsp[-2].symVal)->getAraIndex()] + (yyvsp[0].symVal)->ints[0];
										(yyval.symVal) = temp;
									}
								}
								else if((yyvsp[0].symVal)->getIDType() == "ARA"){						
									if((yyvsp[-2].symVal)->getVarType() == "FLOAT"){
										SymbolInfo* temp = new SymbolInfo("FLOAT");
										if((yyvsp[0].symVal)->getVarType() == "INT"){
											temp->floats[0]=(yyvsp[-2].symVal)->floats[(yyvsp[-2].symVal)->getAraIndex()] + (yyvsp[0].symVal)->ints[(yyvsp[0].symVal)->getAraIndex()];
										}
										else{
											temp->floats[0]=(yyvsp[-2].symVal)->floats[(yyvsp[-2].symVal)->getAraIndex()] + (yyvsp[0].symVal)->floats[(yyvsp[0].symVal)->getAraIndex()];
										}
										(yyval.symVal) = temp;
									}
									else if((yyvsp[0].symVal)->getVarType() == "FLOAT"){
										SymbolInfo* temp = new SymbolInfo("FLOAT");
										if((yyvsp[-2].symVal)->getVarType() == "INT"){
											temp->floats[0]=(yyvsp[-2].symVal)->ints[(yyvsp[-2].symVal)->getAraIndex()] + (yyvsp[0].symVal)->floats[(yyvsp[0].symVal)->getAraIndex()];
										}
										else{
											temp->floats[0]=(yyvsp[-2].symVal)->floats[(yyvsp[-2].symVal)->getAraIndex()] + (yyvsp[0].symVal)->floats[(yyvsp[0].symVal)->getAraIndex()];
										}
										(yyval.symVal) = temp;
									}
									else if((yyvsp[0].symVal)->getVarType() == "INT" && (yyvsp[-2].symVal)->getVarType() == "INT"){
										SymbolInfo* temp = new SymbolInfo("INT");
										temp->ints[0]=(yyvsp[-2].symVal)->ints[(yyvsp[-2].symVal)->getAraIndex()] + (yyvsp[0].symVal)->ints[(yyvsp[0].symVal)->getAraIndex()];
										(yyval.symVal) = temp;
									}
								}
							}
						}
						else if(addop == "-"){
							if((yyvsp[-2].symVal)->getIDType() == "VAR"){
								if((yyvsp[0].symVal)->getIDType() == "VAR"){						
									if((yyvsp[-2].symVal)->getVarType() == "FLOAT"){
										SymbolInfo* temp = new SymbolInfo("FLOAT");
										if((yyvsp[0].symVal)->getVarType() == "INT"){
											temp->floats[0]=(yyvsp[-2].symVal)->floats[0] - (yyvsp[0].symVal)->ints[0];							
										}
										else{
											temp->floats[0]=(yyvsp[-2].symVal)->floats[0] - (yyvsp[0].symVal)->floats[0];
										}
										(yyval.symVal) = temp;
									}
									else if((yyvsp[0].symVal)->getVarType() == "FLOAT"){
										SymbolInfo* temp = new SymbolInfo("FLOAT");
										if((yyvsp[-2].symVal)->getVarType() == "INT"){
											temp->floats[0]=(yyvsp[-2].symVal)->ints[0] - (yyvsp[0].symVal)->floats[0];							
										}
										else{
											temp->floats[0]=(yyvsp[-2].symVal)->floats[0] - (yyvsp[0].symVal)->floats[0];
										}
										(yyval.symVal) = temp;
									}
									else if((yyvsp[0].symVal)->getVarType() == "INT" && (yyvsp[-2].symVal)->getVarType() == "INT"){
										SymbolInfo* temp = new SymbolInfo("INT");
										temp->ints[0]=(yyvsp[-2].symVal)->ints[0] - (yyvsp[0].symVal)->ints[0];
										(yyval.symVal) = temp;
									}
								}
								else if((yyvsp[0].symVal)->getIDType() == "ARA"){						
									if((yyvsp[-2].symVal)->getVarType() == "FLOAT"){
										SymbolInfo* temp = new SymbolInfo("FLOAT");
										if((yyvsp[0].symVal)->getVarType() == "INT"){
											temp->floats[0]=(yyvsp[-2].symVal)->floats[0] - (yyvsp[0].symVal)->ints[(yyvsp[0].symVal)->getAraIndex()];							
										}
										else{
											temp->floats[0]=(yyvsp[-2].symVal)->floats[0] - (yyvsp[0].symVal)->floats[(yyvsp[0].symVal)->getAraIndex()];
										}
										(yyval.symVal) = temp;
									}
									else if((yyvsp[0].symVal)->getVarType() == "FLOAT"){
										SymbolInfo* temp = new SymbolInfo("FLOAT");
										if((yyvsp[-2].symVal)->getVarType() == "INT"){
											temp->floats[0]=(yyvsp[-2].symVal)->ints[0] - (yyvsp[0].symVal)->floats[(yyvsp[0].symVal)->getAraIndex()];							
										}
										else{
											temp->floats[0]=(yyvsp[-2].symVal)->floats[0] - (yyvsp[0].symVal)->floats[(yyvsp[0].symVal)->getAraIndex()];
										}
										(yyval.symVal) = temp;
									}
									else if((yyvsp[0].symVal)->getVarType() == "INT" && (yyvsp[-2].symVal)->getVarType() == "INT"){
										SymbolInfo* temp = new SymbolInfo("INT");
										temp->ints[0]=(yyvsp[-2].symVal)->ints[0] - (yyvsp[0].symVal)->ints[(yyvsp[0].symVal)->getAraIndex()];
										(yyval.symVal) = temp;
									}
								}
							}
							else if((yyvsp[-2].symVal)->getIDType() == "ARA"){
								if((yyvsp[0].symVal)->getIDType() == "VAR"){						
									if((yyvsp[-2].symVal)->getVarType() == "FLOAT"){
										SymbolInfo* temp = new SymbolInfo("FLOAT");
										if((yyvsp[0].symVal)->getVarType() == "INT"){
											temp->floats[0]=(yyvsp[-2].symVal)->floats[(yyvsp[-2].symVal)->getAraIndex()] - (yyvsp[0].symVal)->ints[0];							
										}
										else{
											temp->floats[0]= (yyvsp[-2].symVal)->floats[(yyvsp[-2].symVal)->getAraIndex()] - (yyvsp[0].symVal)->floats[0];
										}
										(yyval.symVal) = temp;
									}
									else if((yyvsp[0].symVal)->getVarType() == "FLOAT"){
										SymbolInfo* temp = new SymbolInfo("FLOAT");
										if((yyvsp[-2].symVal)->getVarType() == "INT"){
											temp->floats[0]=(yyvsp[-2].symVal)->ints[(yyvsp[-2].symVal)->getAraIndex()] - (yyvsp[0].symVal)->floats[0];							
										}
										else{
											temp->floats[0]=(yyvsp[-2].symVal)->floats[(yyvsp[-2].symVal)->getAraIndex()] - (yyvsp[0].symVal)->floats[0];
										}
										(yyval.symVal) = temp;
									}
									else if((yyvsp[0].symVal)->getVarType() == "INT" && (yyvsp[-2].symVal)->getVarType() == "INT"){
										SymbolInfo* temp = new SymbolInfo("INT");
										temp->ints[0]=(yyvsp[-2].symVal)->ints[(yyvsp[-2].symVal)->getAraIndex()] - (yyvsp[0].symVal)->ints[0];
										(yyval.symVal) = temp;
									}
								}
								else if((yyvsp[0].symVal)->getIDType() == "ARA"){						
									if((yyvsp[-2].symVal)->getVarType() == "FLOAT"){
										SymbolInfo* temp = new SymbolInfo("FLOAT");
										if((yyvsp[0].symVal)->getVarType() == "INT"){
											temp->floats[0]=(yyvsp[-2].symVal)->floats[(yyvsp[-2].symVal)->getAraIndex()] - (yyvsp[0].symVal)->ints[(yyvsp[0].symVal)->getAraIndex()];
										}
										else{
											temp->floats[0]=(yyvsp[-2].symVal)->floats[(yyvsp[-2].symVal)->getAraIndex()] - (yyvsp[0].symVal)->floats[(yyvsp[0].symVal)->getAraIndex()];
										}
										(yyval.symVal) = temp;
									}
									else if((yyvsp[0].symVal)->getVarType() == "FLOAT"){
										SymbolInfo* temp = new SymbolInfo("FLOAT");
										if((yyvsp[-2].symVal)->getVarType() == "INT"){
											temp->floats[0]=(yyvsp[-2].symVal)->ints[(yyvsp[-2].symVal)->getAraIndex()] - (yyvsp[0].symVal)->floats[(yyvsp[0].symVal)->getAraIndex()];
										}
										else{
											temp->floats[0]=(yyvsp[-2].symVal)->floats[(yyvsp[-2].symVal)->getAraIndex()] - (yyvsp[0].symVal)->floats[(yyvsp[0].symVal)->getAraIndex()];
										}
										(yyval.symVal) = temp;
									}
									else if((yyvsp[0].symVal)->getVarType() == "INT" && (yyvsp[-2].symVal)->getVarType() == "INT"){
										SymbolInfo* temp = new SymbolInfo("INT");
										temp->ints[0]=(yyvsp[-2].symVal)->ints[(yyvsp[-2].symVal)->getAraIndex()] - (yyvsp[0].symVal)->ints[(yyvsp[0].symVal)->getAraIndex()];
										(yyval.symVal) = temp;
									}
								}
							}
						}
					}
#line 2527 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 982 "71parser.y" /* yacc.c:1646  */
    {
			logFile << "Line " << lCount << " : term : unary_expression\n"<< endl;
			(yyval.symVal) = (yyvsp[0].symVal);
			(yyval.symVal)->ints.push_back(0);
			(yyval.symVal)->floats.push_back(0);
			//logFile << "At Unary , value " << $$->floats[0]<< " Type = " << $$->getVarType() << endl;
		}
#line 2539 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 990 "71parser.y" /* yacc.c:1646  */
    {
			string mulop = (yyvsp[-1].symVal)->getName();
			logFile << "Line " << lCount << " : term : term MULOP unary_expression\n"<< endl;

			if(mulop == "*")
			{
				if((yyvsp[-2].symVal)->getIDType() == "VAR"){	
					if((yyvsp[0].symVal)->getIDType() == "VAR"){		
						if((yyvsp[-2].symVal)->getVarType() == "FLOAT"){
							SymbolInfo* temp = new SymbolInfo("FLOAT");
							if((yyvsp[0].symVal)->getVarType() == "INT"){
								temp->floats[0]=(yyvsp[-2].symVal)->floats[0] * (yyvsp[0].symVal)->ints[0];							
							}
							else{
								temp->floats[0]=(yyvsp[-2].symVal)->floats[0] * (yyvsp[0].symVal)->floats[0];
							}
							(yyval.symVal) = temp;
						}
						else if((yyvsp[0].symVal)->getVarType() == "FLOAT"){
							SymbolInfo* temp = new SymbolInfo("FLOAT");
							if((yyvsp[-2].symVal)->getVarType() == "INT"){
								temp->floats[0]=(yyvsp[-2].symVal)->ints[0] * (yyvsp[0].symVal)->floats[0];							
							}
							else{
								temp->floats[0]=(yyvsp[-2].symVal)->floats[0] * (yyvsp[0].symVal)->floats[0];
							}
							(yyval.symVal) = temp;
						}
						else if((yyvsp[0].symVal)->getVarType() == "INT" && (yyvsp[-2].symVal)->getVarType() == "INT"){
							SymbolInfo* temp = new SymbolInfo("INT");
							temp->ints[0]=(yyvsp[-2].symVal)->ints[0] * (yyvsp[0].symVal)->ints[0];
							(yyval.symVal) = temp;
						}
					}
					else if((yyvsp[0].symVal)->getIDType() == "ARA"){		
						if((yyvsp[-2].symVal)->getVarType() == "FLOAT"){
							SymbolInfo* temp = new SymbolInfo("FLOAT");
							if((yyvsp[0].symVal)->getVarType() == "INT"){
								temp->floats[0]=(yyvsp[-2].symVal)->floats[0] * (yyvsp[0].symVal)->ints[(yyvsp[0].symVal)->getAraIndex()];							
							}
							else{
								temp->floats[0]=(yyvsp[-2].symVal)->floats[0] * (yyvsp[0].symVal)->floats[(yyvsp[0].symVal)->getAraIndex()];
							}
							(yyval.symVal) = temp;
						}
						else if((yyvsp[0].symVal)->getVarType() == "FLOAT"){
							SymbolInfo* temp = new SymbolInfo("FLOAT");
							if((yyvsp[-2].symVal)->getVarType() == "INT"){
								temp->floats[0]=(yyvsp[-2].symVal)->ints[0] * (yyvsp[0].symVal)->floats[(yyvsp[0].symVal)->getAraIndex()];							
							}
							else{
								temp->floats[0]=(yyvsp[-2].symVal)->floats[0] * (yyvsp[0].symVal)->floats[(yyvsp[0].symVal)->getAraIndex()];
							}
							(yyval.symVal) = temp;
						}
						else if((yyvsp[0].symVal)->getVarType() == "INT" && (yyvsp[-2].symVal)->getVarType() == "INT"){
							SymbolInfo* temp = new SymbolInfo("INT");
							temp->ints[0]=(yyvsp[-2].symVal)->ints[0] * (yyvsp[0].symVal)->ints[0];
							(yyval.symVal) = temp;
						}
					}
				}
				else if((yyvsp[-2].symVal)->getIDType() == "ARA"){	
					if((yyvsp[0].symVal)->getIDType() == "VAR"){		
						if((yyvsp[-2].symVal)->getVarType() == "FLOAT"){
							SymbolInfo* temp = new SymbolInfo("FLOAT");
							if((yyvsp[0].symVal)->getVarType() == "INT"){
								temp->floats[0]=(yyvsp[-2].symVal)->floats[(yyvsp[-2].symVal)->getAraIndex()] * (yyvsp[0].symVal)->ints[0];							
							}
							else{
								temp->floats[0]=(yyvsp[-2].symVal)->floats[(yyvsp[-2].symVal)->getAraIndex()] * (yyvsp[0].symVal)->floats[0];
							}
							(yyval.symVal) = temp;
						}
						else if((yyvsp[0].symVal)->getVarType() == "FLOAT"){
							SymbolInfo* temp = new SymbolInfo("FLOAT");
							if((yyvsp[-2].symVal)->getVarType() == "INT"){
								temp->floats[0]=(yyvsp[-2].symVal)->ints[(yyvsp[-2].symVal)->getAraIndex()] * (yyvsp[0].symVal)->floats[0];							
							}
							else{
								temp->floats[0]=(yyvsp[-2].symVal)->floats[(yyvsp[-2].symVal)->getAraIndex()] * (yyvsp[0].symVal)->floats[0];
							}
							(yyval.symVal) = temp;
						}
						else if((yyvsp[0].symVal)->getVarType() == "INT" && (yyvsp[-2].symVal)->getVarType() == "INT"){
							SymbolInfo* temp = new SymbolInfo("INT");
							temp->ints[0]=(yyvsp[-2].symVal)->ints[(yyvsp[-2].symVal)->getAraIndex()] * (yyvsp[0].symVal)->ints[0];
							(yyval.symVal) = temp;
						}
					}
					else if((yyvsp[0].symVal)->getIDType() == "ARA"){		
						if((yyvsp[-2].symVal)->getVarType() == "FLOAT"){
							SymbolInfo* temp = new SymbolInfo("FLOAT");
							if((yyvsp[0].symVal)->getVarType() == "INT"){
								temp->floats[0]=(yyvsp[-2].symVal)->floats[(yyvsp[-2].symVal)->getAraIndex()] * (yyvsp[0].symVal)->ints[(yyvsp[0].symVal)->getAraIndex()];
							}
							else{
								temp->floats[0]=(yyvsp[-2].symVal)->floats[(yyvsp[-2].symVal)->getAraIndex()] * (yyvsp[0].symVal)->floats[(yyvsp[0].symVal)->getAraIndex()];
							}
							(yyval.symVal) = temp;
						}
						else if((yyvsp[0].symVal)->getVarType() == "FLOAT"){
							SymbolInfo* temp = new SymbolInfo("FLOAT");
							if((yyvsp[-2].symVal)->getVarType() == "INT"){
								temp->floats[0]=(yyvsp[-2].symVal)->ints[(yyvsp[-2].symVal)->getAraIndex()] * (yyvsp[0].symVal)->floats[(yyvsp[0].symVal)->getAraIndex()];
							}
							else{
								temp->floats[0]=(yyvsp[-2].symVal)->floats[(yyvsp[-2].symVal)->getAraIndex()] * (yyvsp[0].symVal)->floats[(yyvsp[0].symVal)->getAraIndex()];
							}
							(yyval.symVal) = temp;
						}
						else if((yyvsp[0].symVal)->getVarType() == "INT" && (yyvsp[-2].symVal)->getVarType() == "INT"){
							SymbolInfo* temp = new SymbolInfo("INT");
							temp->ints[0]=(yyvsp[-2].symVal)->ints[(yyvsp[-2].symVal)->getAraIndex()] * (yyvsp[0].symVal)->ints[0];
							(yyval.symVal) = temp;
						}
					}
				}
			}
			else if(mulop == "/")
			{
				if((yyvsp[-2].symVal)->getVarType() == "FLOAT"){
					SymbolInfo* temp = new SymbolInfo("FLOAT");
					if((yyvsp[0].symVal)->getVarType() == "INT"){
						if((yyvsp[-2].symVal)->getIDType() == "VAR"){
							if((yyvsp[0].symVal)->getIDType() == "VAR"){
								if((yyvsp[0].symVal)->ints[0] != 0)temp->floats[0]=(yyvsp[-2].symVal)->floats[0] / (yyvsp[0].symVal)->ints[0];
								else{
									temp->floats[0]=numeric_limits<float>::infinity();
							errorFile << "Error at line " << lCount <<" : Divide by zero"<<endl << endl;
									semErrors++; 
								}							
							}
							else if((yyvsp[0].symVal)->getIDType() == "ARA"){
								if((yyvsp[0].symVal)->ints[(yyvsp[0].symVal)->getAraIndex()] != 0)temp->floats[0]=(yyvsp[-2].symVal)->floats[0] / (yyvsp[0].symVal)->ints[(yyvsp[0].symVal)->getAraIndex()];
								else{
									temp->floats[0]=numeric_limits<float>::infinity();
							errorFile << "Error at line " << lCount <<" : Divide by zero"<<endl << endl;
									semErrors++;
								}
							}
						}
						else if((yyvsp[-2].symVal)->getIDType() == "ARA"){
							if((yyvsp[0].symVal)->getIDType() == "VAR"){
								if((yyvsp[0].symVal)->ints[0] != 0)temp->floats[0]=(yyvsp[-2].symVal)->floats[(yyvsp[-2].symVal)->getAraIndex()] / (yyvsp[0].symVal)->ints[0];
								else{
									temp->floats[0]=numeric_limits<float>::infinity();
							errorFile << "Error at line " << lCount <<" : Divide by zero"<<endl << endl;
									semErrors++;
								}							
							}
							else if((yyvsp[0].symVal)->getIDType() == "ARA"){
								if((yyvsp[0].symVal)->ints[(yyvsp[0].symVal)->getAraIndex()] != 0){
									temp->floats[0]=(yyvsp[-2].symVal)->floats[(yyvsp[-2].symVal)->getAraIndex()] / (yyvsp[0].symVal)->ints[(yyvsp[0].symVal)->getAraIndex()];
								}
								else{
									temp->floats[0]=numeric_limits<float>::infinity();
							errorFile << "Error at line " << lCount <<" : Divide by zero"<<endl << endl;
									semErrors++;
								}
							}
						}
					}
					else if((yyvsp[0].symVal)->getVarType() == "FLOAT"){
						if((yyvsp[-2].symVal)->getIDType() == "VAR"){
							if((yyvsp[0].symVal)->getIDType() == "VAR"){
								if((yyvsp[0].symVal)->floats[0] != 0)temp->floats[0]=(yyvsp[-2].symVal)->floats[0] / (yyvsp[0].symVal)->floats[0];
								else{
									temp->floats[0]=numeric_limits<float>::infinity();
							errorFile << "Error at line " << lCount <<" : Divide by zero"<<endl << endl;
									semErrors++;
								}							
							}
							else if((yyvsp[0].symVal)->getIDType() == "ARA"){
								if((yyvsp[0].symVal)->floats[(yyvsp[0].symVal)->getAraIndex()] != 0)temp->floats[0]=(yyvsp[-2].symVal)->floats[0] / (yyvsp[0].symVal)->floats[(yyvsp[0].symVal)->getAraIndex()];
								else{
									temp->floats[0]=numeric_limits<float>::infinity();
							errorFile << "Error at line " << lCount <<" : Divide by zero"<<endl << endl;
									semErrors++;
								}
							}
						}
						else if((yyvsp[-2].symVal)->getIDType() == "ARA"){
							if((yyvsp[0].symVal)->getIDType() == "VAR"){
								if((yyvsp[0].symVal)->floats[0] != 0)temp->floats[0]=(yyvsp[-2].symVal)->floats[(yyvsp[-2].symVal)->getAraIndex()] / (yyvsp[0].symVal)->floats[0];
								else{
									temp->floats[0]=numeric_limits<float>::infinity();
							errorFile << "Error at line " << lCount <<" : Divide by zero"<<endl << endl;
									semErrors++;
								}							
							}
							else if((yyvsp[0].symVal)->getIDType() == "ARA"){
								if((yyvsp[0].symVal)->floats[(yyvsp[0].symVal)->getAraIndex()] != 0){
									temp->floats[0]=(yyvsp[-2].symVal)->floats[(yyvsp[-2].symVal)->getAraIndex()] / (yyvsp[0].symVal)->floats[(yyvsp[0].symVal)->getAraIndex()];
								}
								else{
									temp->floats[0]=numeric_limits<float>::infinity();
							errorFile << "Error at line " << lCount <<" : Divide by zero"<<endl << endl;
									semErrors++;
								}
							}
						}
					}
					(yyval.symVal) = temp;
				}
				else if((yyvsp[0].symVal)->getVarType() == "FLOAT"){
					SymbolInfo* temp = new SymbolInfo("FLOAT");
					if((yyvsp[-2].symVal)->getVarType() == "INT"){
						if((yyvsp[-2].symVal)->getIDType() == "VAR"){
							if((yyvsp[0].symVal)->getIDType() == "VAR"){
								if((yyvsp[0].symVal)->floats[0] != 0)temp->floats[0]=(yyvsp[-2].symVal)->ints[0] / (yyvsp[0].symVal)->floats[0];
								else{
									temp->floats[0]=numeric_limits<float>::infinity();
							errorFile << "Error at line " << lCount <<" : Divide by zero"<<endl << endl;
									semErrors++;
								}							
							}
							else if((yyvsp[0].symVal)->getIDType() == "ARA"){
								if((yyvsp[0].symVal)->floats[(yyvsp[0].symVal)->getAraIndex()] != 0)temp->floats[0]=(yyvsp[-2].symVal)->ints[0] / (yyvsp[0].symVal)->floats[(yyvsp[0].symVal)->getAraIndex()];
								else{
									temp->floats[0]=numeric_limits<float>::infinity();
							errorFile << "Error at line " << lCount <<" : Divide by zero"<<endl << endl;
									semErrors++;
								}
							}
						}
						else if((yyvsp[-2].symVal)->getIDType() == "ARA"){
							if((yyvsp[0].symVal)->getIDType() == "VAR"){
								if((yyvsp[0].symVal)->floats[0] != 0)temp->floats[0]=(yyvsp[-2].symVal)->ints[(yyvsp[-2].symVal)->getAraIndex()] / (yyvsp[0].symVal)->floats[0];
								else{
									temp->floats[0]=numeric_limits<float>::infinity();
							errorFile << "Error at line " << lCount <<" : Divide by zero"<<endl << endl;
									semErrors++;
								}							
							}
							else if((yyvsp[0].symVal)->getIDType() == "ARA"){
								if((yyvsp[0].symVal)->floats[(yyvsp[0].symVal)->getAraIndex()] != 0){
									temp->floats[0]=(yyvsp[-2].symVal)->ints[(yyvsp[-2].symVal)->getAraIndex()] / (yyvsp[0].symVal)->floats[(yyvsp[0].symVal)->getAraIndex()];
								}
								else{
									temp->floats[0]=numeric_limits<float>::infinity();
							errorFile << "Error at line " << lCount <<" : Divide by zero"<<endl << endl;
									semErrors++;
								}
							}
						}
					}
					else if((yyvsp[-2].symVal)->getVarType() == "FLOAT"){
						if((yyvsp[-2].symVal)->getIDType() == "VAR"){
							if((yyvsp[0].symVal)->getIDType() == "VAR"){
								if((yyvsp[0].symVal)->floats[0] != 0)temp->floats[0]=(yyvsp[-2].symVal)->floats[0] / (yyvsp[0].symVal)->floats[0];
								else{
									temp->floats[0]=numeric_limits<float>::infinity();
							errorFile << "Error at line " << lCount <<" : Divide by zero"<<endl << endl;
									semErrors++;
								}							
							}
							else if((yyvsp[0].symVal)->getIDType() == "ARA"){
								if((yyvsp[0].symVal)->floats[(yyvsp[0].symVal)->getAraIndex()] != 0)temp->floats[0]=(yyvsp[-2].symVal)->floats[0] / (yyvsp[0].symVal)->floats[(yyvsp[0].symVal)->getAraIndex()];
								else{
									temp->floats[0]=numeric_limits<float>::infinity();
							errorFile << "Error at line " << lCount <<" : Divide by zero"<<endl << endl;
									semErrors++;
								}
							}
						}
						else if((yyvsp[-2].symVal)->getIDType() == "ARA"){
							if((yyvsp[0].symVal)->getIDType() == "VAR"){
								if((yyvsp[0].symVal)->floats[0] != 0)temp->floats[0]=(yyvsp[-2].symVal)->floats[(yyvsp[-2].symVal)->getAraIndex()] / (yyvsp[0].symVal)->floats[0];
								else{
									temp->floats[0]=numeric_limits<float>::infinity();
							errorFile << "Error at line " << lCount <<" : Divide by zero"<<endl << endl;
									semErrors++;
								}							
							}
							else if((yyvsp[0].symVal)->getIDType() == "ARA"){
								if((yyvsp[0].symVal)->floats[(yyvsp[0].symVal)->getAraIndex()] != 0){
									temp->floats[0]=(yyvsp[-2].symVal)->floats[(yyvsp[-2].symVal)->getAraIndex()] / (yyvsp[0].symVal)->floats[(yyvsp[0].symVal)->getAraIndex()];
								}
								else{
									temp->floats[0]=numeric_limits<float>::infinity();
							errorFile << "Error at line " << lCount <<" : Divide by zero"<<endl << endl;
									semErrors++;
								}
							}
						}
					}				
					(yyval.symVal) = temp;
				}
				else if((yyvsp[0].symVal)->getVarType() == "INT" && (yyvsp[-2].symVal)->getVarType() == "INT"){
					SymbolInfo* temp = new SymbolInfo("INT");
					if((yyvsp[-2].symVal)->getIDType() == "VAR"){	
						if((yyvsp[0].symVal)->getIDType() == "VAR"){			
							if((yyvsp[0].symVal)->ints[0] != 0)temp->ints[0]=(yyvsp[-2].symVal)->ints[0] / (yyvsp[0].symVal)->ints[0];
							else{
								temp->ints[0]=numeric_limits<int>::max();
							errorFile << "Error at line " << lCount <<" : Divide by zero"<<endl << endl;
								semErrors++;
							}
						}
						else if((yyvsp[0].symVal)->getIDType() == "ARA"){
							if((yyvsp[0].symVal)->ints[(yyvsp[0].symVal)->getAraIndex()] != 0)temp->ints[0]=(yyvsp[-2].symVal)->ints[0] / (yyvsp[0].symVal)->ints[(yyvsp[0].symVal)->getAraIndex()];
							else{
								temp->ints[0]=numeric_limits<int>::max();
							errorFile << "Error at line " << lCount <<" : Divide by zero"<<endl << endl;
								semErrors++;
							}
						}
					}
					else if((yyvsp[-2].symVal)->getIDType() == "ARA"){
						if((yyvsp[0].symVal)->getIDType() == "VAR"){			
							if((yyvsp[0].symVal)->ints[0] != 0)temp->ints[0]=(yyvsp[-2].symVal)->ints[(yyvsp[-2].symVal)->getAraIndex()] / (yyvsp[0].symVal)->ints[0];
							else{
								temp->ints[0]=numeric_limits<int>::max();
							errorFile << "Error at line " << lCount <<" : Divide by zero"<<endl << endl;
								semErrors++;
							}
						}
						else if((yyvsp[0].symVal)->getIDType() == "ARA"){
							if((yyvsp[0].symVal)->ints[(yyvsp[0].symVal)->getAraIndex()] != 0)
							{
								temp->ints[0]=(yyvsp[-2].symVal)->ints[(yyvsp[-2].symVal)->getAraIndex()] / (yyvsp[0].symVal)->ints[(yyvsp[0].symVal)->getAraIndex()];
							}
							else{
								temp->floats[0]=numeric_limits<int>::max();
							errorFile << "Error at line " << lCount <<" : Divide by zero"<<endl << endl;	
								semErrors++;
							}
						}
					}
					(yyval.symVal) = temp;
				}
			}
			else if(mulop == "%"){
				SymbolInfo* temp = new SymbolInfo("INT");
				temp->setIDType("VAR");
				if((yyvsp[-2].symVal)->getVarType() == "FLOAT" || (yyvsp[0].symVal)->getVarType() == "FLOAT"){
					errorFile << "Error at line " << lCount <<" : Unsuported operand for mod operator"<<endl << endl;
					semErrors++;
				}
				else if((yyvsp[-2].symVal)->getVarType() == "INT" && (yyvsp[0].symVal)->getVarType() == "INT"){
					if((yyvsp[-2].symVal)->getIDType() == "VAR"){
						if((yyvsp[0].symVal)->getIDType() == "VAR")temp->ints[0]=((yyvsp[-2].symVal)->ints[0])%((yyvsp[0].symVal)->ints[0]);
						else temp->ints[0]= ((yyvsp[-2].symVal)->ints[0])%((yyvsp[0].symVal)->ints[(yyvsp[0].symVal)->getAraIndex()]);					
					}
					else{
						if((yyvsp[0].symVal)->getIDType() == "VAR")temp->ints[0]=((yyvsp[-2].symVal)->ints[(yyvsp[-2].symVal)->getAraIndex()])%((yyvsp[0].symVal)->ints[0]);
						else temp->ints[0]=((yyvsp[-2].symVal)->ints[(yyvsp[-2].symVal)->getAraIndex()])%((yyvsp[0].symVal)->ints[(yyvsp[0].symVal)->getAraIndex()]);					
					}
				}
				(yyval.symVal) = temp;
			}
		}
#line 2897 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 1345 "71parser.y" /* yacc.c:1646  */
    {
            logFile << "Line " << lCount << " unary_expression : ADDOP unary_expression :\n"<< endl;
            if((yyvsp[-1].symVal)->getName() == "-"){
			    if((yyvsp[0].symVal)->getVarType() == "VAR"){
				    (yyvsp[0].symVal)->ints[0] = (-1)*((yyvsp[0].symVal)->ints[0]);
			    }
			    else if((yyvsp[0].symVal)->getVarType() == "ARA"){
				    (yyvsp[0].symVal)->ints[(yyvsp[0].symVal)->getAraIndex()] = (-1)*((yyvsp[0].symVal)->ints[(yyvsp[0].symVal)->getAraIndex()]);
			    }
		    }
		    (yyval.symVal) = (yyvsp[0].symVal);    
        }
#line 2914 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 1358 "71parser.y" /* yacc.c:1646  */
    {
		    logFile << "Line " << lCount << " unary_expression :NOT unary_expression :\n"<< endl;
            SymbolInfo* temp = new SymbolInfo("INT");
			temp->setIDType("VAR");
			int value;
			if((yyvsp[0].symVal)->getVarType() == "INT"){
				if((yyvsp[0].symVal)->getIDType() == "VAR") value = (yyvsp[0].symVal)->ints[0];
				else if((yyvsp[0].symVal)->getIDType() == "ARA")value = (yyvsp[0].symVal)->ints[(yyvsp[0].symVal)->getAraIndex()];
			}
			else if((yyvsp[0].symVal)->getVarType() == "FLOAT"){
				if((yyvsp[0].symVal)->getIDType() == "VAR") value = (int)(yyvsp[0].symVal)->floats[0];
				else if((yyvsp[0].symVal)->getIDType() == "ARA") value = (int)(yyvsp[0].symVal)->floats[(yyvsp[0].symVal)->getAraIndex()];
			} 
			if(value != 0) value = 0;
			else value = 1;

			temp->ints[0]=value;
			(yyval.symVal)=temp;        		 
		 }
#line 2938 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 1378 "71parser.y" /* yacc.c:1646  */
    {
		    logFile << "Line " << lCount << " unary_expression : factor:\n"<< endl;
		    logFile << "Line " << lCount << " : unary_expression : factor\n"<< endl;
			(yyval.symVal) = (yyvsp[0].symVal);
			(yyval.symVal)->ints.push_back(0);
			(yyval.symVal)->floats.push_back(0);
		 }
#line 2950 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 1388 "71parser.y" /* yacc.c:1646  */
    {
        logFile << "Line " << lCount << " factor	: variable :\n"<< endl;
     }
#line 2958 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 1392 "71parser.y" /* yacc.c:1646  */
    {
	    logFile << "Line " << lCount << " factor	: ID LPAREN argument_list RPAREN:\n"<< endl;
	    logFile << (yyvsp[-3].symVal)->getName() << endl << endl;
	    		SymbolInfo *temp=new SymbolInfo();
			temp = table->lookUp((yyvsp[-3].symVal)->getName(), "FUNC");
			if(temp == NULL){
				errorFile << "Error at line " << lCount <<" : Function " <<(yyvsp[-3].symVal)->getName() <<" doesn't exist"<<endl << endl;
			}
			else{
				if(temp->getFuncRet() == "VOID"){
					errorFile << "Error at line " << lCount <<" : Function " <<(yyvsp[-3].symVal)->getName() <<" returns void"<<endl << endl;
				} 
				else{ 
					SymbolInfo *temp2 = new SymbolInfo((yyvsp[-3].symVal)->getFuncRet());
					if(temp2->getVarType() == "INT")temp2->ints[0] = 0;
					else if(temp2->getVarType() == "FLOAT")temp2->floats[0] = 0;
					else if(temp2->getVarType() == "CHAR")temp2->chars[0] = '\0';
					(yyval.symVal) = temp2;
				}
			}
	}
#line 2984 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 1414 "71parser.y" /* yacc.c:1646  */
    {
        logFile << "Line " << lCount << ": factor	: LPAREN expression RPAREN :\n"<< endl;
        (yyval.symVal) = (yyvsp[-1].symVal);
    }
#line 2993 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 1419 "71parser.y" /* yacc.c:1646  */
    {
        logFile << "Line " << lCount << ": factor	: CONST_INT:\n"<< endl;
        logFile << (yyvsp[0].symVal)->getName() << endl << endl;
        (yyvsp[0].symVal)->setVarType("INT");			
        (yyvsp[0].symVal)->ints[0]= atoi((yyvsp[0].symVal)->getName().c_str());
        (yyvsp[0].symVal)->setIDType("VAR");
        (yyval.symVal) = (yyvsp[0].symVal);
    }
#line 3006 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 1428 "71parser.y" /* yacc.c:1646  */
    {    
         logFile << "Line " << lCount << ": factor	: CONST_FLOAT:\n"<< endl;
         logFile << (yyvsp[0].symVal)->getName() << endl << endl;
         (yyvsp[0].symVal)->setVarType("FLOAT");
         (yyvsp[0].symVal)->floats[0]= atof((yyvsp[0].symVal)->getName().c_str());
         (yyvsp[0].symVal)->setIDType("VAR");
         (yyval.symVal) = (yyvsp[0].symVal);      
	}
#line 3019 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 1437 "71parser.y" /* yacc.c:1646  */
    {
	    logFile << "Line " << lCount << ": factor : CONST_CHAR\n";
	    logFile << (yyvsp[0].symVal)->getName() << endl << endl;
	    (yyval.symVal) = (yyvsp[0].symVal);
    }
#line 3029 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 1443 "71parser.y" /* yacc.c:1646  */
    {
	    logFile << "Line " << lCount << ": factor	: variable INCOP :\n"<< endl;
		if((yyvsp[-1].symVal)->getIDType() == "ARA"){
			if((yyvsp[-1].symVal)->getVarType() == "INT"){
				(yyvsp[-1].symVal)->ints[(yyvsp[-1].symVal)->getAraIndex()] = (yyvsp[-1].symVal)->ints[(yyvsp[-1].symVal)->getAraIndex()]+1; 
			}
			else if((yyvsp[-1].symVal)->getVarType() == "FLOAT"){
				(yyvsp[-1].symVal)->floats[(yyvsp[-1].symVal)->getAraIndex()] = (yyvsp[-1].symVal)->floats[(yyvsp[-1].symVal)->getAraIndex()]+1.0; 
			}			
		}
		else if((yyvsp[-1].symVal)->getIDType() == "VAR"){
			if((yyvsp[-1].symVal)->getVarType() == "INT"){
				(yyvsp[-1].symVal)->ints[0] = (yyvsp[-1].symVal)->ints[0]+1; 
			}
			else if((yyvsp[-1].symVal)->getVarType() == "FLOAT"){
				(yyvsp[-1].symVal)->floats[0] = (yyvsp[-1].symVal)->floats[0]+1.0; 
			}					
		}
		(yyval.symVal) = (yyvsp[-1].symVal);	    
	}
#line 3054 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 1464 "71parser.y" /* yacc.c:1646  */
    {
		logFile << "Line " << lCount << " : factor : variable DECOP\n"<< endl;
		if((yyvsp[-1].symVal)->getIDType() == "ARA"){
			if((yyvsp[-1].symVal)->getVarType() == "INT"){
				(yyvsp[-1].symVal)->ints[(yyvsp[-1].symVal)->getAraIndex()] = (yyvsp[-1].symVal)->ints[(yyvsp[-1].symVal)->getAraIndex()]-1; 
			}
			else if((yyvsp[-1].symVal)->getVarType() == "FLOAT"){
				(yyvsp[-1].symVal)->floats[(yyvsp[-1].symVal)->getAraIndex()] = (yyvsp[-1].symVal)->floats[(yyvsp[-1].symVal)->getAraIndex()]-1.0; 
			}			
		}
		else if((yyvsp[-1].symVal)->getIDType() == "VAR"){
			if((yyvsp[-1].symVal)->getVarType() == "INT"){
				(yyvsp[-1].symVal)->ints[0] = (yyvsp[-1].symVal)->ints[0]-1; 
			}
			else if((yyvsp[-1].symVal)->getVarType() == "FLOAT"){
				(yyvsp[-1].symVal)->floats[0] = (yyvsp[-1].symVal)->floats[0]-1.0; 
			}					
		}
		(yyval.symVal) = (yyvsp[-1].symVal);	    
	}
#line 3079 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 1487 "71parser.y" /* yacc.c:1646  */
    {
                  logFile << "Line " << lCount << ": argument_list : arguments:\n"<< endl;
              }
#line 3087 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 1494 "71parser.y" /* yacc.c:1646  */
    {
              logFile << "Line " << lCount << ": arguments : arguments COMMA logic_expression :\n"<< endl;
          }
#line 3095 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 1498 "71parser.y" /* yacc.c:1646  */
    {
	          logFile << "Line " << lCount << ":arguments :logic_expression :\n"<< endl;
	      }
#line 3103 "y.tab.c" /* yacc.c:1646  */
    break;


#line 3107 "y.tab.c" /* yacc.c:1646  */
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
#line 1503 "71parser.y" /* yacc.c:1906  */


int main(int argc,char *argv[])
{

	if((yyin=fopen(argv[1],"r"))==NULL)
	{
		printf("Cannot Open Input File.\n");
		exit(1);
	}

	logFile.open("log.txt");
	errorFile.open("errors.txt");
	
	//	logFile << "Kichu" << endl;
	//yyin=fp;
	yyparse();
	
	logFile << "Total Lines : " << lCount << endl << endl; 
	logFile << "Total Errors : " << semErrors << endl;
	logFile.close();
	errorFile.close();

	return 0;
}

