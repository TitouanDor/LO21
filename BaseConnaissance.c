#include <stdlib.h>
#include <stdio.h>
#include "BaseConnaissance.h"
#include "Regle.h"

BC create_BC(){
    return NULL;
}

BC add_rules(BC bc, Regle *r){
    if(!bc){
        return r;
    }
    Regle *temp = bc; //variable temp pour ce déplacer à la fin de la liste chainée
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = r;
    return bc;
}

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
    add_premise(r4, "Canicule");
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

BaseFait MI(BC baseC, BaseFait baseF){
    int modif = 0; //0 si aucune modif n'a été faite sinon 1
    if(!baseF){
        fprintf(stderr, "La base de faits est vide (MI)\n");
        return NULL;
    }
    if(!baseC){
        fprintf(stderr, "La base de connaissances est vide (MI)\n");
        return baseF;
    }
    fprintf(stderr, "Commencement MI\n");
    Proposition *fait = baseF;
    while(fait){
        Regle *r = baseC;
        while(r){
            Proposition *prem = Get_premise(r);
            if(Is_in(prem, fait->name)){
                r = remove_premise(r, fait->name);
            }
            if(Is_empty(r)){
                char *conclu = Get_Conclusion(r);
                if(Is_in(baseF, conclu) == 0){
                    baseF = add_to_queue(baseF, conclu);
                }
            }
            r = r->next;
        }
        fait = fait->next;
    }
    return baseF;
}

void print_BC(BC bc){
    if(!bc){
        printf("La base de connaissance est vide\n");
    }
    printf("[ ");
    Regle *temp = bc; //variable temp pour se déplacer dans la liste chainée
    while(temp != NULL){
        print_rules(temp);
        if(temp->next){
            printf(", ");
        }
        temp = temp->next;
    }
    printf(" ]\n");
}

void print_BF(BaseFait bf){
    if(!bf){
        printf("La base de faits est vide\n");
        return;
    }
    BaseFait temp = bf; 
    while(temp){
        printf("%s", temp->name);
        if(temp->next){
            printf(", ");
        }
        temp = temp->next;
    }
    printf("\n");
}