/******************************************************************************\
fichier : Parametres_Regulateur_PID.h
\******************************************************************************/


#ifndef PARAMETRES_REGULATEUR_PID_H
#define PARAMETRES_REGULATEUR_PID_H

/* Inclusion des bibliotheques standard du C */
#include <stdint.h> /* int16_t */

typedef struct _Parametres_Regulateur_PID
{
    int16_t fact_prop_cons; /* facteur proportionnelle applique a la consigne */
    int16_t fact_prop_err; /* facteur de l'action proportionnelle */
    int16_t fact_integ_err; /* facteur de l'action integrale */
    int16_t fact_deriv_err; /* facteur de l'action derivee */
    int16_t max_cmd; /* valeur maximale de la commande */
    int16_t min_cmd; /* valeur minimale de la commande */
}Param_Regul_PID;

#endif
