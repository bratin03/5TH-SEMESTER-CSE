%{
#include<string.h>
#include<iostream>
#include"parser.h"
extern int yylex();
void yyerror(const char*s);
#define NYSMS 50
symboltable symtab[NYSMS];
%}

%union {
    int intval;
    struct symtab *symp;
}

%token <symp> NAME
%token <intval> NUMBER

%left '+' '-'
%left '*' '/'
%nonassoc UMINUS

%type<symp> expression
%%

stmt_list   :   statement '\n'
            |   stmt_list statement '\n'
            ;

statement   :   NAME '=' expression
            {   emit($1->name,$3->name);    }
            ;

expression  :   expression '+' expression
            {   
                $$ = gentemp();             
                emit($$->name,$1->name,'+',$3->name);
            }
            |   expression '-' expression
            {  
                $$ = gentemp();             
                emit($$->name,$1->name,'-',$3->name);
            }
            |   expression '*' expression
            {  
                $$ = gentemp();             
                emit($$->name,$1->name,'*',$3->name);
            }
            |   expression '/' expression
            {  
                $$ = gentemp();             
                emit($$->name,$1->name,'/',$3->name);
            }
            |   '(' expression ')'
            {
                $$ = $2;
            }
            |   '-' expression %prec UMINUS
            {
                $$ = gentemp();
                emit($$->name,$2->name,'-');
            }
            |   NAME
            {
                $$= $1;
            }
            |   NUMBER
            {
                $$ = gentemp();
                printf("\t%s = %d\n",$$->name,$1);
            }

%%

symboltable *symlook(char *s)
{
    char *p;
    struct symtab *sp;
    for(sp = symtab; sp<&symtab[NYSMS]; sp++)
    {
        if(sp->name && !strcmp(sp->name,s))
        return sp;
    
        if(!sp->name)
        {
            sp->name = strdup(s);
            return sp;
        }
    }
    yyerror("Too many symbols\n");
    exit(1);
}

symboltable *gentemp()
{
    static int c = 0;
    char str[10];
    sprintf(str,"t%02d",c++);
    return symlook(str);
}

void emit(char *s1, char* s2,char c,char *s3)
{
    if(s3)
    {
        printf("\t%s = %s %c %s\n",s1,s2,c,s3);
    }
    else
    {
        if(c)
        {
            printf("\t%s = %c %s\n",s1,c,s2);
        }
        else
        {
            printf("\t%s = %s\n",s1,s2);
        }
    }
}

void yyerror(const char *s)
{
    std::cout<<s<<std::endl;
}

int main()
{
    yyparse();
}

