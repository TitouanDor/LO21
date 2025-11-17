#include <stdio.h>

#include "Regle.h"

int main(void){
    Regle *r1 = new_rule();
    printf("%d\n", Is_empty(r1));
    r1 = add_premisse(r1, "Moteur");
    r1 = add_premisse(r1, "Roue");
    r1 = add_premisse(r1, "Volant");
    print_rules(r1);
    r1 = add_conclusion(r1, "roue");
    print_rules(r1);
    printf("%d\n", Is_in(r1->premise, "Volant"));
    remove_prem(r1, "Moteur");
    printf("%d\n", Is_empty(r1));
    printf("%s\n", Get_Conclu(r1));
    print_rules(r1);
    return 0;
}