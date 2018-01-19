/******************************************************************************\
fichier : Classe_Regulateur_PID.h
\******************************************************************************/


#ifndef CLASSE_REGULATEUR_PID_H
#define CLASSE_REGULATEUR_PID_H

/* Inclusion des bibliotheques standard du C */
#include <stdint.h> /* int16_t, int32_t */

#include "Parametres_Regulateur_PID.h"

/******************************************************************************/
/* Definition des attributs la classe Classe_Regulateur_PID */
typedef struct _Classe_Regulateur_PID
{
    Param_Regul_PID* param;
    int32_t somme_err; /* somme des erreurs */
    int32_t err_prec; /* erreur (=consigne-mesure) precedente */
    int16_t cmd; /* commande calculee par le regulateur */
    int16_t cons_prec; /* consigne precedente */
}Regul_PID;


/******************************************************************************/
/* REGPID_Initialiser_Regulateur

Description :


Parametres :


Retour :

*/
Regul_PID REGPID_Initialiser_Regulateur( const Param_Regul_PID* const param );


/******************************************************************************/
/* REGPID_Calculer_Commande

Description :


Parametres :


Retour :

*/
void REGPID_Calculer_Commande( Regul_PID* const regul,
                               const int16_t* const consigne,
                               const int16_t* const mesure );

#endif
