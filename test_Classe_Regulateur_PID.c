#include <stdio.h> /* printf, getchar */
#include <stdlib.h> /* EXIT_SUCCESS */

#include "Classe_Regulateur_PID.h"
#include "Parametres_Regulateur_PID.h"

int main ( int argc, char *argv[] )
{
    Regul_PID regul;
    Param_Regul_PID param = { .fact_prop_cons = 1,
                             .fact_prop_err = 1,
                             .fact_integ_err = -15,
                             .fact_deriv_err = 1,
                             .max_cmd = 1000,
                             .min_cmd =-1500 };
    int16_t consigne = 80;
    int16_t mesure = 13;
    int temps;

    printf( "Test de la classe Classe_Regulateur_PID\n" );

    regul = REGPID_Initialiser_Regulateur( &param );

    for( temps = 0; temps<20 ; temps++ )
    {
        REGPID_Calculer_Commande( &regul, &consigne, &mesure );
        printf( "%u %d %d %d %d\n", temps, regul.cmd, regul.somme_err, 
                                    regul.cons_prec, regul.err_prec );
    }

    /*getchar();*/
    return EXIT_SUCCESS;
}
