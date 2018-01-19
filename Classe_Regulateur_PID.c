/******************************************************************************\
fichier : Classe_Regulateur_PID.c
\******************************************************************************/

#include "Classe_Regulateur_PID.h"

/* Inclusion des bibliotheques standard du C */


/* */
#include "Additions.h" /* Additionner_int32_int32 */
#include "Soustractions.h" /* Soustraire_int32_int32 */


/******************************************************************************/
/* Definition des methodes publiques */
/******************************************************************************/
Regul_PID REGPID_Initialiser_Regulateur( const Param_Regul_PID* const param )
{
    Regul_PID regul;
    regul.cmd = 0;
    regul.cons_prec = 0;
    regul.err_prec = 0;
    regul.somme_err = 0;
    regul.param = param;

    return regul;
}
/******************************************************************************/
void REGPID_Calculer_Commande( Regul_PID* const regul,
                               const int16_t* const consigne,
                               const int16_t* const mesure )
{
    int32_t erreur;
    int32_t corr_prop_cons;
    int32_t corr_prop_err;
    int32_t corr_integ_err;
    int32_t corr_deriv_err;
    int32_t diff_erreur;

    /* Calcul de l'erreur */
    erreur = ((int32_t)(*consigne)) - ((int32_t)(*mesure));

    /* Gestion de l'action proportionnel a la consigne */
    corr_prop_cons=(int32_t)(*consigne)*(int32_t)(regul->param->fact_prop_cons);

    /* Gestion de l'action proportionnelle */
    corr_prop_err = erreur * (int32_t)(regul->param->fact_prop_err);

    /* Gestion de l'action integrale */
    /* Réinitialisation de la somme des erreurs si la consigne a changee */
    if( *consigne!=regul->cons_prec)
    {
        regul->somme_err = 0;
    }
    else
    {
        regul->somme_err = Additionner_int32_int32( regul->somme_err, erreur );
    }
    /* Calcul de la correction intégrale */
    corr_integ_err = regul->somme_err*((int32_t)(regul->param->fact_integ_err));

    /* Gestion de l'action derivee */
    /* Calcul de la correction derivee */
    diff_erreur = Soustraire_int32_int32( erreur, regul->err_prec );
    corr_deriv_err = diff_erreur * (int32_t)(regul->param->fact_deriv_err);
    /* Mise a jour de l'erreur precedente */
    regul->err_prec = erreur;

    /* Calcul de la commande total */
    regul->cmd = Additionner_int32_int32( corr_prop_cons, corr_prop_err );
    regul->cmd = Additionner_int32_int32( regul->cmd, corr_integ_err );
    regul->cmd = Additionner_int32_int32( regul->cmd, corr_deriv_err );

    /* Saturation de la commande */
    if( regul->cmd > regul->param->max_cmd )
    {
        regul->cmd = regul->param->max_cmd;
    }
    else if( regul->cmd < regul->param->min_cmd )
    {
        regul->cmd = regul->param->min_cmd;
    }

    regul->cons_prec = *consigne;
}
/******************************************************************************/
