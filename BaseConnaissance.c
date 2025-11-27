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
    int modif = 0; //0 si aucune modif n'a été fait sinon 1
    if(!baseC){
        fprintf(stderr, "Base connaissance null");
        return baseF;
    }
    if(!baseF){
        fprintf(stderr, "Base fait null");
        return NULL;
    }
    Proposition *fait = baseF;
    while(fait){
        Regle *r = baseC;
        while(r){
            Proposition *prem = Get_premise(r);
            if(Is_in(prem, fait->name)){
                r = remove_premise(r, fait->name);
            }
            if(Is_empty(r)){
                baseF = add_to_queue(baseF, fait->name);
            }

            r = r->next;
        }
        fait = fait->next;
    }
    return baseF;
}

void print_BC(BC bc){
    if(!bc){
        printf("Base de connaissance Vide\n");
    }
    Regle *temp = bc; //variable temp pour ce déplacer dans la liste chainée
    while(temp != NULL){
        print_rules(temp);
        temp = temp->next;
    }
}