#ifndef BASECONNAISSANCE_H
#define BASECONNAISSANCE_H
#include "Regle.h"

/**
*
*Base de connaissances du système d'inférence. Implémentée comme une liste chaînée de règles, 
*    chaque élément pointant vers une structure Regle et la suivante dans la base.
*
*
*/
typedef Regle *BC;

/**
 * Base de faits du système d'inférence.
 *
 * Implémentée comme une liste chaînée de propositions.
 */
typedef Proposition *BaseFait;

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
 * Crée une base de connaissances d'exemple.
 *
 * Construit et initialise une BC contenant quelques règles prédéfinies
 * utiles pour des tests ou des démonstrations.
 *
 * \return Un pointeur vers la base de connaissances d'exemple créée.
 */
BC create_example_BC(void);

/**
 * Crée une base de faits d'exemple.
 *
 * Construit et initialise une BaseFait contenant quelques propositions
 * prédéfinies pour des scénarios de test ou d'illustration.
 *
 * \return Un pointeur vers la base de faits d'exemple créée.
 */
BaseFait create_example_BF(void);

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

/**
*  Affiche la base de faits passée en paramètre.
*  Parcourt la structure BaseFait et affiche l'ensemble des faits qu'elle contient sur la sortie standard (ou un autre support défini).
*
*  \param bf Pointeur vers la base de faits à afficher.
*/
void print_BF(BaseFait bf);

#endif