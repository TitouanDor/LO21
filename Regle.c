#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Regle.h"

Regle* new_rule(void){
    Regle *new = (Regle*)malloc(sizeof(Regle));
    if(!new){
        return NULL;
    }
    new->premise = NULL;
    new->conclusion = NULL;
    new->next = NULL;
    return new;
}

Regle* add_premise(Regle*r, char* name){
    Proposition *temp = r->premise;
    Proposition *new = (Proposition*)malloc(sizeof(Proposition));
    if(!new){
        return NULL;
    }
    if(!r){
        return NULL;
    }
    if(!name){
        return r;
    }
    int n = strlen(name);
    new->name = (char*)malloc((n+1)*sizeof(char));
    strcpy(new->name, name);
    new->next = NULL;
    if(!temp){
        r->premise = new;
        return r;
    }
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = new;
    return r;
}

Regle* add_conclusion(Regle*r, char* name){
    if(!r){
        return NULL;
    }
    int n = strlen(name);
    r->conclusion = (char*)malloc((n+1)*sizeof(char));
    strcpy(r->conclusion, name);
    return r;
}

Regle* remove_premise(Regle* r, char *name){
    if(!r){
        return r;
    }
    Proposition *temp = r->premise;
    if(!temp){
        return r;
    }

    if(temp && strcmp(temp->name, name) == 0){
        r->premise = temp->next;
        free(temp->name);
        free(temp);
        return r;
    }

    while(temp->next && strcmp(temp->next->name, name) != 0){
        temp = temp->next;
    }
    if(temp->next && strcmp(temp->next->name, name) == 0){
        Proposition *to_free = temp->next;
        temp->next = temp->next->next;
        free(to_free->name);
        free(to_free);
    }

    return r;
}

Proposition* add_to_queue(Proposition *lp, char *name){
    Proposition *temp = lp;
    Proposition *new = (Proposition*)calloc(1, sizeof(Proposition));
    new->next = NULL;
    new->name = (char*)calloc(strlen(name), sizeof(char));
    strcpy(new->name, name);
    if(!lp){
        return new;
    }
    while(temp->next)
    {
        temp=temp->next;
    }
    temp->next = new;
    return lp;
}

Proposition* remove_duplicates(Proposition* liste){
    Proposition *current = liste;
    if (!liste) {
        return NULL;
    }
    while (current) {
        Proposition *runner = current;
        while (runner->next != NULL) {
            if (strcmp(runner->next->name, current->name) == 0) { //si doublon, on sauvegarde pour le supp apres
                Proposition *to_free = runner->next;
                runner->next = to_free->next; //on deplace le pointeur
                free(to_free->name);
                free(to_free);
            } else {
                runner = runner->next;
            }
        }
        current = current->next;
    }
    return liste;
}

Proposition* Get_premise(Regle* r){
    if(!r){
        return NULL;
    }
    return r->premise;
}

char* Get_Conclusion(Regle *r){
    if(!r){
        return NULL;
    }
    if(r->conclusion == NULL){
        return NULL;
    }
    char *text = (char*)malloc(strlen(r->conclusion)+1);
    strcpy(text, r->conclusion);
    return text;
}

int Is_in(Proposition* liste, char *propo){//return 1 if find else 0
    if(liste == NULL){
        return 0;
    }
    else if(strcmp(liste->name, propo) == 0){
        return 1;
    }
    else{
        return Is_in(liste->next, propo);
    }
}

int Is_empty(Regle *regle){ //return 0 if empty else 1
    if(!regle){
        return -1;
    }
    if(regle->premise == NULL){
        return 0;
    }
    return 1;
}

void print_rules(Regle *r){
    if(!r){
        printf("Regle inexistante !\n");
    }

    Proposition *temp = r->premise;
    if(!temp){
        printf("Aucune prémisse !\n");
    }
    else{
        while(temp != NULL){
            printf("%s,", temp->name);
            temp = temp->next;
        }

        if(r->conclusion){
            printf("=> %s\n", r->conclusion);
        }
        else{
            printf("=> Pas de conclusion\n");
        }
    }
}