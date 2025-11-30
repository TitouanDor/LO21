#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "Regle.h"
#include "BaseConnaissance.h"
#define MAX 256

/**
 * Voici une base de connaissances et de faits deja construite pour essayer le projet avec l'utilisation de l'argument ex
 *
 * cela nous permet de tester sans a chaque fois redonner des regles et faits
 */
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

BaseFait create_example_BF(void){      //pour pouvoir essayer le projet avec une base de connaissances et de faits deja construite.
    BaseFait new = NULL;
    new = add_to_queue(new, "Nuages");
    new = add_to_queue(new, "Froid");
    new = add_to_queue(new, "Soleil");
    return new;
}

char *get_input(int *ret, char *text){
    int get_one = 0;
    char *input = (char*)malloc(MAX*sizeof(char));
    while (get_one == 0){
        printf("%s", text);
        if(fgets(input, MAX, stdin) != NULL){
            input[strcspn(input, "\n")] = '\0';
            if(strcmp(input, ".") == 0){
                printf("Fin\n");
                *ret = 1;
                get_one = 1;
                return "";
            }

            if (strlen(input) > 2){
                *ret = 0;
                get_one = 1;
                return input;

            }
            printf("problème lors de la saisie de l'input veuillez reéssayer ! \n");
        }
    }
}

BC input_BC_user(void){
    int loop_r = 1, loop_pre = 0, loop_conclu = 0,premise_count, ret;
    BC bc = create_BC();
    char *get = (char*)malloc(MAX*sizeof(char)), text[MAX];
    printf("\n--- SAISIE DE LA BASE DE CONNAISSANCES (BC) ---\n");
    printf("fonctionnement : <premisse> / <.> (fin des premisse) / <conclusion>\n");
    printf("si la premiere premisse est un <.> alors on a terminé la BC.\n");
    while (loop_r == 1){
        Regle *new = (Regle*)malloc(sizeof(Regle));
        new->next = NULL;
        loop_pre = 1;
        premise_count = 0;
        while (loop_pre == 1) {
            sprintf(text, "premisse %d (ou '.' pour conclusion) > ", premise_count+1);
            get = get_input(&ret, text);
            if(ret == 1){
                loop_pre = 0;
                if(premise_count == 0){
                    loop_r = 0;
                } else {
                    loop_conclu = 1;
                }
            } else if (ret == 0){
                new = add_premise(new, get);
                premise_count++;
            }
            
        }
        while (loop_conclu == 1){
            sprintf(text, "Conclu > ");
            get = get_input(&ret, text);
            if (ret == 0){
                new = add_conclusion(new, get);
                loop_conclu = 0;
            }
        }

        if(Is_empty(new) == 1){
            free(new);
        } else {
            printf("Ajout de la règle\n");
            bc = add_rules(bc, new);
        }
    }
    return bc;
}

BaseFait input_BF_user(void){
    BaseFait bf = NULL;
    char *get = (char*)malloc(MAX*sizeof(char)), *text = "Fait > ";
    int loop = 1, ret;
    while (loop == 1){
        get = get_input(&ret, text);
        if(ret == 1){
            loop = 0;
        } else if (ret == 0){
            bf = add_to_queue(bf, get);
        }
    }
    return bf;
}

int main(int argc, char *argv[]){
    BC bc;
    BaseFait bf = NULL;
    int example = 0;
    if(argc == 2){      //verification de l'argument ex pour utiliser la BC et BF préconstruite
        if(strcmp(argv[1], "ex") == 0){
            example = 1;
        }
    }

    if(example == 1){       //utiliser l'exemple 1
        bc = create_example_BC();
        bf = create_example_BF();
    } else{     // Saisie utilisateur
        printf("--- Saisie utilisateur activée ---\n");
        bc = input_BC_user();
        bf = input_BF_user();
    }

    printf("\n--- Base de connaissances initiale ---\n");
    print_BC(bc);

    printf("\n--- Base de faits initiale ---\n");
    print_BF(bf);


    printf("\n--- Exécution du moteur d'inférence ---\n");      // appel du moteur d'inférence
    bf = MI(bc, bf);

    printf("\n--- Base de faits finale (après inférence) ---\n");
    print_BF(bf);

    return 0;
}