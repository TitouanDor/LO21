#include <stdio.h>

#include "Regle.h"
#include "BaseConnaissance.h"

int main(void){
    Regle *r1 = new_rule();
<<<<<<< HEAD
    printf("%d\n", Is_empty(r1));
    r1 = add_premise(r1, "Moteur");
    r1 = add_premise(r1, "Roue");
    r1 = add_premise(r1, "Volant");
    r1 = add_premise(r1, "Volant");
    print_rules(r1);
    r1->premise = remove_duplicates(r1->premise);
=======
    /*printf("%d\n", Is_empty(r1));
    r1 = add_premisse(r1, "Moteur");
    r1 = add_premisse(r1, "Roue");
    r1 = add_premisse(r1, "Volant");
>>>>>>> edc4993 (ajout base connaissance)
    print_rules(r1);
    r1 = add_conclusion(r1, "roue");
    print_rules(r1);
    printf("%d\n", Is_in(r1->premise, "Volant"));
    remove_premise(r1, "Moteur");
    printf("%d\n", Is_empty(r1));
<<<<<<< HEAD
    printf("%s\n", Get_Conclusion(r1));
    print_rules(r1);
=======
    printf("%s\n", Get_Conclu(r1));
    print_rules(r1);*/
    BC base = create_BC();
    BaseFait bf = NULL;
    bf = MI(base, bf);
>>>>>>> edc4993 (ajout base connaissance)
    return 0;
}