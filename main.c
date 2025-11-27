#include <stdio.h>
#include <string.h>

#include "Regle.h"
#include "BaseConnaissance.h"

BC create_example_BC(void) {
    BC base_connaissance = create_BC();
    
    Regle *r2 = new_rule();
    add_premise(r2, "Pluie");
    add_premise(r2, "Froid");
    add_conclusion(r2, "Neige");
    base_connaissance = add_rules(base_connaissance, r2);

    Regle *r1 = new_rule();
    add_premise(r1, "Nuages");
    add_conclusion(r1, "Pluie");
    base_connaissance = add_rules(base_connaissance, r1);

    Regle *r3 = new_rule();
    add_premise(r3, "Neige");
    add_conclusion(r3, "Hiver");
    base_connaissance = add_rules(base_connaissance, r3);

    Regle *r4 = new_rule();
    add_premise(r4, "Soleil");
    add_premise(r4, "Cannicule");
    add_conclusion(r4, "été");
    base_connaissance = add_rules(base_connaissance, r4);

    return base_connaissance;
}

BaseFait create_example_BF(void){
    BaseFait new = NULL;
    new = add_to_queue(new, "Nuages");
    new = add_to_queue(new, "Froid");
    new = add_to_queue(new, "Soleil");
    return new;
}

int main(int argc, char *argv[]){
    BC bc;
    BaseFait bf = NULL;
    int example = 0;
    if(argc == 2){
        if(strcmp(argv[1], "ex") == 0){
            example = 1;
        }
    }

    if(example == 1){
        bc = create_example_BC();
        bf = create_example_BF();
        print_BC(bc);
        print_BF(bf);
    } else{
        bc = create_BC();
        bf = NULL;
    }
    
    bf = MI(bc, bf);
    print_BF(bf);
    return 0;
}