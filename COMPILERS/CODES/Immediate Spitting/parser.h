#ifndef __PARSER_H
#define __PARSER_H

typedef struct symtab
{
    char *name;
    int value;
} symboltable;

symboltable *symlook(char *);

symboltable *gentemp();

void emit(char *s1,char *s2,char c = 0, char *s3 = 0);

#endif