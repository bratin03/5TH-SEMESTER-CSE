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




/* First part of user prologue.  */
#line 11 "ass5_21CS10016_21CS30050.y"

    // This is the beginning of the declarations section.
    // It includes some C++ standard libraries and header files.
    #include <bits/stdc++.h>
    #include <sstream>
    using namespace std;  // Using the standard C++ namespace.
    #include "ass5_21CS10016_21CS30050_translator.h"
    extern int yylex();  // Declaration of an external function yylex.
    void yyerror(string s);  // Declaration of a function yyerror.
    extern string variable_type;  // Declaration of an external string variable.
    extern vector<label> label_store;  // Declaration of an external vector.
    extern int lineno;  // Declaration of an external integer variable.

#line 84 "ass5_21CS10016_21CS30050.tab.c"

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
#ifndef YY_YY_ASS5_21CS10016_21CS30050_TAB_H_INCLUDED
# define YY_YY_ASS5_21CS10016_21CS30050_TAB_H_INCLUDED
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
    BREAK = 258,
    RETURN = 259,
    CASE = 260,
    FOR = 261,
    WHILE = 262,
    GOTO = 263,
    SIZEOF = 264,
    CONTINUE = 265,
    IF = 266,
    DO = 267,
    SWITCH = 268,
    ELSE = 269,
    FLOAT = 270,
    SHORT = 271,
    CHAR = 272,
    BOOL = 273,
    IMAGINARY = 274,
    COMPLEX = 275,
    INT = 276,
    DOUBLE = 277,
    LONG = 278,
    VOID = 279,
    SIGNED = 280,
    AUTO = 281,
    UNSIGNED = 282,
    ENUM = 283,
    UNION = 284,
    STRUCT = 285,
    TYPEDEF = 286,
    CONST = 287,
    DEFAULT = 288,
    STATIC = 289,
    REGISTER = 290,
    RESTRICT = 291,
    VOLATILE = 292,
    EXTERN = 293,
    INLINE = 294,
    SQR_BRACE_OPEN = 295,
    SQR_BRACE_CLOSE = 296,
    PARENTHESIS_OPEN = 297,
    PARENTHESIS_CLOSE = 298,
    CURLY_BRACE_OPEN = 299,
    CURLY_BRACE_CLOSE = 300,
    DOT = 301,
    QUESTION_MARK = 302,
    COLON = 303,
    SEMI_COLON = 304,
    COMMA = 305,
    HASH = 306,
    PLUS = 307,
    MINUS = 308,
    STAR = 309,
    DIVIDE = 310,
    PTR_OP = 311,
    INC_OP = 312,
    DEC_OP = 313,
    RIGHT_OP = 314,
    LEFT_OP = 315,
    LESS_THAN = 316,
    GREATER_THAN = 317,
    LTE_OP = 318,
    GTE_OP = 319,
    EQ_OP = 320,
    NE_OP = 321,
    BITWISEOR = 322,
    OR_OP = 323,
    BITWISEAND = 324,
    AND_OP = 325,
    BITWISEXOR = 326,
    NOT = 327,
    EXCLAMATION = 328,
    ELLIPSIS = 329,
    PERCENTAGE = 330,
    EQ = 331,
    ENUMERATION_CONST = 332,
    ADD_ASSIGN = 333,
    SUB_ASSIGN = 334,
    MUL_ASSIGN = 335,
    DIV_ASSIGN = 336,
    MOD_ASSIGN = 337,
    LEFT_ASSIGN = 338,
    RIGHT_ASSIGN = 339,
    AND_ASSIGN = 340,
    OR_ASSIGN = 341,
    XOR_ASSIGN = 342,
    IDENTIFIER = 343,
    INTEGER_CONSTANT = 344,
    CHARACTER_CONSTANT = 345,
    FLOATING_CONSTANT = 346,
    STRING_LITERAL = 347
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 25 "ass5_21CS10016_21CS30050.y"

    int iVal;        // integer value
    char* cVal;     // char value
    float fVal;    // float value
    char unaryOp;       // This union defines different types of tokens with associated data types.
    int param_no;     // number of parameters
    int instruction_no;   // instruction number: for backpatching
    symboltype* symbol_type;   // symbol type
    sym* sym_ptr;          // sym_ptr
    Expression* expr;   // Expression
    Statement* stat;    // Statement
    Array* A;           // Array type

#line 243 "ass5_21CS10016_21CS30050.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_ASS5_21CS10016_21CS30050_TAB_H_INCLUDED  */



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
typedef yytype_int16 yy_state_t;

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
#define YYFINAL  54
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1311

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  94
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  85
/* YYNRULES -- Number of rules.  */
#define YYNRULES  239
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  422

#define YYUNDEFTOK  2
#define YYMAXUTOK   348


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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    89,    89,    97,   105,   115,   125,   131,   140,   152,
     185,   197,   202,   207,   219,   231,   236,   244,   251,   261,
     266,   274,   279,   286,   293,   338,   343,   351,   356,   361,
     366,   371,   376,   384,   389,   399,   415,   430,   444,   461,
     466,   480,   496,   501,   514,   530,   535,   552,   569,   586,
     606,   610,   631,   654,   658,   679,   683,   704,   708,   729,
     733,   751,   755,   772,   774,   793,   795,   818,   820,   822,
     824,   826,   828,   830,   832,   834,   836,   838,   843,   845,
     850,   855,   860,   861,   865,   867,   869,   871,   876,   877,
     881,   883,   888,   892,   902,   904,   906,   908,   913,   915,
     917,   919,   921,   923,   925,   927,   929,   931,   933,   935,
     937,   939,   944,   946,   951,   952,   956,   958,   960,   965,
     967,   972,   974,   979,   981,   986,   988,   992,   994,   996,
    1001,  1003,  1005,  1010,  1011,  1015,  1017,  1023,  1025,  1031,
    1033,  1035,  1040,  1045,  1056,  1062,  1068,  1069,  1070,  1071,
    1092,  1112,  1113,  1114,  1115,  1116,  1130,  1131,  1148,  1149,
    1154,  1158,  1165,  1167,  1172,  1174,  1179,  1181,  1186,  1188,
    1193,  1195,  1200,  1205,  1207,  1209,  1214,  1216,  1221,  1222,
    1226,  1231,  1233,  1238,  1240,  1245,  1247,  1249,  1254,  1256,
    1258,  1263,  1264,  1269,  1270,  1271,  1274,  1298,  1300,  1305,
    1313,  1315,  1323,  1325,  1330,  1332,  1337,  1339,  1344,  1356,
    1369,  1374,  1391,  1408,  1421,  1433,  1451,  1469,  1487,  1506,
    1536,  1543,  1550,  1559,  1571,  1573,  1578,  1580,  1585,  1604,
    1606,  1611,  1613,  1617,  1635,  1643,  1651,  1659,  1668,  1692
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "BREAK", "RETURN", "CASE", "FOR",
  "WHILE", "GOTO", "SIZEOF", "CONTINUE", "IF", "DO", "SWITCH", "ELSE",
  "FLOAT", "SHORT", "CHAR", "BOOL", "IMAGINARY", "COMPLEX", "INT",
  "DOUBLE", "LONG", "VOID", "SIGNED", "AUTO", "UNSIGNED", "ENUM", "UNION",
  "STRUCT", "TYPEDEF", "CONST", "DEFAULT", "STATIC", "REGISTER",
  "RESTRICT", "VOLATILE", "EXTERN", "INLINE", "SQR_BRACE_OPEN",
  "SQR_BRACE_CLOSE", "PARENTHESIS_OPEN", "PARENTHESIS_CLOSE",
  "CURLY_BRACE_OPEN", "CURLY_BRACE_CLOSE", "DOT", "QUESTION_MARK", "COLON",
  "SEMI_COLON", "COMMA", "HASH", "PLUS", "MINUS", "STAR", "DIVIDE",
  "PTR_OP", "INC_OP", "DEC_OP", "RIGHT_OP", "LEFT_OP", "LESS_THAN",
  "GREATER_THAN", "LTE_OP", "GTE_OP", "EQ_OP", "NE_OP", "BITWISEOR",
  "OR_OP", "BITWISEAND", "AND_OP", "BITWISEXOR", "NOT", "EXCLAMATION",
  "ELLIPSIS", "PERCENTAGE", "EQ", "ENUMERATION_CONST", "ADD_ASSIGN",
  "SUB_ASSIGN", "MUL_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN", "LEFT_ASSIGN",
  "RIGHT_ASSIGN", "AND_ASSIGN", "OR_ASSIGN", "XOR_ASSIGN", "IDENTIFIER",
  "INTEGER_CONSTANT", "CHARACTER_CONSTANT", "FLOATING_CONSTANT",
  "STRING_LITERAL", "\"then\"", "$accept", "constant",
  "primary_expression", "postfix_expression", "argument_expression_list",
  "argument_expression_list_opt", "unary_expression", "unary_operator",
  "cast_expression", "multiplicative_expression", "additive_expression",
  "shift_expression", "relational_expression", "equality_expression",
  "and_expression", "exclusive_or_expression", "inclusive_or_expression",
  "logical_and_expression", "logical_or_expression",
  "conditional_expression", "assignment_expression", "assignment_operator",
  "expression", "constant_expression", "declaration",
  "init_declarator_list_opt", "declaration_specifiers",
  "declaration_specifiers_opt", "init_declarator_list", "init_declarator",
  "storage_class_specifier", "type_specifier", "specifier_qualifier_list",
  "specifier_qualifier_list_opt", "struct_or_union_specifier",
  "struct_or_union", "struct_declaration_list", "struct_declaration",
  "struct_declarator_list", "struct_declarator", "enum_specifier",
  "identifier_opt", "enumerator_list", "enumerator", "type_qualifier",
  "function_specifier", "declarator", "direct_declarator",
  "type_qualifier_list_opt", "pointer", "type_qualifier_list",
  "parameter_type_list", "parameter_list", "parameter_declaration",
  "identifier_list", "type_name", "initializer", "initializer_list",
  "designation_opt", "designation", "designator_list", "designator",
  "statement", "loop_statement", "labeled_statement", "compound_statement",
  "block_item_list", "block_item_list_opt", "block_item",
  "expression_statement", "selection_statement", "iteration_statement",
  "jump_statement", "translation_unit", "external_declaration",
  "function_definition", "declaration_list_opt", "declaration_list",
  "changetable", "M", "F", "W", "D", "X", "N", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348
};
# endif

