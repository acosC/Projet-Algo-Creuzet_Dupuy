#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "rdm.h"

int main()
{
    int nb_point, i, var = -1, a = 0, origine = -1;

    int ChoixUtilisateur = 0;



    printf("Bonjour, nous allons vous aider dans la resolution de votre probleme de RDM.\n");
    printf("Quelques questions pour comprendre l'exercice : \n");
    printf("Combien de points dans votre probleme ? ");
    scanf("%i",&nb_point);

    NombrePoints(nb_point);
    torseur t[nb_point];


    printf("Est-t-on sur un probleme a 2 dimensions ou a 3 dimensions ? ");
    printf("\nEntrez 2 ou 3\n");

    scanf("%i", &var);

    while (var != 2 && var != 3){
        printf("Choisissez entre 2 ou 3 ");
        scanf("%i",&var);
    }

    for (i = 0 ; i < nb_point ; i++){
        printf("On va remplir les information du torseur %i\n",i+1);
        origine = EntrerTorseurInit(i, t, var, origine);
        EntrerTorseurFin(i, t, var, origine);
    }

    printf("1 - Donnez les Resultantes\n");
    printf("2 - Donnez les Moments\n");
    printf("3 - Donnez les Torseurs\n");
    printf("4 - Donnez les Torseurs Cohesion\n");
    printf("5 - Donnez les Diagrammes\n");
    printf("6 - Quitter le programme\n");
    printf("\nVeuillez entrer votre choix !\n");
    scanf("%i",&ChoixUtilisateur);

    do {
        switch(ChoixUtilisateur){
        case 1 :
            printf("Voici vos resultantes\n");
	    if (nb_point == 2)
		ResolForce2Torseurs(t);
	    else
            	ResolForce3Torseurs(t);
            break;
        case 2 :
            printf("Voici vos moments\n");
	          babar(t, origine);
            break;
        case 3 :
            printf("Voici vos torseurs\n");
            AfficherlesTorseurs(t, 0);
            AfficherlesTorseurs(t, 1);
            if (nb_point==3)
              AfficherlesTorseurs(t, 2);
            break;
        case 4 :
            printf("Voici vos torseurs de cohesion\n");
            break;
        case 5 :
            printf("Voici vos diagrammes\n");
            affichercourbe(t);
            break;
        case 6 :
            assert (a == 0);
        default :
            printf("Vous n'avez pas fais de choix\n");
            break;
        }

        printf("1 - Donnez les Resultantes\n");
        printf("2 - Donnez les Moments\n");
        printf("3 - Donnez les Torseurs\n");
        printf("4 - Donnez les Torseurs Cohesion\n");
        printf("5 - Donnez les Diagrammes\n");
        printf("6 - Quitter le programme\n");
        printf("\nVeuillez entrer votre choix !\n");
        scanf("%i",&ChoixUtilisateur);

    } while (ChoixUtilisateur != 6);

    return 0;
}
