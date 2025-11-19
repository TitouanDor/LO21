#ifndef REGLE_H
#define REGLE_H

typedef struct proposition{
    char *name;
    struct proposition *next;
}Proposition;

typedef struct regle{
    Proposition *premise;
    char *conclusion;
    struct regle *next;
}Regle;

typedef Proposition *BaseFait;

/**
 * Crée une nouvelle règle et l'initialise.
 *
 * \return Un pointeur vers la nouvelle structure Regle.
 */
Regle *new_rule(void);

/**
 * Ajoute une prémisse à la règle spécifiée.
 *
 * \param rule Règle à laquelle ajouter la prémisse.
 * \param name_premise Nom de la prémisse à ajouter.
 * \return Un pointeur vers la structure Regle modifiée.
 */
Regle *add_premise(Regle *rule, char *name_premise);

/**
 * Ajoute une conclusion à la règle spécifiée.
 *
 * \param rule Règle à laquelle ajouter la conclusion.
 * \param name_conclusion Nom de la conclusion à ajouter.
 * \return Un pointeur vers la structure Regle modifiée.
 */
Regle *add_conclusion(Regle *rule, char *name_conclusion);

/**
 * Supprime une prémisse spécifique de la règle indiquée.
 *
 * \param rule Règle dont on veut retirer la prémisse.
 * \param name_premise Nom de la prémisse à supprimer.
 * \return Un pointeur vers la structure Regle modifiée.
 */
Regle *remove_premise(Regle *rule, char *name_premise);

/**
 * Crée une nouvelle proposition et l'initialise avec le nom donné.
 *
 * \param name Nom de la proposition à créer.
 * \return Un pointeur vers la nouvelle structure Proposition.
 */
Proposition *new_proposition(char *name);

/**
 * Ajoute une proposition à la file (queue) de propositions.
 *
 * \param list_proposition Liste de propositions existante.
 * \param name_proposition Nom de la proposition à ajouter.
 * \return Un pointeur vers la liste mise à jour.
 */
Proposition *add_to_queue(Proposition* list_proposition, char *name_proposition);

/**
 * Récupère la première prémisse d'une règle.
 *
 * \param rule Règle dont on souhaite la prémisse.
 * \return Un pointeur vers la structure Proposition recherchée.
 */
Proposition *Get_premise(Regle *rule);

/**
 * Supprime les doublons d'une liste de propositions.
 *
 * \param list_proposition Liste de propositions à traiter.
 * \return Un pointeur vers la nouvelle liste sans doublons.
 */
Proposition *remove_duplicates(Proposition* list_proposition);

/**
 * Récupère la conclusion d'une règle.
 *
 * \param r Règle à interroger.
 * \return Nom de la conclusion (chaîne de caractères).
 */
char *Get_Conclusion(Regle *r);

/**
 * Indique si une proposition existe dans une liste.
 *
 * \param list_proposition Liste à inspecter.
 * \param proposition Nom de la proposition recherchée.
 * \return 1 si présente, 0 sinon.
 */
int Is_in(Proposition* list_proposition, char *proposition);

/**
 * Vérifie si une règle est vide (aucune prémisse ni conclusion).
 *
 * \param rule Règle à vérifier.
 * \return 1 si vide, 0 sinon.
 */
int Is_empty(Regle* rule);

/**
 * Affiche les règles contenues dans la structure passée en paramètre.
 *
 * \param rule Liste ou pointeur sur une ou plusieurs règles à afficher.
 */
void print_rules(Regle *rule);

#endif