#define YYPACT_NINF (-358)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-231)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1249,  -358,  -358,  -358,  -358,  -358,  -358,  -358,  -358,  -358,
    -358,  -358,  -358,  -358,   -19,  -358,  -358,  -358,  -358,  -358,
    -358,  -358,  -358,  -358,  -358,    33,  1249,  1249,  -358,     6,
    -358,  1249,  1249,  1131,  -358,  -358,    44,    61,    33,   160,
    -358,   -21,    27,  -358,  1068,    93,   -24,  -358,  -358,  -358,
    1274,    64,  -358,  -358,  -358,  -358,    28,   143,  -358,   109,
     160,  -358,    33,   579,  -358,    33,  -358,  1249,   775,   113,
      93,  1274,   120,  1158,  -358,  1274,  1274,   131,   130,  -358,
    -358,  -358,  -358,  -358,   141,   941,   746,    13,  -358,  -358,
    -358,   966,   966,  -358,  -358,  -358,  -358,  -358,  -358,  -358,
    -358,  -358,   192,   324,   991,  -358,   112,   119,   182,   199,
     205,   151,   186,   213,   212,    72,  -358,  -358,  -358,   243,
    -358,   788,  -358,   252,   254,   817,  -358,     4,  1220,  -358,
    -358,   991,  -358,   224,  -358,   253,  -358,  -358,  -358,  1189,
     991,  -358,   -23,   746,  -358,  -358,    84,  -358,   257,   991,
     214,   195,   579,  -358,    60,  -358,   746,  -358,  -358,   991,
     991,   215,   218,  -358,  -358,  -358,  -358,  -358,  -358,  -358,
    -358,  -358,  -358,  -358,  -358,  -358,   991,  -358,  -358,   991,
     991,   991,   991,   991,   991,   991,   991,   991,   991,   991,
     991,   991,   991,   991,   991,  -358,   991,  -358,   308,   266,
     788,  -358,  -358,  -358,   267,   269,  -358,   234,  -358,    33,
     296,   298,  -358,  -358,  -358,  -358,   -16,   991,  -358,  -358,
    -358,  -358,   306,  -358,   991,   841,   310,  -358,  -358,   191,
    -358,  -358,  -358,   311,     1,   303,   312,  -358,  -358,  -358,
    -358,  -358,  -358,  -358,   112,   112,   119,   119,   182,   182,
     182,   182,   199,   199,   205,   151,   186,   991,    -5,   991,
     307,   891,   991,  -358,  -358,   270,   314,   317,  -358,   325,
     320,  -358,  -358,   321,   226,  -358,  -358,  -358,  -358,   326,
     327,  -358,  -358,  -358,  -358,  -358,  -358,   329,  -358,  -358,
    -358,  -358,  -358,  1098,  -358,  -358,   330,  -358,    13,  -358,
    -358,  -358,   579,   330,  -358,   991,  -358,   213,   991,   212,
    -358,  -358,   229,   328,   331,   333,   344,  -358,   991,   334,
     991,   379,  -358,  -358,  -358,   308,  -358,  -358,  -358,  -358,
     206,  -358,  -358,  -358,  -358,   379,  -358,  -358,  -358,   345,
    -358,   592,    89,  -358,   308,   379,  -358,  -358,   207,  -358,
    -358,  -358,   336,   308,  -358,  -358,  -358,  -358,  -358,  -358,
     379,   349,  -358,  -358,   669,  -358,  -358,   356,   406,  -358,
    -358,  -358,  -358,   991,   379,  -358,   372,   916,   916,   127,
    -358,   408,   991,  -358,  -358,   373,   402,   376,   172,   991,
     991,  -358,   592,  -358,   991,   370,   345,   345,   308,  -358,
     379,   175,  -358,   377,   381,   380,  -358,   378,  -358,  -358,
    -358,  -358,   450,   521,   308,  -358,   308,  -358,   384,   385,
    -358,  -358
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,   103,   100,    99,   107,   109,   108,   101,   104,   102,
      98,   105,    96,   106,   134,   120,   119,   139,    95,    97,
     140,   141,    94,   142,   227,    83,    89,    89,   111,     0,
     110,    89,    89,     0,   224,   226,   132,     0,     0,   159,
     145,     0,    82,    90,    92,   144,     0,    88,    84,    85,
       0,   118,    86,    87,     1,   225,     0,     0,   162,   160,
     158,    81,     0,     0,   231,    83,   233,   229,     0,   233,
     143,   115,     0,     0,   121,   115,     0,   137,     0,   135,
     146,   161,   163,    91,    92,     0,     0,   179,    29,    30,
      28,     0,     0,    27,    31,    32,     5,     2,     4,     3,
       6,     8,    21,    33,     0,    35,    39,    42,    45,    50,
      53,    55,    57,    59,    61,    63,    65,   173,    93,     0,
     232,     0,   150,    28,     0,     0,   170,     0,     0,   114,
     112,     0,   123,     0,   125,   129,   116,   122,   113,     0,
       0,   130,     0,     0,    25,    78,     0,   172,     0,     0,
       0,     0,     0,   178,     0,   181,     0,    22,    23,     0,
      20,     0,     0,    13,    14,    67,    71,    72,    68,    69,
      70,    73,    74,    75,    77,    76,     0,    33,    24,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   234,     0,   234,   203,     0,
       0,   154,   149,   148,    28,     0,   156,     0,   157,   169,
       0,   164,   166,    80,   127,   124,     0,     0,   117,   138,
     131,   136,     0,     7,     0,     0,     0,   184,   174,   179,
     176,   180,   182,     0,     0,    19,     0,    17,    11,    12,
      66,    36,    37,    38,    40,    41,    44,    43,    46,    47,
      48,    49,    51,    52,    54,    56,    58,     0,     0,     0,
       0,     0,     0,   235,   236,     0,     0,     0,   237,     0,
       0,   238,   206,     5,     0,   204,   205,   185,   186,   234,
       0,   200,   187,   188,   189,   190,   152,     0,   153,   147,
     171,   168,   155,     0,   126,   128,    26,    79,   179,    34,
     183,   175,     0,     0,     9,     0,    10,    60,     0,    62,
     221,   223,     0,     0,     0,     0,     0,   220,     0,   234,
       0,     0,   233,   234,   207,     0,   228,   151,   165,   167,
       0,   177,    18,    64,   222,     0,   238,   238,   219,   239,
     234,     0,     0,   198,   203,     0,   201,    15,   179,   197,
     233,   233,     0,   203,   234,   191,   192,   193,   194,   195,
       0,     0,   196,    16,     0,   234,   234,     0,     0,   210,
     199,   234,   234,     0,     0,   234,     0,     0,     0,     0,
     239,     0,     0,   234,   234,   234,   208,     0,     0,     0,
       0,   234,     0,   234,     0,     0,   239,   239,   203,   211,
       0,     0,   213,     0,     0,     0,   209,     0,   234,   234,
     212,   214,     0,     0,   203,   215,   203,   216,     0,     0,
     217,   218
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -358,  -358,  -358,  -358,  -358,  -358,   -36,  -358,   -99,   103,
     105,    80,   101,   230,   233,   240,   178,   179,  -358,  -125,
     -59,  -358,   -85,  -132,     0,  -358,     3,   227,  -358,   382,
    -358,   138,   -34,   364,  -358,  -358,   365,   -60,  -358,   231,
    -358,  -358,  -358,   300,    39,  -358,   -11,   394,  -358,   386,
     -48,  -358,  -358,   150,  -358,    63,  -141,   148,  -219,  -358,
    -358,   295,  -314,  -289,  -329,  -358,  -358,  -296,   125,  -148,
    -322,  -316,  -213,  -358,   431,  -358,  -358,  -358,   -67,  -181,
    -358,  -358,  -358,   -38,  -357
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,   100,   101,   102,   235,   236,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     145,   176,   274,   214,   275,    41,    65,    48,    42,    43,
      26,    27,    72,   130,    28,    29,    73,    74,   133,   134,
      30,    37,    78,    79,    31,    32,    84,    45,    59,    46,
      60,   210,   211,   212,   127,   148,   118,   151,   152,   153,
     154,   155,   276,   354,   277,   278,   279,   280,   281,   282,
     283,   284,   285,    33,    34,    35,    66,    67,   119,   257,
     314,   315,   319,   322,   352
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      24,   146,   128,    25,   117,   178,   213,   343,   219,   124,
     302,   230,   355,   137,    44,   213,   259,   226,    38,   357,
     125,   349,   220,   386,   213,   358,    38,    57,    61,    47,
      47,   362,   131,    24,    47,    47,    25,   129,    39,   403,
     404,   129,   304,   308,    64,   224,   369,   206,   361,   144,
      50,   224,   147,   149,   207,   157,   158,   367,   146,   150,
     380,   135,   199,   355,    40,    77,   205,   120,   177,    36,
     357,   146,    40,   200,   234,    38,   358,    62,    58,   137,
     241,   242,   243,   355,   355,   295,   406,    39,  -133,    75,
     357,   357,   213,   117,    51,   177,   358,   358,   325,    82,
     149,   237,   405,   399,   177,    56,   150,    58,    76,   147,
      75,   258,    75,   177,    75,    75,    77,   240,   418,   196,
     419,    40,   147,   415,   417,    75,   299,   223,   359,   302,
     313,   209,   360,    68,   224,    69,   231,   213,   341,   224,
     197,   287,   345,   177,   177,   177,   177,   177,   177,   177,
     177,   177,   177,   177,   177,   177,   177,   177,   177,   353,
      58,   331,    38,    39,    82,   297,   179,   180,   131,   132,
     385,   182,   183,   368,    39,   141,   312,   224,    75,   359,
     142,   177,    75,   333,   373,   374,    80,   181,    71,   177,
     377,   378,    17,   356,   381,    75,    20,    21,   291,   359,
     359,   126,   389,   390,   392,   135,   222,   140,    40,    71,
     398,    71,   400,    71,    71,   395,   372,    63,   407,   233,
     192,   177,   224,   177,    71,   224,   177,   412,   413,   383,
     384,   149,   159,   339,   160,   342,   301,   150,   161,    82,
     228,   184,   185,   117,   356,   229,   332,   149,   162,   163,
     164,   347,   363,   150,    49,   344,   348,   193,    52,    53,
     186,   187,   188,   189,   356,   356,   248,   249,   250,   251,
     190,   191,   177,   215,   216,   324,   224,    71,   334,   224,
     194,    71,   195,   364,   365,   244,   245,   198,   379,   246,
     247,   252,   253,   201,    71,   202,   209,   388,   350,   351,
     225,   217,   227,   238,   396,   397,   239,   286,   288,   401,
     289,   260,   261,   262,   263,   264,   265,    85,   266,   267,
     268,   269,   290,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,   292,
      17,   270,    18,    19,    20,    21,    22,    23,   293,   296,
      86,   300,   271,   305,   303,   306,   310,   272,   316,   318,
      88,    89,    90,   317,   371,    91,    92,   320,   321,   323,
     327,  -202,   326,   336,   298,   337,   335,    93,   340,   366,
      94,    95,   260,   261,   262,   263,   264,   265,    85,   266,
     267,   268,   269,   338,   370,   224,   273,    97,    98,    99,
     165,   375,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   270,   376,   382,   387,   393,   391,   394,   402,
     408,    86,   254,   271,   409,   410,   255,   411,   272,   420,
     421,    88,    89,    90,   256,   307,    91,    92,   309,   138,
      70,   139,   221,   329,    83,    81,   330,   294,    93,   232,
     346,    94,    95,   260,   261,   262,   263,   264,   265,    85,
     266,   267,   268,   269,    55,     0,     0,   273,    97,    98,
      99,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   270,     0,     0,     0,     0,     0,     0,
       0,     0,    86,     0,   414,     0,     0,     0,     0,   272,
       0,     0,    88,    89,    90,     0,     0,    91,    92,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    93,
       0,     0,    94,    95,   260,   261,   262,   263,   264,   265,
      85,   266,   267,   268,   269,     0,     0,     0,   273,    97,
      98,    99,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   270,     0,     0,     0,     0,     0,
       0,     0,     0,    86,     0,   416,     0,     0,     0,     0,
     272,     0,     0,    88,    89,    90,     0,     0,    91,    92,
       0,     0,     0,     0,     0,     0,     0,     0,    85,     0,
      93,     0,     0,    94,    95,   260,   261,   262,   263,   264,
     265,    85,   266,   267,   268,   269,     0,     0,     0,   273,
      97,    98,    99,     0,     0,     0,     0,     0,     0,     0,
       0,    86,     0,    87,     0,   270,     0,     0,     0,     0,
       0,    88,    89,    90,    86,     0,    91,    92,     0,     0,
       0,   272,     0,     0,    88,    89,    90,     0,    93,    91,
      92,    94,    95,     0,     0,     0,     0,     0,     0,     0,
       0,    93,     0,     0,    94,    95,     0,    96,    97,    98,
      99,     0,     0,     0,     0,     0,     0,     0,    85,     0,
     273,    97,    98,    99,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
       0,    17,     0,    18,    19,    20,    21,    22,    23,     0,
       0,    86,     0,     0,     0,     0,     0,     0,   272,     0,
       0,    88,    89,    90,     0,     0,    91,    92,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    93,     0,
       0,    94,    95,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    85,     0,    96,    97,    98,
      99,     1,     2,     3,     4,     5,     6,     7,     8,     9,
      10,    11,     0,    13,    14,    15,    16,     0,    17,     0,
       0,     0,    20,    21,    85,     0,     0,     0,    86,     0,
       0,     0,     0,     0,     0,     0,     0,    85,    88,    89,
      90,     0,     0,    91,    92,     0,     0,    17,     0,   121,
       0,    20,    21,     0,     0,    93,   122,    86,    94,    95,
      17,     0,     0,     0,    20,    21,    85,    88,    89,   123,
      86,     0,    91,    92,    96,    97,    98,    99,     0,     0,
      88,    89,    90,     0,    93,    91,    92,    94,    95,    17,
      85,     0,     0,    20,    21,     0,     0,    93,   203,    86,
      94,    95,     0,    96,    97,    98,    99,     0,     0,    88,
      89,   204,     0,     0,    91,    92,    96,    97,    98,    99,
       0,     0,     0,    86,     0,   298,    93,     0,     0,    94,
      95,     0,     0,    88,    89,    90,     0,     0,    91,    92,
      85,     0,     0,     0,     0,    96,    97,    98,    99,     0,
      93,     0,     0,    94,    95,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    85,     0,     0,     0,    96,
      97,    98,    99,    86,     0,     0,     0,     0,     0,     0,
     311,     0,     0,    88,    89,    90,     0,     0,    91,    92,
      85,     0,     0,     0,     0,     0,     0,     0,    86,     0,
      93,     0,     0,    94,    95,   272,     0,     0,    88,    89,
      90,     0,     0,    91,    92,    85,     0,     0,     0,    96,
      97,    98,    99,   143,     0,    93,     0,     0,    94,    95,
       0,     0,     0,    88,    89,    90,     0,     0,    91,    92,
      85,     0,     0,     0,    96,    97,    98,    99,   156,     0,
      93,     0,     0,    94,    95,     0,     0,     0,    88,    89,
      90,     0,     0,    91,    92,     0,     0,     0,     0,    96,
      97,    98,    99,    86,     0,    93,     0,     0,    94,    95,
       0,     0,     0,    88,    89,    90,     0,     0,    91,    92,
       0,     0,     0,     0,    96,    97,    98,    99,     0,     0,
      93,     0,     0,    94,    95,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    96,
      97,    98,    99,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,     0,
      17,     0,    18,    19,    20,    21,    22,    23,     0,     0,
       0,     0,  -230,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,     0,
      17,    54,    18,    19,    20,    21,    22,    23,     0,     0,
       0,     0,     0,     0,    63,     0,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,     0,    17,     0,    18,    19,    20,    21,    22,
      23,     0,   328,     1,     2,     3,     4,     5,     6,     7,
       8,     9,    10,    11,     0,    13,    14,    15,    16,     0,
      17,     0,     0,     0,    20,    21,     0,     0,     0,     0,
       0,     0,     0,   136,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,     0,    13,    14,    15,    16,
       0,    17,     0,     0,     0,    20,    21,     0,     0,     0,
       0,     0,     0,     0,   218,     1,     2,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,     0,    17,     0,    18,    19,    20,    21,    22,    23,
       0,     0,     0,   208,     1,     2,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
       0,    17,     0,    18,    19,    20,    21,    22,    23,     1,
       2,     3,     4,     5,     6,     7,     8,     9,    10,    11,
       0,    13,    14,    15,    16,     0,    17,     0,     0,     0,
      20,    21
};

