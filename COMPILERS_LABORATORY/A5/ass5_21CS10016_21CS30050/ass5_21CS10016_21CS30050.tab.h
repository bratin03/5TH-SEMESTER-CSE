/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison interface for Yacc-like parsers in C

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

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

#line 164 "ass5_21CS10016_21CS30050.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_ASS5_21CS10016_21CS30050_TAB_H_INCLUDED  */
