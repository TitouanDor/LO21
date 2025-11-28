#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "Regle.h"

Regle *new_rule(void){
    Regle *new = (Regle*)malloc(sizeof(Regle));
    if(!new){
        return NULL;
    }
    new->premise = NULL;
    new->conclusion = NULL;
    new->next = NULL;
    return new;
}

Regle *add_premise(Regle*r, char* name){
    if(!r){
        //si la règle n'existe pas renvoyer NULL
        return NULL;
    }
    if(!name){
        //si aucun nom n'a été donné renvoyer la règle sans modification
        return r;
    }
    Proposition *temp = r->premise; //pointeur vers une prémisse pour se déplacer à la fin de la liste chainée
    Proposition *new = new_proposition(name); //pointeur vers la nouvelle prémisse à ajouter

    if(!new){
        //erreur dans l'allocation de new_proposition() renvoyer la règle sans modification
        return r;
    }
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

Regle *add_conclusion(Regle*r, char* name){
    if(!r){
        //si la règle n'existe pas renvoyer NULL
        return NULL;
    }
    if(!name){
        //si aucun nom n'a été donné renvoyer la règle sans modification
        return r;
    }
    int n = strlen(name);
    r->conclusion = (char*)malloc((n+1)*sizeof(char));
    strcpy(r->conclusion, name);
    return r;
}

Regle *remove_premise(Regle* r, char *name){
    if(!r){
        //si la règle n'existe pas renvoyer NULL
        return NULL;
    }
    if(!name){
        //si aucun nom n'a été donné renvoyer la règle sans modification
        return r;
    }
    Proposition *temp = r->premise;
    if(!temp){
        return r;
    }

    if(temp && strcmp(temp->name, name) == 0){
        //Si la première prémisse est celle à supprimer alors la supmrime
        r->premise = temp->next;
        free(temp->name);
        free(temp);
        return r;
    }

    int cmp = strcmp(temp->next->name, name);

    while(temp->next && cmp != 0){
        //parcours la liste jusqu'à ce que la prochaine prémisse n'existe pas ou que ce soit celle à supprimer
        temp = temp->next;
        cmp = strcmp(temp->next->name, name);
    }
    if(temp->next && cmp == 0){
        //regarde si la prémisse suivante est celle à supprimer et que la suivante existe alors supprime la suivante
        Proposition *to_free = temp->next;
        temp->next = temp->next->next;
        free(to_free->name);
        free(to_free);
    }

    return r;
}

Proposition *new_proposition(char *name){
    if(!name){
        return NULL;//si aucun nom n'a été donné renvoyer NULL
    }
    Proposition *new = (Proposition*)malloc(sizeof(Proposition));
    if(!new){
        return NULL;
    }
    int n = strlen(name) + 1;
    new->name = (char*)malloc(n*sizeof(char));
    strcpy(new->name, name);
    new->next = NULL;
    return new;
}

Proposition *add_to_queue(Proposition *lp, char *name){
    if(!name){
        //si aucun nom n'a été donné renvoyer la liste sans modification
        return lp;
    }
    
    Proposition *new = new_proposition(name);    //nouvelle proposition à ajouter à la fin de la liste
    if(!lp){
        //si la liste est vide
        return new;
    }
    Proposition *temp = lp;//pointeur vers une prémisse pour se déplacer à la fin de la liste chainée
    while(temp->next)
    {
        temp=temp->next;
    }
    temp->next = new;
    return lp;
}

Proposition *remove_duplicates(Proposition* liste){
    Proposition *current = liste;       //premier pointeur vers une prémisse pour se déplacer dans la liste chainée
    if(!liste){
        //si la liste n'existe pas
        return NULL;
    }
    while(current){
        Proposition *runner = current; //deuxième pointeur vers une prémisse pour se déplacer dans la liste chainée entre le premier pointeur et la fin de la liste
        while(runner->next != NULL){
            if(strcmp(runner->next->name, current->name) == 0){
                //si doublon, on sauvegarde pour le supp apres
                Proposition *to_free = runner->next;
                runner->next = to_free->next; //on deplace le pointeur
                free(to_free->name);
                free(to_free);
            }else{
                runner = runner->next;
            }
        }
        current = current->next;
    }
    return liste;
}

Proposition *Get_premise(Regle* r){
    if(!r){
        //si la règle donnée n'existe pas
        return NULL;
    }
    return r->premise;
}

char *Get_Conclusion(Regle *r){
    if(!r){
        //si la règle donnée n'existe pas
        return NULL;
    }
    if(r->conclusion == NULL){
        //si la conclusion n'existe pas
        return NULL;
    }
    char *text = (char*)malloc(strlen(r->conclusion)+1);
    strcpy(text, r->conclusion);
    return text;
}

int Is_in(Proposition* liste, char *propo){
    if(liste == NULL){
        return 0;
    }
    if(strcmp(liste->name, propo) == 0){
        return 1;
    }
    else{
        return Is_in(liste->next, propo);
    }
}

int Is_empty(Regle *regle){
    if(!regle){
        return -1;
    }
    if(regle->premise == NULL){
        return 1;
    }
    return 0;
}

void print_rules(Regle *r){
    if(!r){
        //si aucune règle n'a été donnée
        printf("Regle inexistante !\n");
    }

    Proposition *temp = r->premise;
    if(!temp){
        //si la règle n'a aucune prémisse
        printf("Aucune prémisse !\n");
    }
    else{
        while(temp != NULL){
            printf("%s", temp->name);
            if(temp->next){
            printf("+");
        }
            temp = temp->next;
        }

        if(r->conclusion){
            printf(" => %s", r->conclusion);
        }
        else{
            printf("=> Pas de conclusion\n");
        }
    }
}