static const yytype_int16 yycheck[] =
{
       0,    86,    69,     0,    63,   104,   131,   321,   140,    68,
     229,   152,   341,    73,    25,   140,   197,   149,    42,   341,
      68,   335,    45,   380,   149,   341,    42,    38,    49,    26,
      27,   345,    48,    33,    31,    32,    33,    71,    54,   396,
     397,    75,    41,    48,    44,    50,   360,    43,   344,    85,
      44,    50,    86,    40,    50,    91,    92,   353,   143,    46,
     374,    72,   121,   392,    88,    88,   125,    67,   104,    88,
     392,   156,    88,   121,   159,    42,   392,    50,    39,   139,
     179,   180,   181,   412,   413,   217,   400,    54,    44,    50,
     412,   413,   217,   152,    88,   131,   412,   413,   279,    60,
      40,   160,   398,   392,   140,    44,    46,    68,    44,   143,
      71,   196,    73,   149,    75,    76,    88,   176,   414,    47,
     416,    88,   156,   412,   413,    86,   225,    43,   341,   348,
     262,   128,    43,    40,    50,    42,    76,   262,   319,    50,
      68,   200,   323,   179,   180,   181,   182,   183,   184,   185,
     186,   187,   188,   189,   190,   191,   192,   193,   194,   340,
     121,   302,    42,    54,   125,   224,    54,    55,    48,    49,
      43,    52,    53,   354,    54,    45,   261,    50,   139,   392,
      50,   217,   143,   308,   365,   366,    43,    75,    50,   225,
     371,   372,    32,   341,   375,   156,    36,    37,   209,   412,
     413,    88,   383,   384,   385,   216,   143,    76,    88,    71,
     391,    73,   393,    75,    76,    43,   364,    76,    43,   156,
      69,   257,    50,   259,    86,    50,   262,   408,   409,   377,
     378,    40,    40,   318,    42,   320,    45,    46,    46,   200,
      45,    59,    60,   302,   392,    50,   305,    40,    56,    57,
      58,    45,    45,    46,    27,   322,    50,    71,    31,    32,
      61,    62,    63,    64,   412,   413,   186,   187,   188,   189,
      65,    66,   308,    49,    50,    49,    50,   139,    49,    50,
      67,   143,    70,   350,   351,   182,   183,    44,   373,   184,
     185,   190,   191,    41,   156,    41,   293,   382,   336,   337,
      43,    48,    88,    88,   389,   390,    88,    41,    41,   394,
      41,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    88,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    43,
      32,    33,    34,    35,    36,    37,    38,    39,    50,    43,
      42,    41,    44,    50,    43,    43,    49,    49,    88,    42,
      52,    53,    54,    49,   364,    57,    58,    42,    48,    48,
      41,    45,    45,    42,    44,    42,    48,    69,    44,    43,
      72,    73,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    49,    45,    50,    88,    89,    90,    91,
      76,    45,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    33,     7,    42,     7,    14,    44,    42,    49,
      43,    42,   192,    44,    43,    45,   193,    49,    49,    45,
      45,    52,    53,    54,   194,   257,    57,    58,   259,    75,
      46,    76,   142,   293,    62,    59,   298,   216,    69,   154,
     325,    72,    73,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    33,    -1,    -1,    88,    89,    90,
      91,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    33,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    -1,    44,    -1,    -1,    -1,    -1,    49,
      -1,    -1,    52,    53,    54,    -1,    -1,    57,    58,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,
      -1,    -1,    72,    73,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    -1,    -1,    -1,    88,    89,
      90,    91,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    33,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    -1,    44,    -1,    -1,    -1,    -1,
      49,    -1,    -1,    52,    53,    54,    -1,    -1,    57,    58,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,    -1,
      69,    -1,    -1,    72,    73,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    -1,    -1,    -1,    88,
      89,    90,    91,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    -1,    44,    -1,    33,    -1,    -1,    -1,    -1,
      -1,    52,    53,    54,    42,    -1,    57,    58,    -1,    -1,
      -1,    49,    -1,    -1,    52,    53,    54,    -1,    69,    57,
      58,    72,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    -1,    -1,    72,    73,    -1,    88,    89,    90,
      91,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,    -1,
      88,    89,    90,    91,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      -1,    32,    -1,    34,    35,    36,    37,    38,    39,    -1,
      -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,
      -1,    52,    53,    54,    -1,    -1,    57,    58,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    69,    -1,
      -1,    72,    73,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     9,    -1,    88,    89,    90,
      91,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    -1,    27,    28,    29,    30,    -1,    32,    -1,
      -1,    -1,    36,    37,     9,    -1,    -1,    -1,    42,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     9,    52,    53,
      54,    -1,    -1,    57,    58,    -1,    -1,    32,    -1,    34,
      -1,    36,    37,    -1,    -1,    69,    41,    42,    72,    73,
      32,    -1,    -1,    -1,    36,    37,     9,    52,    53,    54,
      42,    -1,    57,    58,    88,    89,    90,    91,    -1,    -1,
      52,    53,    54,    -1,    69,    57,    58,    72,    73,    32,
       9,    -1,    -1,    36,    37,    -1,    -1,    69,    41,    42,
      72,    73,    -1,    88,    89,    90,    91,    -1,    -1,    52,
      53,    54,    -1,    -1,    57,    58,    88,    89,    90,    91,
      -1,    -1,    -1,    42,    -1,    44,    69,    -1,    -1,    72,
      73,    -1,    -1,    52,    53,    54,    -1,    -1,    57,    58,
       9,    -1,    -1,    -1,    -1,    88,    89,    90,    91,    -1,
      69,    -1,    -1,    72,    73,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     9,    -1,    -1,    -1,    88,
      89,    90,    91,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      49,    -1,    -1,    52,    53,    54,    -1,    -1,    57,    58,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    -1,
      69,    -1,    -1,    72,    73,    49,    -1,    -1,    52,    53,
      54,    -1,    -1,    57,    58,     9,    -1,    -1,    -1,    88,
      89,    90,    91,    42,    -1,    69,    -1,    -1,    72,    73,
      -1,    -1,    -1,    52,    53,    54,    -1,    -1,    57,    58,
       9,    -1,    -1,    -1,    88,    89,    90,    91,    42,    -1,
      69,    -1,    -1,    72,    73,    -1,    -1,    -1,    52,    53,
      54,    -1,    -1,    57,    58,    -1,    -1,    -1,    -1,    88,
      89,    90,    91,    42,    -1,    69,    -1,    -1,    72,    73,
      -1,    -1,    -1,    52,    53,    54,    -1,    -1,    57,    58,
      -1,    -1,    -1,    -1,    88,    89,    90,    91,    -1,    -1,
      69,    -1,    -1,    72,    73,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    88,
      89,    90,    91,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    -1,
      32,    -1,    34,    35,    36,    37,    38,    39,    -1,    -1,
      -1,    -1,    44,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    -1,
      32,     0,    34,    35,    36,    37,    38,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    76,    -1,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    -1,    32,    -1,    34,    35,    36,    37,    38,
      39,    -1,    74,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    -1,    27,    28,    29,    30,    -1,
      32,    -1,    -1,    -1,    36,    37,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    45,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    -1,    27,    28,    29,    30,
      -1,    32,    -1,    -1,    -1,    36,    37,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    45,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    -1,    32,    -1,    34,    35,    36,    37,    38,    39,
      -1,    -1,    -1,    43,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      -1,    32,    -1,    34,    35,    36,    37,    38,    39,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      -1,    27,    28,    29,    30,    -1,    32,    -1,    -1,    -1,
      36,    37
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    32,    34,    35,
      36,    37,    38,    39,   118,   120,   124,   125,   128,   129,
     134,   138,   139,   167,   168,   169,    88,   135,    42,    54,
      88,   119,   122,   123,   140,   141,   143,   120,   121,   121,
      44,    88,   121,   121,     0,   168,    44,   140,   138,   142,
     144,    49,    50,    76,   118,   120,   170,   171,    40,    42,
     141,   125,   126,   130,   131,   138,    44,    88,   136,   137,
      43,   143,   138,   123,   140,     9,    42,    44,    52,    53,
      54,    57,    58,    69,    72,    73,    88,    89,    90,    91,
      95,    96,    97,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   150,   172,
     118,    34,    41,    54,   114,   144,    88,   148,   172,   126,
     127,    48,    49,   132,   133,   140,    45,   131,   127,   130,
      76,    45,    50,    42,   100,   114,   116,   126,   149,    40,
      46,   151,   152,   153,   154,   155,    42,   100,   100,    40,
      42,    46,    56,    57,    58,    76,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,   115,   100,   102,    54,
      55,    75,    52,    53,    59,    60,    61,    62,    63,    64,
      65,    66,    69,    71,    67,    70,    47,    68,    44,   114,
     144,    41,    41,    41,    54,   114,    43,    50,    43,   120,
     145,   146,   147,   113,   117,    49,    50,    48,    45,   117,
      45,   137,   149,    43,    50,    43,   117,    88,    45,    50,
     150,    76,   155,   149,   116,    98,    99,   114,    88,    88,
     114,   102,   102,   102,   103,   103,   104,   104,   105,   105,
     105,   105,   106,   106,   107,   108,   109,   173,   116,   173,
       3,     4,     5,     6,     7,     8,    10,    11,    12,    13,
      33,    44,    49,    88,   116,   118,   156,   158,   159,   160,
     161,   162,   163,   164,   165,   166,    41,   114,    41,    41,
      88,   140,    43,    50,   133,   117,    43,   114,    44,   102,
      41,    45,   152,    43,    41,    50,    43,   110,    48,   111,
      49,    49,   116,   117,   174,   175,    88,    49,    42,   176,
      42,    48,   177,    48,    49,   173,    45,    41,    74,   147,
     151,   150,   114,   113,    49,    48,    42,    42,    49,   116,
      44,   173,   116,   156,   172,   173,   162,    45,    50,   156,
     177,   177,   178,   173,   157,   158,   163,   164,   165,   166,
      43,   161,   156,    45,   172,   172,    43,   161,   173,   156,
      45,   118,   163,   173,   173,    45,     7,   173,   173,   116,
     156,   173,    42,   163,   163,    43,   178,     7,   116,   173,
     173,    44,   173,    14,    42,    43,   116,   116,   173,   157,
     173,   116,    49,   178,   178,   161,   156,    43,    43,    43,
      45,    49,   173,   173,    44,   157,    44,   157,   161,   161,
      45,    45
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    94,    95,    95,    95,    96,    96,    96,    97,    97,
      97,    97,    97,    97,    97,    97,    97,    98,    98,    99,
      99,   100,   100,   100,   100,   100,   100,   101,   101,   101,
     101,   101,   101,   102,   102,   103,   103,   103,   103,   104,
     104,   104,   105,   105,   105,   106,   106,   106,   106,   106,
     107,   107,   107,   108,   108,   109,   109,   110,   110,   111,
     111,   112,   112,   113,   113,   114,   114,   115,   115,   115,
     115,   115,   115,   115,   115,   115,   115,   115,   116,   116,
     117,   118,   119,   119,   120,   120,   120,   120,   121,   121,
     122,   122,   123,   123,   124,   124,   124,   124,   125,   125,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   125,   126,   126,   127,   127,   128,   128,   128,   129,
     129,   130,   130,   131,   131,   132,   132,   133,   133,   133,
     134,   134,   134,   135,   135,   136,   136,   137,   137,   138,
     138,   138,   139,   140,   140,   141,   141,   141,   141,   141,
     141,   141,   141,   141,   141,   141,   141,   141,   142,   142,
     143,   143,   144,   144,   145,   145,   146,   146,   147,   147,
     148,   148,   149,   150,   150,   150,   151,   151,   152,   152,
     153,   154,   154,   155,   155,   156,   156,   156,   156,   156,
     156,   157,   157,   157,   157,   157,   158,   158,   158,   159,
     160,   160,   161,   161,   162,   162,   163,   163,   164,   164,
     164,   165,   165,   165,   165,   165,   165,   165,   165,   166,
     166,   166,   166,   166,   167,   167,   168,   168,   169,   170,
     170,   171,   171,   172,   173,   174,   175,   176,   177,   178
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     1,     1,     1,     3,     1,     4,
       4,     3,     3,     2,     2,     6,     7,     1,     3,     1,
       0,     1,     2,     2,     2,     2,     4,     1,     1,     1,
       1,     1,     1,     1,     4,     1,     3,     3,     3,     1,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       1,     3,     3,     1,     3,     1,     3,     1,     3,     1,
       4,     1,     4,     1,     5,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     3,     1,     0,     2,     2,     2,     2,     1,     0,
       1,     3,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     1,     0,     4,     5,     2,     1,
       1,     1,     2,     2,     3,     1,     3,     2,     3,     1,
       5,     6,     2,     1,     0,     1,     3,     1,     3,     1,
       1,     1,     1,     2,     1,     1,     3,     5,     4,     4,
       3,     6,     5,     5,     4,     5,     4,     4,     1,     0,
       2,     3,     1,     2,     1,     3,     1,     3,     2,     1,
       1,     3,     1,     1,     3,     4,     2,     4,     1,     0,
       2,     1,     2,     3,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     4,     4,     3,     5,
       1,     3,     1,     0,     1,     1,     1,     2,     8,    11,
       5,    10,    12,    10,    12,    14,    14,    16,    16,     3,
       2,     2,     3,     2,     1,     2,     1,     1,     7,     1,
       0,     1,     2,     0,     0,     0,     0,     0,     0,     0
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
#line 90 "ass5_21CS10016_21CS30050.y"
    { 
        // This rule defines how to handle integer constants.
        (yyval.expr) = new Expression();  // Create a new Expression instance.
        string temp = INT2STRING((yyvsp[0].iVal));  // Convert the constant to a string.
        (yyval.expr)->loc = gentemp(new symboltype("int"), temp);  // Create a temporary variable.
        Q.emit("=", (yyval.expr)->loc->name, temp);  // Emit an assignment in the intermediate code.
    }
#line 1943 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 3:
#line 98 "ass5_21CS10016_21CS30050.y"
    {                                                                         
        // This rule defines how to handle floating-point constants.
        (yyval.expr) = new Expression();  // Create a new Expression instance.
        string temp = FLT2STRING((yyvsp[0].fVal));  // Convert the constant to a string.
        (yyval.expr)->loc = gentemp(new symboltype("float"), temp);  // Create a temporary variable.
        Q.emit("=", (yyval.expr)->loc->name, temp);  // Emit an assignment in the intermediate code.
    }
#line 1955 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 4:
#line 106 "ass5_21CS10016_21CS30050.y"
    {                                                                        
        // This rule defines how to handle character constants.
        (yyval.expr) = new Expression();  // Create a new Expression instance.
        (yyval.expr)->loc = gentemp(new symboltype("char"), (yyvsp[0].cVal));  // Create a temporary variable.
        Q.emit("=", (yyval.expr)->loc->name, string((yyvsp[0].cVal)));  // Emit an assignment in the intermediate code.
    }
#line 1966 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 5:
#line 116 "ass5_21CS10016_21CS30050.y"
    {
        // This rule handles an identifier as a primary expression.
        // Create a new Expression instance and assign it to the result ($$).
        (yyval.expr) = new Expression();
        // Store the identifier in the expression's 'loc' field.
        (yyval.expr)->loc = (yyvsp[0].sym_ptr);
        // Mark the type as "not-boolean" for the primary expression.
        (yyval.expr)->type = "not-boolean";
    }
#line 1980 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 6:
#line 126 "ass5_21CS10016_21CS30050.y"
    {
        // This case handles a constant as a primary expression.
        // Assign the constant to the result ($$).
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 1990 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 7:
#line 132 "ass5_21CS10016_21CS30050.y"
    {
        // This rule handles an expression enclosed in parentheses.
        // The result is the expression itself.
        (yyval.expr) = (yyvsp[-1].expr);
    }
#line 2000 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 8:
#line 141 "ass5_21CS10016_21CS30050.y"
    {
        // This rule deals with a primary expression in postfix.
        // Create a new Array instance and assign it to the result ($$).
        (yyval.A) = new Array();
        // Assign the primary expression's 'loc' to the Array's 'Array' field.
        (yyval.A)->Array = (yyvsp[0].expr)->loc;
        // Copy the type of the primary expression to the Array's type.
        (yyval.A)->type = (yyvsp[0].expr)->loc->type;
        // Set the location of the Array to the primary expression.
        (yyval.A)->loc = (yyval.A)->Array;
    }
#line 2016 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 9:
#line 153 "ass5_21CS10016_21CS30050.y"
    {
        // This rule handles postfix expressions with square brackets (arrays).
        // Create a new Array instance and assign it to the result ($$).
        (yyval.A) = new Array();
        // Set the type of the Array to the array type of the previous expression.
        (yyval.A)->type = (yyvsp[-3].A)->type->arrtype;
        // Copy the 'Array' field from the previous expression to the new Array.
        (yyval.A)->Array = (yyvsp[-3].A)->Array;
        // Generate a temporary location for the Array's location.
        (yyval.A)->loc = gentemp(new symboltype("int"));
        // Set the Array type as 'arr'.
        (yyval.A)->atype = "arr";

        // Recursive definition for arrays is crucial.
        if ((yyvsp[-3].A)->atype == "arr") {
            // Generate a temporary symbol for array size computation.
            sym* t = gentemp(new symboltype("int"));
            // Compute the size of the array type.
            int temp = computeSize((yyval.A)->type);
            string str = INT2STRING(temp);
            // Emit code to multiply and add for array indexing.
            Q.emit("*", t->name, (yyvsp[-1].expr)->loc->name, str);
            Q.emit("+", (yyval.A)->loc->name, (yyvsp[-3].A)->loc->name, t->name);
        }
        else {
            // Compute the size of the array type.
            int temp = computeSize((yyval.A)->type);
            string str = INT2STRING(temp);
            // Emit code to multiply for array indexing.
            Q.emit("*", (yyval.A)->loc->name, (yyvsp[-1].expr)->loc->name, str);
        }
    }
#line 2053 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 10:
#line 186 "ass5_21CS10016_21CS30050.y"
    {
        // This handles function calls with a variable number of arguments.
        // Create a new Array instance and assign it to the result ($$).
        (yyval.A) = new Array();
        // Generate a temporary location for the Array.
        (yyval.A)->Array = gentemp((yyvsp[-3].A)->type);
        // Convert the number of arguments to a string.
        string str = INT2STRING((yyvsp[-1].param_no));
        // Emit a function call with the arguments.
        Q.emit("call", (yyval.A)->Array->name, (yyvsp[-3].A)->Array->name, str);
    }
#line 2069 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 11:
#line 198 "ass5_21CS10016_21CS30050.y"
    {
        // Handle the dot operator with an identifier (struct member access).
        // No action needed.
    }
#line 2078 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 12:
#line 203 "ass5_21CS10016_21CS30050.y"
    {
        // Handle the pointer operator with an identifier (member access via pointer).
        // No action needed.
    }
#line 2087 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 13:
#line 208 "ass5_21CS10016_21CS30050.y"
    {
        // This handles the increment operator '++'.
        // Create a new Array instance and assign it to the result ($$).
        (yyval.A) = new Array();
        // Generate a temporary location for the Array.
        (yyval.A)->Array = gentemp((yyvsp[-1].A)->Array->type);
        // Emit code to copy the previous expression to the result.
        Q.emit("=", (yyval.A)->Array->name, (yyvsp[-1].A)->Array->name);
        // Emit code to increment the previous expression by 1.
        Q.emit("+", (yyvsp[-1].A)->Array->name, (yyvsp[-1].A)->Array->name, "1");
    }
#line 2103 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 14:
#line 220 "ass5_21CS10016_21CS30050.y"
    {
        // This handles the decrement operator '--'.
        // Create a new Array instance and assign it to the result ($$).
        (yyval.A) = new Array();
        // Generate a temporary location for the Array.
        (yyval.A)->Array = gentemp((yyvsp[-1].A)->Array->type);
        // Emit code to copy the previous expression to the result.
        Q.emit("=", (yyval.A)->Array->name, (yyvsp[-1].A)->Array->name);
        // Emit code to decrement the previous expression by 1.
        Q.emit("-", (yyvsp[-1].A)->Array->name, (yyvsp[-1].A)->Array->name, "1");
    }
#line 2119 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 15:
#line 232 "ass5_21CS10016_21CS30050.y"
    {
        // Handle a cast expression with an initializer.
        // No action needed.
    }
#line 2128 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 16:
#line 237 "ass5_21CS10016_21CS30050.y"
    {
        // Handle a cast expression with an initializer list.
        // No action needed.
    }
#line 2137 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 17:
#line 245 "ass5_21CS10016_21CS30050.y"
    {
        // This rule handles a single assignment expression.
        (yyval.param_no) = 1; // Simple assignment
        // Emit code to pass the assignment expression as a parameter.
        Q.emit("param", (yyvsp[0].expr)->loc->name);
    }
#line 2148 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 18:
#line 252 "ass5_21CS10016_21CS30050.y"
    {
        // This handles a list of argument expressions separated by commas.
        (yyval.param_no) = (yyvsp[-2].param_no) + 1; // Increment the argument count.
        // Emit code to pass the assignment expression as a parameter.
        Q.emit("param", (yyvsp[0].expr)->loc->name);
    }
#line 2159 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 19:
#line 262 "ass5_21CS10016_21CS30050.y"
    {
        // This rule represents a non-empty argument expression list.
        (yyval.param_no) = (yyvsp[0].param_no); // Simple assignment
    }
#line 2168 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 20:
#line 267 "ass5_21CS10016_21CS30050.y"
    {
        // This rule represents an empty argument expression list.
        (yyval.param_no) = 0; // Defaults to 0 arguments.
    }
#line 2177 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 21:
#line 275 "ass5_21CS10016_21CS30050.y"
    {
        // This rule represents a unary expression with a postfix expression.
        (yyval.A) = (yyvsp[0].A); // Assign the result to the postfix expression.
    }
#line 2186 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 22:
#line 280 "ass5_21CS10016_21CS30050.y"
    {
        // This handles the increment operator '++' as a unary expression.
        // Emit code to increment the operand by 1.
        Q.emit("+", (yyvsp[0].A)->Array->name, (yyvsp[0].A)->Array->name, "1");
        (yyval.A) = (yyvsp[0].A);
    }
#line 2197 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 23:
#line 287 "ass5_21CS10016_21CS30050.y"
    {
        // This handles the decrement operator '--' as a unary expression.
        // Emit code to decrement the operand by 1.
        Q.emit("-", (yyvsp[0].A)->Array->name, (yyvsp[0].A)->Array->name, "1");
        (yyval.A) = (yyvsp[0].A);
    }
#line 2208 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 24:
#line 294 "ass5_21CS10016_21CS30050.y"
    {
        // This rule handles unary operators applied to a cast expression.
        (yyval.A) = new Array();
        // Perform different actions based on the unary operator type.
        switch ((yyvsp[-1].unaryOp)) {
            case '&':
                // Handle the address-of operator '&'.
                (yyval.A)->Array = gentemp(new symboltype("ptr"));
                (yyval.A)->Array->type->arrtype = (yyvsp[0].A)->Array->type;
                // Emit code to take the address of the operand.
                Q.emit("=&", (yyval.A)->Array->name, (yyvsp[0].A)->Array->name);
                break;
            case '*':
                // Handle the dereferencing operator '*'.
                (yyval.A)->atype = "ptr";
                (yyval.A)->loc = gentemp((yyvsp[0].A)->Array->type->arrtype);
                (yyval.A)->Array = (yyvsp[0].A)->Array;
                // Emit code to dereference the pointer.
                Q.emit("=*", (yyval.A)->loc->name, (yyvsp[0].A)->Array->name);
                break;
            case '+':
                // Handle the unary plus operator '+', which doesn't change the operand.
                (yyval.A) = (yyvsp[0].A);
                break;
            case '-':
                // Handle the unary minus operator '-', which negates the operand.
                (yyval.A)->Array = gentemp(new symboltype((yyvsp[0].A)->Array->type->type));
                // Emit code to negate the operand.
                Q.emit("uminus", (yyval.A)->Array->name, (yyvsp[0].A)->Array->name);
                break;
            case '~':
                // Handle the bitwise NOT operator '~'.
                (yyval.A)->Array = gentemp(new symboltype((yyvsp[0].A)->Array->type->type));
                // Emit code to perform bitwise NOT on the operand.
                Q.emit("~", (yyval.A)->Array->name, (yyvsp[0].A)->Array->name);
                break;
            case '!':
                // Handle the logical NOT operator '!', which negates the operand.
                (yyval.A)->Array = gentemp(new symboltype((yyvsp[0].A)->Array->type->type));
                // Emit code to perform logical NOT on the operand.
                Q.emit("!", (yyval.A)->Array->name, (yyvsp[0].A)->Array->name);
                break;
        }
    }
#line 2257 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 25:
#line 339 "ass5_21CS10016_21CS30050.y"
    {
        // Handle the sizeof operator applied to an expression.
        // No action needed.
    }
#line 2266 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 26:
#line 344 "ass5_21CS10016_21CS30050.y"
    {
        // Handle the sizeof operator applied to a type name.
        // No action needed.
    }
#line 2275 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 27:
#line 352 "ass5_21CS10016_21CS30050.y"
    { 
        // This rule represents the bitwise AND operator '&' in unary expressions.
        (yyval.unaryOp) = '&'; 
    }
#line 2284 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 28:
#line 357 "ass5_21CS10016_21CS30050.y"
    { 
        // This rule represents the pointer dereference operator '*' in unary expressions.
        (yyval.unaryOp) = '*'; 
    }
#line 2293 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 29:
#line 362 "ass5_21CS10016_21CS30050.y"
    { 
        // This rule represents the unary plus operator '+' in unary expressions.
        (yyval.unaryOp) = '+'; 
    }
#line 2302 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 30:
#line 367 "ass5_21CS10016_21CS30050.y"
    { 
        // This rule represents the unary minus operator '-' in unary expressions.
        (yyval.unaryOp) = '-'; 
    }
#line 2311 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 31:
#line 372 "ass5_21CS10016_21CS30050.y"
    { 
        // This rule represents the bitwise NOT operator '~' in unary expressions.
        (yyval.unaryOp) = '~'; 
    }
#line 2320 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 32:
#line 377 "ass5_21CS10016_21CS30050.y"
    { 
        // This rule represents the logical NOT operator '!' in unary expressions.
        (yyval.unaryOp) = '!'; 
    }
#line 2329 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 33:
#line 385 "ass5_21CS10016_21CS30050.y"
    { 
        // This rule handles a cast expression with a unary expression.
        (yyval.A) = (yyvsp[0].A); 
    }
#line 2338 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 34:
#line 390 "ass5_21CS10016_21CS30050.y"
    { 
        // This rule handles a cast expression with a type name and a cast expression.
        (yyval.A) = new Array();
        // Convert and assign the type of the cast expression.
        (yyval.A)->Array = convertType((yyvsp[0].A)->Array, variable_type);
    }
#line 2349 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 35:
#line 400 "ass5_21CS10016_21CS30050.y"
    {
        // This rule handles multiplicative expressions starting with a cast expression.
        (yyval.expr) = new Expression();
        // Handle casting by checking types and performing necessary conversions.
        if ((yyvsp[0].A)->atype == "arr") {
            (yyval.expr)->loc = gentemp((yyvsp[0].A)->loc->type);	
            Q.emit("=[]", (yyval.expr)->loc->name, (yyvsp[0].A)->Array->name, (yyvsp[0].A)->loc->name);     
        }
        else if ((yyvsp[0].A)->atype == "ptr") { 
            (yyval.expr)->loc = (yyvsp[0].A)->loc;        
        }
        else {
            (yyval.expr)->loc = (yyvsp[0].A)->Array;
        }
    }
#line 2369 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 36:
#line 416 "ass5_21CS10016_21CS30050.y"
    { 
        // This rule handles multiplication in multiplicative expressions.
        if (!compareSymbolType((yyvsp[-2].expr)->loc, (yyvsp[0].A)->Array)) {
            // Types are not the same; report a type error.
            yyerror("Error! Type not matched");
            return 1;
        }
        else {
            // Perform the multiplication operation.
            (yyval.expr) = new Expression();	
            (yyval.expr)->loc = gentemp(new symboltype((yyvsp[-2].expr)->loc->type->type));
            Q.emit("*", (yyval.expr)->loc->name, (yyvsp[-2].expr)->loc->name, (yyvsp[0].A)->Array->name);
        }
    }
#line 2388 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 37:
#line 431 "ass5_21CS10016_21CS30050.y"
    {
        // This rule handles division in multiplicative expressions.
        if (!compareSymbolType((yyvsp[-2].expr)->loc, (yyvsp[0].A)->Array)) {
            // Types are not the same; report a type error.
            cout << "Error! Type not matched" << endl;
        }
        else {
            // Perform the division operation.
            (yyval.expr) = new Expression();
            (yyval.expr)->loc = gentemp(new symboltype((yyvsp[-2].expr)->loc->type->type));
            Q.emit("/", (yyval.expr)->loc->name, (yyvsp[-2].expr)->loc->name, (yyvsp[0].A)->Array->name);
        }
    }
#line 2406 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 38:
#line 445 "ass5_21CS10016_21CS30050.y"
    {
        // This rule handles the modulo operation in multiplicative expressions.
        if (!compareSymbolType((yyvsp[-2].expr)->loc, (yyvsp[0].A)->Array)) {
            // Incompatible types; report a type error.
            cout << "Error! Type not matched" << endl;		
        }
        else {
            // Perform the modulo operation.
            (yyval.expr) = new Expression();
            (yyval.expr)->loc = gentemp(new symboltype((yyvsp[-2].expr)->loc->type->type));
            Q.emit("%", (yyval.expr)->loc->name, (yyvsp[-2].expr)->loc->name, (yyvsp[0].A)->Array->name);	
        }
    }
#line 2424 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 39:
#line 462 "ass5_21CS10016_21CS30050.y"
    { 
        // This rule handles additive expressions starting with a multiplicative expression.
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 2433 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 40:
#line 467 "ass5_21CS10016_21CS30050.y"
    {
        // This rule handles addition in additive expressions.
        if (!compareSymbolType((yyvsp[-2].expr)->loc, (yyvsp[0].expr)->loc)) {
            // Incompatible types; report a type error.
            cout << "Error! Type not matched" << endl;
        }
        else {
            // Continue with the addition operation.
            (yyval.expr) = new Expression();	
            (yyval.expr)->loc = gentemp(new symboltype((yyvsp[-2].expr)->loc->type->type));
            Q.emit("+", (yyval.expr)->loc->name, (yyvsp[-2].expr)->loc->name, (yyvsp[0].expr)->loc->name);
        }
    }
#line 2451 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 41:
#line 481 "ass5_21CS10016_21CS30050.y"
    {
        // This rule handles subtraction in additive expressions.
        if (!compareSymbolType((yyvsp[-2].expr)->loc, (yyvsp[0].expr)->loc)) {
            // Incompatible types; report a type error.
            cout << "Error! Type not matched" << endl;		
        }
        else {	
            (yyval.expr) = new Expression();	
            (yyval.expr)->loc = gentemp(new symboltype((yyvsp[-2].expr)->loc->type->type));
            Q.emit("-", (yyval.expr)->loc->name, (yyvsp[-2].expr)->loc->name, (yyvsp[0].expr)->loc->name);
        }
    }
#line 2468 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 42:
#line 497 "ass5_21CS10016_21CS30050.y"
    { 
        // This rule handles shift expressions starting with an additive expression.
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 2477 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 43:
#line 502 "ass5_21CS10016_21CS30050.y"
    { 
        // This rule handles left shift in shift expressions.
        if (!((yyvsp[0].expr)->loc->type->type == "int")) {
            // Incompatible types; report a type error.
            cout << "Error! Type not matched" << endl; 		
        }
        else {		
            (yyval.expr) = new Expression();		
            (yyval.expr)->loc = gentemp(new symboltype("int"));
            Q.emit("<<", (yyval.expr)->loc->name, (yyvsp[-2].expr)->loc->name, (yyvsp[0].expr)->loc->name);		
        }
    }
#line 2494 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 44:
#line 515 "ass5_21CS10016_21CS30050.y"
    { 	
        // This rule handles right shift in shift expressions.
        if (!((yyvsp[0].expr)->loc->type->type == "int")) {
            // Incompatible types; report a type error.
            cout << "Error! Type not matched" << endl; 		
        }
        else {			
            (yyval.expr) = new Expression();	
            (yyval.expr)->loc = gentemp(new symboltype("int"));
            Q.emit(">>", (yyval.expr)->loc->name, (yyvsp[-2].expr)->loc->name, (yyvsp[0].expr)->loc->name);			
        }
    }
#line 2511 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 45:
#line 531 "ass5_21CS10016_21CS30050.y"
    { 
        // This rule handles relational expressions starting with a shift expression.
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 2520 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 46:
#line 536 "ass5_21CS10016_21CS30050.y"
    {
        // This rule handles the less than operator in relational expressions.
        if (!compareSymbolType((yyvsp[-2].expr)->loc, (yyvsp[0].expr)->loc)) {
            // Incompatible types; report a type error.
            yyerror("Error! Type not matched");
        }
        else {      
            (yyval.expr) = new Expression();
            (yyval.expr)->type = "bool";
            // Need to update truelist and falselist since the type is boolean.
            (yyval.expr)->truelist = makelist(nextinstr());     
            (yyval.expr)->falselist = makelist(nextinstr() + 1);
            Q.emit("<", "", (yyvsp[-2].expr)->loc->name, (yyvsp[0].expr)->loc->name);     
            Q.emit("goto", "");	
        }
    }
#line 2541 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 47:
#line 553 "ass5_21CS10016_21CS30050.y"
    {
        // This rule handles the greater than operator in relational expressions.
        if (!compareSymbolType((yyvsp[-2].expr)->loc, (yyvsp[0].expr)->loc)) {
            // Incompatible types; report a type error.
            yyerror("Error! Type not matched");
        }
        else {	
            (yyval.expr) = new Expression();		
            (yyval.expr)->type = "bool";
            // Need to update truelist and falselist since the type is boolean.
            (yyval.expr)->truelist = makelist(nextinstr());
            (yyval.expr)->falselist = makelist(nextinstr() + 1);
            Q.emit(">", "", (yyvsp[-2].expr)->loc->name, (yyvsp[0].expr)->loc->name);
            Q.emit("goto", "");
        }	
    }
#line 2562 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 48:
#line 570 "ass5_21CS10016_21CS30050.y"
    {
        // This rule handles the less than or equal to operator in relational expressions.
        if (!compareSymbolType((yyvsp[-2].expr)->loc, (yyvsp[0].expr)->loc)) {
            // Incompatible types; report a type error.
            cout << "Error! Type not matched" << endl;
        }
        else {			
            (yyval.expr) = new Expression();		
            (yyval.expr)->type = "bool";
            // Need to update the attributes for boolean data type.
            (yyval.expr)->truelist = makelist(nextinstr());
            (yyval.expr)->falselist = makelist(nextinstr() + 1);
            Q.emit("<=", "", (yyvsp[-2].expr)->loc->name, (yyvsp[0].expr)->loc->name);
            Q.emit("goto", "");
        }		
    }
#line 2583 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 49:
#line 587 "ass5_21CS10016_21CS30050.y"
    {
        // This rule handles the greater than or equal to operator in relational expressions.
        if (!compareSymbolType((yyvsp[-2].expr)->loc, (yyvsp[0].expr)->loc)) {
            // Incompatible types; report a type error.
            cout << "Error! Type not matched" << endl;
        }
        else {	
            (yyval.expr) = new Expression();	
            (yyval.expr)->type = "bool";
            // Need to update the attributes for the boolean data type.
            (yyval.expr)->truelist = makelist(nextinstr());
            (yyval.expr)->falselist = makelist(nextinstr() + 1);
            Q.emit(">=", "", (yyvsp[-2].expr)->loc->name, (yyvsp[0].expr)->loc->name);
            Q.emit("goto", "");
        }
    }
#line 2604 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 50:
#line 607 "ass5_21CS10016_21CS30050.y"
    { 
        (yyval.expr)=(yyvsp[0].expr);
    }
#line 2612 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 51:
#line 611 "ass5_21CS10016_21CS30050.y"
    {
        // Check and assign
        if(!compareSymbolType((yyvsp[-2].expr)->loc, (yyvsp[0].expr)->loc)) {
            cout << "Error! Type not matched"<< endl;
        }
        else {
            // We need to convert here
            BOOL2INT((yyvsp[-2].expr));                  
            BOOL2INT((yyvsp[0].expr));

            (yyval.expr) = new Expression();

            (yyval.expr)->type = "bool";
            (yyval.expr)->truelist = makelist(nextinstr());            
            (yyval.expr)->falselist = makelist(nextinstr()+1); 

            Q.emit("==", "", (yyvsp[-2].expr)->loc->name, (yyvsp[0].expr)->loc->name);      
            Q.emit("goto", "");				
        }
    }
#line 2637 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 52:
#line 632 "ass5_21CS10016_21CS30050.y"
    {
        // Check and assign
        if(!compareSymbolType((yyvsp[-2].expr)->loc, (yyvsp[0].expr)->loc)) {
            cout << "Error! Type not matched"<< endl;
        }
        else {			
            BOOL2INT((yyvsp[-2].expr));
            BOOL2INT((yyvsp[0].expr));

            (yyval.expr) = new Expression();                 

            (yyval.expr)->type = "bool";
            (yyval.expr)->truelist = makelist(nextinstr());
            (yyval.expr)->falselist = makelist(nextinstr()+1);

            Q.emit("!=", "", (yyvsp[-2].expr)->loc->name, (yyvsp[0].expr)->loc->name);
            Q.emit("goto", "");
        }
    }
#line 2661 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 53:
#line 655 "ass5_21CS10016_21CS30050.y"
    { 
        (yyval.expr)=(yyvsp[0].expr);
    }
#line 2669 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 54:
#line 659 "ass5_21CS10016_21CS30050.y"
    {
        // Check and assign
        if(!compareSymbolType((yyvsp[-2].expr)->loc, (yyvsp[0].expr)->loc)){		
            cout << "Error! Type not matched"<< endl;
        }
        else {              
            BOOL2INT((yyvsp[-2].expr));                             
            BOOL2INT((yyvsp[0].expr));			

            (yyval.expr) = new Expression();

            (yyval.expr)->type = "not-boolean";                   
            (yyval.expr)->loc = gentemp(new symboltype("int"));

            Q.emit("&", (yyval.expr)->loc->name, (yyvsp[-2].expr)->loc->name, (yyvsp[0].expr)->loc->name);               
        }
    }
#line 2691 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 55:
#line 680 "ass5_21CS10016_21CS30050.y"
    { 
        (yyval.expr)=(yyvsp[0].expr);
    }
#line 2699 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 56:
#line 684 "ass5_21CS10016_21CS30050.y"
    {
        // Check and assign
        if(!compareSymbolType((yyvsp[-2].expr)->loc, (yyvsp[0].expr)->loc)) {
            cout << "Error! Type not matched"<< endl;
        }
        else {
            BOOL2INT((yyvsp[-2].expr));
            BOOL2INT((yyvsp[0].expr));

            (yyval.expr) = new Expression();

            (yyval.expr)->type = "not-boolean";
            (yyval.expr)->loc = gentemp(new symboltype("int"));

            Q.emit("^", (yyval.expr)->loc->name, (yyvsp[-2].expr)->loc->name, (yyvsp[0].expr)->loc->name);
        }
    }
#line 2721 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 57:
#line 705 "ass5_21CS10016_21CS30050.y"
    { 
        (yyval.expr)=(yyvsp[0].expr);
    }
#line 2729 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 58:
#line 709 "ass5_21CS10016_21CS30050.y"
    { 
        // Check and assign
        if(!compareSymbolType((yyvsp[-2].expr)->loc, (yyvsp[0].expr)->loc)) { 
            yyerror("Error! Type not matched"); 
        }
        else {
            BOOL2INT((yyvsp[-2].expr));		
            BOOL2INT((yyvsp[0].expr));

            (yyval.expr) = new Expression();

            (yyval.expr)->type = "not-boolean";
            (yyval.expr)->loc = gentemp(new symboltype("int"));

            Q.emit("|", (yyval.expr)->loc->name, (yyvsp[-2].expr)->loc->name, (yyvsp[0].expr)->loc->name);
        } 
    }
#line 2751 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 59:
#line 730 "ass5_21CS10016_21CS30050.y"
    { 
        (yyval.expr)=(yyvsp[0].expr);
    }
#line 2759 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 60:
#line 734 "ass5_21CS10016_21CS30050.y"
    { 
        // Converto to bool before the logical operation
        INT2BOOL((yyvsp[0].expr));                                  
        INT2BOOL((yyvsp[-3].expr));                                 

        // Generate new boolean expression
        (yyval.expr) = new Expression();                               
        (yyval.expr)->type = "bool";
        
        // Do the backpatching and generate the attributes
        backpatch((yyvsp[-3].expr)->truelist, (yyvsp[-1].instruction_no));                        
        (yyval.expr)->truelist = (yyvsp[0].expr)->truelist;                       
        (yyval.expr)->falselist = merge((yyvsp[-3].expr)->falselist, (yyvsp[0].expr)->falselist);   
    }
#line 2778 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 61:
#line 752 "ass5_21CS10016_21CS30050.y"
    { 
        (yyval.expr)=(yyvsp[0].expr);
    }
#line 2786 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 62:
#line 756 "ass5_21CS10016_21CS30050.y"
    { 
        // Convert to bool before the logical operation
        INT2BOOL((yyvsp[0].expr));			 
        INT2BOOL((yyvsp[-3].expr));			

        (yyval.expr) = new Expression();	
        (yyval.expr)->type = "bool";

        // As per requirement
        backpatch((yyvsp[-3].expr)->falselist, (yyvsp[-1].instruction_no));		
        (yyval.expr)->truelist = merge((yyvsp[-3].expr)->truelist, (yyvsp[0].expr)->truelist);		
        (yyval.expr)->falselist = (yyvsp[0].expr)->falselist;		 	
    }
#line 2804 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 63:
#line 773 "ass5_21CS10016_21CS30050.y"
    { (yyval.expr)=(yyvsp[0].expr);/* Simple assign */ }
#line 2810 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 64:
#line 775 "ass5_21CS10016_21CS30050.y"
    {
        //normal conversion method to get conditional expressions
        (yyval.expr)->loc = gentemp((yyvsp[-2].expr)->loc->type);       //generate temporary for expression
        (yyval.expr)->loc->update((yyvsp[-2].expr)->loc->type);
        
        backpatch((yyvsp[-4].expr)->truelist, nextinstr());           // $1 true goes to expression
        Q.emit("=", (yyval.expr)->loc->name, (yyvsp[-2].expr)->loc->name);      // make it equal to first expression
        list<int> temp = makelist(nextinstr());            //makelist next instruction
        Q.emit("goto", "");                             //prevent fallthrough

        backpatch((yyvsp[-4].expr)->falselist, nextinstr());          // $1 false goes to conditional expression
        Q.emit("=", (yyval.expr)->loc->name, (yyvsp[0].expr)->loc->name);      // Second Expression

        backpatch(temp, nextinstr());                      // fallthrough, go to next instruction
    }
#line 2830 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 65:
#line 794 "ass5_21CS10016_21CS30050.y"
    { (yyval.expr)=(yyvsp[0].expr);/* Simple assign */ }
#line 2836 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 66:
#line 796 "ass5_21CS10016_21CS30050.y"
    {
        if((yyvsp[-2].A)->atype=="arr")                                            // if type is arr, Check and convert then Q.emit as []=
        {
            (yyvsp[0].expr)->loc = convertType((yyvsp[0].expr)->loc, (yyvsp[-2].A)->type->type);
            Q.emit("[]=", (yyvsp[-2].A)->Array->name, (yyvsp[-2].A)->loc->name, (yyvsp[0].expr)->loc->name);		
        }
        else if((yyvsp[-2].A)->atype=="ptr")                                       // if type is ptr, simply Q.emit as *=
        {
            Q.emit("*=", (yyvsp[-2].A)->Array->name, (yyvsp[0].expr)->loc->name);	
        }
        else                                                            // otherwise simple assignment
        {
            (yyvsp[0].expr)->loc = convertType((yyvsp[0].expr)->loc, (yyvsp[-2].A)->Array->type->type);
            Q.emit("=", (yyvsp[-2].A)->Array->name, (yyvsp[0].expr)->loc->name);
        }
        
        (yyval.expr) = (yyvsp[0].expr);
    }
#line 2859 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 67:
#line 819 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 2865 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 68:
#line 821 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 2871 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 69:
#line 823 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 2877 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 70:
#line 825 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 2883 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 71:
#line 827 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 2889 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 72:
#line 829 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 2895 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 73:
#line 831 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 2901 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 74:
#line 833 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 2907 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 75:
#line 835 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 2913 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 76:
#line 837 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 2919 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 77:
#line 839 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 2925 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 78:
#line 844 "ass5_21CS10016_21CS30050.y"
    { (yyval.expr) = (yyvsp[0].expr); }
#line 2931 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 79:
#line 846 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 2937 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 80:
#line 851 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 2943 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 81:
#line 856 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 2949 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 82:
#line 860 "ass5_21CS10016_21CS30050.y"
                         { /*No action needed*/ }
#line 2955 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 83:
#line 861 "ass5_21CS10016_21CS30050.y"
            { /*No action needed*/ }
#line 2961 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 84:
#line 866 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 2967 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 85:
#line 868 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 2973 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 86:
#line 870 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 2979 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 87:
#line 872 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 2985 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 88:
#line 876 "ass5_21CS10016_21CS30050.y"
                           { /*No action needed*/ }
#line 2991 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 89:
#line 877 "ass5_21CS10016_21CS30050.y"
             { /*No action needed*/ }
#line 2997 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 90:
#line 882 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 3003 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 91:
#line 884 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 3009 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 92:
#line 889 "ass5_21CS10016_21CS30050.y"
    { 
        (yyval.sym_ptr) = (yyvsp[0].sym_ptr);                            // Simple Assign 
    }
#line 3017 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 93:
#line 893 "ass5_21CS10016_21CS30050.y"
    {
        if((yyvsp[0].sym_ptr)->val != ""){
            (yyvsp[-2].sym_ptr)->val=(yyvsp[0].sym_ptr)->val;                // get the initial value
        }
        Q.emit("=", (yyvsp[-2].sym_ptr)->name, (yyvsp[0].sym_ptr)->name);	// emit that initial value with Assign operator
    }
#line 3028 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 94:
#line 903 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 3034 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 95:
#line 905 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 3040 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 96:
#line 907 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 3046 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 97:
#line 909 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 3052 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 98:
#line 914 "ass5_21CS10016_21CS30050.y"
    { variable_type="void"; /* Store the latest var type */ }
#line 3058 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 99:
#line 916 "ass5_21CS10016_21CS30050.y"
    { variable_type="char"; /* Store the latest var type */ }
#line 3064 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 100:
#line 918 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 3070 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 101:
#line 920 "ass5_21CS10016_21CS30050.y"
    { variable_type="int"; /* Store the latest var type */ }
#line 3076 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 102:
#line 922 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 3082 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 103:
#line 924 "ass5_21CS10016_21CS30050.y"
    { variable_type="float"; /* Store the latest var type */ }
#line 3088 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 104:
#line 926 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 3094 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 105:
#line 928 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 3100 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 106:
#line 930 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 3106 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 107:
#line 932 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 3112 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 108:
#line 934 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 3118 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 109:
#line 936 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 3124 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 110:
#line 938 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 3130 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 111:
#line 940 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 3136 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 112:
#line 945 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 3142 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 113:
#line 947 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 3148 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 114:
#line 951 "ass5_21CS10016_21CS30050.y"
                             { /*No action needed*/ }
#line 3154 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 115:
#line 952 "ass5_21CS10016_21CS30050.y"
             { /*No action needed*/ }
#line 3160 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 116:
#line 957 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 3166 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 117:
#line 959 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 3172 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 118:
#line 961 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 3178 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 119:
#line 966 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 3184 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 120:
#line 968 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 3190 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 121:
#line 973 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 3196 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 122:
#line 975 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 3202 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 123:
#line 980 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 3208 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 124:
#line 982 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 3214 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 125:
#line 987 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 3220 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 126:
#line 989 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 3226 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 127:
#line 993 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 3232 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 128:
#line 995 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 3238 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 129:
#line 997 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 3244 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 130:
#line 1002 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 3250 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 131:
#line 1004 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 3256 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 132:
#line 1006 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 3262 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 133:
#line 1010 "ass5_21CS10016_21CS30050.y"
               { /*No action needed*/ }
#line 3268 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 134:
#line 1011 "ass5_21CS10016_21CS30050.y"
             { /*No action needed*/ }
#line 3274 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 135:
#line 1016 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 3280 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 136:
#line 1018 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 3286 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 137:
#line 1024 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 3292 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 138:
#line 1026 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 3298 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 139:
#line 1032 "ass5_21CS10016_21CS30050.y"
    { /* NOT to be modelled */ }
#line 3304 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 140:
#line 1034 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 3310 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 141:
#line 1036 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 3316 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 142:
#line 1041 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 3322 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 143:
#line 1046 "ass5_21CS10016_21CS30050.y"
    {
        symboltype *t = (yyvsp[-1].symbol_type);
        while(t->arrtype!=NULL)
        {
            t = t->arrtype;                                         // Recursively get to the base Array
        }   
        t->arrtype = (yyvsp[0].sym_ptr)->type;                                      // add the base type 
        
        (yyval.sym_ptr) = (yyvsp[0].sym_ptr)->update((yyvsp[-1].symbol_type));                                        // update the symbol type
    }
#line 3337 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 144:
#line 1056 "ass5_21CS10016_21CS30050.y"
                        {   }
#line 3343 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 145:
#line 1063 "ass5_21CS10016_21CS30050.y"
    {
        //if ID, simply add a new variable of variable_type
        (yyval.sym_ptr) = (yyvsp[0].sym_ptr)->update(new symboltype(variable_type));                                      // update the symbol type to latest type specifier
        currSymbolPtr = (yyval.sym_ptr);	                                                            // store the latest Symbol
    }
#line 3353 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 146:
#line 1068 "ass5_21CS10016_21CS30050.y"
                                                    {(yyval.sym_ptr)=(yyvsp[-1].sym_ptr);}
#line 3359 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 147:
#line 1069 "ass5_21CS10016_21CS30050.y"
                                                                                                 {	}
#line 3365 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 148:
#line 1070 "ass5_21CS10016_21CS30050.y"
                                                                           {	}
#line 3371 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 149:
#line 1072 "ass5_21CS10016_21CS30050.y"
    {
        symboltype *t = (yyvsp[-3].sym_ptr) -> type;
        symboltype *prev = NULL;                                                        // prev initialized to NULL
        while(t->type == "arr") 
        {
            prev = t;	
            t = t->arrtype;                                                             // recursively find the base type
        }
        if(prev==NULL) 
        {
            int temp = atoi((yyvsp[-1].expr)->loc->val.c_str());                                      // temp = string(value)
            symboltype* s = new symboltype("arr", (yyvsp[-3].sym_ptr)->type, temp);                      // Create a new symbol with the initial value
            (yyval.sym_ptr) = (yyvsp[-3].sym_ptr)->update(s);                                                         // Update the symbol type
        }
        else 
        {
            prev->arrtype =  new symboltype("arr", t, atoi((yyvsp[-1].expr)->loc->val.c_str()));      // similar arguments as above		
            (yyval.sym_ptr) = (yyvsp[-3].sym_ptr)->update((yyvsp[-3].sym_ptr)->type);
        }
    }
#line 3396 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 150:
#line 1093 "ass5_21CS10016_21CS30050.y"
    {
        symboltype *t = (yyvsp[-2].sym_ptr) -> type;
        symboltype *prev = NULL;                                    // initialize prev to NULL
        while(t->type == "arr") 
        {
            prev = t;	
            t = t->arrtype;                                         // Recursively find the base type
        }
        if(prev==NULL) 
        {
            symboltype* s = new symboltype("arr", (yyvsp[-2].sym_ptr)->type, 0);     // no initial values, simply keep 0
            (yyval.sym_ptr) = (yyvsp[-2].sym_ptr)->update(s);                                     // Update the symboltype of $$
        }
        else 
        {
            prev->arrtype =  new symboltype("arr", t, 0);
            (yyval.sym_ptr) = (yyvsp[-2].sym_ptr)->update((yyvsp[-2].sym_ptr)->type);
        }
    }
#line 3420 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 151:
#line 1112 "ass5_21CS10016_21CS30050.y"
                                                                                                        {	}
#line 3426 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 152:
#line 1113 "ass5_21CS10016_21CS30050.y"
                                                                                    {	}
#line 3432 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 153:
#line 1114 "ass5_21CS10016_21CS30050.y"
                                                                                {	}
#line 3438 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 154:
#line 1115 "ass5_21CS10016_21CS30050.y"
                                                            {	}
#line 3444 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 155:
#line 1117 "ass5_21CS10016_21CS30050.y"
    {
        ST->name = (yyvsp[-4].sym_ptr)->name;	                    // change the ST name to fun
        if((yyvsp[-4].sym_ptr)->type->type !="void") 
        {
            sym *s = ST->lookup("return");          // lookup for return value	
            s->update((yyvsp[-4].sym_ptr)->type);		            // update return type
        }
        (yyvsp[-4].sym_ptr)->nested=ST;                              // link nested Symbol Table 
        ST->parent = globalST;                      // link parent Symbol Table
        
        changeTable(globalST);				        // Come back to globalsymbol table
        currSymbolPtr = (yyval.sym_ptr);
    }
#line 3462 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 156:
#line 1130 "ass5_21CS10016_21CS30050.y"
                                                                           {	}
#line 3468 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 157:
#line 1132 "ass5_21CS10016_21CS30050.y"
    {        //similar as above
        ST->name = (yyvsp[-3].sym_ptr)->name;
        if((yyvsp[-3].sym_ptr)->type->type !="void") 
        {
            sym *s = ST->lookup("return");
            s->update((yyvsp[-3].sym_ptr)->type);            // update return type
        }
        (yyvsp[-3].sym_ptr)->nested=ST;                      // link nested Symbol table
        ST->parent = globalST;              // Set parent to Global Symbol table
        
        changeTable(globalST);				// Go back to global Symbol table
        currSymbolPtr = (yyval.sym_ptr);
    }
#line 3486 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 158:
#line 1148 "ass5_21CS10016_21CS30050.y"
                        { /*No action needed*/ }
#line 3492 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 159:
#line 1149 "ass5_21CS10016_21CS30050.y"
             { /*No action needed*/ }
#line 3498 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 160:
#line 1155 "ass5_21CS10016_21CS30050.y"
    { 
        (yyval.symbol_type) = new symboltype("ptr");   //create a new pointer symbol
    }
#line 3506 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 161:
#line 1159 "ass5_21CS10016_21CS30050.y"
    { 
        (yyval.symbol_type) = new symboltype("ptr",(yyvsp[0].symbol_type)); // create the symboltype with $3 symbol type
    }
#line 3514 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 162:
#line 1166 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 3520 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 163:
#line 1168 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 3526 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 164:
#line 1173 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 3532 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 165:
#line 1175 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 3538 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 166:
#line 1180 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 3544 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 167:
#line 1182 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 3550 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 168:
#line 1187 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 3556 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 169:
#line 1189 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 3562 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 170:
#line 1194 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 3568 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 171:
#line 1196 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 3574 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 172:
#line 1201 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 3580 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 173:
#line 1206 "ass5_21CS10016_21CS30050.y"
    { (yyval.sym_ptr)=(yyvsp[0].expr)->loc; /* assignment */  }
#line 3586 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 174:
#line 1208 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 3592 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 175:
#line 1210 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 3598 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 176:
#line 1215 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 3604 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 177:
#line 1217 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 3610 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 178:
#line 1221 "ass5_21CS10016_21CS30050.y"
                { /*No action needed*/ }
#line 3616 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 179:
#line 1222 "ass5_21CS10016_21CS30050.y"
             { /*No action needed*/ }
#line 3622 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 180:
#line 1227 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 3628 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 181:
#line 1232 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 3634 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 182:
#line 1234 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 3640 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 183:
#line 1239 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 3646 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 184:
#line 1241 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 3652 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 185:
#line 1246 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 3658 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 186:
#line 1248 "ass5_21CS10016_21CS30050.y"
    { (yyval.stat)=(yyvsp[0].stat); }
#line 3664 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 187:
#line 1250 "ass5_21CS10016_21CS30050.y"
    { 
        (yyval.stat)=new Statement();              //create new statement with same nextlist
        (yyval.stat)->nextlist=(yyvsp[0].expr)->nextlist; 
    }
#line 3673 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 188:
#line 1255 "ass5_21CS10016_21CS30050.y"
    { (yyval.stat)=(yyvsp[0].stat); }
#line 3679 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 189:
#line 1257 "ass5_21CS10016_21CS30050.y"
    { (yyval.stat)=(yyvsp[0].stat); }
#line 3685 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 190:
#line 1259 "ass5_21CS10016_21CS30050.y"
    { (yyval.stat)=(yyvsp[0].stat); }
#line 3691 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 191:
#line 1263 "ass5_21CS10016_21CS30050.y"
                        { /*No action needed*/ }
#line 3697 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 192:
#line 1265 "ass5_21CS10016_21CS30050.y"
    { 
        (yyval.stat)=new Statement();                         // create new statement with same nextlist
        (yyval.stat)->nextlist=(yyvsp[0].expr)->nextlist;                  // assign the nextlist
    }
#line 3706 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 193:
#line 1269 "ass5_21CS10016_21CS30050.y"
                            { (yyval.stat)=(yyvsp[0].stat); }
#line 3712 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 194:
#line 1270 "ass5_21CS10016_21CS30050.y"
                            { (yyval.stat)=(yyvsp[0].stat); }
#line 3718 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 195:
#line 1271 "ass5_21CS10016_21CS30050.y"
                       { (yyval.stat)=(yyvsp[0].stat); }
#line 3724 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 196:
#line 1275 "ass5_21CS10016_21CS30050.y"
    {
        // Set the result of this production to the result of the 'statement'.
        (yyval.stat) = (yyvsp[0].stat);

        // Find the label associated with the provided identifier.
        label *s = find_label((yyvsp[-3].sym_ptr)->name);

        if (s != nullptr) {
            // If the label exists, set its address and backpatch its nextlist.
            s->addr = (yyvsp[-1].instruction_no);
            backpatch(s->nextlist, s->addr);
        } else {
            // If the label does not exist, create a new label.
            s = new label((yyvsp[-3].sym_ptr)->name);

            // Set the label's address to the next instruction and create a nextlist with $3.
            s->addr = nextinstr();
            s->nextlist = makelist((yyvsp[-1].instruction_no));

            // Add the newly created label to the label store.
            label_store.push_back(*s);
        }
    }
#line 3752 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 197:
#line 1299 "ass5_21CS10016_21CS30050.y"
    { /* Not to be modelled */ }
#line 3758 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 198:
#line 1301 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 3764 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 199:
#line 1306 "ass5_21CS10016_21CS30050.y"
    { 
        (yyval.stat)=(yyvsp[-1].stat);                           // Compound Statement = blockItemList
        changeTable(ST->parent);         // Change Symbol Table
    }
#line 3773 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 200:
#line 1314 "ass5_21CS10016_21CS30050.y"
    { (yyval.stat)=(yyvsp[0].stat); /* Simple assign */}
#line 3779 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 201:
#line 1316 "ass5_21CS10016_21CS30050.y"
    { 
        (yyval.stat)=(yyvsp[0].stat);
        backpatch((yyvsp[-2].stat)->nextlist,(yyvsp[-1].instruction_no));     //after $1, move to block_item via $2
    }
#line 3788 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 202:
#line 1324 "ass5_21CS10016_21CS30050.y"
    { (yyval.stat)=(yyvsp[0].stat) ;/* simple assign */}
#line 3794 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 203:
#line 1326 "ass5_21CS10016_21CS30050.y"
    { (yyval.stat)=new Statement(); /* Create new statement */}
#line 3800 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 204:
#line 1331 "ass5_21CS10016_21CS30050.y"
    { (yyval.stat)=new Statement(); /* Create new statement */}
#line 3806 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 205:
#line 1333 "ass5_21CS10016_21CS30050.y"
    { (yyval.stat)=(yyvsp[0].stat); /* Simple assign */}
#line 3812 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 206:
#line 1338 "ass5_21CS10016_21CS30050.y"
    { (yyval.expr) = new Expression(); /* new Expression */ }
#line 3818 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 207:
#line 1340 "ass5_21CS10016_21CS30050.y"
    { (yyval.expr)=(yyvsp[-1].expr); /* Simple assign */}
#line 3824 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 208:
#line 1345 "ass5_21CS10016_21CS30050.y"
    {
        // if without else
        backpatch((yyvsp[-4].stat)->nextlist, nextinstr());                   // After we hit N we go to next instr
        INT2BOOL((yyvsp[-5].expr));                                   // expression in IF is converted to bool

        (yyval.stat) = new Statement();                                   
        backpatch((yyvsp[-5].expr)->truelist, (yyvsp[-2].instruction_no));                            // We do the backpatch here

        list<int> temp = merge((yyvsp[-5].expr)->falselist, (yyvsp[-1].stat)->nextlist);    // If it is false, we just escape the inner statement
        (yyval.stat)->nextlist = merge((yyvsp[0].stat)->nextlist, temp);
    }
#line 3840 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 209:
#line 1357 "ass5_21CS10016_21CS30050.y"
    {
        // if with else
        backpatch((yyvsp[-7].stat)->nextlist, nextinstr());		            // After we hit N we go to next instr
        INT2BOOL((yyvsp[-8].expr));                                   // convert expression to bool 

        (yyval.stat) = new Statement();                                   
        backpatch((yyvsp[-8].expr)->truelist, (yyvsp[-5].instruction_no));                            // If true, we access the first part
        backpatch((yyvsp[-8].expr)->falselist, (yyvsp[-1].instruction_no));                          // Else the second prt

        list<int> temp = merge((yyvsp[-4].stat)->nextlist, (yyvsp[-3].stat)->nextlist);       // Then we merge with the nextlists of both statements
        (yyval.stat)->nextlist = merge((yyvsp[0].stat)->nextlist,temp);	
    }
#line 3857 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 210:
#line 1370 "ass5_21CS10016_21CS30050.y"
    { /* Not asked in question */ }
#line 3863 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 211:
#line 1375 "ass5_21CS10016_21CS30050.y"
    {	
        // while statement
        (yyval.stat) = new Statement();                                  
        INT2BOOL((yyvsp[-3].expr));                                 
        
        // Proper backpatching
        backpatch((yyvsp[0].stat)->nextlist, (yyvsp[-4].instruction_no));	            // M1 to go back to expression again
        backpatch((yyvsp[-3].expr)->truelist, (yyvsp[-1].instruction_no));	            // M2 to go to statement if the expression is true
        (yyval.stat)->nextlist = (yyvsp[-3].expr)->falselist;               // If expression is false, Exit loop

        // Q.emit to prevent fallthrough
        string str=INT2STRING((yyvsp[-4].instruction_no));		
        Q.emit("goto",str);	
        loop_name = "";
        changeTable(ST->parent);
    }
#line 3884 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 212:
#line 1392 "ass5_21CS10016_21CS30050.y"
    {	
        //while statement
        (yyval.stat) = new Statement();                   // create statement
        INT2BOOL((yyvsp[-5].expr));                   // convert expression to bool
        
        // Proper Backpatching
        backpatch((yyvsp[-1].stat)->nextlist, (yyvsp[-6].instruction_no));	        // M1 to go back to expression again
        backpatch((yyvsp[-5].expr)->truelist, (yyvsp[-2].instruction_no));	        // M2 to go to statement if the expression is true
        (yyval.stat)->nextlist = (yyvsp[-5].expr)->falselist;           // If expression is false, then exit loop
        
        // Q.emit to prevent fallthrough
        string str=INT2STRING((yyvsp[-6].instruction_no));		
        Q.emit("goto",str);	
        loop_name = "";
        changeTable(ST->parent);
    }
#line 3905 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 213:
#line 1409 "ass5_21CS10016_21CS30050.y"
    {
        //do statement
        (yyval.stat) = new Statement();                               //create statement	
        INT2BOOL((yyvsp[-2].expr));                               //convert to bool
        
        // proper Backpatching
        backpatch((yyvsp[-2].expr)->truelist, (yyvsp[-7].instruction_no));						// M1 to go back to statement if expression is true
        backpatch((yyvsp[-6].stat)->nextlist, (yyvsp[-5].instruction_no));						// M2 to go to check expression if statement is complete
        
        (yyval.stat)->nextlist = (yyvsp[-2].expr)->falselist;                       // Exit loop if statement is false
        loop_name = "";
    }
#line 3922 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 214:
#line 1422 "ass5_21CS10016_21CS30050.y"
    {
        //do statement
        (yyval.stat) = new Statement();     //create statement	
        INT2BOOL((yyvsp[-2].expr));      //convert to bool
        
        backpatch((yyvsp[-2].expr)->truelist, (yyvsp[-8].instruction_no));						// M1 to go back to statement if expression is true
        backpatch((yyvsp[-7].stat)->nextlist, (yyvsp[-5].instruction_no));						// M2 to go to check expression if statement is complete
        
        (yyval.stat)->nextlist = (yyvsp[-2].expr)->falselist;                       // Exit loop if statement is false
        loop_name = "";
    }
#line 3938 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 215:
#line 1434 "ass5_21CS10016_21CS30050.y"
    {
        //for loop
        (yyval.stat) = new Statement();		            // create new statement
        INT2BOOL((yyvsp[-6].expr));                   // convert check expression to boolean
        
        // Proper Backpatching
        backpatch((yyvsp[-6].expr)->truelist, (yyvsp[-1].instruction_no));	        // if expression is true, go to M2
        backpatch((yyvsp[-3].stat)->nextlist, (yyvsp[-7].instruction_no));	        // after N, go back to M1
        backpatch((yyvsp[0].stat)->nextlist, (yyvsp[-5].instruction_no));	        // statement go back to expression
        
        
        string str=INT2STRING((yyvsp[-5].instruction_no));
        Q.emit("goto", str);				    // Emit goto
        (yyval.stat)->nextlist = (yyvsp[-6].expr)->falselist;	        // Exit loop if statement is false
        loop_name = "";
        changeTable(ST->parent);
    }
#line 3960 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 216:
#line 1452 "ass5_21CS10016_21CS30050.y"
    {
        //for loop
        (yyval.stat) = new Statement();		 //create new statement
        INT2BOOL((yyvsp[-6].expr));  //convert check expression to boolean
        
        // Proper Backpatching
        backpatch((yyvsp[-6].expr)->truelist, (yyvsp[-1].instruction_no));	                // if expression is true, go to M2
        backpatch((yyvsp[-3].stat)->nextlist, (yyvsp[-7].instruction_no));	                // after N, go back to M1
        backpatch((yyvsp[0].stat)->nextlist, (yyvsp[-5].instruction_no));	                // statement go back to expression
        
        
        string str=INT2STRING((yyvsp[-5].instruction_no));
        Q.emit("goto", str);				            //  emit goto str
        (yyval.stat)->nextlist = (yyvsp[-6].expr)->falselist;	                // Exit loop if statement is false
        loop_name = "";
        changeTable(ST->parent);
    }
#line 3982 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 217:
#line 1470 "ass5_21CS10016_21CS30050.y"
    {
        //for loop
        (yyval.stat) = new Statement();		                    // create new statement
        INT2BOOL((yyvsp[-8].expr));                           // convert check expression to boolean

        // Correctly backpatch lists
        backpatch((yyvsp[-8].expr)->truelist, (yyvsp[-3].instruction_no));	                // if expression is true, then go to M2
        backpatch((yyvsp[-5].stat)->nextlist, (yyvsp[-9].instruction_no));	                // after N, go back to M1
        backpatch((yyvsp[-1].stat)->nextlist, (yyvsp[-7].instruction_no));	                //statement go back to expression
        
        
        string str=INT2STRING((yyvsp[-7].instruction_no));
        Q.emit("goto", str);				            //prevent fallthrough
        (yyval.stat)->nextlist = (yyvsp[-8].expr)->falselist;	                // Exit loop if statement is false
        loop_name = "";
        changeTable(ST->parent);
    }
#line 4004 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 218:
#line 1488 "ass5_21CS10016_21CS30050.y"
    {	
        (yyval.stat) = new Statement();		                    // create new statement
        INT2BOOL((yyvsp[-8].expr));                           // convert expression to boolean
        
        // proper backpatching
        backpatch((yyvsp[-8].expr)->truelist, (yyvsp[-3].instruction_no));	                // backpatch &13
        backpatch((yyvsp[-5].stat)->nextlist, (yyvsp[-9].instruction_no));	                // after N, go back to M1
        backpatch((yyvsp[-1].stat)->nextlist, (yyvsp[-7].instruction_no));	                // statement go back to expression
        
        string str=INT2STRING((yyvsp[-7].instruction_no));
        Q.emit("goto", str);				            // Emit goto Str
        (yyval.stat)->nextlist = (yyvsp[-8].expr)->falselist;	                // Exit if statement is false
        loop_name = "";
        changeTable(ST->parent);                        
    }
#line 4024 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 219:
#line 1507 "ass5_21CS10016_21CS30050.y"
    { 
        // Handle the GOTO statement.
        // Create a new Statement.
        (yyval.stat) = new Statement();

        // Find the label associated with the provided identifier.
        label *l = find_label((yyvsp[-1].sym_ptr)->name);

        if (l) {
            // If the label exists, emit a "goto" statement.
            Q.emit("goto", "");

            // Create a list of the next instruction and merge it with the label's nextlist.
            list<int> lst = makelist(nextinstr());
            l->nextlist = merge(l->nextlist, lst);

            if (l->addr != -1) {
                // If the label's address is known, backpatch the nextlist.
                backpatch(l->nextlist, l->addr);
            }
        } else {
            // If the label does not exist, create a new label and add it to the label store.
            l = new label((yyvsp[-1].sym_ptr)->name);
            l->nextlist = makelist(nextinstr());
            Q.emit("goto", "");
            label_store.push_back(*l);
        }
    }
#line 4057 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 220:
#line 1537 "ass5_21CS10016_21CS30050.y"
    {
        // Handle the CONTINUE statement.
        // Create a new Statement.
        (yyval.stat) = new Statement();
    }
#line 4067 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 221:
#line 1544 "ass5_21CS10016_21CS30050.y"
    {
        // Handle the BREAK statement.
        // Create a new Statement.
        (yyval.stat) = new Statement();
    }
#line 4077 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 222:
#line 1551 "ass5_21CS10016_21CS30050.y"
    {
        // Handle the RETURN statement with an expression.
        // Create a new Statement.
        (yyval.stat) = new Statement();
        // Emit a "return" statement with the expression's name.
        Q.emit("return", (yyvsp[-1].expr)->loc->name);             
    }
#line 4089 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 223:
#line 1560 "ass5_21CS10016_21CS30050.y"
    {
        // Handle the RETURN statement without an expression.
        // Create a new Statement.
        (yyval.stat) = new Statement();
        // Emit a "return" statement without an expression.
        Q.emit("return", "");                         
    }
#line 4101 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 224:
#line 1572 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 4107 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 225:
#line 1574 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 4113 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 226:
#line 1579 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 4119 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 227:
#line 1581 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 4125 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 228:
#line 1586 "ass5_21CS10016_21CS30050.y"
    {
        // Set the parent symbol table to the global symbol table.
        ST->parent = globalST;

        // Update the function status.
        (yyvsp[-5].sym_ptr)->UpdateFunctStatus(true);

        // Initialize counters and clear data.
        table_count = 0;
        label_store.clear();

        // Change the symbol table to the global symbol table.
        changeTable(globalST);
    }
#line 4144 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 229:
#line 1605 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 4150 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 230:
#line 1607 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 4156 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 231:
#line 1612 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 4162 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 232:
#line 1614 "ass5_21CS10016_21CS30050.y"
    { /*No action needed*/ }
#line 4168 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 233:
#line 1618 "ass5_21CS10016_21CS30050.y"
    {    
        // This rule represents a change in the symbol table.
        // It includes some operations on the symbol table.
        parent_ST = ST;  // Backup the current symbol table.

        // If nested, call recursively on the nested table.
        if (currSymbolPtr->nested == NULL) {
            changeTable(new symtable(""));  // Create a new symbol table if it's nested.	                                           
        }
        else {
            changeTable(currSymbolPtr->nested);  // Change to the nested symbol table.
            Q.emit("label", ST->name);  // Emit a label in the intermediate code.
        }
    }
#line 4187 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 234:
#line 1636 "ass5_21CS10016_21CS30050.y"
    {
        // This empty production is used for backpatching. 
        // It sets the result ($$) to the next instruction in the generated code.
        (yyval.instruction_no) = nextinstr();
    }
#line 4197 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 235:
#line 1644 "ass5_21CS10016_21CS30050.y"
    {
        // This empty production is used at the beginning of a for statement.
        // It sets the loop_name to "FOR," which is useful for identifying the type of loop.
        loop_name = "FOR";
    }
#line 4207 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 236:
#line 1652 "ass5_21CS10016_21CS30050.y"
    {
        // This empty production is used at the beginning of a while statement.
        // It sets the loop_name to "WHILE," helping to distinguish the loop type.
        loop_name = "WHILE";
    }
#line 4217 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 237:
#line 1660 "ass5_21CS10016_21CS30050.y"
    {
        // This empty production is used at the beginning of a do-while statement.
        // It sets the loop_name to "DO_WHILE" for proper loop type identification.
        loop_name = "DO_WHILE";
    }
#line 4227 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 238:
#line 1669 "ass5_21CS10016_21CS30050.y"
    {
        // Create a name for the nested symbol table based on the current symbol table's name,
        // the loop name, and a table count.
        string name = ST->name + "." + loop_name + "$" + to_string(table_count);
        table_count++;

        // First, create an entry for the new symbol table.
        sym* s = ST->lookup(name);

        // Create a new nested symbol table and set its parent to the current symbol table.
        s->nested = new symtable(name);
        s->nested->parent = ST;
        s->name = name;

        // Update the symbol entry with a symbol type of "block."
        s->update(new symboltype("block"));

        // Update the current symbol pointer to the newly created symbol entry.
        currSymbolPtr = s; // Update the current symbol.
    }
#line 4252 "ass5_21CS10016_21CS30050.tab.c"
    break;

  case 239:
#line 1693 "ass5_21CS10016_21CS30050.y"
        {
        /*
        In this production, we handle the case where N is empty.
        It creates a new Statement and sets its nextlist to a new list containing the current next instruction.
        After that, it emits a "goto" statement (action is not specified) for further processing.
        */
		(yyval.stat) = new Statement();
		(yyval.stat)->nextlist=makelist(nextinstr());

		Q.emit("goto","");
	}
#line 4268 "ass5_21CS10016_21CS30050.tab.c"
    break;


#line 4272 "ass5_21CS10016_21CS30050.tab.c"

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
#line 1705 "ass5_21CS10016_21CS30050.y"


/*Auxiliaries*/
void yyerror(string s) 
    {
        // print error
        cout<<s<<endl;
    }
