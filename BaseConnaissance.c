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
    Regle *temp = bc; //variable temp pour se déplacer dans la liste chainée
    while(temp != NULL){
        print_rules(temp);
        temp = temp->next;
    }
}