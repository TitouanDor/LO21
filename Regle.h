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

int Is_in(Proposition* liste, char *propo);

void print_rules(Regle *r);

#endif