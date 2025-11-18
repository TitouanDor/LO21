#include <stdlib.h>
#include <stdio.h>
#include "BaseConnaissance.h"
#include "Regle.h"

BC create_BC(){
    BC new = (BC)calloc(1, sizeof(Regle));
    if(!new){
        return NULL;
    }
    return new;
}

BC add_rules(BC bc, Regle *r){
    if(!bc){
        return NULL;
    }
    Regle *temp = bc;
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
            Proposition *prem = Get_prem(r);
            if(Is_in(prem, fait->name)){
                r = remove_prem(r, fait->name);
            }
            if(Is_empty(r)){
                baseF = ajouter_queue(baseF, fait->name);
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
    Regle *temp = bc;
    while(temp != NULL){
        print_rules(temp);
        temp = temp->next;
    }
}