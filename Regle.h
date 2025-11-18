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

typedef Proposition *BaseFait;

Regle* new_rule(void);
Regle* add_premise(Regle *regle, char *name);
Regle* add_conclusion(Regle *regle, char *name);
Regle* remove_premise(Regle* r, char *name);

<<<<<<< HEAD
=======
Proposition* Get_prem(Regle *r);
Proposition* ajouter_queue(Proposition *lp, char *name);
Proposition* supp_doublon(Proposition *lp);
>>>>>>> edc4993 (ajout base connaissance)

Proposition* Get_premise(Regle *r);
Proposition* remove_duplicates(Proposition* liste);

char* Get_Conclusion(Regle *r);

int Is_in(Proposition* liste, char *proposition);
int Is_empty(Regle* r);

void print_rules(Regle *r);

#endif