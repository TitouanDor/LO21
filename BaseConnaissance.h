#ifndef BASECONNAISSANCE_H
#define BASECONNAISSANCE_H
#include "Regle.h"

typedef Regle *BC;

/**
 * Creer une Base de connaissance vide. Une base de connaissance étant une liste de Regle
 *
 * \returns le pointeur sur le premier élément de la liste de regle
 *
 */
BC create_BC();


/**
 * Ajoute une regle à la fin de la base de connaissance
 *
 * \param base_connaissance Pointeur vers la base de connaissance
 * \param rule Pointeur vers la règle à ajouter
 * \returns le pointeur de la base de connaissance mise à jour
 *
 */
BC add_rules(BC base_connaissance, Regle *rule);


/**
 * Moteur d'inférence, permet de vérifier si des règles établies ont des prémisses vrais, 
 *      si tel est le cas, ajout la conclusion comme un fait dans la base de fait
 *
 * \param base_connaissance Pointeur vers la base de connaissance
 * \param base_fait Pointeur vers la base de fait
 * 
 * \returns le pointeur de la base de fait mise à jour
 *
 */
BaseFait MI(BC base_connaissance, BaseFait base_fait);

/**
 * Afficher une base de connaissance
 * 
 * \param base_connaissance Base de connaissance à afficher
 * 
 */
void print_BC(BC base_connaissance);

#endif