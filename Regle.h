#ifndef REGLE_H
#define REGLE_H

typedef struct proposition{
    char *name;
    struct proposition *next;
}Proposition;

typedef struct regle{
    Proposition *premise;
    char *conclusion;
    struct regle *next;
}Regle;

Regle* new_rule(void);
Regle* add_premisse(Regle *regle, char *name);
Regle* add_conclusion(Regle *regle, char *name);
Regle* remove_prem(Regle* r, char *name);

Proposition* Get_prem(Regle *r);

char* Get_Conclu(Regle *r);

int Is_in(Proposition* liste, char *propo);
int Is_empty(Regle* r);

void print_rules(Regle *r);

#endif